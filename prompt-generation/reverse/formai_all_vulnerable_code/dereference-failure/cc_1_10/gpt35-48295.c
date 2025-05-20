//FormAI DATASET v1.0 Category: Banking Record System ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_CUSTOMERS 100
#define MAX_TRANSACTIONS 1000

typedef struct {
    char name[50];
    int accountNum;
    double balance;
} Customer;

typedef struct {
    int transID;
    int accountNum;
    double amount;
    char date[20];
} Transaction;

Customer customers[MAX_CUSTOMERS];
Transaction transactions[MAX_TRANSACTIONS];
int numCustomers = 0;
int numTransactions = 0;

void addCustomer(char* name, int accountNum, double balance) {
    if (numCustomers >= MAX_CUSTOMERS) {
        printf("Error: Maximum number of customers reached\n");
        return;
    }
    Customer newCustomer;
    strcpy(newCustomer.name, name);
    newCustomer.accountNum = accountNum;
    newCustomer.balance = balance;
    customers[numCustomers] = newCustomer;
    numCustomers++;
}

void addTransaction(int accountNum, double amount) {
    if (numTransactions >= MAX_TRANSACTIONS) {
        printf("Error: Maximum number of transactions reached\n");
        return;
    }
    Transaction newTransaction;
    newTransaction.transID = rand() % 10000 + 1;
    newTransaction.accountNum = accountNum;
    newTransaction.amount = amount;
    time_t currentTime = time(NULL);
    char* date = ctime(&currentTime);
    date[strlen(date) - 1] = '\0'; //remove newline character
    strcpy(newTransaction.date, date);
    transactions[numTransactions] = newTransaction;
    numTransactions++;
}

void printAllCustomers() {
    printf("%-20s %-15s %s\n", "Name", "Account #", "Balance");
    for (int i = 0; i < numCustomers; i++) {
        printf("%-20s %-15d $%.2f\n", customers[i].name, customers[i].accountNum, customers[i].balance);
    }
}

void printAllTransactions() {
    printf("%-15s %-15s %-10s %s\n", "Trans ID", "Account #", "Amount", "Date");
    for (int i = 0; i < numTransactions; i++) {
        printf("%-15d %-15d $%.2f %s\n", transactions[i].transID, transactions[i].accountNum, transactions[i].amount, transactions[i].date);
    }
}

int main() {
    printf("Welcome to the Cryptic Banking Record System!\n");

    addCustomer("John Doe", 1001, 5000.00);
    addCustomer("Jane Smith", 1002, 2000.00);
    addCustomer("Bob Johnson", 1003, 10000.00);
    addCustomer("Samantha Lee", 1004, 7500.00);

    printf("\nAdded all customers:\n");
    printAllCustomers();

    addTransaction(1001, -1000.00);
    addTransaction(1002, 500.00);
    addTransaction(1003, -2000.00);
    addTransaction(1004, 100.00);

    printf("\nAdded all transactions:\n");
    printAllTransactions();

    return 0;
}