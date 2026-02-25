#include "FileManager.h"

/// ================= ADD =================

void FileManager::addClient(Client obj) {
    ofstream file("Clients.txt", ios::app);

    file << obj.get_id() << ","
        << obj.get_name() << ","
        << obj.get_password() << ","
        << obj.get_balance() << endl;

    file.close();
}

void FileManager::addEmployee(Employee obj) {
    ofstream file("Employees.txt", ios::app);

    file << obj.get_id() << ","
        << obj.get_name() << ","
        << obj.get_password() << ","
        << obj.get_salary() << endl;

    file.close();
}

void FileManager::addAdmin(Admin obj) {
    ofstream file("Admins.txt", ios::app);

    file << obj.get_id() << ","
        << obj.get_name() << ","
        << obj.get_password() << ","
        << obj.get_salary() << endl;

    file.close();
}

/// ================= GET ALL =================

void FileManager::getAllClients() {
    ifstream file("Clients.txt");
    string line;

    while (getline(file, line)) {
        cout << line << endl;
    }

    file.close();
}

void FileManager::getAllEmployees() {
    ifstream file("Employees.txt");
    string line;

    while (getline(file, line)) {
        cout << line << endl;
    }

    file.close();
}

void FileManager::getAllAdmins() {
    ifstream file("Admins.txt");
    string line;

    while (getline(file, line)) {
        cout << line << endl;
    }

    file.close();
}

/// ================= REMOVE ALL =================

void FileManager::removeAllClients() {
    ofstream file("Clients.txt", ios::trunc);
    file.close();
}

void FileManager::removeAllEmployees() {
    ofstream file("Employees.txt", ios::trunc);
    file.close();
}

void FileManager::removeAllAdmins() {
    ofstream file("Admins.txt", ios::trunc);
    file.close();
}