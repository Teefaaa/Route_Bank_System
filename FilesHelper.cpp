#include "FilesHelper.h"
#include <fstream>


int FilesHelper::getNextClientId()
{
    int id;
    ifstream in("Clients_Last_ID.txt");

    if (!in)
    {
        id = 2400000;
    }
    else
    {
        in >> id;
        id++;
    }
    in.close();

    ofstream out("Clients_Last_ID.txt", ios::trunc);
    out << id;
    out.close();

    return id;
}





int FilesHelper::getNextEmployeeId()
{
    int id;
    ifstream in("Employees_Last_ID.txt");

    if (!in)
    {
        id = 2100000;
    }
    else
    {
        in >> id;
        id++;
    }
    in.close();

    ofstream out("Employees_Last_ID.txt", ios::trunc);
    out << id;
    out.close();

    return id;
}

int FilesHelper::getNextAdminId()
{
    int id;
    ifstream in("Admins_Last_ID.txt");

    if (!in)
    {
        id = 1900000;
    }
    else
    {
        in >> id;
        id++;
    }
    in.close();

    ofstream out("Admins_Last_ID.txt", ios::trunc);
    out << id;
    out.close();

    return id;
}



