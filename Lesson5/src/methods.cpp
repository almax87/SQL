#include "methods.h"
#include <tuple>
#include "queries.cpp"
#include <iterator>

void clientdb::create_clientdb()
{
    pqxx::work tx(clientdb::c);
    tx.exec("CREATE TABLE IF NOT EXISTS clients("
        "id SERIAL PRIMARY KEY, "
        "name VARCHAR(80) NOT NULL, "
        "second_name VARCHAR(80) NOT NULL, "
        "email VARCHAR(60) UNIQUE NOT NULL, "
        "phone1 VARCHAR(20));");
    tx.commit();
}

void clientdb::add_new_client()
{
    int count {1};
    int id{};
    pqxx::work tx(clientdb::c);
    std::string name, sec_name, email, phone{};
    std::string input{};
    std::cout << "Введите имя клиента: ";
    std::getline(std::cin, name);
    std::cout << "Введите фамилию клиента: ";
    std::getline(std::cin, sec_name);
    std::cout << "Введите email клиента: ";
    std::getline(std::cin, email);
    
    tx.exec("INSERT INTO clients (name, second_name, email) "
            "VALUES('" + tx.esc(name) + "', '" + tx.esc(sec_name) + "', '" +
            tx.esc(email) + "');");

    id = tx.query_value<int>("SELECT id FROM clients WHERE email='" + email + "';");
    while (true)
    {
        std::cout << "Введите номер телефона клиента (0 для выхода): ";
        std::getline(std::cin, input);
        if (input == std::to_string(0))
        {
            break;
        }
        else
        {
            if(!check_column(tx,count))
            {
                add_column(tx,count);
            }
            set_phone(tx, count, id, input);
            count++;
        }
        input.clear();
    };
    tx.commit();
}

void clientdb::add_phone_to_client()
{
    pqxx::work tx{c};
    int id{};
    std::cout << "Введите id клиента для добавления контактного номера: ";
    std::cin >> id;
    std::cin.get();
    int count{1};
    std::string phone_number{};
    std::cout << "Введите номер телефона клиента: ";
    std::getline (std::cin, phone_number);
    if (check_empty(tx, count))
        {
            set_phone(tx, count, id, phone_number);
            phone_number.clear();
        }
    else
        {
            while (true)
            {
                count++;
                if (!check_column(tx, count))
                    {
                        add_column(tx,count);
                    }

                if (check_empty(tx, count))
                {
                    set_phone(tx, count, id, phone_number);
                }
                else
                    continue;
            }
        };
        tx.commit();
}


void clientdb::update_client()
{
    int id{};
    std::string param{}, val{};
    pqxx::work tx{c};
    std::cout << "Введите id клиента для изменения данных: ";
    std::cin >> id;
    std::cin.get();
    std::cout << "Введите поле, которое хотите изменить : ";
    std::getline(std::cin, param);
    std::cout << "Введите новое значение: ";
    std::getline (std::cin, val);
    tx.exec("UPDATE clients SET " + tx.esc(param) + "='" + tx.esc(val) + "' "
            "WHERE id=" + tx.esc(std::to_string(id)) +";");
    tx.commit();
}

void clientdb::remove_client()
{
    int id{};
    pqxx::work tx{c};
    std::cout << "Введите id клиента для удаления: ";
    std::cin >> id;
    std::cin.get();
    tx.exec("DELETE FROM clients "
            "WHERE id=" + tx.esc(std::to_string(id)) +";");
    tx.commit();
}

void clientdb::remove_contacts()
{
    int id{};
    int count{1};
    std::string val{"null"};
    pqxx::work tx{c};
    std::cout << "Введите id клиента для удаления телефона: ";
    std::cin >> id;
    std::cin.get();
    while(true)
    {
        if (check_empty(tx, count))
        {
            set_phone(tx, count, id, val);
        }
        else
            continue;
        count++;
        if (!check_column(tx,count))
            break;
    };
    tx.commit();
}

void clientdb::find_client_by_name()
{
    int count{};
    std::string name{}, sec_name{}, email{}, phone{};
    pqxx::work tx{c};
    std::cout << "Введите имя клиента : ";
    std::getline(std::cin, name);
    std::cout << "Введите фамилию клиента: ";
    std::getline (std::cin, sec_name);
    for (auto[id]: tx.query<int>("SELECT id FROM clients WHERE name = '" + tx.esc(name) + "' AND second_name = '" + tx.esc(sec_name) + "';"))
    {
        std::cout << "Найден клиент id " << id << std::endl;
        count++;
    }
    if (count == 0)
        std::cout << "Поиск не дал результатов" << std::endl;
    tx.commit();
}

void clientdb::find_client_by_email()
{
    int count{};
    std::string email{};
    pqxx::work tx{c};
    std::cout << "Введите email клиента : ";
    std::getline(std::cin, email);
    for (auto[id]: tx.query<int>("SELECT id FROM clients WHERE email = '" + tx.esc(email) + "';"))
    {
        std::cout << "Найден клиент id " << id << std::endl;
        count++;
    }
    if (count == 0)
        std::cout << "Поиск не дал результатов" << std::endl;
    tx.commit();
}

void clientdb::find_client_by_phone()
{
    int count{};
    std::string phone{};
    pqxx::work tx{c};
    std::cout << "Введите телефон клиента : ";
    std::getline(std::cin, phone);
    for (auto[id]: tx.query<int>("SELECT id FROM clients WHERE phone = '" + tx.esc(phone) + "';"))
    {
        std::cout << "Найден клиент id " << id << std::endl;
        count++;
    }
    if (count == 0)
        std::cout << "Поиск не дал результатов" << std::endl;
    tx.commit();
}