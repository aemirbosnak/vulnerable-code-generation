//LLAMA2-13B DATASET v1.0 Category: Database simulation ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Structure to represent a customer
typedef struct {
    char name[50];
    int age;
} customer_t;

// Function to create a new customer
customer_t *create_customer(char *name, int age) {
    customer_t *cust = malloc(sizeof(customer_t));
    strcpy(cust->name, name);
    cust->age = age;
    return cust;
}

// Function to add a customer to the database
void add_customer(customer_t **customers, int num_customers, customer_t *cust) {
    if (num_customers == 0) {
        // Initialize the array with the new customer
        customers[0] = cust;
    } else {
        // Find the last index of the array and add the new customer there
        int i = num_customers - 1;
        while (i >= 0 && strcmp(customers[i]->name, cust->name) < 0) {
            i--;
        }
        customers[i + 1] = cust;
    }
    num_customers++;
}

// Function to retrieve a customer from the database
customer_t *get_customer(customer_t **customers, int num_customers, char *name) {
    int i;
    for (i = 0; i < num_customers; i++) {
        if (strcmp(customers[i]->name, name) == 0) {
            return customers[i];
        }
    }
    return NULL;
}

// Function to print all customers in the database
void print_customers(customer_t **customers, int num_customers) {
    int i;
    for (i = 0; i < num_customers; i++) {
        printf("%s (%d)\n", customers[i]->name, customers[i]->age);
    }
}

int main() {
    // Initialize the database with some sample customers
    customer_t *customers[5] = {
        create_customer("John Doe", 35),
        create_customer("Jane Doe", 27),
        create_customer("Bob Smith", 42),
        create_customer("Alice Johnson", 30),
        create_customer("Mike Brown", 45)
    };
    int num_customers = 5;

    // Add some more customers to the database
    add_customer(customers, num_customers, create_customer("Jim Davis", 29));
    add_customer(customers, num_customers, create_customer("Sarah Taylor", 32));

    // Retrieve a customer from the database
    customer_t *cust = get_customer(customers, num_customers, "John Doe");
    if (cust != NULL) {
        printf("Found customer: %s (%d)\n", cust->name, cust->age);
    } else {
        printf("Customer not found\n");
    }

    // Print all customers in the database
    print_customers(customers, num_customers);

    return 0;
}