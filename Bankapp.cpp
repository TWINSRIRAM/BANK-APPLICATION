
#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <ctime>
#include <iomanip>
#include<string>


using namespace std;

class Account {
public:
    int accnum, pin;
    string accname;
    double bal;
    int wrong; 

    Account(int a, string& b, double c, int d) : accnum(a), accname(b), bal(c), pin(d), wrong(0) {
        cout << "********* Account Created ********** " << "\n  " 
        <<"\n\tAccount holder name :" <<accname
      <<"\n\tAccount number      : " <<"********"<< accnum 
      <<"\n\tPin number          :" << pin 
        <<"\n\t\tHave a nice day" << endl;
    }

    void deposit(double a) {
        bal += a;
        cout<< "Deposited Amount :$"<<a<<"\nUpdated balance :$" << bal << endl;
    }

    void withdraw(double a) {
        if (a > bal) {
            cout << "Insufficient balance" << endl;
        } else {
            bal -= a;
            cout << "Withdrawn amount :$" << a 
            <<"\nNew balance is     :$" << bal << endl;
        }
    }

   void DD() const {
    cout<<" "<<endl;
    cout<<"|\t\t***Account details***";
    cout<<" "<<endl;
    cout<<"\tAccount holder name: " << accname << "\n";
    cout<<"\tAccount number     : " <<"********"<<accnum << "\n";
    cout<<"\tBalance            : $" << bal << "\n";
    cout<<" "<<endl;
}


    double Bal(){
        return bal;
    }

    int Accnum(){
        return accnum;
    }

    int GP(){
        return pin;
    }

    int inc(){
        return wrong++;
    }

    int Wrong(){
        return wrong;
    }
};


int ran() {
    srand(time(0));
    return rand() % 9000 + 1000;
}

int ranp() {
    srand(time(0));
    return rand() % 800 + 100;
}

int main() {
    cout << "||\t\t****** TWINSPIRA BANK  ******* " << "\t\t||" << endl;
    cout << "\n\t\tWelcome to Our Financial Harbour\n" << endl;

    vector<Account> acc;
    unordered_set<int> z;

    int choice;
    char r;

        do {
            cout << "Choose an option:\n";
            cout << "1. Create Account\n";
            cout << "2. Deposit\n";
            cout << "3. Withdraw\n";
            cout << "4. Dispatch Details\n";
            cout << "5. Exit\n";
            cout << "===============================================\n";
            cout << "Enter the option to proceed: ";
            cin >> choice;

            switch (choice) {
                case 1: {
                    string accname;
                    double bal;
                    int pin,age;

                    cout << "\nEnter name: ";
                    cin.ignore();
                    getline(cin, accname);
                    cout<<"Enter your Age : ";
                    cin>>age;
                    cout << "Enter the initial funds: $";
                    cin >> bal;
                    cout << endl;
                    cout << "================================================\n";
                    cout << " " << endl;
                    int accnum;
                    do {
                        accnum = ran();
                        pin = ranp();
                    } while (z.find(accnum) != z.end());

                    z.insert(accnum);

                    acc.emplace_back(accnum, accname, bal, pin);
                    cout << "\nAccount created successfully!\n";
                    cout << " "<<"\n***********************************************" << endl;
                   
                    break;
                }
                
                case 2: {
                int accnum, enteredPin;
                double amount;
                cout<<"***Hint:Make sure your account number\n\t\tand pin number are entering right***"<<endl;

                cout << "\nEnter account number[last four digit]: ";
                cin >> accnum;

                auto it = find_if(acc.begin(), acc.end(), [&](const Account& ac) {
                    return ac.Accnum() == accnum;
                });

                if (it != acc.end()) {
                    while (it->Wrong() < 4) {
                        cout << "Enter PIN: ";
                        cin >> enteredPin;
                        cout<<" \n";

                        if (enteredPin == it->GP()) {
                            cout << "Enter deposit amount: $";
                            cin >> amount;
                            it->deposit(amount);
                            break;
                        } else {
                            cout << "Incorrect PIN. Please re-enter the correct PIN." << endl;
                            
                            cout<<"Try :"<<it->inc()+1<<endl;
                        }
                    }
                    if (it->Wrong() >= 4) {
                        cout << "Too many incorrect attempts. Exiting application." << endl;
                        return 0; 
                    }
                } else {
                    cout << "Account not found. Deposit canceled.\n";
                }

                cout << "***********************************************" << endl;
                cout << "Glad to be of service to you!\n\n";
                break;
            }
            case 3: {
                int accnum, enteredPin;
                double amount;
                 cout<<"***Hint:Make sure your account number\n                and pin number are entering right***"<<endl;

                cout << "\nEnter account number[last four digit]: ";
                cin >> accnum;

                auto it = find_if(acc.begin(), acc.end(), [&](const Account& ac) {
                    return ac.Accnum() == accnum;
                });

                if (it != acc.end()) {
                    while (it->Wrong() < 4) {
                        cout << "Enter PIN: "<<"\n ";
                        cin >> enteredPin;

                        if (enteredPin == it->GP()) {
                            cout << "Enter withdrawal amount: $";
                            cin >> amount;
                            it->withdraw(amount);
                            break;
                        } else {
                            cout << "Incorrect PIN. Please re-enter the correct PIN." << endl;
                            cout<<"Try :"<<it->inc()+1<<endl;
                        }
                    }
                    if (it->Wrong() >= 4) {
                        cout << "Too many incorrect attempts. Exiting application." << endl;
                        return 0; 
                    }
                } else {
                    cout << "Account not found. Withdrawal canceled.\n";
                }
                cout<<" "<<endl;

                cout << "***********************************************" << endl;
                cout << "Glad to be of service to you!\n\n";
                break;
            }
            case 4: {
                int accnum, enteredPin;
                 cout<<"***Hint:Make sure your account number\n                and pin number are entering right***"<<endl;

                cout << "\nEnter account number[last four digit]: ";
                cin >> accnum;

                auto it = find_if(acc.begin(), acc.end(), [&](const Account& ac) {
                    return ac.Accnum() == accnum;
                });

                if (it != acc.end()) {
                    while (it->Wrong() < 4) {
                        cout << "Enter PIN: ";
                        cin >> enteredPin;

                        if (enteredPin == it->GP()) {
                            it->DD();
                            break;
                        } else {
                            cout << "Incorrect PIN. Please re-enter the correct PIN." << endl;
                            cout<<"Try :"<<it->inc()+1<<endl;
                        }
                    }
                    if (it->Wrong() >= 4) {
                        cout << "Too many incorrect attempts. Exiting application." << endl;
                        return 0; 
                    }
                } else {
                    cout << "Account not found.\n";
                }

                cout <<"***********************************************" << endl;
                cout << "Glad to be of service to you!\n\n";
                break;
            }

                case 5: {
                    cout << "Exiting program.\n";
                     cout << "This program was Done by Twinsriram V\nCSE-\'D\'.\n";
                    return 0; 
                }
                default:
                    cout << "Invalid choice. Try again.\n";
            }

        
        cout << "Do you want to continue? yes or no (Y/N): ";
        cin >>r;
        }while(choice!=5 && toupper(r)=='Y');
         cout << "Exiting program.\n";
                    cout << "This program was Done by Twinsriram V\nCSE-\'D\'.\n";

    return 0;
}
