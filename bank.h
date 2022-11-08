#ifndef ATM_PROGRA3_BANK_H
#define ATM_PROGRA3_BANK_H

#include <iostream>
#include <vector>

using std::vector;

class bank {
public:
    bank();
    bank(int a, int b, int c);
    ~bank();

    void getBalance();
    void removeTrays();
    void depositTrays();

    void withdraw(int amount);
    void saveHistory();
    void showHistory();

private:
    int balance500;
    int balance100;
    int balance50;

protected:
    vector<bank> bankBills;
    vector<bank> history;
};


#endif //ATM_PROGRA3_BANK_H
