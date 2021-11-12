//
// Created by Traed on 11/12/2021.
//

#include "BankAccount.h"

BankAccount::BankAccount(double balance, double minDeposit) {
    this->balance = balance;
    this->minDepositAmt = minDeposit;
    accountID = rand() % 10000000; //Not a good way to generate an ID
}

string BankAccount::ToString() {
    return "AccountID: " + to_string(accountID) + " Balance: " + to_string(balance);
}

int BankAccount::GetAccountID() {
    return accountID;
}

double BankAccount::GetBalance() {
    return balance;
}

bool BankAccount::TransferFunds(double value, BankAccount& otherAccount) {
    if(this->GetBalance() >= value){
        if(otherAccount.GetMinDeposit() <= value){
            this->Withdraw(value);
            otherAccount.Deposit(value);
            cout << "Transfer successful" << endl;
            return true;
        }
        cout << "The amount you have tried to deposit or transfer is too small for this account" << endl;
        return false;
    }
    cout << "Insufficient funds" << endl;
    return false;
}

bool BankAccount::Withdraw(double value) {
    if(balance < value){
        cout << "Insufficient funds" << endl;
        return false;
    }
    balance -= value;
    return true;
}

bool BankAccount::Deposit(double value) {
    if(value < minDepositAmt){
        cout << "The amount you have tried to deposit or transfer is too small for this account" << endl;
        return false;
    }
    balance += value;
    return true;
}

bool BankAccount::SetMinDeposit(double value) {
    if(value < 0){
        cout << "You can not have a negative minimum deposit amount" << endl;
        return false;
    }
    minDepositAmt = value;
    return true;
}

double BankAccount::GetMinDeposit() {
    return minDepositAmt;
}
