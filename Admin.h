#pragma once
#include "Employee.h"
class Admin :
    public Employee
{
private:
    static int admin_counter;
    void turn_on();

public:
    Admin(string name, string password, double salary);
    void see_system_statistics_till(Client c,Employee e);
    void risk_assessment(Client& c);
    void increase_salary(Employee& e, double amount);
    void decrease_salary(Employee& e, double amount);
    void display();
};
