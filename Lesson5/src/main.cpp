#include "input_output.h"

int main()
{
    try
    {
        std::string pass;
        std::string firstName, lastName, email, phoneNumber;
        int id{};
        std::vector<int> id_list{};
        std::cout << "Введите пароль для доступа к базе данных: ";
        std::getline(std::cin, pass);
        ClientManager *clientManager = new ClientManager(pass);

        /*inputClientData(firstName, lastName, email, phoneNumber);
        clientManager->addClient(firstName, lastName, email, phoneNumber);

        inputClientPhone(id, phoneNumber, clientManager);

        std::string param, val;
        inputUpdateData(id, val, param);
        clientManager->updateClient(id, val, param);

        inputIdToRemove(id);
        clientManager->removeClient(id);

        inputIdToRemoveContacts(id);
        clientManager->removeContacts(id);*/

        inputDataToFindByName(firstName, lastName);
        clientManager->findByName(firstName, lastName, id_list);
        printSearchResult(id_list);

        inputDataToFindByEmail(email);
        id = clientManager->findByEmail(email);
        std::cout << "Найден клиент с ID " << id << std::endl;

        inputDataToFindByPhone(phoneNumber);
        id = clientManager->findByPhone(phoneNumber);
        std::cout << "Найден клиент с ID " << id << std::endl;

    }
    catch (pqxx::sql_error err)
    {
        std::cout << err.what() << std::endl;
    }

    return 0;
}