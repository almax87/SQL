#pragma once
#include <iostream>
#include <pqxx/pqxx>

class ClientManager{

    private:
        pqxx::connection c;
    
    public:
        ClientManager(std::string& pass) : c{"host=localhost "
        "port=5432 "
        "dbname=client_manager "
        "user=postgres "
        "password="+ pass}{};

        void initDbStructure();
        void addClient(const std::string& firstName, const std::string& lastName, 
                        const std::string& email, const std::string& phoneNumber);
        void addPhoneNumber(int clientId, int& count, std::string& phoneNumber);
        void updateClient(int id, const std::string& val, const std::string& param);
        void removeClient(int id);
        void removeContacts(int id);
        std::vector<int>& findByName(const std::string& firstName, const std::string& lastName, std::vector<int>&);
        int findByEmail(const std::string& email);
        int findByPhone(const std::string& phoneNumber);
    };