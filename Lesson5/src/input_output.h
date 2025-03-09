#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "methods.h"

void inputClientData(std::string& firstName, std::string& lastName, std::string& email, std::string& phoneNumber);
void inputClientPhone(int& id, std::string& phoneNumber, ClientManager* clientmanager);
void inputUpdateData(int& id, std::string& val, std::string& param);
void inputIdToRemove(int& id);
void inputIdToRemoveContacts(int& id);
void inputDataToFindByName(std::string& firstName, std::string& lastName);
void printSearchResult(const std::vector<int>& list);
void inputDataToFindByEmail(std::string& email);
void inputDataToFindByPhone(std::string& phoneNumber);

