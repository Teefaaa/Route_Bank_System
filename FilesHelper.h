#pragma once
#include "Admin.h"

class Client;
class Employee;
class Admin;


class FilesHelper
{
public:
    static int getNextClientId();
    static int getNextEmployeeId();
    static int getNextAdminId();



friend class Client;
friend class Employee;
friend class Admin;
};



