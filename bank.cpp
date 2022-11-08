#include "bank.h"
#include "iostream"

using std::cout, std::endl, std::cin;

bank::bank() {
    balance500 = 0;
    balance100 = 0;
    balance50 = 0;
}

bank::bank(int a, int b, int c) {
    this->balance500 = a;
    this->balance100 = b;
    this->balance50 = c;
    bankBills.push_back(*this);
}

bank::~bank() {
    bankBills.clear();
    history.clear();
}

void bank::withdraw(int amount) {
    int temp = amount;
    int temp500 = 0;
    int temp100 = 0;
    int temp50 = 0;
    for (int i = 0; i < bankBills.size(); ++i) {
        if (bankBills[i].balance500 >= temp / 500) {
            temp500 = temp / 500;
            temp -= temp500 * 500;
        } else {
            temp500 = bankBills[i].balance500;
            temp -= temp500 * 500;
        }
        if (bankBills[i].balance100 >= temp / 100) {
            temp100 = temp / 100;
            temp -= temp100 * 100;
        } else {
            temp100 = bankBills[i].balance100;
            temp -= temp100 * 100;
        }
        if (bankBills[i].balance50 >= temp / 50) {
            temp50 = temp / 50;
            temp -= temp50 * 50;
        } else {
            temp50 = bankBills[i].balance50;
            temp -= temp50 * 50;
        }
        if (temp == 0) {
            bankBills[i].balance500 -= temp500;
            bankBills[i].balance100 -= temp100;
            bankBills[i].balance50 -= temp50;
            cout << "Retiro exitoso" << endl;
            cout << "Billetes de 500: " << temp500 << endl;
            cout << "Billetes de 100: " << temp100 << endl;
            cout << "Billetes de 50: " << temp50 << endl;
        } else {
            cout << "No hay suficientes billetes" << endl;
        }
    }
    saveHistory();
}

void bank::getBalance() {
    for (int i = 0; i < bankBills.size(); ++i) {
        cout << "Billetes de 500: " << bankBills[i].balance500 << endl;
        cout << "Billetes de 100: " << bankBills[i].balance100 << endl;
        cout << "Billetes de 50: " << bankBills[i].balance50 << endl;
        cout << "Total: " << bankBills[i].balance500 * 500 + bankBills[i].balance100 * 100 + bankBills[i].balance50 * 50 << endl;
    }
}

void bank::removeTrays() {
    // Mostrar el balance actual y solicitar confirmación
    for (int i = 0; i < bankBills.size(); ++i) {
        cout << "Billetes de 500: " << bankBills[i].balance500 << endl;
        cout << "Billetes de 100: " << bankBills[i].balance100 << endl;
        cout << "Billetes de 50: " << bankBills[i].balance50 << endl;
        cout << "Total: " << bankBills[i].balance500 * 500 + bankBills[i].balance100 * 100 + bankBills[i].balance50 * 50 << endl;
        cout << "¿Desea continuar? (y/n)" << endl;
        char confirmation;
        cin >> confirmation;
        if (confirmation == 'y') {
            bankBills[i].balance500 = 0;
            bankBills[i].balance100 = 0;
            bankBills[i].balance50 = 0;
            // Actualizar el balance
            cout << "Actualice el balance" << endl;
            cout << "Billetes de 500: ";
            cin >> bankBills[i].balance500;
            cout << "Billetes de 100: ";
            cin >> bankBills[i].balance100;
            cout << "Billetes de 50: ";
            cin >> bankBills[i].balance50;
        } else {
            cout << "Operación cancelada" << endl;
        }
    }

}

void bank::depositTrays() {
    // Indicar la cantidad de billetes que hay en el cajero y el total
    for (int i = 0; i < bankBills.size(); ++i) {
        cout << "Cantidad de 500 en la bandeja: " << bankBills[i].balance500 << endl;
        cout << "Cantidad de 100 en la bandeja: " << bankBills[i].balance100 << endl;
        cout << "Cantidad de 50 en la bandeja: " << bankBills[i].balance50 << endl;
        cout << "Total en L" << bankBills[i].balance500 * 500 + bankBills[i].balance100 * 100 + bankBills[i].balance50 * 50 << endl;
    }
}

void bank::saveHistory() {
    // Guardar el historial de transacciones
    for (int i = 0; i < bankBills.size(); ++i) {
        history.push_back(bankBills[i]);
    }
}

void bank::showHistory() {
    for (int i = 0; i < 1; ++i) {
        cout << "Cantidad inicial de billetes de 500: " << history[i].balance500 << endl;
        cout << "Cantidad inicial de billetes de 100: " << history[i].balance100 << endl;
        cout << "Cantidad inicial de billetes de 50: " << history[i].balance50 << endl;
        cout << "Total inicial en L: " << history[i].balance500 * 500 + history[i].balance100 * 100 + history[i].balance50 * 50 << endl;
    }

    // Cantidad de transacciones hechas
    cout << "Cantidad de transacciones hechas: " << history.size() - 1 << endl;

    // Total dispensado a los clientes
    int totalDispensed = 0;
    for (int i = 1; i < history.size(); ++i) {
        totalDispensed += (history[i - 1].balance500 - history[i].balance500) * 500 + (history[i - 1].balance100 - history[i].balance100) * 100 + (history[i - 1].balance50 - history[i].balance50) * 50;
    }
    cout << "Total dispensado a los clientes: " << totalDispensed << endl;

    // Saldo actual del ATM (cantidad de billetes por bandeja y total en Lempiras)
    for (int i = 0; i < bankBills.size(); ++i) {
        cout << "Cantidad de billetes de 500: " << bankBills[i].balance500 << endl;
        cout << "Cantidad de billetes de 100: " << bankBills[i].balance100 << endl;
        cout << "Cantidad de billetes de 50: " << bankBills[i].balance50 << endl;
        cout << "Total en L: " << bankBills[i].balance500 * 500 + bankBills[i].balance100 * 100 + bankBills[i].balance50 * 50 << endl;
    }
}



