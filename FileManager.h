#pragma once
#include <vector>
#include "Client.h"
#include "Employee.h"
#include "Admin.h"
#include "DataSourceInterface.h"

using namespace std;

extern vector<Client> allClients;
extern vector<Employee> allEmployees;
extern vector<Admin> allAdmins;


class FileManager : public DataSourceInterface
{
public:
    void addClient(Client c);
    void getAllClients();
    void removeAllClients();

    void addEmployee(Employee e);
    void getAllEmployees();
    void removeAllEmployees();

    void addAdmin(Admin a);
    void getAllAdmins();
    void removeAllAdmins();
};