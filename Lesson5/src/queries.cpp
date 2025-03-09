#pragma once
#include "methods.h"

inline void add_column(pqxx::work& tx, int count)
{
    tx.exec( "ALTER TABLE clients ADD COLUMN phone" + tx.esc(std::to_string(count)) + " VARCHAR(80); ");
}

bool check_empty(pqxx::work& tx, int count)
{
    auto res = tx.exec("SELECT (phone" + tx.esc(std::to_string(count)) + " IS NULL OR phone" + tx.esc(std::to_string(count)) + " = '') AS is_empty "
                                            "FROM clients;");
    bool check = res[0][0].as<bool>();
    return check;
}

bool check_column(pqxx::work& tx, int count)
{
    pqxx::result res = tx.exec("SELECT EXISTS("
                                "SELECT 1 "
                                "FROM information_schema.columns "
                                "WHERE table_name = 'clients' "
                                "AND column_name = 'phone" + tx.esc(std::to_string(count)) + "');");
    return res[0][0].as<bool>();
}

inline void set_phone(pqxx::work& tx, int count, int id, std::string& phone_num)
{
    tx.exec("UPDATE clients SET phone" + tx.esc(std::to_string(count)) + "='" + tx.esc(phone_num) + "'"
                                " WHERE id=" +  tx.esc(std::to_string(id)) + ";");
}

