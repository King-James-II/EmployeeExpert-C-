/* This program showcases OOP (classes, inheritance, polymorphism), input validation, control flow 
 (conditional statements, loops), encapsulation, and modularization through function 
 organization, enabling clarity and reusability. */
// Declare header files
#include <iostream>
#include <string>
#include <vector>
#include <cctype>
using namespace std;

// Employee base class
class Employee {
    // Class variables and functions
    protected:
        string name;
        int employeeID;
        string type = "Employee";

    public:
        Employee(string name, int id) :name(name), employeeID(id) {}

        void viewProfile() {
            cout << "\nName: " << name << endl << "Employee ID: " << employeeID << "\nRole: " << type << endl;
        }
        void showMenu (Employee emp) {
            string user_in;

            //Infinite loop to display overriden employee menu for HR employees.
            do {
                cout << "\n" << type << " Menu\n-------------\n" << "1. Show My Profile" << endl;
                cout << "2. Return to previous menu." << endl;
                cin >> user_in;
                // Use input to call the appropriate class function.
                if (user_in == "1") {
                    emp.viewProfile();
                    break;
                }
                if (user_in == "2") {
                    break;
                }
            }while (true);      
        }
};

// Manager class using inheritance from Employee parent class.
class Manager : public Employee {
    public:
        Manager(string name, int id) : Employee(name, id) {
            type = "Manager";
        }
        // Overriden class function
        void viewProfile() {
            cout << "\nDisplaying Employees: " << endl;
            cout << "Name: " << name << endl << "Employee ID: " << employeeID << "\nRole: " << type << endl;
        }
        void searchEmployees() {
            cout << "\nSearch for an employee: " << endl;
        }
        // Overriden class function
        void showMenu (Manager mng) {
            string user_in;
            //Infinite loop to display overriden employee menu for HR employees.
            do {
                cout << "\n" << type << " Menu\n-------------\n" << "1. View all Employees" << endl;
                cout << "2. Search Employees" << endl << "3. Return to previous menu." << endl;
                cin >> user_in;

                // Use input to call the appropriate parent or child class function.
                if (user_in == "1") {
                    mng.viewProfile();
                    break;
                }
                if (user_in == "2") {
                    mng.searchEmployees();
                    break;
                }
                if (user_in == "3") {
                    break;
                }
            } while (true);
        }

};

// Manager class using inheritance from Manager and Employee parent classes.
class HREmp : public Manager {
    public:
        HREmp(string name, int id) : Manager(name, id) {
            type = "HR Employee";
        }
        void addEmployee() {
            cout << "\nAdding new Employee. " << endl;
        }
        void modEmployee() {
            cout << "\nEditing Employee." << endl;
        }
        void delEmployee() {
            cout << "\nDeleting Employee." << endl;
        }
        // Overriden class function
        void showMenu (HREmp hremp) {
            string user_in;

            //Infinite loop to display overriden employee menu for HR employees.
            do {
                cout << "\n" << type << " Menu\n-------------\n" << "1. View all Employees" << endl;
                cout << "2. Search Employees" << endl << "3. Add Employee" << endl << "4. Edit Employee" << endl;
                cout << "5. Delete Employee" << endl << "6. Return to previous menu." << endl;
                cin >> user_in;

                // Use input to call the appropriate parent or child class function.
                if (user_in == "1") {
                    hremp.viewProfile();
                    break;
                }
                if (user_in == "2") {
                    hremp.searchEmployees();
                    break;
                }
                if (user_in == "3") {
                    hremp.addEmployee();
                    break;
                }
                if (user_in == "4") {
                    hremp.modEmployee();
                    break;
                }
                if (user_in == "5") {
                    hremp.delEmployee();
                    break;
                }
                if (user_in == "6") {
                    break;
                }
            } while (true);

        }
};

// Function to validate user id input to demonstrate how conditional statements can verify login info.
bool validateUser(const string& user) {
    for (char c : user) {
        if (!isdigit(c)) {
            return false;
        }
    }
    return true;
};

//Function to validate password length to demonstrate how conditional statements can verify login info.
bool validatePass(const string& pass) {
    if (pass.length() < 8) {
        return false;
    }
    else {
        return true;
    }
};

// Function to display menus and handle navigation
void ShowMenu(Employee emp, Manager mng, HREmp hremp) {
    string user_input;
    // Infinite loop to display menu until a valid option is selected or program is exited. 
    do {
    cout << "\nView Menus: " << endl << "-------------\n" << "1. View Employee Menu" << endl;
    cout << "2. View Manager Menu" << endl << "3. View HR Menu" << endl << "4. Exit program." <<endl;
    cin >> user_input;

    // Use input to call the appropriate parent or child class function.
        if (user_input == "1") {
            emp.showMenu(emp);
        }
        else if (user_input == "2") {
            mng.showMenu(mng);
        }
        else if (user_input == "3") {
            hremp.showMenu(hremp);
        }
        else if (user_input == "4") {
            exit(0);
        }
        else {
            cout << "Please enter a valid number." << endl;
        }
    } while (true);
}

// Main function that initializes employee objects and displays a example login menu.
// Calls Show validateUser function until valid information is entered then displays the test Menu.
int main() {
    string userId, password;

    Employee emp("Professor Sycamore", 386);
    Manager mng("Professor Elm", 251);
    HREmp hremp("Professor Oak", 151);

    // Infinite loop that keeps displaying menu until a proper password value is entered.
    do {
        cout << "Enter Login Credentials:" << endl;
        cout << "User ID (numbers only)";
        cin >> userId;
        cout << "Password: (8 or more characters) ";
        cin >> password;

    if (validateUser(userId) && validatePass(password)) {
        cout << "Login Successful!" << endl;
        break;
    }
    else {
        cout << "Invalid Login credentials. Please Try again." << endl;
    }
    } while (true);

    // Call ShowMenu function and pass it the created employee objects

    ShowMenu(emp,mng,hremp);

    return 0;
}