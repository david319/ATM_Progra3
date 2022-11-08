#include "usersAccounts.h"

usersAccounts::usersAccounts() {
    accountNumber = 0;
    accountBalance = 0;
    accountPassword = 0;
}

usersAccounts::usersAccounts(int accountNumber, int pin, int balance) {
    this->accountNumber = accountNumber;
    this->accountPassword = pin;
    this->accountBalance = balance;
    accounts.push_back(*this);
}

usersAccounts::~usersAccounts() {
    accounts.clear();
}

void usersAccounts::withdrawMoney(int _pin, int _accountNumber, int _amount) {
    for (int i = 0; i < accounts.size(); ++i) {
        if (accounts[i].accountNumber == _accountNumber && accounts[i].accountPassword == _pin) {
            if (accounts[i].accountBalance >= _amount) {
                accounts[i].accountBalance -= _amount;
                cout << "Retiro exitoso" << endl;
            } else {
                cout << "Saldo insuficiente" << endl;
            }
        } else {
            cout << "Cuenta o pin incorrectos" << endl;
        }
    }
}

int usersAccounts::getAccountNumber() {
    return accountNumber;
}

int usersAccounts::getAccountPassword() {
    return accountPassword;
}


