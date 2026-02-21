#include "Employee.h"
#include "FilesHelper.h"
#include <iostream>

int Employee::employee_counter = 2100000;
double Employee::total_salaries = 0;

void Employee::turn_on() { ; }

Employee::Employee(string name, string password, double salary)
    : Person(name, password)
{
    this->id = /*employee_counter++*/   FilesHelper::getNextEmployeeId();
    this->salary = salary;
    this->total_salaries+=this->salary;
}

void Employee::set_salary(double salary)
{
    if (salary >= 5000)
    {
        this->total_salaries-=this->salary;
        this->salary = salary;
        this->total_salaries+=this->salary;
    }
    else
    {
        cout << "Sorry! it should be greater than or equal 5000" << endl;
    }
}

double Employee::get_salary()
{
    return this->salary;
}

void Employee::activate_client(Client& c)
{
    c.setActive(true);
    cout << "Client account activated successfully" << endl;
}

void Employee::deactivate_client(Client& c)
{
    c.setActive(false);
    cout << "Client account deactivated successfully" << endl;
}

void Employee:: update_client_password(Client& recipient, string newPassword)
 {
    if (!recipient.getActive())
        return;
    if (Validate::validate_password(newPassword))
        {
        recipient.set_password(newPassword);
        cout << "Client password updated successfully" << endl;
		}
		else
        {
        cout << "Invalid password" << endl;
		}

	}


int	Employee:: count_clients_till(Client c)
{
	return c.get_id() - 2399999;
}

void Employee:: view_client_balance(Client c)
{
    cout << c.get_id() << " 's Balance: " << c.get_balance() << endl;

}



void Employee::display()
{
    cout << " \t\t  */\t\tEmployee Information\t\t\\* " << endl << endl;
    Person::display();
    cout << "Salary: " << this->salary << endl;
}
