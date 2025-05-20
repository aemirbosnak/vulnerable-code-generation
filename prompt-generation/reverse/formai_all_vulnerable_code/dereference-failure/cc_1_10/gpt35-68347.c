//FormAI DATASET v1.0 Category: Data mining ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for storing transaction data
typedef struct Transaction {
    int transaction_id;
    float amount;
    char description[100];
} Transaction;

// Structure for storing customer data
typedef struct Customer {
    int customer_id;
    char name[50];
    char email[50];
    int num_transactions;
    Transaction *transactions; // Dynamic array of transaction data
} Customer;

// Function to read customer data from a file
Customer* read_customer_data(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("Error: could not open file %s\n", filename);
        return NULL;
    }

    int num_customers;
    fscanf(file, "%d\n", &num_customers);

    Customer *customers = (Customer*) malloc(num_customers * sizeof(Customer));

    for (int i = 0; i < num_customers; i++) {
        int customer_id;
        fscanf(file, "%d\n", &customer_id);

        char name[50];
        fscanf(file, "%s\n", name);

        char email[50];
        fscanf(file, "%s\n", email);

        int num_transactions;
        fscanf(file, "%d\n", &num_transactions);

        Transaction *transactions = (Transaction*) malloc(num_transactions * sizeof(Transaction));
        for (int j = 0; j < num_transactions; j++) {
            int transaction_id;
            fscanf(file, "%d\n", &transaction_id);

            float amount;
            fscanf(file, "%f\n", &amount);

            char description[100];
            fscanf(file, "%[^\n]s\n", description);

            transactions[j].transaction_id = transaction_id;
            transactions[j].amount = amount;
            strcpy(transactions[j].description, description);
        }

        customers[i].customer_id = customer_id;
        strcpy(customers[i].name, name);
        strcpy(customers[i].email, email);
        customers[i].num_transactions = num_transactions;
        customers[i].transactions = transactions;
    }

    fclose(file);
    return customers;
}

// Function to perform data mining on customer transaction data
void data_mine(Customer *customers, int num_customers) {
    for (int i = 0; i < num_customers; i++) {
        float total_spent = 0.0;
        int num_high_transactions = 0;

        for (int j = 0; j < customers[i].num_transactions; j++) {
            float amount = customers[i].transactions[j].amount;
            total_spent += amount;

            if (amount > 100.0) {
                num_high_transactions++;
            }
        }

        float avg_spent = total_spent / customers[i].num_transactions;
        printf("Customer %d (%s) spent $%.2f on average, with %d transactions over $100\n", customers[i].customer_id, customers[i].name, avg_spent, num_high_transactions);
    }
}

int main() {
    Customer *customers = read_customer_data("customer_data.txt");
    if (!customers) {
        return 1;
    }

    data_mine(customers, 3);

    // Free memory used by transaction data
    for (int i = 0; i < 3; i++) {
        free(customers[i].transactions);
    }
    // Free memory used by customer data
    free(customers);

    return 0;
}