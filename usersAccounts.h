#ifndef ATM_PROGRA3_USERSACCOUNTS_H
#define ATM_PROGRA3_USERSACCOUNTS_H

#include <iostream>
#include <vector>

using namespace std;

class usersAccounts {
public:
    usersAccounts();

    usersAccounts(int accountNumber, int pin, int balance);

    ~usersAccounts();

    int getAccountBalance();
    int getAccountNumber();
    int getAccountPassword();

    void withdrawMoney(int pin, int accountNumber, int amount);

private:
    int accountNumber;
    int accountBalance;
    int accountPassword;

protected:
        vector<usersAccounts> accounts;
};


#endif //ATM_PROGRA3_USERSACCOUNTS_H
