#include "Client.h"
#include <iostream>

void Client::turn_on() { ; }

Client::Client(string name, string password, double balance)
    : Person(name, password)
{
    this->balance = balance;
    this->isActive = true;
}

void Client::set_balance(double balance)
{
    if (balance >= 1500)
    {
        this->balance = balance;
    }
    else
    {
        cout << "Sorry! it should be greater than or equal 1500" << endl;
    }
}

double Client::get_balance()
{
    return this->balance;
}

void Client::setActive(bool status)
{
    isActive = status;
}

bool Client::getActive() const
{
    return isActive;
}

void Client::deposit(double amount)
{
    if (!isActive)
    {
        cout << "Account is deactivated!" << endl;
        return;
    }
    balance += amount;
}

void Client::withdraw(double amount)
{
    if (!isActive)
    {
        cout << "Account is deactivated!" << endl;
        return;
    }
    if (balance >= amount)
    {
        balance -= amount;
    }
    else
    {
        cout << "Sorry! your balance is lower than this amount" << endl;
    }
}

void Client::transfer_to(double amount, Client& recipient)
{
    if (!isActive)
    {
        cout << "Account is deactivated!" << endl;
        return;
    }
    if (balance >= amount)
    {
        if (!recipient.getActive())
        {
            cout << "Recipient account is deactivated!" << endl;
            return;
        }
        this->withdraw(amount);
        recipient.deposit(amount);
        cout << "Successfully! " + to_string(amount) +
            " transferred to " + recipient.get_name() << endl;
    }
    else
    {
        cout << "Sorry! failed transfer, your balance is lower than this amount" << endl;
    }
}

void Client::check_balance() const
{
    if (!isActive)
    {
        cout << "Account is deactivated!" << endl;
        return;
    }
    cout << "Your balance:" << balance << endl;
}

void Client::display()
{
    if (!isActive)
    {
        cout << "Account is deactivated!" << endl;
        return;
    }
    cout << " \t\t  */\t\tClient Information\t\t\\* " << endl << endl;
    Person::display();
    cout << "Balance: " << this->balance << endl;
}
