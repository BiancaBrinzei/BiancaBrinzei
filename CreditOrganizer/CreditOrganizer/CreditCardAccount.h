#pragma once
#include "LoyaltyScheme.h"
ref class CreditCardAccount
{
public:
    void SetCreditLimit(double amount);
    bool MakePurchase(double amount);
    void MakeRepayment(double amount);
    void PrintStatement();
    long GetAccountNumber();
    static int GetNumberOfAccounts();
    static CreditCardAccount();
    void RedeemLoyaltyPoints();
    CreditCardAccount(long number, double limit);


private:
    long accountNumber = 12345;
    double currentBalance = 0;
    double creditLimit = 3000;
    static int numberOfAccounts = 0;
    static double interestRate;
    LoyaltyScheme^ scheme;
};