#pragma once
#include "Person.h"
class Client :
    public Person
{
private:
    double balance;
    bool isActive;
    void turn_on();

public:
    Client(string name, string password, double balance);

    void set_balance(double balance);
    double get_balance();

    void setActive(bool status);
    bool getActive() const;

    void deposit(double amount);
    void withdraw(double amount);
    void transfer_to(double amount, Client& recipient);
    void check_balance() const;

    void display();
};

