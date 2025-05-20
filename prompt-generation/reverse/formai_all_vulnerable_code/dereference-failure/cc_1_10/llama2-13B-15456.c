//LLAMA2-13B DATASET v1.0 Category: Database simulation ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for a customer
typedef struct customer {
    char name[50];
    int age;
    double spending;
} customer;

// Define the structure for a transaction
typedef struct transaction {
    char date[20];
    char item[50];
    double amount;
    customer customer;
} transaction;

// Define the structure for a database
typedef struct database {
    customer *customers;
    transaction *transactions;
    int num_customers;
    int num_transactions;
} database;

// Function to insert a new customer into the database
void insert_customer(database *db, char *name, int age) {
    customer *new_customer = (customer *)malloc(sizeof(customer));
    strcpy(new_customer->name, name);
    new_customer->age = age;
    db->customers = realloc(db->customers, (db->num_customers + 1) * sizeof(customer));
    db->customers[db->num_customers] = *new_customer;
    db->num_customers++;
}

// Function to insert a new transaction into the database
void insert_transaction(database *db, char *date, char *item, double amount) {
    transaction *new_transaction = (transaction *)malloc(sizeof(transaction));
    strcpy(new_transaction->date, date);
    strcpy(new_transaction->item, item);
    new_transaction->amount = amount;
    db->transactions = realloc(db->transactions, (db->num_transactions + 1) * sizeof(transaction));
    db->transactions[db->num_transactions] = *new_transaction;
    db->num_transactions++;
}

// Function to print the contents of the database
void print_database(database *db) {
    printf("Customers:\n");
    for (int i = 0; i < db->num_customers; i++) {
        printf("    %s (%d)\n", db->customers[i].name, db->customers[i].age);
    }
    printf("\nTransactions:\n");
    for (int i = 0; i < db->num_transactions; i++) {
        printf("    %s (%f)\n", db->transactions[i].date, db->transactions[i].amount);
    }
}

int main() {
    database db;

    // Insert some customers
    insert_customer(&db, "Alice", 25);
    insert_customer(&db, "Bob", 30);
    insert_customer(&db, "Charlie", 20);

    // Insert some transactions
    insert_transaction(&db, "2022-01-01", "Coffee", 5.00);
    insert_transaction(&db, "2022-01-15", "Sandwich", 10.00);
    insert_transaction(&db, "2022-02-01", "Coffee", 5.00);

    // Print the contents of the database
    print_database(&db);

    return 0;
}