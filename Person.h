//
// Created by Traed on 11/10/2021.
//

#ifndef CLASSES_PERSON_H
#define CLASSES_PERSON_H

#include "BankAccount.h"
#include <vector>

using namespace std;

class Person {
private:
    string name;
    string address;
    string birthday;
    vector<BankAccount> accounts;

public:
    Person();
    Person(string aName, string anAddress, string birthday);


    void SetName(string aName);
    string GetName();
    void SetAddress(string anAddress);
    string GetAddress();
    string GetBirthday();
    void OpenAccount(BankAccount account);
    bool DepositMoney(double amount, int accountIndex);
    bool WithdrawMoney(double amount, int accountIndex);
    bool TransferMoney(double amount, int fromAccount, int toAccount);
    bool CloseAccount(int accountID);
    string ToString();
    void PrintAccountDetails();

};


#endif //CLASSES_PERSON_H
