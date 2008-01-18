/**
 * Copyright (c) 2007- T Jake Luciani
 * Distributed under the New BSD Software License
 *
 * See accompanying file LICENSE or visit the Thrudb site at:
 * http://thrudb.googlecode.com
 *
 **/
#ifndef __THRUDEX_SIMPLE_HANDLER__
#define __THRUDEX_SIMPLE_HANDLER__

#include "ThrudexHandler.h"

//Thrucene handler minus logic used to realise remote transactions

class ThrudexSimpleHandler : public ThrudexHandler
{
 public:

    void addList(const std::vector<thrudex::DocMsg> &d){
        this->_addList(d);
    };

    void updateList(const std::vector<thrudex::DocMsg> &u){
        this->_updateList(u);
    };

    void removeList(const std::vector<thrudex::RemoveMsg> &d){
        this->_removeList(d);
    };

    void optimize(const string &domain, const string &index){
        this->_optimize(domain,index);
    };

    void optimizeAll(){
        this->_optimizeAll();
    };

    void commit(const string &domain, const string &index){
        this->_commit(domain,index);
    };

    void commitAll(){
        this->_commitAll();
    };

};

#endif
