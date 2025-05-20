//LLAMA2-13B DATASET v1.0 Category: Database simulation ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Structure to represent a customer
typedef struct {
    char name[50];
    int age;
    char address[100];
} customer_t;

// Function to create a new customer
customer_t *create_customer(char *name, int age, char *address) {
    customer_t *cust = (customer_t *)malloc(sizeof(customer_t));
    strcpy(cust->name, name);
    cust->age = age;
    strcpy(cust->address, address);
    return cust;
}

// Function to add a customer to the database
void add_customer(customer_t **customers, int num_customers, customer_t *new_cust) {
    int i;
    for (i = 0; i < num_customers; i++) {
        if (strcmp(customers[i]->name, new_cust->name) < 0) {
            break;
        }
    }
    customers[i] = new_cust;
}

// Function to retrieve a customer from the database
customer_t *retrieve_customer(customer_t **customers, int num_customers, char *name) {
    int i;
    for (i = 0; i < num_customers; i++) {
        if (strcmp(customers[i]->name, name) == 0) {
            return customers[i];
        }
    }
    return NULL;
}

// Function to update a customer's information
void update_customer(customer_t **customers, int num_customers, char *name, int age, char *address) {
    customer_t *cust = retrieve_customer(customers, num_customers, name);
    if (cust != NULL) {
        strcpy(cust->address, address);
        cust->age = age;
    }
}

// Function to delete a customer from the database
void delete_customer(customer_t **customers, int num_customers, char *name) {
    int i;
    for (i = 0; i < num_customers; i++) {
        if (strcmp(customers[i]->name, name) == 0) {
            free(customers[i]);
            customers[i] = NULL;
            break;
        }
    }
}

int main() {
    // Create an empty database
    customer_t *customers[10];
    int num_customers = 0;

    // Add some customers to the database
    customer_t *cust1 = create_customer("Alice", 25, "123 Main St");
    customer_t *cust2 = create_customer("Bob", 30, "456 Elm St");
    customer_t *cust3 = create_customer("Charlie", 40, "789 Oak St");
    add_customer(customers, num_customers, cust1);
    add_customer(customers, num_customers, cust2);
    add_customer(customers, num_customers, cust3);

    // Retrieve a customer from the database
    customer_t *cust = retrieve_customer(customers, num_customers, "Alice");
    if (cust != NULL) {
        printf("Found customer: %s %d %s\n", cust->name, cust->age, cust->address);
    } else {
        printf("Customer not found\n");
    }

    // Update a customer's information
    update_customer(customers, num_customers, "Alice", 30, "789 Oak St");

    // Delete a customer from the database
    delete_customer(customers, num_customers, "Bob");

    // Print the updated database
    for (int i = 0; i < num_customers; i++) {
        printf("%d. %s %d %s\n", i + 1, customers[i]->name, customers[i]->age, customers[i]->address);
    }

    return 0;
}