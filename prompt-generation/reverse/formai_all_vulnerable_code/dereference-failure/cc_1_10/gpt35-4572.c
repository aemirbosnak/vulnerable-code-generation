//FormAI DATASET v1.0 Category: Data mining ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct to hold information about a customer
typedef struct {
    int id;
    char name[50];
    double balance;
} Customer;

int main() {
    int num_customers = 5;
    
    // Allocate memory for an array of customers
    Customer* customers = (Customer*) malloc(num_customers * sizeof(Customer));
    
    // Initialize the customers
    customers[0].id = 1001;
    strncpy(customers[0].name, "Alice", 50);
    customers[0].balance = 200.0;
    
    customers[1].id = 1002;
    strncpy(customers[1].name, "Bob", 50);
    customers[1].balance = 1000.5;
    
    customers[2].id = 1003;
    strncpy(customers[2].name, "Charlie", 50);
    customers[2].balance = 500.25;
    
    customers[3].id = 1004;
    strncpy(customers[3].name, "David", 50);
    customers[3].balance = 1500.75;
    
    customers[4].id = 1005;
    strncpy(customers[4].name, "Eve", 50);
    customers[4].balance = 750.0;
    
    // Find the customer with the highest balance
    int max_idx = 0;
    for (int i = 1; i < num_customers; i++) {
        if (customers[i].balance > customers[max_idx].balance) {
            max_idx = i;
        }
    }
    
    // Print out information about the customer with the highest balance
    printf("Customer with highest balance:\n");
    printf("ID: %d\n", customers[max_idx].id);
    printf("Name: %s\n", customers[max_idx].name);
    printf("Balance: $%.2f\n", customers[max_idx].balance);
    
    // Free memory
    free(customers);
    
    return 0;
}