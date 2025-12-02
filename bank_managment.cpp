#include <iostream>
#include <vector>
#include <string>
using namespace std;

//add a stucture called accounts
struct Account {
    string name;
    int id;
    double balance;
};

vector<Account> accounts;

// create account 
void create_account() {
    Account acc;
    cout << "\nEnter account name: ";
    cin >> acc.name;
    cout << "Enter account ID (number): ";
    cin >> acc.id;
    acc.balance = 0; 
    accounts.push_back(acc);
    cout << "Account created successfully!\n";
}

// find account by id
Account* find_account(int id) {
    for (auto &acc : accounts) {
        if (acc.id == id) return &acc;
    }
    return nullptr;
}

// send money 
void send_money() {
    int from_id, to_id;
    double amount;
    cout << "\nSender Account ID: ";
    cin >> from_id;
    cout << "Receiver Account ID: ";
    cin >> to_id;

    Account *from = find_account(from_id);
    Account *to = find_account(to_id);

    if (!from || !to) {
        cout << "One or both accounts not found.\n";
        return;
    }

    cout << "Amount to send: ";
    cin >> amount;

    if (from->balance < amount) {
        cout << "Insufficient balance!\n";
        return;
    }

    from->balance -= amount;
    to->balance += amount;

    cout << "Transaction successful!\n";
}

// cash in 
void cash_in() {
    int id;
    double amount;
    cout << "\nEnter account ID: ";
    cin >> id;
    Account *acc = find_account(id);
    if (!acc) {
        cout << "Account not found.\n";
        return;
    }
    cout << "Amount to deposit: ";
    cin >> amount;
    acc->balance += amount;
    cout << "Deposit successful!\n";
}

// cash out
void cash_out() {
    int id;
    double amount;
    cout << "\nEnter account ID: ";
    cin >> id;
    Account *acc = find_account(id);
    if (!acc) {
        cout << "Account not found.\n";
        return;
    }
    cout << "Amount to withdraw: ";
    cin >> amount;

    if (acc->balance < amount) {
        cout << "Insufficient balance!\n";
        return;
    }

    acc->balance -= amount;
    cout << "Withdrawal successful!\n";
}

// view balance
void view_balance() {
    int id;
    cout << "\nEnter account ID: ";
    cin >> id;
    Account *acc = find_account(id);
    if (!acc) {
        cout << "Account not found.\n";
        return;
    }

    cout << "Account: " << acc->name 
         << "\nBalance: $" << acc->balance << "\n";
}

// ls options
void list_operaciones() {
    cout << "\n===== BANK MANAGER =====\n";
    cout << "1. Create New Account\n";
    cout << "2. Send Money\n";
    cout << "3. Cash In (Deposit)\n";
    cout << "4. Cash Out (Withdraw)\n";
    cout << "5. View Balance\n";
    cout << "6. Exit\n";
}

int main() {
    int option;
    //while loop 
    while (true) {
        list_operaciones();
        cout << "\nChoose an option: ";
        cin >> option;

        switch (option) {
            case 1: create_account(); break;
            case 2: send_money(); break;
            case 3: cash_in(); break;
            case 4: cash_out(); break;
            case 5: view_balance(); break;
            case 6: 
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid option!\n";
        }
    }
}
