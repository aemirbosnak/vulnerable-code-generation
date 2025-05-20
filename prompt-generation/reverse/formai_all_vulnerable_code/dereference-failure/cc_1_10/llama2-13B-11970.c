//LLAMA2-13B DATASET v1.0 Category: Database simulation ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

// Structure to represent a bank account
struct account {
    int id;
    char name[50];
    double balance;
    double interest_rate;
    time_t last_update;
};

// Function to create a new account
struct account* new_account(int id, char name[50], double balance, double interest_rate) {
    struct account* acc = (struct account*) malloc(sizeof(struct account));
    acc->id = id;
    strcpy(acc->name, name);
    acc->balance = balance;
    acc->interest_rate = interest_rate;
    acc->last_update = time(NULL);
    return acc;
}

// Function to deposit money into an account
void deposit(struct account* acc, double amount) {
    acc->balance += amount;
    acc->last_update = time(NULL);
}

// Function to withdraw money from an account
void withdraw(struct account* acc, double amount) {
    if (acc->balance >= amount) {
        acc->balance -= amount;
        acc->last_update = time(NULL);
    } else {
        printf("Insufficient funds\n");
    }
}

// Function to calculate interest on an account
void calculate_interest(struct account* acc) {
    double interest = acc->balance * acc->interest_rate;
    acc->balance += interest;
    acc->last_update = time(NULL);
}

// Function to print the details of an account
void print_account(struct account* acc) {
    printf("Account ID: %d\n", acc->id);
    printf("Account Name: %s\n", acc->name);
    printf("Balance: %f\n", acc->balance);
    printf("Interest Rate: %f%%\n", acc->interest_rate);
    printf("Last Update: %s\n", ctime(&acc->last_update));
}

// Function to main function
int main() {
    struct account* acc1 = new_account(1, "John Doe", 1000.00, 5.00);
    struct account* acc2 = new_account(2, "Jane Doe", 500.00, 3.50);

    deposit(acc1, 1000.00);
    deposit(acc2, 500.00);

    calculate_interest(acc1);
    calculate_interest(acc2);

    print_account(acc1);
    print_account(acc2);

    withdraw(acc1, 500.00);
    withdraw(acc2, 200.00);

    calculate_interest(acc1);
    calculate_interest(acc2);

    print_account(acc1);
    print_account(acc2);

    return 0;
}