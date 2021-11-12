//
// Created by Traed on 11/10/2021.
//

#include "Person.h"

Person::Person(string aName, string anAddress, string birthday) {
    name = aName;
    address = anAddress;
    this->birthday = birthday; //if names are the same must use the reserved word 'this'
}

Person::Person() {
    name = "none";
    address = "none";
    birthday = "none";
}

void Person::SetName(string aName) {
    name = aName;
}

string Person::GetName() {
    return name;
}

void Person::SetAddress(string anAddress) {
    address = anAddress;
}

string Person::GetAddress() {
    return address;
}

string Person::GetBirthday() {
    return birthday;
}

void Person::OpenAccount(BankAccount account) {
    accounts.push_back(account);
}

bool Person::CloseAccount(int accountID) {
    for(int i = 0; i < accounts.size(); i++){
        if(accounts.at(i).GetAccountID() == accountID && accounts.at(i).GetBalance() < 0.01){
            accounts.erase(accounts.begin() + i);
            return true;
        }
    }
    return false;
}

string Person::ToString() {
    return name + " was born on " + birthday + " and lives at " + address + ".";
}

void Person::PrintAccountDetails() {
    for (int i = 0; i < accounts.size(); ++i) {
        cout << accounts.at(i).ToString() << endl;
    }
}

bool Person::DepositMoney(double amount, int accountIndex) {
    return accounts.at(accountIndex).Deposit(amount);
}

bool Person::WithdrawMoney(double amount, int accountIndex) {
    return accounts.at(accountIndex).Withdraw(amount);
}

bool Person::TransferMoney(double amount, int fromAccount, int toAccount) {
    return accounts.at(fromAccount).TransferFunds(amount, accounts.at(toAccount));
}


