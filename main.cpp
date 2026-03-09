/*

#include <iostream>
#include "Admin.h"
#include <iomanip>
#include <fstream>
#include "FilesHelper.h"

using namespace std;

int main()
{

    Client c1("Mahmoud", "Pass@123", 3000);
    Client c2("Ahmed", "Hello@456", 2000);

    Employee e1("Sara", "Emp@789", 7000);
    Admin a1("Omar", "Admin@000", 10000);

    cout << "----- Client 1 -----" << endl;
    c1.display();
    cout << endl;

    cout << "----- Client 2 -----" << endl;
    c2.display();
    cout << endl;

    cout << "----- Employee -----" << endl;
    e1.display();
    cout << endl;

    cout << "----- Admin -----" << endl;
    a1.display();
    cout << endl;

    cout << "Transfer test:" << endl;
    c1.transfer_to(500, c2);

    cout << endl << "Balances after transfer:" << endl;
    c1.check_balance();
    c2.check_balance();

    cout << endl << "Deactivating client 2..." << endl;
    e1.deactivate_client(c2);

    cout << endl << "Trying to deposit to deactivated client:" << endl;
    c2.deposit(1000);
    Client c3("Mostafa", "CR7&juventus",3000);
    c3.deposit(5000);
    c3.display();
    c3.show_transaction_history();
/*
    cout << "Initial balances:\n";
    c1.check_balance();
    c2.check_balance();

    cout << "\nAuto transfer will run when time matches...\n";
    cout << "Allowed window: 12:00 -> 23:59:59\n\n";

    while (true)
    {
        c1.auto_transfer_at(
            18, 30, 0,
            500,
            c2
        );
    }
*/
/*
    Client c7("Mahmoud", "Pass@123", 5000);
    Client c8("Ahmed", "Hello@456", 2000);
    int hour, minute, second;

    cout << "Initial Balances:\n";
    c7.check_balance();
    c8.check_balance();
    cout << "Enter auto transfer time (HH MM SS): ";
    cin >> hour >> minute >> second;

    cout << "\nAuto transfer scheduled at "
    << setw(2) << setfill('0') << hour << ":"
    << setw(2) << setfill('0') << minute << ":"
    << setw(2) << setfill('0') << second << endl;

    cout << "Waiting...\n";
    while (true)
    {
        c7.auto_transfer_at(hour, minute, second, 1000, c8);

        if (c7.get_balance() < 5000)
            break;
    }

    c7.show_transaction_history();

    c3.request_loan();

    Client c9("Salah", "Hello@999", 8000);
    c9.deposit(1000000);
    c9.deposit(1000000);
    a1.risk_assessment(c9);
    c9.deposit(1000000);
    a1.risk_assessment(c9);

    a1.see_system_statistics_till(c3,e1);


    return 0;
}



*/

#include "Admin.h"
#include "Client.h"
#include "Employee.h"
#include "FilesHelper.h"
#include <iostream>

using namespace std;

int main() {
  // ============ STEP 1: Load all data from files ============
  FilesHelper::getClients();
  FilesHelper::getEmployees();
  FilesHelper::getAdmins();

  cout << "========================================" << endl;
  cout << "   Clients loaded:   " << allClients.size() << endl;
  cout << "   Employees loaded: " << allEmployees.size() << endl;
  cout << "   Admins loaded:    " << allAdmins.size() << endl;
  cout << "========================================" << endl << endl;

  // ============ STEP 2: CLIENT file editing demo ============
  cout << "--- CLIENT: Before ---" << endl;
  for (size_t i = 0; i < allClients.size(); i++) {
    cout << "  ID: " << allClients[i].get_id()
         << " | Name: " << allClients[i].get_name()
         << " | Balance: " << allClients[i].get_balance()
         << " | Loan: " << allClients[i].get_loan() << endl;
  }
  cout << endl;

  if (allClients.size() >= 1) {
    cout << ">> Depositing 5000 to " << allClients[0].get_name() << "..."
         << endl;
    allClients[0].deposit(5000); // saves to Clients.txt automatically
    cout << "   New balance: " << allClients[0].get_balance() << endl << endl;
  }

  if (allClients.size() >= 2) {
    cout << ">> Withdrawing 1000 from " << allClients[1].get_name() << "..."
         << endl;
    allClients[1].withdraw(1000); // saves to Clients.txt automatically
    cout << "   New balance: " << allClients[1].get_balance() << endl << endl;
  }

  cout << "--- CLIENT: After ---" << endl;
  for (size_t i = 0; i < allClients.size(); i++) {
    cout << "  ID: " << allClients[i].get_id()
         << " | Name: " << allClients[i].get_name()
         << " | Balance: " << allClients[i].get_balance() << endl;
  }
  cout << endl;
  cout << ">> Clients.txt updated!" << endl << endl;

  // ============ STEP 3: EMPLOYEE file editing demo ============
  cout << "--- EMPLOYEE: Before ---" << endl;
  for (size_t i = 0; i < allEmployees.size(); i++) {
    cout << "  ID: " << allEmployees[i].get_id()
         << " | Name: " << allEmployees[i].get_name()
         << " | Salary: " << allEmployees[i].get_salary() << endl;
  }
  cout << endl;

  // Create a new employee and add via Admin (if an admin exists)
  if (allAdmins.size() >= 1) {
    Employee newEmp("Youssef", "Emp@321", 8000);
    cout << ">> Admin '" << allAdmins[0].get_name()
         << "' adding new employee 'Youssef'..." << endl;
    allAdmins[0].addEmployee(newEmp); // saves to Employees.txt automatically
    cout << "   Employee added!" << endl << endl;

    // Increase salary of first employee
    if (allEmployees.size() >= 1) {
      cout << ">> Admin increasing salary of '" << allEmployees[0].get_name()
           << "' by 2000..." << endl;
      allAdmins[0].increase_salary(allEmployees[0],
                                   2000); // saves to Employees.txt
      cout << "   New salary: " << allEmployees[0].get_salary() << endl << endl;
    }
  }

  cout << "--- EMPLOYEE: After ---" << endl;
  for (size_t i = 0; i < allEmployees.size(); i++) {
    cout << "  ID: " << allEmployees[i].get_id()
         << " | Name: " << allEmployees[i].get_name()
         << " | Salary: " << allEmployees[i].get_salary() << endl;
  }
  cout << endl;
  cout << ">> Employees.txt updated!" << endl << endl;

  // ============ STEP 4: ADMIN file editing demo ============
  cout << "--- ADMIN: Before ---" << endl;
  for (size_t i = 0; i < allAdmins.size(); i++) {
    cout << "  ID: " << allAdmins[i].get_id()
         << " | Name: " << allAdmins[i].get_name()
         << " | Salary: " << allAdmins[i].get_salary() << endl;
  }
  cout << endl;

  // Create a new admin and save directly
  Admin newAdmin("Khaled", "Admin@555", 12000);
  allAdmins.push_back(newAdmin);
  FilesHelper::saveAllAdmins(); // saves to Admins.txt
  cout << ">> New admin 'Khaled' added and saved!" << endl << endl;

  cout << "--- ADMIN: After ---" << endl;
  for (size_t i = 0; i < allAdmins.size(); i++) {
    cout << "  ID: " << allAdmins[i].get_id()
         << " | Name: " << allAdmins[i].get_name()
         << " | Salary: " << allAdmins[i].get_salary() << endl;
  }
  cout << endl;
  cout << ">> Admins.txt updated!" << endl << endl;

  // ============ DONE ============
  cout << "========================================" << endl;
  cout << "   All changes saved to files!" << endl;
  cout << "   Open Clients.txt, Employees.txt," << endl;
  cout << "   and Admins.txt to verify." << endl;
  cout << "========================================" << endl;

  return 0;
}