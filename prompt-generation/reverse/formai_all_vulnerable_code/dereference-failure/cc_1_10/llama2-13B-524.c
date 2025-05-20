//LLAMA2-13B DATASET v1.0 Category: Database simulation ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

// Structure to represent a customer
struct customer {
    char name[50];
    char email[50];
    int age;
    int id;
};

// Function to create a new customer
struct customer *new_customer(char *name, char *email, int age) {
    struct customer *customer = (struct customer *)malloc(sizeof(struct customer));
    strcpy(customer->name, name);
    strcpy(customer->email, email);
    customer->age = age;
    customer->id = rand() % 1000;
    return customer;
}

// Function to add a customer to the database
void add_customer(struct customer **customers, int *num_customers, struct customer *new_customer) {
    int i;
    for (i = 0; i < *num_customers; i++) {
        if (strcmp(customers[i]->name, new_customer->name) == 0) {
            // Customer already exists, do nothing
            break;
        }
    }
    if (i == *num_customers) {
        // Customer does not exist, add it to the list
        customers[*num_customers] = new_customer;
        (*num_customers)++;
    }
}

// Function to retrieve a customer from the database
struct customer *get_customer(struct customer **customers, int num_customers, int id) {
    int i;
    for (i = 0; i < num_customers; i++) {
        if (customers[i]->id == id) {
            return customers[i];
        }
    }
    return NULL;
}

// Function to remove a customer from the database
void remove_customer(struct customer **customers, int *num_customers, int id) {
    int i;
    for (i = 0; i < *num_customers; i++) {
        if (customers[i]->id == id) {
            // Found the customer, remove it from the list
            memmove(&customers[i], &customers[i + 1], (*num_customers - i - 1) * sizeof(struct customer));
            (*num_customers)--;
            break;
        }
    }
}

// Function to print all customers in the database
void print_customers(struct customer **customers, int num_customers) {
    int i;
    for (i = 0; i < num_customers; i++) {
        printf("%d. %s %s %d\n", i + 1, customers[i]->name, customers[i]->email, customers[i]->age);
    }
}

int main() {
    struct customer **customers = (struct customer **)malloc(sizeof(struct customer *) * 10);
    int num_customers = 0;

    // Add some customers to the database
    customers[num_customers] = new_customer("John Doe", "john.doe@example.com", 35);
    num_customers++;
    customers[num_customers] = new_customer("Jane Doe", "jane.doe@example.com", 27);
    num_customers++;
    customers[num_customers] = new_customer("Bob Smith", "bob.smith@example.com", 42);
    num_customers++;

    // Retrieve a customer from the database
    struct customer *customer = get_customer(customers, num_customers, 35);
    if (customer != NULL) {
        printf("Found customer: %s %s %d\n", customer->name, customer->email, customer->age);
    } else {
        printf("No customer found\n");
    }

    // Remove a customer from the database
    remove_customer(customers, &num_customers, 35);

    // Print all customers in the database
    print_customers(customers, num_customers);

    // Free memory
    free(customers);

    return 0;
}