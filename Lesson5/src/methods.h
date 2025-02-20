#pragma once
#include <iostream>
#include <pqxx/pqxx>


class clientdb{
    private:
        pqxx::connection c {"host=localhost "
        "port=5432 "
        "dbname=client_manager "
        "user=postgres "
        "password=Nofagem2211_"};

    public:
        clientdb(){}
        void create_clientdb();
        void add_new_client();
        void add_phone_to_client();
        void update_client();
        void remove_client();
        void remove_contacts();
        void find_client_by_name();
        void find_client_by_email();
        void find_client_by_phone();
    };