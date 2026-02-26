#include "FileManager.h"
#include "Client.h"
#include "Employee.h"
#include "Admin.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

vector<Client> allClients;
vector<Employee> allEmployees;
vector<Admin> allAdmins;

// ================== CLIENTS =======================

void FileManager::addClient(Client c)
{
    ofstream file("Clients.txt", ios::app);

    file << c.get_id() << "&"
        << c.get_name() << "&"
        << c.get_password() << "&"
        << c.get_balance() << "&"
        << c.get_status() << "&"
        << c.get_loan() << "&"
        << c.get_risk_counter()
        << endl;

    file.close();
}

void FileManager::getAllClients()
{
    ifstream file("Clients.txt");
    string line;

    allClients.clear();

    while (getline(file, line))
    {
        int id;
        string name, password;
        double balance, loan;
        bool status;
        short risk_counter;

        string temp;
        stringstream ss(line);

        getline(ss, temp, '&');
        id = stoi(temp);

        getline(ss, name, '&');
        getline(ss, password, '&');

        getline(ss, temp, '&');
        balance = stod(temp);

        getline(ss, temp, '&');
        status = stoi(temp);

        getline(ss, temp, '&');
        loan = stod(temp);

        getline(ss, temp, '&');
        risk_counter = stoi(temp);

        Client c(id, name, password, balance, status, loan, risk_counter);
        allClients.push_back(c);
    }

    file.close();
}

void FileManager::removeAllClients()
{
    ofstream file("Clients.txt", ios::trunc);
    file.close();
}

// ================= EMPLOYEES ======================

void FileManager::addEmployee(Employee e)
{
    ofstream file("Employees.txt", ios::app);

    file << e.get_id() << "&"
        << e.get_name() << "&"
        << e.get_password() << "&"
        << e.get_salary()
        << endl;

    file.close();
}

void FileManager::getAllEmployees()
{
    ifstream file("Employees.txt");
    string line;

    allEmployees.clear();

    while (getline(file, line))
    {
        int id;
        string name, password;
        double salary;

        stringstream ss(line);
        string temp;

        getline(ss, temp, '&');
        id = stoi(temp);

        getline(ss, name, '&');
        getline(ss, password, '&');

        getline(ss, temp, '&');
        salary = stod(temp);

        Employee e(id, name, password, salary);
        allEmployees.push_back(e);
    }

    file.close();
}

void FileManager::removeAllEmployees()
{
    ofstream file("Employees.txt", ios::trunc);
    file.close();
}

// ==================== ADMINS ======================

void FileManager::addAdmin(Admin a)
{
    ofstream file("Admins.txt", ios::app);

    file << a.get_id() << "&"
        << a.get_name() << "&"
        << a.get_password() << "&"
        << a.get_salary()
        << endl;

    file.close();
}

void FileManager::getAllAdmins()
{
    ifstream file("Admins.txt");
    string line;

    allAdmins.clear();

    while (getline(file, line))
    {
        int id;
        string name, password;
        double salary;

        stringstream ss(line);
        string temp;

        getline(ss, temp, '&');
        id = stoi(temp);

        getline(ss, name, '&');
        getline(ss, password, '&');

        getline(ss, temp, '&');
        salary = stod(temp);

        Admin a(id, name, password, salary);
        allAdmins.push_back(a);
    }

    file.close();
}

void FileManager::removeAllAdmins()
{
    ofstream file("Admins.txt", ios::trunc);
    file.close();
}