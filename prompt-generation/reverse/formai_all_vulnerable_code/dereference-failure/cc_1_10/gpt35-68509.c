//FormAI DATASET v1.0 Category: Banking Record System ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Struct to hold customer data
struct customer{
    char* name; 
    char* account_number;
    float balance;
};

//Function to initialize a new customer
struct customer* create_customer(char* name, char* account_number, float balance){
    struct customer* new_customer = (struct customer*)malloc(sizeof(struct customer));
    new_customer -> name = strdup(name);
    new_customer -> account_number = strdup(account_number);
    new_customer -> balance = balance;
    return new_customer;
}

//Function to deposit money into an account
void deposit(struct customer* customer, float amount){
    customer -> balance += amount;
    printf("New balance for %s: $%.2f\n", customer -> name, customer -> balance);
}

//Function to withdraw money from an account
void withdrawal(struct customer* customer, float amount){
    if(customer -> balance >= amount){
        customer -> balance -= amount;
        printf("New balance for %s: $%.2f\n", customer -> name, customer -> balance);
    }
    else{
        printf("Insufficient funds in %s's account.\n", customer -> name);
    }
}

//Main function to test the program
int main(){
    //Create new customers
    struct customer* customer_one = create_customer("John Smith", "123456789", 5000.00);
    struct customer* customer_two = create_customer("Jane Doe", "987654321", 10000.00);

    //Deposit money into accounts
    deposit(customer_one, 250.00);
    deposit(customer_two, 500.00);

    //Withdraw money from accounts
    withdrawal(customer_one, 1000.00);
    withdrawal(customer_two, 15000.00);

    //Free memory allocated for customers
    free(customer_one -> name);
    free(customer_one -> account_number);
    free(customer_one);
    free(customer_two -> name);
    free(customer_two -> account_number);
    free(customer_two);

    return 0;
}