//LLAMA2-13B DATASET v1.0 Category: Database simulation ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

// Structure to represent a customer
typedef struct {
    char name[50];
    int age;
    char address[100];
} customer_t;

// Function to create a new customer
customer_t *create_customer(char *name, int age, char *address) {
    customer_t *new_customer = (customer_t *)malloc(sizeof(customer_t));
    strcpy(new_customer->name, name);
    new_customer->age = age;
    strcpy(new_customer->address, address);
    return new_customer;
}

// Function to add a customer to the database
void add_customer(customer_t **customers, int *num_customers, customer_t *new_customer) {
    // Check if the customer already exists in the database
    for (int i = 0; i < *num_customers; i++) {
        if (strcmp(customers[i]->name, new_customer->name) == 0) {
            printf("Error: Customer already exists in the database\n");
            return;
        }
    }

    // Add the new customer to the end of the database
    customers[*num_customers] = new_customer;
    (*num_customers)++;
}

// Function to retrieve all customers who are over 30 years old
customer_t **get_older_customers(customer_t **customers, int *num_customers) {
    // Create a new array to store the older customers
    customer_t **older_customers = (customer_t **)malloc(sizeof(customer_t *) * (*num_customers));

    // Loop through the customers and add those who are over 30 years old to the older_customers array
    for (int i = 0; i < *num_customers; i++) {
        if (customers[i]->age > 30) {
            older_customers[i] = customers[i];
        }
    }

    return older_customers;
}

int main() {
    // Create an array to store the customers
    customer_t **customers = (customer_t **)malloc(sizeof(customer_t *) * 5);

    // Create some sample customers
    customer_t *customer1 = create_customer("John Doe", 25, "123 Main St");
    customer_t *customer2 = create_customer("Jane Doe", 35, "456 Elm St");
    customer_t *customer3 = create_customer("Bob Smith", 40, "789 Oak St");

    // Add the customers to the database
    add_customer(customers, &customers, customer1);
    add_customer(customers, &customers, customer2);
    add_customer(customers, &customers, customer3);

    // Retrieve all customers who are over 30 years old
    customer_t **older_customers = get_older_customers(customers, &customers);

    // Print the older customers
    for (int i = 0; i < 3; i++) {
        printf("Older customer %d: %s %s %d\n", i, older_customers[i]->name, older_customers[i]->address, older_customers[i]->age);
    }

    // Free the memory
    free(customers);

    return 0;
}