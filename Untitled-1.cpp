#include <iostream>
#include <vector>
#include <string>
#include "center.h" 

using namespace std;

struct bankaccount {
    string name, accnum, dob, pnum;
    double amount, balance;
};

class Bank {
public:
    vector<bankaccount> accounts;

public:
    int NewAcc(string name, string pnum, string anum, string dob, double balance) {
        bankaccount newaccount = {name, anum, dob, pnum, balance, balance};
        accounts.push_back(newaccount);
        cout << ("\nYour account has been created with a balance of Rs.") << balance << endl;
        return 0;
    }

    bankaccount* findAccount(string anum) {
	    for (vector<bankaccount>::iterator it = accounts.begin(); it != accounts.end(); ++it) {
	        if (it->accnum == anum) {
	            return &(*it);
	        }
	    }
	    return nullptr;
	}

    void displayAllAccounts() const {
        if (accounts.empty()) {
            cout << "No accounts found." << endl;
            return;
        }

        for (int i = 0; i < accounts.size(); ++i) {
            const auto& account = accounts[i];
            cout << "Account Number: " << account.accnum << endl;
            cout << "Account Holder Name: " << account.name << endl;
            cout << "Balance: $" << account.balance << endl;
            cout << "--------------------------" << endl;
        }
    }

    int manageaccounts(string anum) {
        bankaccount* account = findAccount(anum);
        if (account) {
            int choice;
            do {
                cout << "\nManaging Account " << account->accnum << endl;
                cout << "1. Deposit Money\n";
                cout << "2. Withdraw Money\n";
                cout << "3. Check Balance\n";
                cout << "4. Exit Account Management\n";
                cout << "Enter your choice: ";
                cin >> choice;

                double amount;
                switch (choice) {
                    case 1:
                        cout << "Enter Amount to Deposit: ";
                        cin >> amount;
                        if (amount > 0) {
                            account->balance += amount;
                            cout << "Amount deposited successfully." << endl;
                        } else {
                            cout << "Deposit amount must be positive." << endl;
                        }
                        break;

                        
                    case 2:
				        cout << "Enter Amount to Withdraw: ";
				        cin >> amount;
				        if (amount > 0 && amount <= account->balance) {
				            account->balance -= amount;
				            cout << "Amount withdrawn successfully." << endl;
				        } else {
				            cout << "Insufficient balance or invalid withdrawal amount." << endl;
				        }
				        break;
				
				    case 3:
				        cout << "Current Balance: " << account->balance << endl;
				        break;
				
				    case 4:
				        cout << "Exiting Account Management." << endl;
				        break;
				
				    default:
				        cout << "Invalid choice. Please try again." << endl;
				}
			} while (choice != 4);
		} else {
			cout << "Account not found." << endl;
		}
	}
};
				
int main() {
	int a;
	Bank ba;
	string name, pnum, anum, dob;
	double balance;
	string statement = "----WELCOME TO S BANK----";
	while (true) {
		printCentered(statement);
		cout << ("\n1.Create New Account");
		cout << ("\n2.Manage existing accounts");
		cout << ("\n3.Display all accounts");
		cout << ("\n4.Exit");
		cout << ("\nEnter the serial number of the the function to be performed :");
		cin >> a;

        cin.ignore();

		switch (a) {
			case 1:
				cout << ("\nEnter The Following Details ");
				cout << ("\nName :");
				getline(cin, name);
				cout << ("\nPhone Number :");
				getline(cin, pnum);
				cout << ("\nAccount Number :");
				getline(cin, anum);
				cout << ("\nDate Of Birth(YYYY-MM-DD) :");
				getline(cin, dob);
				cout << ("\nEnter an amount to be Debited(min. of Rs.1000) :");
				cin >> balance;
				ba.NewAcc(name, pnum, anum, dob, balance);
				break;
				
			case 2:
				cout << ("\nEnter Account number :");
				getline(cin, anum);
				ba.manageaccounts(anum);
				break;
				
			case 3:
				ba.displayAllAccounts();
				break;
				
			case 4:
				cout << ("\nExiting program...");
				return 0;
				
			default:
				cout << ("\nInvalid Option....Try again");
		}
	}
	return 0;
}