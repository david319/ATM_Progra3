#include <iostream>
#include "usersAccounts.h"
#include "bank.h"

using std::cout, std::endl, std::cin;

int main() {

    // Users accounts
    usersAccounts user1(1234, 1234, 3000);
    usersAccounts user2(5678, 5678, 5000);
    usersAccounts user3(9012, 9012, 10000);

    // Bank bills
    bank bank1(10, 10, 10);
    bank1.saveHistory();


    // Variables
    int opcion;
    int menuAdm;
    int menuUser;
    int codeRet;
    int montoRet;
    int opcionRet;
    int pin;
    int accountNumber;
    bool inTrays = true;

    // Withdrawal codes and amounts
    int code1 = 852123;
    int code2 = 963654;
    int code3 = 741456;

    int monto1 = 1400;
    int monto2 = 5350;
    int monto3 = 2150;


    do {
        cout << "                               ATM\n"
                "\n"
                "                          ------------   \n"
                "[1] Menu Administrativo  |            |  Menu de usuario [2]\n"
                "                         | BIENVENIDO |\n"
                "                         |     AL     |\n"
                "                         |   CAJERO   |\n"
                "                         |            |\n"
                "                          ------------ \n"
                "                            Salir [0]\n"
                "                         Ingrese Opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 0:
                cout << "Gracias por usar el ATM" << endl;
                break;
            case 1:
                cout << "Menu Administrativo\n";
                cout << "                              ATM\n"
                        "\n"
                        "                          ------------   \n"
                        "[1] Retirar bandejas     |            |  Depositar bandejas [2]\n"
                        "                         | BIENVENIDO |\n"
                        "[3] Saldo Actual         |     AL     |  Resumen del dia    [4]\n"
                        "                         |   CAJERO   |\n"
                        "                         |            |\n"
                        "                          ------------ \n"
                        "                         Menu Principal [0]\n"
                        "                         Ingrese Opcion: ";
                cin >> menuAdm;

                switch (menuAdm) {
                    case 0:
                        cout << "Gracias por usar el ATM" << endl;
                        break;
                    case 1:
                        cout << "Retirar bandejas\n";
                        bank1.removeTrays();
                        inTrays = false;
                        break;
                    case 2:
                        cout << "Depositar bandejas\n";
                        if (inTrays) {
                            cout << "Las bandejas ya estan en el cajero" << endl;
                        } else {
                            bank1.depositTrays();
                            inTrays = true;
                        }
                        break;
                    case 3:
                        cout << "Saldo Actual\n";
                        bank1.getBalance();
                        break;
                    case 4:
                        cout << "Resumen del dia\n";
                        bank1.showHistory();
                        break;
                    default:
                        cout << "Opcion no valida\n";
                        break;
                }

                break;
            case 2:
                cout << "Menu de usuario\n";
                cout << "                               ATM\n"
                        "\n"
                        "                          ------------   \n"
                        "[1] Retiro sin tarjeta   |            |  Retiro normal [2]\n"
                        "                         | BIENVENIDO |\n"
                        "                         |     AL     |\n"
                        "                         |   CAJERO   |\n"
                        "                         |            |\n"
                        "                          ------------ \n"
                        "                         Menu Principal [0]\n"
                        "                         Ingrese Opcion: ";
                cin >> menuUser;

                switch (menuUser) {
                    case 0:
                        cout << "Gracias por usar el ATM" << endl;
                        break;
                    case 1:
                        cout << "Retiro sin tarjeta\n";
                        cout << "Ingrese el codigo de retiro: ";
                        cin >> codeRet;
                        cout << "Ingrese el monto a retirar: ";
                        cin >> montoRet;

                        if (codeRet == code1 && montoRet == monto1) {
                            bank1.withdraw(montoRet);
                        } else if (codeRet == code2 && montoRet == monto2) {
                            bank1.withdraw(montoRet);
                        } else if (codeRet == code3 && montoRet == monto3) {
                            bank1.withdraw(montoRet);
                        } else {
                            cout << "Codigo o monto incorrecto" << endl;
                        }

                        break;
                    case 2:
                        cout << "Retiro normal\n";
                        cout << "Ingrese el pin[4 digitos]: ";
                        cin >> pin;
                        cout << "Ingrese el numero de tarjeta: ";
                        cin >> accountNumber;

                        if (pin == user1.getAccountPassword() && accountNumber == user1.getAccountNumber()) {
                            cout << "Ingrese el monto a retirar: "
                                    "1.\n500\n"
                                    "2.\t1000\n"
                                    "3.\t2000\n"
                                    "4.\t4000\n"
                                    "5.\t5000\n"
                                    "6.\tOtra";
                            cin >> opcionRet;

                            switch (opcionRet) {
                                case 1:
                                    user1.withdrawMoney(pin, accountNumber, 500);
                                    bank1.withdraw(500);
                                    break;
                                case 2:
                                    user1.withdrawMoney(pin, accountNumber, 1000);
                                    bank1.withdraw(1000);
                                    break;
                                case 3:
                                    user1.withdrawMoney(pin, accountNumber, 2000);
                                    bank1.withdraw(2000);
                                    break;
                                case 4:
                                    user1.withdrawMoney(pin, accountNumber, 4000);
                                    bank1.withdraw(4000);
                                    break;
                                case 5:
                                    user1.withdrawMoney(pin, accountNumber, 5000);
                                    bank1.withdraw(5000);
                                    break;
                                case 6:
                                    cout << "Ingrese el monto a retirar: ";
                                    cin >> montoRet;
                                    user1.withdrawMoney(pin, accountNumber, montoRet);
                                    bank1.withdraw(montoRet);
                                    break;
                                default:
                                    cout << "Opcion no valida" << endl;
                                    break;
                            }
                        } else if (pin == user2.getAccountPassword() && accountNumber == user2.getAccountNumber()) {
                            cout << "Ingrese el monto a retirar: "
                                    "1.\n500\n"
                                    "2.\t1000\n"
                                    "3.\t2000\n"
                                    "4.\t4000\n"
                                    "5.\t5000\n"
                                    "6.\tOtra";
                            cin >> opcionRet;

                            switch (opcionRet) {
                                case 1:
                                    user2.withdrawMoney(pin, accountNumber, 500);
                                    bank1.withdraw(500);
                                    break;
                                case 2:
                                    user2.withdrawMoney(pin, accountNumber, 1000);
                                    bank1.withdraw(1000);
                                    break;
                                case 3:
                                    user2.withdrawMoney(pin, accountNumber, 2000);
                                    bank1.withdraw(2000);
                                    break;
                                case 4:
                                    user2.withdrawMoney(pin, accountNumber, 4000);
                                    bank1.withdraw(4000);
                                    break;
                                case 5:
                                    user2.withdrawMoney(pin, accountNumber, 5000);
                                    bank1.withdraw(5000);
                                    break;
                                case 6:
                                    cout << "Ingrese el monto a retirar: ";
                                    cin >> montoRet;
                                    user2.withdrawMoney(pin, accountNumber, montoRet);
                                    bank1.withdraw(montoRet);
                                    break;
                                default:
                                    cout << "Opcion no valida" << endl;
                                    break;
                            }
                        } else if (pin == user3.getAccountPassword() && accountNumber == user3.getAccountNumber()) {
                            cout << "Ingrese el monto a retirar: "
                                    "\n1.\t500\n"
                                    "2.\t1000\n"
                                    "3.\t2000\n"
                                    "4.\t4000\n"
                                    "5.\t5000\n"
                                    "6.\tOtra";

                            cin >> opcionRet;

                            switch (opcionRet) {
                                case 1:
                                    user3.withdrawMoney(pin, accountNumber, 500);
                                    bank1.withdraw(500);
                                    break;
                                case 2:
                                    user3.withdrawMoney(pin, accountNumber, 1000);
                                    bank1.withdraw(1000);
                                    break;
                                case 3:
                                    user3.withdrawMoney(pin, accountNumber, 2000);
                                    bank1.withdraw(2000);
                                    break;
                                case 4:
                                    user3.withdrawMoney(pin, accountNumber, 4000);
                                    bank1.withdraw(4000);
                                    break;
                                case 5:
                                    user3.withdrawMoney(pin, accountNumber, 5000);
                                    bank1.withdraw(5000);
                                    break;
                                case 6:
                                    cout << "Ingrese el monto a retirar: ";
                                    cin >> montoRet;
                                    user3.withdrawMoney(pin, accountNumber, montoRet);
                                    bank1.withdraw(montoRet);
                                    break;
                                default:
                                    cout << "Opcion no valida" << endl;
                                    break;
                            }
                        } else {
                            cout << "Pin o numero de tarjeta incorrectos" << endl;
                        }
                        break;
                    default:
                        cout << "Opcion no valida\n";
                        break;
                }
                break;
            default:
                cout << "Opcion invalida";
                break;
        }
    } while (opcion != 0);
}
