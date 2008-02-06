/**
 * Copyright (c) 2007- T Jake Luciani
 * Distributed under the New BSD Software License
 *
 * See accompanying file LICENSE or visit the Thrudb site at:
 * http://thrudb.googlecode.com
 *
 **/

#ifdef HAVE_CONFIG_H
#include "thrudex_config.h"
#endif
/* hack to work around thrift and log4cxx installing config.h's */
#undef HAVE_CONFIG_H

#include "ThrudexSpreadTask.h"

#include "Thrudex.h"
#include "ThrudexHandler.h"
#include "ThrudexBackend.h"
#include "CLuceneSimpleBackend.h"
#include "RecoveryManager.h"
#include "TransactionManager.h"
#include "Transaction.h"

#include <boost/shared_ptr.hpp>

#include <thrift/Thrift.h>
#include <thrift/concurrency/Thread.h>
#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/transport/TTransportUtils.h>

using namespace thrudex;
using namespace facebook::thrift;
using namespace facebook::thrift::concurrency;
using namespace facebook::thrift::protocol;
using namespace facebook::thrift::transport;

ThrudexSpreadTask::ThrudexSpreadTask(boost::shared_ptr<Transaction> t)
        : transaction(t)
{

}

void ThrudexSpreadTask::ThrudexSpreadTask::run()
{
    //write threads happen locally
    TBinaryProtocolFactory protocol_factory;

    //thrucene handler specific to spread
    boost::shared_ptr<ThrudexBackend>   backend(new CLuceneSimpleBackend ());
    boost::shared_ptr<ThrudexHandler>   handler(new ThrudexHandler(backend));
    boost::shared_ptr<ThrudexProcessor> processor(new ThrudexProcessor(handler));

    const string raw_msg = transaction->getRawBuffer();

    boost::shared_ptr<TTransport> buf(new TMemoryBuffer
                                      ( (uint8_t*)raw_msg.c_str(), 
                                        raw_msg.length()) );

    boost::shared_ptr<TProtocol> prot = protocol_factory.getProtocol(buf);

    try {
        processor->process(prot, prot);

    } catch (TTransportException& ttx) {
        //cerr << "SpreadTask client died: " << ttx.what() << endl;
        throw;
    } catch (TException& x) {
        //cerr << "SpreadTask exception: " << x.what() << endl;
        throw;
    } catch (...) {
        //cerr << "SpreadTask uncaught exception." << endl;
        throw;
    }

    //Cleanup
    RecoveryManager->addRedo(raw_msg, transaction->getId());

    TransactionManager->endTransaction(transaction);
}