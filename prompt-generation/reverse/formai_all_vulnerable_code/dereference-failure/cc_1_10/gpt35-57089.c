//FormAI DATASET v1.0 Category: Banking Record System ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Transaction { // Transaction struct to hold transaction data
  char type[20];
  double amount;
  char date[15];
};

struct Account { // Account struct to hold account data
  char name[50];
  char address[100];
  char phone[15];
  double balance;
  struct Transaction* transactions; // dynamic array to hold transaction history
  int numTransactions; // number of transactions
};

void deposit(struct Account* account, double amount, char* date) { // deposit function
  account->balance += amount; // increase account balance
  account->numTransactions++; // increment number of transactions
  account->transactions = realloc(account->transactions, account->numTransactions * sizeof(struct Transaction)); // resize transactions array
  struct Transaction deposit = {"Deposit", amount, date}; // create new transaction struct
  account->transactions[account->numTransactions - 1] = deposit; // add new transaction to end of array   
}

void withdraw(struct Account* account, double amount, char* date) { // withdraw function
  if(account->balance < amount) { // check if sufficient funds
    printf("Insufficient funds\n");
    return;
  }
  account->balance -= amount; // decrease account balance
  account->numTransactions++; // increment number of transactions
  account->transactions = realloc(account->transactions, account->numTransactions * sizeof(struct Transaction)); // resize transactions array
  struct Transaction withdrawal = {"Withdrawal", amount, date}; // create new transaction struct
  account->transactions[account->numTransactions - 1] = withdrawal; // add new transaction to end of array   
}

void displayTransaction(struct Transaction* transaction) { // display transaction function
  printf("%-12s %-8.2lf %s\n", transaction->type, transaction->amount, transaction->date); // print transaction details
}

void displayHistory(struct Account* account) { // display transaction history function
  printf("\n%s's Transaction History\n\n", account->name); // print account holder name
  printf("%-12s %-8s %-10s\n", "Type", "Amount", "Date"); // print table header
  for(int i = 0; i < account->numTransactions; i++) { // loop through each transaction
    displayTransaction(&account->transactions[i]); // display transaction
  } 
}

int main() {
  struct Account account = {"John Doe", "123 Main St", "555-1234", 100.00, NULL, 0}; // create new account
  char date[15];
  
  deposit(&account, 50.00, "2021-04-01"); // add deposit transaction
  deposit(&account, 25.00, "2021-04-05"); // add deposit transaction
  withdraw(&account, 75.00, "2021-04-10"); // add withdrawal transaction
  
  printf("%s's current balance is %.2lf\n", account.name, account.balance); // print current balance
  displayHistory(&account); // display transaction history
  
  return 0;
}