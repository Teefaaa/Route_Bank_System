#include "FileManager.h"
#include <fstream>
#include <sstream>

vector<Client> allClients;

void FileManager::addClient(Client c)
{
    ofstream file("clients.txt", ios::app);

    file << c.get_name() << ","
        << c.get_password() << ","
        << c.get_balance() << endl;

    file.close();

    allClients.push_back(c);
}

void FileManager::getAllClients()
{
    ifstream file("clients.txt");
    string line;

    allClients.clear();

    while (getline(file, line))
    {
        string name, password;
        double balance;

        stringstream ss(line);
        getline(ss, name, ',');
        getline(ss, password, ',');
        ss >> balance;

        Client c(name, password, balance);
        allClients.push_back(c);
    }

    file.close();
}

void FileManager::removeAllClients()
{
    ofstream file("clients.txt", ios::trunc);
    file.close();

    allClients.clear();
}