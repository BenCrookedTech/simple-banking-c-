#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

double deposit();
void showBalance(double balance);
double withdraw(double balance);

double deposit() {
    double amount;
    cout << "Enter the amount you need to deposit: ";
    cin >> amount;
    return amount;
}

void showBalance(double balance) {
    cout << "Your bank balance is " << setprecision(2) << fixed << balance << endl;
}

double withdraw(double balance) {
    double withdrawal_amount;
    cout << "How much do you wish to withdraw: ";
    cin >> withdrawal_amount;

    if (withdrawal_amount > balance) {
        cout << "Insufficient funds!" << endl;
    } else {
        balance -= withdrawal_amount;
    }
    return balance;
}

int main() {
    vector<string> items = {"showbalance", "deposit", "withdraw", "exit"};
    string userInput;
    double balance = 0;

    while (true) {
        cout << "\nAvailable options:" << endl;
        for (const auto& choice : items) {
            cout << "- " << choice << endl;
        }

        cout << "Enter your choice: ";
        getline(cin, userInput);

        transform(userInput.begin(), userInput.end(), userInput.begin(), ::tolower);

        auto it = find(items.begin(), items.end(), userInput);

        if (it != items.end()) {
            if (userInput == "showbalance") {
                showBalance(balance);
            } else if (userInput == "deposit") {
                balance += deposit();
                showBalance(balance);
            } else if (userInput == "withdraw") {
                balance = withdraw(balance);
                showBalance(balance);
            } else if (userInput == "exit") {
                cout << "Thanks for visiting." << endl;
                break;
            }
        } else {
            cout << "Please enter a valid option." << endl;
        }
    }

    return 0;
}
