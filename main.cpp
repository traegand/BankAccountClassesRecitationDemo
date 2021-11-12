
#include "Person.h"

using namespace std;

int main() {
    Person greg("Greg", "142 Lane", "January 1, 1970");

    greg.OpenAccount(BankAccount());
    greg.OpenAccount(BankAccount(5000));
    greg.OpenAccount(BankAccount(2000, 50));

    greg.TransferMoney(49, 1, 2);
    greg.TransferMoney(50, 1,2);
    greg.PrintAccountDetails();

    greg.DepositMoney(150, 0);
    greg.WithdrawMoney(2200, 2);
    greg.PrintAccountDetails();

    greg.TransferMoney(2000, 2, 0);
    cout << greg.ToString() << endl;
    greg.PrintAccountDetails();

    if(!greg.CloseAccount(41)) {//Should fail because there are still funds in the account
        cout << "Failed to close account." << endl;
    }
    greg.PrintAccountDetails();
    greg.TransferMoney(2150, 0, 2);
    greg.CloseAccount(41); // Will work this time because balance is 0.
    greg.PrintAccountDetails();

    return 0;
}











































/*
 * OpenAccount() -- Add an account to the list of accounts
	CloseAccount(string AccountID) -- remove an account from the list (the account must have a balance of 0)
	SetName(string newName)
	SetAddress(string newAddress)
	GetAge() -- returns the Age of the Person based on birthday
	GetName()
	GetAddress()
	Person() -- Sets all values to null
	Person(string name, string address, string birthday)
 */