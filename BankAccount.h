//
// Created by Traed on 11/12/2021.
//

#ifndef CLASSES_BANKACCOUNT_H
#define CLASSES_BANKACCOUNT_H

#include <string>
#include <cstdlib>
#include <iostream>

using namespace std;

class BankAccount {
private:
    int accountID;
    double minDepositAmt;
    double balance;

public:
    bool Deposit(double value);
    bool SetMinDeposit(double value);
    double GetMinDeposit();
    bool Withdraw(double value);
    bool TransferFunds(double value, BankAccount& otherAccount);
    double GetBalance();
    int GetAccountID();
    BankAccount(double balance = 0, double minDeposit = 0);
    string ToString();
};


#endif //CLASSES_BANKACCOUNT_H
