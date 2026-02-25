#include "FileManager.h"


/// ============== TURNING FILES INTO VECTORS OF LINES ==============

vector<string> FileManager::getData_intoLines(string textFile)
{
    ifstream file(textFile);
    string line;
    vector<string>lines;

    if (file.is_open())
    {
        while (getline(file, line))
        {
            lines.push_back(line);
        }
        file.close();
    }
    return lines;
}


/// ================= ADD =================

void FileManager::addClient(Client obj)
{
    string status = to_string(obj.getActive());
    ofstream file("Clients.txt", ios::app);

    if (file.is_open())
    {

    file << obj.get_id() << "&"
        << obj.get_name() << "&"
        << obj.get_password() << "&"
        << obj.get_balance() << "&" << status << "&" << obj.get_loan() << "&"
        << obj.get_risk_counter() << endl;

    file.close();
    }
}

void FileManager::addEmployee(Employee obj)
{
    ofstream file("Employees.txt", ios::app);

    if (file.is_open())
    {

    file << obj.get_id() << "&"
        << obj.get_name() << "&"
        << obj.get_password() << "&"
        << obj.get_salary() << endl;

    file.close();
    }
}

void FileManager::addAdmin(Admin obj)
{
    ofstream file("Admins.txt", ios::app);

    if (file.is_open())
    {

    file << obj.get_id() << "&"
        << obj.get_name() << "&"
        << obj.get_password() << "&"
        << obj.get_salary() << endl;

    file.close();
    }
}

/// ================= GET ALL =================

void FileManager::getAllClients()
{
    ifstream file("Clients.txt");
    string line;

    if (file.is_open())
    {

    while (getline(file, line))
    {
        cout << line << endl;
    }

    file.close();
    }
}

void FileManager::getAllEmployees()
{
    ifstream file("Employees.txt");
    string line;

    if (file.is_open())
    {

    while (getline(file, line))
    {
        cout << line << endl;
    }

    file.close();
    }
}

void FileManager::getAllAdmins()
{
    ifstream file("Admins.txt");
    string line;

    if (file.is_open())
    {

    while (getline(file, line))
    {
        cout << line << endl;
    }

    file.close();
    }
}

/// ================= REMOVE ALL =================

void FileManager::removeAllClients()
{
    ofstream file("Clients.txt", ios::trunc);
    file.close();
}

void FileManager::removeAllEmployees()
{
    ofstream file("Employees.txt", ios::trunc);
    file.close();
}

void FileManager::removeAllAdmins()
{
    ofstream file("Admins.txt", ios::trunc);
    file.close();
}



