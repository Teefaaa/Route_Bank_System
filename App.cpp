#include "Admin.h"
#include "Client.h"
#include "Employee.h"
#include "FilesHelper.h"
#include <chrono>
#include <iomanip>
#include <iostream>
#include <string>
#include <thread>
#include <windows.h>

using namespace std;

void printCentered(string text, int width) {
  int padding = (width - text.length()) / 2;
  if (padding > 0)
    cout << string(padding, ' ');
  cout << text << endl;
}

// Clear screen
void clearScreen() { system("cls"); }

// Set console color (gold-ish = bright yellow)
void setGoldColor() {
  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN |
                                        FOREGROUND_INTENSITY);
}

void setRedColor() {
  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
}

void setGreenColor() {
  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
}

void setBlueColor() {
  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
}

// Reset to default color
void resetColor() {
  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(hConsole,
                          FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

int search_client(int id) {
  for (int i = 0; i < allClients.size(); i++) {
    if (allClients[i].get_id() == id) {
      return i;
    }
  }
  return -1;
}

int search_employee(int id) {
  for (int i = 0; i < allEmployees.size(); i++) {
    if (allEmployees[i].get_id() == id) {
      return i;
    }
  }
  return -1;
}

int search_admin(int id) {
  for (int i = 0; i < allEmployees.size(); i++) {
    if (allAdmins[i].get_id() == id) {
      return i;
    }
  }
  return -1;
}

void runapp() {

  FilesHelper::getClients();
  FilesHelper::getEmployees();
  FilesHelper::getAdmins();
  const int consoleWidth = 100;

  clearScreen();
  setGoldColor();

  cout << string(4, '\n');

  printCentered("===============================================",
                consoleWidth);

  printCentered("", consoleWidth);

  // Big EGB with stars
  printCentered("@@@@@@   @@@@@@    @@@@@@@@", consoleWidth);
  printCentered("@@       @         @@    @@", consoleWidth);
  printCentered("@@@@@@   @  @@@@   @@@@@@@@ ", consoleWidth);
  printCentered("@@       @     @   @@    @@", consoleWidth);
  printCentered("@@@@@@   @@@@@@@   @@@@@@@@", consoleWidth);

  cout << endl;

  printCentered("EGYPT GLOBAL BANK", consoleWidth);
  cout << endl;

  printCentered("Empowering Your Future, Globally.", consoleWidth);

  printCentered("===============================================",
                consoleWidth);

  cout << string(3, '\n');

  this_thread::sleep_for(chrono::seconds(2));

  printCentered("System Loading...", consoleWidth);

  this_thread::sleep_for(chrono::seconds(3));

  cout << endl;
  clearScreen();

  short module;
  short log_or_sign;
  int client_choice;
  int index_of_client;
  int index_of_employee;
  int employee_choice;
  int c_id;
  int e_id;
  int a_id;
  string cli_password;
  string e_password;
  string a_password;
  int index_of_admin;
  int admin_choice;

  do {
    printCentered("WELCOME TO EGB BANK", consoleWidth);
    printCentered("=================================", consoleWidth);
    printCentered("APP MODULES", consoleWidth);
    printCentered("===============", consoleWidth);
    cout << endl;
    cout << "(1) Client Module" << endl;
    cout << "(2) Employee Module" << endl;
    cout << "(3) Admin Module" << endl;
    cout << "(4) Exit" << endl << endl;
    cout << "ENTER YOUR DESIRED MODULE: ";
    cin >> module;
    cout << endl;
    switch (module) {
    case 1: {
      int id;
      string name;
      string c_password;
      string n_password;
      double balance;
      double amount;
      int hour;
      int minute;
      int second;
      int loan_terms;
      clearScreen();
      do {
        cout << "(1) Log In" << endl;
        cout << " * Already you have an account" << endl;
        cout << "(2) Sign Up" << endl;
        cout << "** Don't have an account, Create new account" << endl;
        cout << "(3) Exit" << endl;
        cout << "ENTER YOUR WISH: ";
        cin >> client_choice;
        cout << endl;
        switch (client_choice) {
        case 1: {
          do {
            clearScreen();
            printCentered("LOG IN AS CLIENT", consoleWidth);
            printCentered("=================================", consoleWidth);
            cout << endl;
            cout << "ENTER YOUR ID: ";
            cin >> c_id;
            cout << endl;
            cout << "ENTER YOUR PASSWORD: ";
            cin >> cli_password;
            cout << endl;
            if (search_client(c_id) == -1) {
              setRedColor();
              cout << "INVALID ID OR PASSWORD ... PLEASE TRY AGAIN :)" << endl;
              setGoldColor();
              this_thread::sleep_for(chrono::seconds(2));
              clearScreen();
            } else {
              index_of_client = search_client(c_id);
              if (allClients[index_of_client].get_password() != cli_password) {
                setRedColor();
                cout << "INVALID ID OR PASSWORD ... PLEASE TRY AGAIN :)"
                     << endl;
                setGoldColor();
                this_thread::sleep_for(chrono::seconds(2));
                clearScreen();
              } else {
                do {
                  clearScreen();
                  printCentered("/*  Client Options  *\\ ", consoleWidth);
                  printCentered("=================================",
                                consoleWidth);
                  cout << "(1)  Deposit" << endl;
                  cout << "(2)  Withdraw" << endl;
                  cout << "(3)  Instant Transfer" << endl;
                  cout << "(4)  Scheduled Transfer" << endl;
                  cout << "(5)  Request Loan" << endl;
                  cout << "(6)  Change Password" << endl;
                  cout << "(7)  Check Balance" << endl;
                  cout << "(8)  Check Progress" << endl;
                  cout << "(9) Transactions History" << endl;
                  cout << "(10) Check Loan" << endl;
                  cout << "(11) View Profile" << endl;
                  cout << "(12) Return to Home Screen" << endl << endl;
                  cout << " ENTER YOUR WISH: ";
                  cin >> client_choice;
                  cout << endl;
                  switch (client_choice) {
                  case 1: {
                    clearScreen();
                    cout << "Enter the amount you want to deposit: ";
                    cin >> amount;
                    allClients[index_of_client].deposit(amount);
                    setGreenColor();
                    cout << "Successfully! " << amount
                         << " is added to your balance" << endl
                         << endl;
                    setGoldColor();
                    cout << "\nPress Enter to return to menu...";
                    cin.ignore();
                    cin.get();
                    break;
                  }
                  case 2: {
                    clearScreen();
                    cout << "Enter the amount you want to withdraw: ";
                    cin >> amount;
                    allClients[index_of_client].withdraw(amount);
                    setGreenColor();
                    cout << "Successfully! " << amount
                         << " is withdrawn from your balance" << endl
                         << endl;
                    setGoldColor();
                    cout << "\nPress Enter to return to menu...";
                    cin.ignore();
                    cin.get();
                    break;
                  }
                  case 3: {
                    clearScreen();
                    cout << "Enter the ID of the desired client: ";
                    cin >> id;
                    if (search_client(id) == -1) {
                      setRedColor();
                      cout << "INVALID ID ... PLEASE TRY AGAIN :)" << endl;
                      setGoldColor();
                      this_thread::sleep_for(chrono::seconds(2));
                      clearScreen();
                    } else {
                      cout << "Enter the amount you want to transfer: ";
                      cin >> amount;
                      allClients[index_of_client].transfer_to(
                          amount, allClients[search_client(id)]);
                      cout << "\nPress Enter to return to menu...";
                      cin.ignore();
                      cin.get();
                    }
                    break;
                  }
                  case 4: {
                    clearScreen();
                    cout << "Enter the ID of the desired client: ";
                    cin >> id;
                    if (search_client(id) == -1) {
                      setRedColor();
                      cout << "INVALID ID ... PLEASE TRY AGAIN :)" << endl;
                      setGoldColor();
                      this_thread::sleep_for(chrono::seconds(2));
                      clearScreen();
                    } else {
                      cout << "Enter the amount you want to transfer: ";
                      cin >> amount;
                      cout << endl << "Enter the desired hour: ";
                      cin >> hour;
                      cout << endl << "Enter the desired minute: ";
                      cin >> minute;
                      cout << endl << "Enter the desired second: ";
                      cin >> second;
                      cout << "\nAuto transfer scheduled at " << setw(2)
                           << setfill('0') << hour << ":" << setw(2)
                           << setfill('0') << minute << ":" << setw(2)
                           << setfill('0') << second << endl;

                      double c_balance =
                          allClients[index_of_client].get_balance();

                      cout << "Waiting...\n";
                      while (true) {
                        allClients[index_of_client].auto_transfer_at(
                            hour, minute, second, amount,
                            allClients[search_client(id)]);

                        if (allClients[index_of_client].get_balance() <
                            c_balance)
                          break;
                      }

                      cout << "\nPress Enter to return to menu...";
                      cin.ignore();
                      cin.get();
                    }
                    break;
                  }
                  case 5: {
                    clearScreen();
                    cout << "1- You will earn 10000 LE and they will be added "
                            "to your balance"
                         << endl;
                    cout << "2- You will have a 1 year duration to pay this "
                            "amount"
                         << endl;
                    cout << "3- It's forbidden to do anything that leads to "
                            "deactivate your account"
                         << endl;
                    cout << "(1) agree  \t\t (2) disagree" << endl;
                    cout << "ENTER YOUR CHOICE: ";
                    cin >> loan_terms;
                    if (loan_terms >= 2) {
                      setRedColor();
                      cout << "Sorry! The loan is not accepted :)" << endl;
                      setGoldColor();
                      this_thread::sleep_for(chrono::seconds(2));
                      clearScreen();
                    } else {
                      allClients[index_of_client].request_loan();
                      cout << "\nPress Enter to return to menu...";
                      cin.ignore();
                      cin.get();
                    }
                    break;
                  }
                  case 6: {
                    clearScreen();
                    cout << "Enter Your Old Password: ";
                    cin >> c_password;
                    if (!allClients[index_of_client].verify_password(
                            c_password)) {
                      setRedColor();
                      cout << "Sorry! This one is incorrect :)" << endl;
                      setGoldColor();
                      this_thread::sleep_for(chrono::seconds(2));
                      clearScreen();
                    } else {
                      cout << "Enter the new desired password: ";
                      cin >> n_password;
                      allClients[index_of_client].change_password(c_password,
                                                                  n_password);
                      cout << "\nPress Enter to return to menu...";
                      cin.ignore();
                      cin.get();
                    }
                    break;
                  }
                  case 7: {
                    clearScreen();
                    allClients[index_of_client].check_balance();
                    cout << "\nPress Enter to return to menu...";
                    cin.ignore();
                    cin.get();
                    break;
                  }
                  case 8: {
                    clearScreen();
                    allClients[index_of_client].check_account_progress();
                    cout << "\nPress Enter to return to menu...";
                    cin.ignore();
                    cin.get();
                    break;
                  }
                  case 9: {
                    clearScreen();
                    allClients[index_of_client].show_transaction_history();
                    cout << "\nPress Enter to return to menu...";
                    cin.ignore();
                    cin.get();
                    break;
                  }
                  case 10: {
                    clearScreen();
                    cout << "Loans taken: "
                         << allClients[index_of_client].get_loan() << endl;
                    cout << "\nPress Enter to return to menu...";
                    cin.ignore();
                    cin.get();
                    break;
                  }
                  case 11: {
                    clearScreen();
                    allClients[index_of_client].display();
                    cout << "\nPress Enter to return to menu...";
                    cin.ignore();
                    cin.get();
                    break;
                  }
                  case 12: {
                    clearScreen();
                    cout << "\nPress Enter to return to menu...";
                    cin.ignore();
                    cin.get();
                    clearScreen();
                    break;
                  }
                  default: {
                    setRedColor();
                    cout << "INVALID CHOICE , PLEASE TRY AGAIN :)" << endl
                         << endl;
                    setGoldColor();
                    this_thread::sleep_for(chrono::seconds(2));
                    clearScreen();
                  }
                  }
                } while (client_choice != 12);
              }
            }

          } while (
              search_client(c_id) == -1 ||
              (allClients[index_of_client].get_password() != cli_password));

          break;
        }
        case 2: {
          do {
            clearScreen();
            printCentered("SIGN UP AS CLIENT", consoleWidth);
            printCentered("=================================", consoleWidth);
            cout << endl;
            cout << "ENTER YOUR NAME: ";
            cin >> name;
            if (!Validate::validate_name(name)) {
              setRedColor();
              cout << endl
                   << "Invalid name, it should be only 5 to 20 alphabetic "
                      "characters only :)"
                   << endl;
              setGoldColor();
              this_thread::sleep_for(chrono::seconds(2));
              clearScreen();
            } else {
              cout << endl << "ENTER YOUR PASSWORD: ";
              cin >> c_password;
              if (!Validate::validate_password(c_password)) {
                setRedColor();
                cout << "Invalid password, it should be from 8 to 20 "
                        "characters..."
                     << endl;
                setGoldColor();
                this_thread::sleep_for(chrono::seconds(2));
                clearScreen();
              } else {
                Client new_commer(name, c_password);
                allClients.push_back(new_commer);
                FilesHelper::saveClient(new_commer);
                setGreenColor();
                cout << "Successfully You have an account <3" << endl;
                cout << "Close and Open the App again to Log in :)" << endl
                     << endl;
                setRedColor();
                cout << "/*\t VERY IMPORTANT\t*\\" << endl;
                setGreenColor();
                cout << "To Activate your account, You should call the "
                        "customer service"
                     << endl;
                cout << "To Ensure, your balance must be greater than or equal "
                        "1500"
                     << endl;
                setGoldColor();
                cout << "\nPress Enter to return to menu...";
                cin.ignore();
                cin.get();
              }
            }
          } while (!(Validate::validate_name(name) &&
                     Validate::validate_password(c_password)));
          break;
        }
        case 3: {
          clearScreen();
          break;
        }
        default: {
          setRedColor();
          cout << "INVALID CHOICE , PLEASE TRY AGAIN :)" << endl << endl;
          setGoldColor();
          this_thread::sleep_for(chrono::seconds(2));
          clearScreen();
        }
        }
      } while (client_choice > 3);

      break;
    }
    case 2: {
      int id;
      string name;
      string c_password;
      string n_password;
      double salary;
      double amount;
      clearScreen();
      do {
        clearScreen();
        printCentered("LOG IN AS EMPLOYEE", consoleWidth);
        printCentered("=================================", consoleWidth);
        cout << endl;
        cout << "ENTER YOUR ID: ";
        cin >> e_id;
        cout << endl;
        cout << "ENTER YOUR PASSWORD: ";
        cin >> e_password;
        cout << endl;
        if (search_employee(e_id) == -1) {
          setRedColor();
          cout << "INVALID ID OR PASSWORD ... PLEASE TRY AGAIN :)" << endl;
          setGoldColor();
          this_thread::sleep_for(chrono::seconds(2));
          clearScreen();
        } else {
          index_of_employee = search_employee(e_id);
          if (allEmployees[index_of_employee].get_password() != e_password) {
            setRedColor();
            cout << "INVALID ID OR PASSWORD ... PLEASE TRY AGAIN :)" << endl;
            setGoldColor();
            this_thread::sleep_for(chrono::seconds(2));
            clearScreen();
          } else {
            do {
              clearScreen();
              printCentered("/*  Employee Options  *\\ ", consoleWidth);
              printCentered("=================================", consoleWidth);
              cout << "(1)  Check Salary" << endl;
              cout << "(2)  Activate Client" << endl;
              cout << "(3)  Deactivate Client" << endl;
              cout << "(4)  Change Password" << endl;
              cout << "(5)  Change Client's Password" << endl;
              cout << "(6)  Count Clients" << endl;
              cout << "(7)  Check Client's Balance" << endl;
              cout << "(8)  Add Client" << endl;
              cout << "(9)  Search Client" << endl;
              cout << "(10) List all Clients" << endl;
              cout << "(11) View Profile" << endl;
              cout << "(12) Return to Home Screen" << endl << endl;
              cout << " ENTER YOUR WISH: ";
              cin >> employee_choice;
              cout << endl;
              switch (employee_choice) {
              case 1: {
                clearScreen();
                cout << "Your Salary is: "
                     << allEmployees[index_of_employee].get_salary() << endl;
                cout << "\nPress Enter to return to menu...";
                cin.ignore();
                cin.get();
                break;
              }
              case 2: {
                clearScreen();
                cout << "Enter the ID of the desired client: ";
                cin >> id;
                allEmployees[index_of_employee].activate_client(
                    allClients[search_client(id)]);
                cout << "\nPress Enter to return to menu...";
                cin.ignore();
                cin.get();
                break;
              }
              case 3: {
                clearScreen();
                cout << "Enter the ID of the desired client: ";
                cin >> id;
                allEmployees[index_of_employee].deactivate_client(
                    allClients[search_client(id)]);
                cout << "\nPress Enter to return to menu...";
                cin.ignore();
                cin.get();
                break;
              }
              case 4: {
                clearScreen();
                cout << "Enter the new desired password: ";
                cin >> n_password;
                allEmployees[index_of_employee].set_password(n_password);
                if (Validate::validate_password(n_password)) {
                  setGreenColor();
                  cout << "Successfully! Your Password Updated :)" << endl;
                  setGoldColor();
                }
                cout << "\nPress Enter to return to menu...";
                cin.ignore();
                cin.get();
                break;
              }
              case 5: {
                clearScreen();
                cout << "Enter the ID of the desired client: ";
                cin >> id;
                cout << endl << "Enter his desired password: ";
                cin >> n_password;
                allEmployees[index_of_employee].update_client_password(
                    allClients[search_client(id)], n_password);
                cout << "\nPress Enter to return to menu...";
                cin.ignore();
                cin.get();
                break;
              }
              case 6: {
                clearScreen();
                cout << "Enter the ID of the desired client: ";
                cin >> id;
                allEmployees[index_of_employee].count_clients_till(
                    allEmployees[index_of_employee].searchClient(id));
                cout << "\nPress Enter to return to menu...";
                cin.ignore();
                cin.get();
                break;
              }
              case 7: {
                clearScreen();
                cout << "Enter the ID of the desired client: ";
                cin >> id;
                allEmployees[index_of_employee].view_client_balance(
                    allEmployees[index_of_employee].searchClient(id));
                cout << "\nPress Enter to return to menu...";
                cin.ignore();
                cin.get();
                break;
              }
              case 8: {
                clearScreen();
                cout << "Enter the name of the desired client: ";
                cin >> name;
                if (Validate::validate_name(name)) {
                  cout << "Enter his password: ";
                  cin >> n_password;
                  if (Validate::validate_password(n_password)) {
                    cout << "Enter his balance: ";
                    cin >> amount;
                    if (amount >= 1500) {
                      Client c(name, n_password, amount);
                      allEmployees[index_of_employee].addClient(c);
                    } else {
                      setRedColor();
                      cout << endl << "Balance must be >= 1500 :)" << endl;
                      setGoldColor();
                      this_thread::sleep_for(chrono::seconds(2));
                      clearScreen();
                    }
                  } else {
                    setRedColor();
                    cout << endl
                         << "Invalid password, it should be from 8 to 20 "
                            "characters..."
                         << endl;
                    setGoldColor();
                    this_thread::sleep_for(chrono::seconds(2));
                    clearScreen();
                  }
                } else {
                  setRedColor();
                  cout << endl
                       << "Invalid name, it should be only 5 to 20 alphabetic "
                          "characters only :)"
                       << endl;
                  setGoldColor();
                  this_thread::sleep_for(chrono::seconds(2));
                  clearScreen();
                }
                cout << "\nPress Enter to return to menu...";
                cin.ignore();
                cin.get();
                break;
              }
              case 9: {
                clearScreen();
                cout << "Enter the ID of the desired client: ";
                cin >> id;
                Client *c = allEmployees[index_of_employee].searchClient(id);
                setGreenColor();
                cout << "Here is his profile: " << endl;
                setGoldColor();
                c->display();
                cout << "\nPress Enter to return to menu...";
                cin.ignore();
                cin.get();
                break;
              }
              case 10: {
                clearScreen();
                allEmployees[index_of_employee].listClient();
                cout << "\nPress Enter to return to menu...";
                cin.ignore();
                cin.get();
                break;
              }
              case 11: {
                clearScreen();
                allEmployees[index_of_employee].display();
                cout << "\nPress Enter to return to menu...";
                cin.ignore();
                cin.get();
                break;
              }
              case 12: {
                clearScreen();
                cout << "\nPress Enter to return to menu...";
                cin.ignore();
                cin.get();
                clearScreen();
                break;
              }
              default: {
                setRedColor();
                cout << "INVALID CHOICE , PLEASE TRY AGAIN :)" << endl << endl;
                setGoldColor();
                this_thread::sleep_for(chrono::seconds(2));
                clearScreen();
                break;
              }
              }
            } while (employee_choice != 12);
          }
        }

      } while (search_employee(e_id) == -1 ||
               (allEmployees[index_of_employee].get_password() != e_password));
      break;
    }
    case 3: {
      int id;
      string name;
      string c_password;
      string n_password;
      double salary;
      double amount;
      clearScreen();
      do {
        clearScreen();
        printCentered("LOG IN AS ADMIN", consoleWidth);
        printCentered("=================================", consoleWidth);
        cout << endl;
        cout << "ENTER YOUR ID: ";
        cin >> a_id;
        cout << endl;
        cout << "ENTER YOUR PASSWORD: ";
        cin >> a_password;
        cout << endl;
        if (search_admin(a_id) == -1) {
          setRedColor();
          cout << "INVALID ID OR PASSWORD ... PLEASE TRY AGAIN :)" << endl;
          setGoldColor();
          this_thread::sleep_for(chrono::seconds(2));
          clearScreen();
        } else {
          index_of_admin = search_admin(a_id);
          if (allAdmins[index_of_employee].get_password() != a_password) {
            setRedColor();
            cout << "INVALID ID OR PASSWORD ... PLEASE TRY AGAIN :)" << endl;
            setGoldColor();
            this_thread::sleep_for(chrono::seconds(2));
            clearScreen();
          } else {
            do {
              clearScreen();
              printCentered("/*  Admin Options  *\\ ", consoleWidth);
              printCentered("=================================", consoleWidth);
              cout << "(1)  See System Statistics" << endl;
              cout << "(2)  Risk Assessment" << endl;
              cout << "(3)  Increase Employee's Salary" << endl;
              cout << "(4)  Change Password" << endl;
              cout << "(5)  Decrease Employee's Salary" << endl;
              cout << "(6)  Add Employee" << endl;
              cout << "(7)  Search Employees" << endl;
              cout << "(8)  List all Employees" << endl;
              cout << "(9)  View Profile" << endl;
              cout << "(10) Return to Home Screen" << endl << endl;
              cout << " ENTER YOUR WISH: ";
              cin >> admin_choice;
              cout << endl;
              switch (admin_choice) {
              case 1: {
                clearScreen();
                cout << "till which client ... Enter his ID: ";
                cin >> id;
                if (search_client(id) != -1) {
                  int temp = id;
                  cout << endl << "till which employee ... Enter his ID: ";
                  cin >> id;
                  if (search_employee(id) != -1) {
                    allAdmins[index_of_admin].see_system_statistics_till(
                        allAdmins[index_of_admin].searchClient(temp),
                        allAdmins[index_of_admin].searchEmployee(id));
                  } else {
                    setRedColor();
                    cout << endl << "ERROR! Invalid Employee's ID" << endl;
                    setGoldColor();
                    this_thread::sleep_for(chrono::seconds(2));
                    clearScreen();
                  }
                } else {
                  setRedColor();
                  cout << endl << "ERROR! Invalid Client's ID" << endl;
                  setGoldColor();
                  this_thread::sleep_for(chrono::seconds(2));
                  clearScreen();
                }
                cout << "\nPress Enter to return to menu...";
                cin.ignore();
                cin.get();
                break;
              }
              case 2: {
                clearScreen();
                cout << "Enter the ID of the desired client: ";
                cin >> id;
                allAdmins[index_of_admin].risk_assessment(
                    allClients[search_client(id)]);
                cout << "\nPress Enter to return to menu...";
                cin.ignore();
                cin.get();
                break;
              }
              case 3: {
                clearScreen();
                cout << "Enter the ID of the desired employee: ";
                cin >> id;
                cout << endl << "Enter the desired amount: ";
                cin >> amount;
                allAdmins[index_of_admin].increase_salary(
                    allEmployees[search_employee(id)], amount);
                setGreenColor();
                cout << "Successfully Increased :)" << endl;
                setGoldColor();
                cout << "\nPress Enter to return to menu...";
                cin.ignore();
                cin.get();
                break;
              }
              case 4: {
                clearScreen();
                cout << "Enter the new desired password: ";
                cin >> n_password;
                allAdmins[index_of_admin].set_password(n_password);
                if (Validate::validate_password(n_password)) {
                  setGreenColor();
                  cout << "Successfully! Your Password Updated :)" << endl;
                  setGoldColor();
                }
                cout << "\nPress Enter to return to menu...";
                cin.ignore();
                cin.get();
                break;
              }
              case 5: {
                clearScreen();
                cout << "Enter the ID of the desired employee: ";
                cin >> id;
                cout << endl << "Enter the desired amount: ";
                cin >> amount;
                allAdmins[index_of_admin].decrease_salary(
                    allEmployees[search_employee(id)], amount);
                setGreenColor();
                cout << "Successfully Decreased :)" << endl;
                setGoldColor();
                cout << "\nPress Enter to return to menu...";
                cin.ignore();
                cin.get();
                break;
              }
              case 6: {
                clearScreen();
                cout << "Enter the name of the desired employee: ";
                cin >> name;
                if (Validate::validate_name(name)) {
                  cout << "Enter his password: ";
                  cin >> n_password;
                  if (Validate::validate_password(n_password)) {
                    cout << "Enter his salary: ";
                    cin >> amount;
                    if (amount >= 5000) {
                      Employee e(name, n_password, amount);
                      allAdmins[index_of_admin].addEmployee(e);
                    } else {
                      setRedColor();
                      cout << endl << "Salary must be >= 5000 :)" << endl;
                      setGoldColor();
                      this_thread::sleep_for(chrono::seconds(2));
                      clearScreen();
                    }
                  } else {
                    setRedColor();
                    cout << endl
                         << "Invalid password, it should be from 8 to 20 "
                            "characters..."
                         << endl;
                    setGoldColor();
                    this_thread::sleep_for(chrono::seconds(2));
                    clearScreen();
                  }
                } else {
                  setRedColor();
                  cout << endl
                       << "Invalid name, it should be only 5 to 20 alphabetic "
                          "characters only :)"
                       << endl;
                  setGoldColor();
                  this_thread::sleep_for(chrono::seconds(2));
                  clearScreen();
                }
                cout << "\nPress Enter to return to menu...";
                cin.ignore();
                cin.get();
                break;
              }
              case 7: {
                clearScreen();
                cout << "Enter the ID of the desired employee: ";
                cin >> id;
                Employee *e = allAdmins[index_of_admin].searchEmployee(id);
                setGreenColor();
                cout << "Here is his profile: " << endl;
                setGoldColor();
                e->display();
                cout << "\nPress Enter to return to menu...";
                cin.ignore();
                cin.get();
                break;
              }
              case 8: {
                clearScreen();
                allAdmins[index_of_admin].listEmployee();
                cout << "\nPress Enter to return to menu...";
                cin.ignore();
                cin.get();
                break;
              }
              case 9: {
                clearScreen();
                allAdmins[index_of_admin].display();
                cout << "\nPress Enter to return to menu...";
                cin.ignore();
                cin.get();
                break;
              }
              case 10: {
                clearScreen();
                cout << "\nPress Enter to return to menu...";
                cin.ignore();
                cin.get();
                clearScreen();
                break;
              }
              default: {
                setRedColor();
                cout << "INVALID CHOICE , PLEASE TRY AGAIN :)" << endl << endl;
                setGoldColor();
                this_thread::sleep_for(chrono::seconds(2));
                clearScreen();
                break;
              }
              }
            } while (admin_choice != 10);
          }
        }

      } while (search_admin(a_id) == -1 ||
               (allAdmins[index_of_admin].get_password() != a_password));
      break;
    }
    case 4: {
      clearScreen();
      printCentered("===============================================",
                    consoleWidth);
      cout << endl << endl;
      printCentered("@@@@@    @@@@@   @@@@@@     @   @    @@@@@    @    @     "
                    "@@@@@@   @@@@@   @@@@@   @    @",
                    consoleWidth);
      printCentered("@@       @       @          @   @    @   @    @    @     "
                    "@@       @   @   @   @   @    @",
                    consoleWidth);
      printCentered(" @@@@    @@@@@   @@@@         @      @   @    @    @      "
                    " @@@@   @   @   @   @   @@   @",
                    consoleWidth);
      printCentered("   @@    @       @            @      @   @    @    @      "
                    "   @@   @   @   @   @   @  @ @",
                    consoleWidth);
      printCentered("@@@@@    @@@@@   @@@@@@       @      @@@@@    @@@@@@      "
                    "@@@@@   @@@@@   @@@@@   @   @@",
                    consoleWidth);
      cout << endl << endl;
      printCentered("===============================================",
                    consoleWidth);

      this_thread::sleep_for(chrono::seconds(2));

      printCentered("Thanks For Your Time", consoleWidth);
      break;
    }
    default: {
      setRedColor();
      cout << "INVALID CHOICE , PLEASE TRY AGAIN :)" << endl << endl;
      setGoldColor();
      clearScreen();
    }
    }
  } while (module != 4);
}
