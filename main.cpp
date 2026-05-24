#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>

#include "Image.h"
#include "ImageFile.h"
#include "FilterSession.h"
#include "Grayscale.h"
#include "Invert.h"
#include "Brightness.h"
#include "Contrast.h"
#include "Red.h"
#include "Green.h"
#include "Blue.h"
#include "Box_Blur.h"
#include "Horizontal.h"
#include "Vertical.h"
using namespace std;
struct CustomerData {
    string cnic;
    string password;
    string name;
    string phone;
    string city;
    int blocked;
};

vector<CustomerData> customersList;
const string CUSTOMERS_FILE = "customers.txt";
void loadCustomers() {
    customersList.clear();
    ifstream file(CUSTOMERS_FILE);
    if (!file.is_open()) return;

    string line;
    while (getline(file, line)) {
        if (line.empty()) continue;
        stringstream ss(line);
        CustomerData c;
        
        getline(ss, c.cnic, '|');
        getline(ss, c.password, '|');
        getline(ss, c.name, '|');
        getline(ss, c.phone, '|');
        getline(ss, c.city, '|');
        
        string blockedStr;
        getline(ss, blockedStr, '|');
        c.blocked = (blockedStr == "1") ? 1 : 0;
        
        customersList.push_back(c);
    }
    file.close();
}

void saveCustomers() {
    ofstream file(CUSTOMERS_FILE);
    for (size_t i = 0; i < customersList.size(); i++) {
        file << customersList[i].cnic << "|" 
             << customersList[i].password << "|" 
             << (customersList[i].name.empty() ? "N/A" : customersList[i].name) << "|" 
             << (customersList[i].phone.empty() ? "N/A" : customersList[i].phone) << "|" 
             << (customersList[i].city.empty() ? "N/A" : customersList[i].city) << "|" 
             << customersList[i].blocked << "\n";
    }
    file.close();
}

bool adminLogin() {
    string cnic, p;
    cout << "--- ADMIN LOGIN ---" << endl;
    cout << "Enter CNIC: ";
    cin >> cnic;
    cout << "Password: ";
    cin >> p;

    return (cnic == "0123456" && p == "Admin123");
}
void adminMenu() {
    while (true) {
        cout << "===== ADMIN DASHBOARD =====\n";
        cout << "Total registered customers: " << customersList.size() << "\n";
        
        for (size_t i = 0; i < customersList.size(); i++) {
            cout << i + 1 << ". CNIC: " << customersList[i].cnic 
                 << " | Name: " << customersList[i].name 
                 << " | Blocked: " << (customersList[i].blocked ? "Yes" : "No") << "\n";
        }
        cout << "1. Block/Unblock Customer\n";
        cout << "2. Logout\n";
        cout << "Choice: ";
        
        int choice;
        cin >> choice;
        if (choice == 1) {
            string cnic;
            cout << "Enter CNIC to toggle block status: ";
            cin >> cnic;
            
            bool found = false;
            for (size_t i = 0; i < customersList.size(); i++) {
                if (customersList[i].cnic == cnic) {
                    customersList[i].blocked = (customersList[i].blocked == 1) ? 0 : 1;
                    cout << "Customer " << cnic << " is now " 
                         << (customersList[i].blocked ? "Blocked" : "Unblocked") << ".\n";
                    saveCustomers();
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << "Customer not found.\n";
            }
        }
        else if (choice == 2) {
            break;
        }
        else {
            cout << "Invalid choice!\n";
        }
    }
}

bool customerLogin() {
    string cnic, p;

    cout << "--- CUSTOMER LOGIN ---\n";
    cout << "Enter CNIC: ";
    cin >> cnic;
    cout << "Password: ";
    cin >> p;

    for (size_t i = 0; i < customersList.size(); i++) {
        if (customersList[i].cnic == cnic && customersList[i].password == p) {
            if (customersList[i].blocked == 1) {
                cout << "Account is blocked. Please contact admin.\n";
                return false;
            }
            return true;
        }
    }

    return false;
}
void registerCustomer() {
    string cnic, p, name, phone, city;

    cout << "\n--- REGISTER CUSTOMER ---\n";
    cout << "Enter CNIC: ";
    cin >> cnic;
    for (size_t i = 0; i < customersList.size(); i++) {
        if (customersList[i].cnic == cnic) {
            cout << "CNIC already registered!\n";
            return;
        }
    }
    
    cout << "Enter Password: ";
    cin >> p;
    cin.ignore();
    
    cout << "Enter Full Name: ";
    getline(cin, name);
    
    cout << "Enter Phone: ";
    getline(cin, phone);
    
    cout << "Enter City: ";
    getline(cin, city);

    CustomerData c;
    c.cnic = cnic;
    c.password = p;
    c.name = name;
    c.phone = phone;
    c.city = city;
    c.blocked = 0;

    customersList.push_back(c);
    saveCustomers();

    cout << "Registered successfully!\n";
}

static void printFilterMenu() {
    cout << "\nAvailable filters:\n";
    cout << "1. Grayscale\n";
    cout << "2. Invert\n";
    cout << "3. Brightness\n";
    cout << "4. Contrast Stretch\n";
    cout << "5. Red Channel Only\n";
    cout << "6. Green Channel Only\n";
    cout << "7. Blue Channel Only\n";
    cout << "8. Box Blur\n";
    cout << "9. Flip Horizontal\n";
    cout << "10. Flip Vertical\n";
    cout << "0. Finish\n";
}
void customerMenu() {
    Image image;
    FilterSession session;

    while (true) {
        cout << "\n=== Image Filter Studio ===\n";
        cout << "1. Load JPG/PNG image\n";
        cout << "2. Show ASCII preview\n";
        cout << "3. Build filter pipeline\n";
        cout << "4. Apply pipeline\n";
        cout << "5. Save output\n";
        cout << "6. Logout\n";
        cout << "Choice: ";

        int choice;
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            string path;
            cout << "Enter image path: ";
            getline(cin, path);

            // Strip leading/trailing whitespace and quotes (e.g. if user types "path")
            while (!path.empty() && (path.front() == ' ' || path.front() == '"' || path.front() == '\''))
                path.erase(path.begin());
            while (!path.empty() && (path.back() == ' ' || path.back() == '"' || path.back() == '\''))
                path.pop_back();

            if (ImageFile::loadImage(path, image)) {
                cout << "Image loaded successfully.\n";
                image.displayASCII();
            } else {
                cout << "Failed to load image.\n";
            }
        }

        else if (choice == 2) {
            image.displayASCII();
        }

        else if (choice == 3) {
            session.clear();

            while (true) {
                printFilterMenu();
                cout << "Select filter: ";

                int f;
                cin >> f;
                cin.ignore();

                if (f == 0) break;

                if (f == 1) session.addFilter(Grayscale());
                else if (f == 2) session.addFilter(Invert());
                else if (f == 3) {
                    int amt;
                    cout << "Brightness: ";
                    cin >> amt;
                    cin.ignore();
                    session.addFilter(Brightness(amt));
                }
                else if (f == 4) session.addFilter(Contrast());
                else if (f == 5) session.addFilter(Red());
                else if (f == 6) session.addFilter(Green());
                else if (f == 7) session.addFilter(Blue());
                else if (f == 8) session.addFilter(Box_Blur());
                else if (f == 9) session.addFilter(Horizontal());
                else if (f == 10) session.addFilter(Vertical());

                cout << "Pipeline: " << session.getPipelineText() << "\n";
            }
        }

        else if (choice == 4) {
            if (image.isEmpty())
                cout << "Load image first.\n";
            else {
                session.apply(image);
                cout << "Applied successfully.\n";
                image.displayASCII();
            }
        }

        else if (choice == 5) {
            string path;
            cout << "Save as: ";
            getline(cin, path);

            if (image.saveToFile(path))
                cout << "Saved!\n";
            else
                cout << "Save failed.\n";
        }

        else if (choice == 6) {
            break;
        }

        else {
            cout << "Invalid choice.\n";
        }
    }
}
int main() {
    loadCustomers();

    while (true) {
        cout << "\n===== MAIN MENU =====\n";
        cout << "1. Admin Login\n";
        cout << "2. Customer Login\n";
        cout << "3. Register Customer\n";
        cout << "4. Exit\n";
        cout << "Choice: ";

        int choice;
        cin >> choice;

        if (choice == 1) {
            if (adminLogin()) {
                adminMenu();
            } else {
                cout << "Invalid admin login!\n";
            }
        }

        else if (choice == 2) {
            if (customerLogin()) {
                customerMenu(); // YOUR IMAGE SYSTEM STARTS HERE
            } else {
                cout << "Invalid login!\n";
            }
        }

        else if (choice == 3) {
            registerCustomer();
        }

        else if (choice == 4) {
            break;
        }

        else {
            cout << "Invalid choice!\n";
        }
    }

    return 0;
}