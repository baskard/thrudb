/**
 *
 **/

#ifndef _MYSQL_BACKEND_H_
#define _MYSQL_BACKEND_H_

#if HAVE_LIBMYSQLCLIENT_R

#include <string>
#include <set>
#include <log4cxx/logger.h>
#include "Thrudoc.h"
#include "ThrudocBackend.h"
#include "mysql_glue.h"

struct FindReturn
{
    mysql::Connection * connection;
    std::string datatable;
};

// TODO: move this out of the header
class Partition
{
    public:
        static bool greater (Partition * a, Partition * b)
        {
            return a->get_end () < b->get_end ();
        }

        Partition (const double & end)
        {
            this->end = end;
            this->hostname = NULL;
            this->slave_hostname = NULL;
            this->db = NULL;
            this->datatable = NULL;
        }

        Partition (mysql::PartitionResults * partition_results)
        {
            this->end = partition_results->get_end ();
            this->hostname = strdup (partition_results->get_hostname ());
            this->port = partition_results->get_port ();
            const char * tmp = partition_results->get_slave_hostname ();
            if (tmp)
                this->slave_hostname = strdup (tmp);
            else
                this->slave_hostname = NULL;
            this->slave_port = partition_results->get_slave_port ();
            this->db = strdup (partition_results->get_db ());
            this->datatable = strdup (partition_results->get_datatable ());
        }

        ~Partition ()
        {
            if (hostname)
                free (hostname);
            if (slave_hostname)
                free (slave_hostname);
            if (db)
                free (db);
            if (datatable)
                free (datatable);
        }

        double get_end ()
        {
            return this->end;
        }

        const char * get_hostname ()
        {
            return this->hostname;
        }

        const int get_port ()
        {
            return this->port;
        }

        const char * get_slave_hostname ()
        {
            return this->slave_hostname;
        }

        const int get_slave_port ()
        {
            return this->slave_port;
        }

        const char * get_db ()
        {
            return this->db;
        }

        const char * get_datatable ()
        {
            return this->datatable;
        }

    protected:
        double end;
        char * hostname;
        short port;
        char * slave_hostname;
        short slave_port;
        char * db;
        char * datatable;
};

class MySQLBackend : public ThrudocBackend
{
    public:
        MySQLBackend (const std::string & master_hostname,
                      const short master_port,
                      const std::string & slave_hostname,
                      const short slave_port,
                      const std::string & directory_db,
                      const std::string & username,
                      const std::string & password,
                      int max_value_size);

        ~MySQLBackend ();

        std::vector<std::string> getBuckets ();
        std::string get (const std::string & bucket,
                         const std::string & key);
        void put (const std::string & bucket, const std::string & key,
                  const std::string & value);
        void remove (const std::string & bucket, const std::string & key);
        thrudoc::ScanResponse scan (const std::string & bucket,
                                    const std::string & seed, int32_t count);
        std::string admin (const std::string & op, const std::string & data);
        void validate (const std::string & bucket, const std::string * key,
                       const std::string * value);

    protected:

        FindReturn find_and_checkout (const std::string & bucket,
                                      const std::string & key);
        FindReturn find_next_and_checkout
            (const std::string & bucket,
             const std::string & current_databucket);

    private:
        static log4cxx::LoggerPtr logger;

        mysql::ConnectionFactory * connection_factory;
        std::map<std::string, std::set<Partition*, bool(*)(Partition*, Partition*)>* >
            partitions;
        std::string master_hostname;
        short master_port;
        std::string slave_hostname;
        short slave_port;
        std::string directory_db;
        std::string username;
        std::string password;
        int max_value_size;

        std::set<Partition*, bool(*)(Partition*, Partition*)> *
            load_partitions (const std::string & bucket);

        FindReturn and_checkout (mysql::Connection * connection,
                                 mysql::PreparedStatement * statement);
        std::string scan_helper (thrudoc::ScanResponse & scan_response,
                                 FindReturn & find_return,
                                 const std::string & offset, int32_t count);
};

#endif /* HAVE_LIBMYSQLCLIENT_R */

#endif
