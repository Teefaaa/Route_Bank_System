#include <iostream>
#include "Client.h"
#include "Employee.h"
#include "Admin.h"

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

    return 0;
}
