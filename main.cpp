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

#include "Client.h"
#include "Employee.h"
#include "FilesHelper.h"
#include <iostream>

using namespace std;

int main() {
  // Step 1: Load existing clients from Clients.txt into allClients vector
  FilesHelper::getClients();

  cout << "========================================" << endl;
  cout << "   Clients loaded from file: " << allClients.size() << endl;
  cout << "========================================" << endl << endl;

  // Step 2: Display all clients before modifications
  cout << "--- BEFORE modifications ---" << endl;
  for (size_t i = 0; i < allClients.size(); i++) {
    cout << "ID: " << allClients[i].get_id()
         << " | Name: " << allClients[i].get_name()
         << " | Balance: " << allClients[i].get_balance()
         << " | Loan: " << allClients[i].get_loan() << endl;
  }
  cout << endl;

  // Step 3: Perform some operations (these will auto-save to Clients.txt)
  if (allClients.size() >= 1) {
    cout << ">> Depositing 5000 to " << allClients[0].get_name() << "..."
         << endl;
    allClients[0].deposit(5000);
    cout << "   New balance: " << allClients[0].get_balance() << endl << endl;
  }

  if (allClients.size() >= 2) {
    cout << ">> Withdrawing 1000 from " << allClients[1].get_name() << "..."
         << endl;
    allClients[1].withdraw(1000);
    cout << "   New balance: " << allClients[1].get_balance() << endl << endl;
  }

  if (allClients.size() >= 3) {
    cout << ">> Requesting loan for " << allClients[2].get_name() << "..."
         << endl;
    allClients[2].request_loan();
    cout << "   New balance: " << allClients[2].get_balance()
         << " | Loan: " << allClients[2].get_loan() << endl
         << endl;
  }

  // Step 4: Display all clients after modifications
  cout << "--- AFTER modifications ---" << endl;
  for (size_t i = 0; i < allClients.size(); i++) {
    cout << "ID: " << allClients[i].get_id()
         << " | Name: " << allClients[i].get_name()
         << " | Balance: " << allClients[i].get_balance()
         << " | Loan: " << allClients[i].get_loan() << endl;
  }

  cout << endl;
  cout << "========================================" << endl;
  cout << "   All changes saved to Clients.txt!" << endl;
  cout << "   Open the file to verify." << endl;
  cout << "========================================" << endl;

  return 0;
}