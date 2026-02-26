#pragma once
#include <vector>
#include "Client.h"
#include "DataSourceInterface.h"

using namespace std;

extern vector<Client> allClients;

class FileManager : public DataSourceInterface
{
public:
    void addClient(Client c);
    void getAllClients();
    void removeAllClients();
};