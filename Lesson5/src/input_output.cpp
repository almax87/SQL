#include "input_output.h"

void inputClientData(std::string& firstName, std::string& lastName, std::string& email, std::string& phoneNumber)
{
    std::cout << "Введите имя клиента: ";
    std::getline(std::cin, firstName);
    std::cout << "Введите фамилию клиента: ";
    std::getline(std::cin, lastName);
    std::cout << "Введите email клиента: ";
    std::getline(std::cin, email);
    std::cout << "Введите номер клиента: ";
    std::getline(std::cin, phoneNumber);
}

void inputClientPhone(int& id, std::string& phoneNumber, ClientManager* clientmanager)
{
    id = 0;
    phoneNumber.clear();
    int count{1};

    std::cout << "Введите id клиента для добавления номера: ";
    std::cin >> id;
    std::cin.get();

    while(true)
    {
        phoneNumber.clear();
        std::cout << "Введите дополнительный номер телефона клиента (введите 0 для выхода): ";
        std::getline(std::cin, phoneNumber);
        if (phoneNumber == std::to_string(0))
        {
            break;
        }
        else 
            clientmanager->addPhoneNumber(id, count, phoneNumber);
        count++;
    }
}

void inputUpdateData(int& id, std::string& val, std::string& param)
{
    id = 0;
    std::cout << "Введите id клиента для изменения данных: ";
    std::cin >> id;
    std::cin.get();
    std::cout << "Введите поле, которое хотите изменить : ";
    std::getline(std::cin, param);
    std::cout << "Введите новое значение: ";
    std::getline (std::cin, val);
}
void inputIdToRemove(int& id)
{
    id = 0;
    std::cout << "Введите ID для удаления: ";
    std::cin >> id;
    std::cin.get();
}

void inputIdToRemoveContacts(int& id)
{
    id = 0;
    std::cout << "Введите ID для удаления контактов: ";
    std::cin >> id;
    std::cin.get();
}

void inputDataToFindByName(std::string& firstName, std::string& lastName)
{
    firstName.clear();
    lastName.clear();
    std::cout << "Введите имя клиента: ";
    std::getline(std::cin, firstName);
    std::cout << "Введите фамилию клиента: ";
    std::getline(std::cin, lastName);
}

void printSearchResult(const std::vector<int>& list)
{
    if (list.empty())
        std::cout << "Поиск не дал результата" << std::endl;
    else
    {
        for (const auto& i : list)
        std::cout << "Найден клиент с id " << i << std::endl;
    }
}

void inputDataToFindByEmail(std::string& email)
{
    email.clear();
    std::cout << "Введите email клиента: ";
    std::getline(std::cin, email);
}

void inputDataToFindByPhone(std::string& phoneNumber)
{
    phoneNumber.clear();
    std::cout << "Введите номер клиента: ";
    std::getline(std::cin, phoneNumber);
}