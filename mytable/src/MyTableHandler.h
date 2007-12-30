/**
 *
 **/

#ifndef __MYTABLE_HANDLER__
#define __MYTABLE_HANDLER__

#include "MyTable.h"
#include "MyTableBackend.h"

#include <string>
#include <log4cxx/logger.h>
#include <libmemcached/memcached.h>

using namespace boost;
using namespace facebook::thrift;
using namespace mytable;
using namespace std;

class MyTableHandler : virtual public MyTableIf {
    public:
        MyTableHandler (boost::shared_ptr<MyTableBackend> backend);

        void getTablenames (vector<string> & _return);

        void put (const string & tablename, const string & key,
                  const string & value);
        void get (string & _return, const string & tablename,
                  const string & key);
        void remove (const string & tablename, const string & key);
        void scan (ScanResponse & _return, const string & tablename,
                   const string & seed, int32_t count);

        void admin (string & _return, const string & op, const string & data);

    protected:
        memcached_st * get_cache ();

        void cache_put (const string & tablename, const string & key, 
                        const string & value);

    private:
        static log4cxx::LoggerPtr logger;
        static pthread_key_t memcache_key;
        static bool memcached_enabled;
        static string memcached_servers;

        shared_ptr<MyTableBackend> backend;

        MyTableHandler (){};
};

#endif