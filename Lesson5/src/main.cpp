#include "methods.h"

int main()
{
    try
    {
        clientdb *clients = new clientdb();
        clients->create_clientdb();
        clients->add_new_client();
        clients->add_phone_to_client();
        clients->update_client();
        clients->remove_contacts();
        clients->remove_client();
        clients->find_client_by_name();
        clients->find_client_by_email();
        clients->find_client_by_phone();
    }
    catch (pqxx::sql_error err)
    {
        std::cout << err.what() << std::endl;
    }

    return 0;
}