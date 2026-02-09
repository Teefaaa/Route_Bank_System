#include "Client.h"
#include <iostream>

using namespace std;

void Client::turn_on() { ; }

Client::Client(string name, string password, double balance)
    : Person(name, password)
{
    this->balance = balance;
    this->isActive = true;
    transactionCount = 0;
}

/* ================= ACCOUNT STATUS ================= */

string Client::getAccountStatus()
{
    if (balance < 5000)
        return "Low";
    else if (balance < 20000)
        return "Normal";
    else if (balance < 50000)
        return "High";
    else if (balance < 100000)
        return "Super";
    else
        return "VIP";
}

/* ================= TIME CHECK ================= */

bool Client::isTransferTimeAllowed()
{
    Time now;
    Time start(9, 0, 0);
    Time end(17, 0, 0);

    return now.seconds_from(start) >= 0 &&
        end.seconds_from(now) >= 0;
}

/* ================= BASIC SETTERS ================= */

void Client::set_balance(double balance)
{
    if (balance >= 1500)
        this->balance = balance;
    else
        cout << "Balance must be >= 1500" << endl;
}

double Client::get_balance()
{
    return balance;
}

void Client::setActive(bool status)
{
    isActive = status;
}

bool Client::getActive()
{
    return isActive;
}

/* ================= TRANSACTIONS ================= */

void Client::deposit(double amount)
{
    if (!isActive)
    {
        cout << "Account is deactivated" << endl;
        return;
    }

    balance += amount;

    if (transactionCount < MAX_TRANSACTIONS)
        transactions[transactionCount++] =
        Transaction("Deposit", amount);
}

void Client::withdraw(double amount)
{
    if (!isActive)
    {
        cout << "Account is deactivated" << endl;
        return;
    }

    if (balance >= amount)
    {
        balance -= amount;

        if (transactionCount < MAX_TRANSACTIONS)
            transactions[transactionCount++] =
            Transaction("Withdraw", amount);
    }
    else
        cout << "Insufficient balance" << endl;
}

void Client::transfer_to(double amount, Client& recipient)
{
    if (!isActive)
    {
        cout << "Account is deactivated" << endl;
        return;
    }

    if (!isTransferTimeAllowed())
    {
        cout << "Transfers allowed only between 09:00 and 17:00" << endl;
        return;
    }

    if (balance >= amount && recipient.getActive())
    {
        balance -= amount;
        recipient.deposit(amount);

        if (transactionCount < MAX_TRANSACTIONS)
            transactions[transactionCount++] =
            Transaction("Transfer", amount);

        cout << "Transfer successful" << endl;
    }
    else
        cout << "Transfer failed" << endl;
}

/* ================= DISPLAY ================= */

void Client::check_balance()
{
    cout << "Balance: " << balance << endl;
}

void Client::check_account_status()
{
    cout << "Account Status: " << getAccountStatus() << endl;
}

void Client::show_transaction_history()
{
    cout << "\n--- Transaction History ---" << endl;

    for (int i = 0; i < transactionCount; i++)
    {
        Time t = transactions[i].get_time();

        cout << transactions[i].get_type() << ": "
            << transactions[i].get_amount()
            << " at "
            << t.get_hours() << ":"
            << t.get_minutes() << ":"
            << t.get_seconds()
            << endl;
    }
}

void Client::display()
{
    if (!isActive)
    {
        cout << "Account is deactivated" << endl;
        return;
    }

    Person::display();
    cout << "Balance: " << balance << endl;
    cout << "Status: " << getAccountStatus() << endl;
}
