#pragma once
#include "Person.h"
#include "Transaction.h"

class Admin;
class Employee;

class Client : public Person
{
private:
    static int client_counter;
    double balance;
    bool isActive;
    double loan;
    static double total_balances;
    static double total_loans;
    short risk_counter;

    double get_total_balances() const;
    double get_total_loans() const;
    short get_risk_counter() const;

    friend class Admin;

    static const int MAX_TRANSACTIONS = 100;
    Transaction transactions[MAX_TRANSACTIONS];
    int transactionCount;

    bool autoTransferDone;
    void turn_on();
    bool isTransferTimeAllowed();
    string getAccountStatus();

public:
    Client(string name, string password, double balance);

    void set_balance(double balance);
    double get_balance();

    void setActive(bool status);
    bool getActive();

    void deposit(double amount);
    void withdraw(double amount);
    void transfer_to(double amount, Client& recipient);
    void request_loan();
    void auto_transfer_at(int hour,int minute,int second,double amount, Client& recipient);

    bool verify_password(string oldPassword);
    void change_password(string oldPassword ,string newPassword);

    void check_balance();
    void check_account_status();
    void show_transaction_history();

    void display();
};
