//LLAMA2-13B DATASET v1.0 Category: Database simulation ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Structure to store customer information
typedef struct {
    char name[50];
    char address[100];
    int age;
} customer_t;

// Function to read customer information from database
customer_t *read_customer(int id) {
    // Simulate database access time
    sleep(rand() % 2 + 1);

    // Return customer information
    customer_t *cust = (customer_t *)malloc(sizeof(customer_t));
    strcpy(cust->name, "John Doe");
    strcpy(cust->address, "123 Main St");
    cust->age = 35;
    return cust;
}

// Function to write customer information to database
void write_customer(int id, customer_t *cust) {
    // Simulate database access time
    sleep(rand() % 2 + 1);

    // Write customer information
    char *name = cust->name;
    char *address = cust->address;
    int age = cust->age;

    // Print message to console
    printf("Wrote customer information: %s %s %d\n", name, address, age);
}

// Function to query customer information from database
customer_t *query_customer(int id) {
    // Simulate database access time
    sleep(rand() % 2 + 1);

    // Return customer information
    customer_t *cust = (customer_t *)malloc(sizeof(customer_t));
    strcpy(cust->name, "Jane Doe");
    strcpy(cust->address, "456 Elm St");
    cust->age = 27;
    return cust;
}

int main() {
    // Initialize database
    customer_t *cust1 = read_customer(1);
    customer_t *cust2 = read_customer(2);
    customer_t *cust3 = read_customer(3);

    // Write customer information to database
    write_customer(1, cust1);
    write_customer(2, cust2);
    write_customer(3, cust3);

    // Query customer information from database
    customer_t *query_cust = query_customer(1);

    // Print customer information
    printf("Customer information: %s %s %d\n", query_cust->name, query_cust->address, query_cust->age);

    return 0;
}