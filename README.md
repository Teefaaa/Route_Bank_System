# Route Bank System

Route Bank System is a **console-based banking management application** written in modern C++.  
It simulates a small bank with distinct roles (Client, Employee, Admin) and supports basic operations such as account management and simple transactions, all persisted to flat text files.

## Features

- **Role-based modules**
  - **Client**: view balance, deposit, withdraw, transfer, and review simple history (depending on configuration).
  - **Employee**: manage client accounts and data through guided console flows.
  - **Admin**: manage employees, high‑level data, and perform administrative actions.
- **Text-file persistence**
  - Uses files such as `Clients.txt`, `Employees.txt`, `Admins.txt`, and ID trackers like `Clients_Last_ID.txt` to simulate a lightweight database.
  - Startup loads data from disk, shutdown writes changes back.
- **Console UI**
  - Splash screen and exit screen for Egypt Global Bank (EGB).
  - Colored output (ANSI escape codes) and centered text for a more readable console experience.
- **Layered structure**
  - Core domain entities (`Client`, `Employee`, `Admin`, `Person`, `Transaction`, `Time`).
  - Service / manager layer (`ClientManager`, `EmployeeManager`, `AdminManager`) containing the user flows.
  - Infrastructure helpers (`FilesHelper`, `FileManager`, `Parser`, `Validate`, `DataSourceInterface`) for persistence, parsing, and validation.

## Project Structure (high level)

Key files in the project:

- `main.cpp` – program entry point; starts the app by calling `runapp()`.
- `Screens.cpp` / `Screens.h` – main menu, splash screen, module routing, and shared console helpers.
- `Client.cpp` / `Client.h`, `Employee.cpp` / `Employee.h`, `Admin.cpp` / `Admin.h`, `Person.*` – domain models for people and roles.
- `Transaction.cpp` / `Transaction.h`, `Time.*` – transaction and time utilities.
- `ClientManager.*`, `EmployeeManager.*`, `AdminManager.*` – role-specific workflows and menu handling.
- `FilesHelper.*`, `FileManager.*`, `Parser.*`, `Validate.*`, `DataSourceInterface.h` – file I/O, parsing, and validation logic.
- `*.txt` files – text “database” for clients, employees, admins, transactions, and auto-increment ID tracking.
- Visual Studio and Code::Blocks project files – e.g. `Route_Bank_System.vcxproj`, `Route Bank System.cbp`, and `Route_Bank_System.slnx`.

> Note: In the repository you may see duplicated source files under both the root folder and `Route_Bank_System/`. They are logically the same modules, structured to support different IDEs and project configurations.

## Getting Started

### Prerequisites

- A C++17-compatible compiler (e.g. MSVC, GCC, or Clang).
- On Windows, **Visual Studio** (recommended) or **Code::Blocks** if you prefer using the provided project files.
- A terminal that supports ANSI color codes (most modern terminals do; on Windows, use PowerShell or the integrated terminal in your IDE).

### Building with Visual Studio (recommended)

1. Open `Route_Bank_System.slnx` (or the corresponding `.sln` if you have one) in Visual Studio.
2. Select the desired configuration (e.g. `Release` or `Debug`).
3. Build the solution (`Build > Build Solution`).
4. Run the produced executable from Visual Studio or from the build output directory.

### Building from the command line (generic)

If you prefer a manual build using a command-line compiler, from the repository root you can compile all `.cpp` files with a command similar to:

```bash
g++ -std=c++17 -O2 -Wall -Wextra -pedantic *.cpp -o RouteBank
```

> Adjust the command to match your compiler, platform, and actual file layout (for example, you may need to compile files inside `Route_Bank_System/` or point to your chosen build directory).

## Running the Application

After building:

1. Make sure the data files (`Clients.txt`, `Employees.txt`, `Admins.txt`, and the corresponding `*_Last_ID.txt` files) exist in the same directory as the executable.  
   - If they do not exist, the application or its helpers will create them on first run or expect you to provide them depending on the current implementation.
2. Run the executable:

   ```bash
   ./RouteBank
   ```

3. On startup you will see:
   - A splash screen for **Egypt Global Bank (EGB)**.
   - The main menu with four options: **Client Module**, **Employee Module**, **Admin Module**, and **Exit**.
4. Choose the desired module and follow the on-screen instructions.

## Data and Persistence

The system relies on plain-text files to store data:

- **Clients:** `Clients.txt` plus `Clients_Last_ID.txt` for incremental IDs.
- **Employees:** `Employees.txt` plus `Employees_Last_ID.txt`.
- **Admins:** `Admins.txt` plus `Admins_Last_ID.txt`.
- **Transactions:** stored according to the logic in `Transaction.*` and related helpers.

The `FilesHelper` and `FileManager` components orchestrate reading/writing these files at application start and during operations, enabling a simple persistent store without an external database.

## Extending the System

When adding new functionality:

- **New operations** (e.g. a new type of transaction):
  - Update or extend the relevant domain class (such as `Transaction` or `Client`).
  - Add menu entries and flows inside the appropriate `*Manager` file.
  - Ensure the persistence layer (`FilesHelper`, `FileManager`, parsers) can read/write any new fields.
- **New roles or modules**:
  - Create new role classes and a new `XXXManager` module.
  - Wire it into the main menu in `Screens.cpp` (and corresponding headers).

Keep in mind that this is a console application; any new features should be implemented with clear, text-based menus and prompts for a consistent user experience.

## License

This repository does not yet declare a license.  
If you intend to publish or reuse this code, consider adding a `LICENSE` file (for example, MIT, Apache 2.0, or another license that suits your needs).

# Route Bank System

**Cycle 25 – Fundamentals of Programming**

---

## Team Members

| Name                    | Phone Number |
| ----------------------- | ------------ |
| Mostafa Aly Mostafa     | 1111107647   |
| Mahmoud Samir Mahmoud   | 1128969594   |
| Saeed Mohammed Saeed    | 1012814048   |
| Kareem Mahmoud Kamal    | 1091752344   |
| Amr Mohammed Elshabrawy | 1279823389   |

---

## Course Information

* **Course:** Fundamentals of Programming
* **Project:** Route Bank System
* **Cycle:** 25

---

## Notes
## Contributions (Mostafa Aly)

As part of the team and serving as the team leader, I contributed to:

- Implementing and developing core features across the **Client, Employee, and Admin modules**.
- Reviewing, optimizing, and refining all modules to improve efficiency and performance.
- Designing the system architecture and role-based structure for maintainability and scalability.
- Managing file handling (reading/writing client, employee, and admin data) and integrating it with the application logic.
- Debugging, testing, and enhancing overall application performance.
- Coordinating and collaborating with team members to ensure seamless integration of all modules into a cohesive system.

> This project was developed collaboratively as a team effort.
