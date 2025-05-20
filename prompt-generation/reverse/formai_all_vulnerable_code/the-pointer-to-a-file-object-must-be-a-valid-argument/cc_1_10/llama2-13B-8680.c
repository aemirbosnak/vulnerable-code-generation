//LLAMA2-13B DATASET v1.0 Category: Database simulation ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Structure to represent a customer
struct customer {
    char name[50];
    int age;
    char address[100];
};

// Function to read customer data from a file
struct customer *read_customer_data(FILE *file) {
    struct customer *customer;
    char line[100];

    // Initialize customer pointer to NULL
    customer = NULL;

    // Read line by line from file
    while (fgets(line, 100, file) != NULL) {
        // Tokenize the line into name, age, and address
        char *name = strtok(line, " ");
        int age = atoi(strtok(NULL, " "));
        char *address = strtok(NULL, "\n");

        // Create a new customer struct and fill it with the data
        customer = (struct customer *)malloc(sizeof(struct customer));
        strcpy(customer->name, name);
        customer->age = age;
        strcpy(customer->address, address);

        // Return the customer struct
        return customer;
    }

    // If EOF is reached, return NULL
    return NULL;
}

// Function to write customer data to a file
void write_customer_data(struct customer *customer, FILE *file) {
    char line[100];

    // Tokenize the customer struct into name, age, and address
    sprintf(line, "%s %d %s", customer->name, customer->age, customer->address);

    // Write the line to the file
    fputs(line, file);
}

// Function to simulate a banking system
int main() {
    // Open a file for reading and writing
    FILE *file = fopen("customer_data.txt", "r+");

    // Read the customer data from the file
    struct customer *customer = read_customer_data(file);

    // Simulate a banking transaction
    if (customer != NULL) {
        printf("Customer name: %s, age: %d, address: %s\n", customer->name, customer->age, customer->address);

        // Simulate a deposit transaction
        if (customer->age >= 18) {
            printf("Customer is eligible for a loan\n");
            // Simulate a loan transaction
            if (rand() % 2 == 0) {
                printf("Loan approved! Customer can borrow $1000\n");
                customer->age -= 5;
            } else {
                printf("Loan denied. Customer cannot borrow $1000\n");
            }
        } else {
            printf("Customer is not eligible for a loan\n");
        }

        // Simulate a withdrawal transaction
        if (customer->age >= 25) {
            printf("Customer can withdraw $500\n");
            customer->age -= 5;
        } else {
            printf("Customer cannot withdraw $500\n");
        }

        // Write the updated customer data to the file
        write_customer_data(customer, file);
    } else {
        printf("Error: No customer data found in file\n");
    }

    // Close the file
    fclose(file);

    return 0;
}