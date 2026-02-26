#pragma once
#include "DataSourceInterface.h"
#include <fstream>
#include <iostream>
#include <vector>
#include "parser.h"
using namespace std;



extern vector<Client> allClients;
extern vector<Employee> allEmployees;
extern vector<Admin> allAdmins;

class Client;
class Employee;
class Admin;

class FileManager : public DataSourceInterface
{
public:
    void addClient(Client obj) override;
    void addEmployee(Employee obj) override;
    void addAdmin(Admin obj) override;

    void getAllClients() override;
    void getAllEmployees() override;
    void getAllAdmins() override;

    void removeAllClients() override;
    void removeAllEmployees() override;
    void removeAllAdmins() override;

    vector<string> getData_intoLines(string textFile);



};
