#include "methods.h"
#include <tuple>
#include "queries.cpp"
#include <iterator>

void ClientManager::initDbStructure()
{
    pqxx::work tx(ClientManager::c);
    tx.exec("CREATE TABLE IF NOT EXISTS clients("
        "id SERIAL PRIMARY KEY, "
        "name VARCHAR(80) NOT NULL, "
        "second_name VARCHAR(80) NOT NULL, "
        "email VARCHAR(60) UNIQUE NOT NULL, "
        "phone1 VARCHAR(20));");
    tx.commit();
}

void ClientManager::addClient(const std::string& firstName, const std::string& lastName, 
                                const std::string& email, const std::string& phoneNumber)
{
    int id{};
    pqxx::work tx(ClientManager::c);
    std::string input{};

    tx.exec("INSERT INTO clients (name, second_name, email, phone1) "
            "VALUES('" + tx.esc(firstName) + "', '" + tx.esc(lastName) + "', '" +
            tx.esc(email) + "', '" + tx.esc(phoneNumber) + "');");
    tx.commit();
}

void ClientManager::addPhoneNumber(int id, int& count, std::string& phoneNumber)
{
    pqxx::work tx(ClientManager::c);
    while (true)
    {
        if (!check_column(tx, count))
            add_column(tx,count);
        if (check_empty)
            {
                set_phone(tx, count, id, phoneNumber);
                break;
            }
        else
            count++;
    }
    tx.commit();  
}

void ClientManager::updateClient(int id, const std::string& val, const std::string& param)
{
    pqxx::work tx{ClientManager::c};
    tx.exec("UPDATE clients SET " + tx.esc(param) + "='" + tx.esc(val) + "' "
            "WHERE id=" + tx.esc(std::to_string(id)) +";");
    tx.commit();
}

void ClientManager::removeClient(int id)
{
    pqxx::work tx{ClientManager::c};

    tx.exec("DELETE FROM clients "
            "WHERE id=" + tx.esc(std::to_string(id)) +";");
    tx.commit();
}

void ClientManager::removeContacts(int id)
{
    int count{1};
    std::string val{"null"};
    pqxx::work tx{ClientManager::c};
    while(true)
    {
        if (check_empty(tx,count))
        {
            set_phone(tx, count, id, val);
        }
        count++;
        if (!check_column(tx,count))
            break;
        else
            continue;   
    };
    tx.commit();
}

std::vector<int>& ClientManager::findByName(const std::string& firstName, const std::string& lastName, std::vector<int>& id_list)
{
    id_list.clear();
    pqxx::work tx{ClientManager::c};
    for (auto[id]: tx.query<int>("SELECT id FROM clients WHERE name = '" + tx.esc(firstName) + "' AND second_name = '" + tx.esc(lastName) + "';"))
    {
        id_list.push_back(id);
    }
    tx.commit();
    return id_list;
}

int ClientManager::findByEmail(const std::string& email)
{
    pqxx::work tx{ClientManager::c};
    auto res = tx.exec("SELECT id FROM clients WHERE email = '" + tx.esc(email) + "';");
    tx.commit();
    return res[0][0].as<int>();
}

int ClientManager::findByPhone(const std::string& phoneNumber)
{
    pqxx::work tx{ClientManager::c};
    auto res = tx.exec("SELECT id FROM clients WHERE phone1 = '" + tx.esc(phoneNumber) + "';");
    tx.commit();
    return res[0][0].as<int>();
}