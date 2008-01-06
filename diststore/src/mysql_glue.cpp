
#include "mysql_glue.h"

using namespace std;
using namespace log4cxx;
using namespace mysql;
using namespace facebook::thrift::concurrency;

// private
LoggerPtr PreparedStatement::logger (Logger::getLogger ("PreparedStatement"));
LoggerPtr Connection::logger (Logger::getLogger ("Connection"));

void StringParams::init (const char * str)
{
    this->set_str (str);

    this->params = new MYSQL_BIND[1];
    memset (this->params, 0, sizeof (MYSQL_BIND) * 1);
    this->params[0].buffer_type = MYSQL_TYPE_STRING;
    this->params[0].buffer = this->str;
    this->params[0].is_null = &this->str_is_null;
    this->params[0].length = &this->str_length;
}

void StringIntParams::init (const char * str, unsigned int i)
{
    this->set_str (str);
    this->set_i (i);

    this->params = new MYSQL_BIND[2];
    memset (this->params, 0, sizeof (MYSQL_BIND) * 2);
    this->params[0].buffer_type = MYSQL_TYPE_STRING;
    this->params[0].buffer = this->str;
    this->params[0].is_null = &this->str_is_null;
    this->params[0].length = &this->str_length;
    this->params[1].buffer_type = MYSQL_TYPE_LONG;
    this->params[1].buffer = &this->i;
    this->params[1].is_null = 0;
    this->params[1].length = 0;
}

void StringStringParams::init (const char * str1, const char * str2)
{
    this->set_str1 (str1);
    this->set_str2 (str2);

    this->params = new MYSQL_BIND[2];
    memset (this->params, 0, sizeof (MYSQL_BIND) * 2);
    this->params[0].buffer_type = MYSQL_TYPE_STRING;
    this->params[0].buffer = this->str1;
    this->params[0].is_null = &this->str1_is_null;
    this->params[0].length = &this->str1_length;
    this->params[1].buffer_type = MYSQL_TYPE_STRING;
    this->params[1].buffer = this->str2;
    this->params[1].is_null = &this->str2_is_null;
    this->params[1].length = &this->str2_length;
}

PartitionsResults::PartitionsResults ()
{
    this->results = new MYSQL_BIND[10];
    memset (this->results, 0, sizeof (MYSQL_BIND) * 10);
    this->results[0].buffer_type = MYSQL_TYPE_LONG;
    this->results[0].buffer = &this->id;
    this->results[0].is_null = &this->id_is_null;
    this->results[0].length = &this->id_length;
    this->results[0].error = &this->id_error;
    this->results[1].buffer_type = MYSQL_TYPE_STRING;
    this->results[1].buffer = &this->tablename;
    this->results[1].buffer_length = sizeof (this->tablename);
    this->results[1].is_null = &this->tablename_is_null;
    this->results[1].length = &this->tablename_length;
    this->results[1].error = &this->tablename_error;
    this->results[2].buffer_type = MYSQL_TYPE_DOUBLE;
    this->results[2].buffer = &this->start;
    this->results[2].is_null = &this->start_is_null;
    this->results[2].length = &this->start_length;
    this->results[2].error = &this->start_error;
    this->results[3].buffer_type = MYSQL_TYPE_DOUBLE;
    this->results[3].buffer = &this->end;
    this->results[3].is_null = &this->end_is_null;
    this->results[3].length = &this->end_length;
    this->results[3].error = &this->end_error;
    this->results[4].buffer_type = MYSQL_TYPE_STRING;
    this->results[4].buffer = &this->host;
    this->results[4].buffer_length = sizeof (this->host);
    this->results[4].is_null = &this->host_is_null;
    this->results[4].length = &this->host_length;
    this->results[4].error = &this->host_error;
    this->results[5].buffer_type = MYSQL_TYPE_SHORT;
    this->results[5].buffer = &this->port;
    this->results[5].is_null = &this->port_is_null;
    this->results[5].length = &this->port_length;
    this->results[5].error = &this->port_error;
    this->results[6].buffer_type = MYSQL_TYPE_STRING;
    this->results[6].buffer = &this->db;
    this->results[6].buffer_length = sizeof (this->db);
    this->results[6].is_null = &this->db_is_null;
    this->results[6].length = &this->db_length;
    this->results[6].error = &this->db_error;
    this->results[7].buffer_type = MYSQL_TYPE_STRING;
    this->results[7].buffer = &this->datatable;
    this->results[7].buffer_length = sizeof (this->datatable);
    this->results[7].is_null = &this->datatable_is_null;
    this->results[7].length = &this->datatable_length;
    this->results[7].error = &this->datatable_error;
    this->results[8].buffer_type = MYSQL_TYPE_TIMESTAMP;
    this->results[8].buffer = &this->created_at;
    this->results[8].is_null = &this->created_at_is_null;
    this->results[8].length = &this->created_at_length;
    this->results[8].error = &this->created_at_error;
    this->results[9].buffer_type = MYSQL_TYPE_DATETIME;
    this->results[9].buffer = &this->retired_at;
    this->results[9].is_null = &this->retired_at_is_null;
    this->results[9].length = &this->retired_at_length;
    this->results[9].error = &this->retired_at_error;
}

KeyValueResults::KeyValueResults ()
{
    this->results = new MYSQL_BIND[4];
    memset (this->results, 0, sizeof (MYSQL_BIND) * 4);
    this->results[0].buffer_type = MYSQL_TYPE_STRING;
    this->results[0].buffer = &this->key;
    this->results[0].buffer_length = sizeof (this->key);
    this->results[0].is_null = &this->key_is_null;
    this->results[0].length = &this->key_length;
    this->results[0].error = &this->key_error;
    this->results[1].buffer_type = MYSQL_TYPE_STRING;
    this->results[1].buffer = &this->value;
    this->results[1].buffer_length = sizeof (this->value);
    this->results[1].is_null = &this->value_is_null;
    this->results[1].length = &this->value_length;
    this->results[1].error = &this->value_error;
    this->results[2].buffer_type = MYSQL_TYPE_TIMESTAMP;
    this->results[2].buffer = &this->created_at;
    this->results[2].is_null = &this->created_at_is_null;
    this->results[2].length = &this->created_at_length;
    this->results[2].error = &this->created_at_error;
    this->results[3].buffer_type = MYSQL_TYPE_DATETIME;
    this->results[3].buffer = &this->modified_at;
    this->results[3].is_null = &this->modified_at_is_null;
    this->results[3].length = &this->modified_at_length;
    this->results[3].error = &this->modified_at_error;
}

PreparedStatement::PreparedStatement (MYSQL * mysql,
                                      const char * query,
                                      BindParams * bind_params)
{
    init (mysql, query, bind_params, NULL);
}

PreparedStatement::PreparedStatement (MYSQL * mysql,
                                      const char * query,
                                      BindParams * bind_params,
                                      BindResults * bind_results)
{
    init (mysql, query, bind_params, bind_results);
}

void PreparedStatement::init (MYSQL * mysql, const char * query,
                              BindParams * bind_params,
                              BindResults * bind_results)
{
    this->query = query;
    this->bind_params = bind_params;
    this->bind_results = bind_results;
    LOG4CXX_DEBUG (logger, string ("init: query=") + this->query);

    this->stmt = mysql_stmt_init (mysql);
    if (this->stmt == NULL)
    {
        char buf[1024];
        sprintf (buf, "mysql_stmt_init failed: %p - %d - %s - %s", this->stmt,
                 mysql_errno (mysql), mysql_error (mysql), query);
        LOG4CXX_ERROR (logger, buf);
        DistStoreException e;
        e.what = "MySQLBackend error";
        throw e;
    }

    int ret;
    if ((ret = mysql_stmt_prepare (this->stmt, this->query, 
                                   strlen (this->query))) != 0)
    {
        char buf[1024];
        sprintf (buf, "mysql_stmt_prepare failed: %d - %p - %d - %s - %s",
                 ret, this->stmt, mysql_errno (mysql), mysql_error (mysql), 
                 query);
        LOG4CXX_ERROR (logger, buf);
        DistStoreException e;
        e.what = "MySQLBackend error";
        throw e;
    }

    if (this->bind_params != NULL)
    {
        if (mysql_stmt_bind_param (this->stmt,
                                   this->bind_params->get_params ()))
        {
            LOG4CXX_ERROR (logger, "mysql_stmt_bind_param failed");
            DistStoreException e;
            e.what = "MySQLBackend error";
            throw e;
        }
    }

    if (this->bind_results)
    {
        if (mysql_stmt_bind_result (this->stmt,
                                    this->bind_results->get_results ()))
        {
            char buf[1024];
            sprintf (buf, "mysql_stmt_bind_result failed: %p - %d - %s",
                     this->stmt, mysql_stmt_errno (this->stmt),
                     mysql_stmt_error (this->stmt));
            LOG4CXX_ERROR (logger, buf);
            DistStoreException e;
            e.what = "MySQLBackend error";
            throw e;
        }
    }
}

void PreparedStatement::execute ()
{
    LOG4CXX_DEBUG (logger, "execute");

    int ret;
    if ((ret = mysql_stmt_execute (this->stmt)) != 0)
    {
        char buf[1024];
        sprintf (buf, "mysql_stmt_execute failed: %d - %p - %d - %s", ret, 
                 this->stmt, mysql_stmt_errno (this->stmt), 
                 mysql_stmt_error (this->stmt));
        LOG4CXX_ERROR (logger, buf);
        DistStoreException e;
        e.what = "MySQLBackend error";
        throw e;
    }

    // optional, buffer results to client
    if ((ret = mysql_stmt_store_result (this->stmt)) != 0)
    {
        char buf[1024];
        sprintf (buf, "mysql_stmt_store_result failed: %d - %p - %d - %s", ret, 
                 this->stmt, mysql_stmt_errno (this->stmt), 
                 mysql_stmt_error (this->stmt));
        LOG4CXX_ERROR (logger, buf);
        DistStoreException e;
        e.what = "MySQLBackend error";
        throw e;
    }
}

unsigned long PreparedStatement::num_rows ()
{
    LOG4CXX_DEBUG (logger, "execute");

    mysql_stmt_store_result (this->stmt);
    return mysql_stmt_num_rows (this->stmt);
}

int PreparedStatement::fetch ()
{
    LOG4CXX_DEBUG (logger, "fetch");
    int ret = mysql_stmt_fetch (this->stmt);
    if (ret != 0 && ret != MYSQL_NO_DATA)
    {
        char buf[1024];
        sprintf (buf, "mysql_stmt_fetch failed: %d - %p - %d - %s",
                 ret, this->stmt, mysql_stmt_errno (this->stmt),
                 mysql_stmt_error (this->stmt));
        LOG4CXX_ERROR (logger,buf);
        DistStoreException e;
        e.what = "MySQLBackend error";
        throw e;
    }
    return ret;
}

void PreparedStatement::free_result ()
{
    LOG4CXX_DEBUG (logger, "free_result");
    int ret = mysql_stmt_free_result (this->stmt);
    if (ret != 0)
    {
        char buf[1024];
        sprintf (buf, "mysql_stmt_free_result failed: %d - %p - %d - %s",
                 ret, this->stmt, mysql_stmt_errno (this->stmt),
                 mysql_stmt_error (this->stmt));
        LOG4CXX_ERROR (logger,buf);
    }
}

Connection::Connection (const char * hostname, const char * db, const int port,
                        const char * username, const char * password)
{
    this->hostname = hostname;
    this->port = port;
    this->db = db;

    if (!mysql_init (&this->mysql))
        LOG4CXX_ERROR (logger, "mysql_init failed");

    my_bool val = true;
    mysql_options (&this->mysql, MYSQL_OPT_RECONNECT, &val);

    if (!mysql_real_connect (&this->mysql, hostname, username, password, db,
                             port, NULL, 0))
        LOG4CXX_ERROR (logger, string ("mysql_real_connect failed: host=") +
                       string (hostname) + string (", db=") + string (db) +
                       string (", username=") + string (username));

    // doing this before and after to work around potential bugs in mysql
    // server versions < 5.0.19
    mysql_options (&this->mysql, MYSQL_OPT_RECONNECT, &val);
}

PreparedStatement::~PreparedStatement ()
{
    LOG4CXX_DEBUG (logger, "~PreparedStatement");
    mysql_stmt_close (this->stmt);
}

Connection::~Connection ()
{
    LOG4CXX_DEBUG (logger, "~Connection");
    map<string, PreparedStatement *>::iterator i;
    for (i = partitions_statements.begin (); 
         i != partitions_statements.end (); i++)
        delete i->second;
    for (i = next_statements.begin (); i != next_statements.end (); i++)
        delete i->second;
    for (i = get_statements.begin (); i != get_statements.end (); i++)
        delete i->second;
    for (i = put_statements.begin (); i != put_statements.end (); i++)
        delete i->second;
    for (i = delete_statements.begin (); i != delete_statements.end (); i++)
        delete i->second;
    for (i = scan_statements.begin (); i != scan_statements.end (); i++)
        delete i->second;
    mysql_close (&this->mysql);
}

PreparedStatement * Connection::find_partitions_statement (const char * tablename)
{
    string key = string (tablename);
    PreparedStatement * stmt = this->partitions_statements[key];
    if (!stmt)
    {
        BindParams * bind_params = new StringParams ();
        BindResults * bind_results = new PartitionsResults ();
        char query[256];
        sprintf (query, "select id, tablename, start, end, host, port, db, datatable, created_at, retired_at from %s where tablename = ? and retired_at is null order by end asc",
                 tablename);
        stmt = new PreparedStatement (&this->mysql, query, bind_params, bind_results);
        this->partitions_statements[key] = stmt;
    }
    return stmt;
}

PreparedStatement * Connection::find_next_statement (const char * tablename)
{
    string key = string (tablename);
    PreparedStatement * stmt = this->next_statements[key];
    if (!stmt)
    {
        BindParams * bind_params = new StringStringParams ();
        BindResults * bind_results = new PartitionsResults ();
        char query[256];
        sprintf (query, "select id, tablename, start, end, host, port, db, datatable, created_at, retired_at from %s where tablename = ? and datatable > ? and retired_at is null order by end asc limit 1",
                 tablename);
        stmt = new PreparedStatement (&this->mysql, query, bind_params,
                                      bind_results);
        this->next_statements[key] = stmt;
    }
    return stmt;
}

PreparedStatement * Connection::find_get_statement (const char * tablename)
{
    string key = string (tablename);
    PreparedStatement * stmt = this->get_statements[key];
    if (!stmt)
    {
        BindParams * bind_params = new StringParams ();
        BindResults * bind_results = new KeyValueResults ();
        char query[256];
        sprintf (query, "select k, v, created_at, modified_at from %s where k = ?",
                 tablename);
        stmt = new PreparedStatement (&this->mysql, query, bind_params,
                                      bind_results);
        this->get_statements[key] = stmt;
    }
    return stmt;
}

PreparedStatement * Connection::find_put_statement (const char * tablename)
{
    string key = string (tablename);
    PreparedStatement * stmt = this->put_statements[key];
    if (!stmt)
    {
        BindParams * bind_params = new StringStringParams ();
        char query[256];
        sprintf (query, "insert into %s (k, v, created_at) values (?, ?, now()) on duplicate key update v = values (v)",
                 tablename);
        stmt = new PreparedStatement (&this->mysql, query, bind_params);
        this->put_statements[key] = stmt;
    }
    return stmt;
}

PreparedStatement * Connection::find_delete_statement (const char * tablename)
{
    string key = string (tablename);
    PreparedStatement * stmt = this->delete_statements[key];
    if (!stmt)
    {
        BindParams * bind_params = new StringParams ();
        char query[128];
        sprintf (query, "delete from %s where k = ?", tablename);
        stmt = new PreparedStatement (&this->mysql, query, bind_params);
        this->delete_statements[key] = stmt;
    }
    return stmt;
}

PreparedStatement * Connection::find_scan_statement (const char * tablename)
{
    string key = string (tablename);
    PreparedStatement * stmt = this->scan_statements[key];
    if (!stmt)
    {
        BindParams * bind_params = new StringIntParams ();
        BindResults * bind_results = new KeyValueResults ();
        char query[256];
        sprintf (query, "select k, v, created_at, modified_at from %s where k > ? order by k asc limit ?",
                 tablename);
        stmt = new PreparedStatement (&this->mysql, query, bind_params,
                                      bind_results);
        this->scan_statements[key] = stmt;
    }
    return stmt;
}
