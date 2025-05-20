//LLAMA2-13B DATASET v1.0 Category: Database simulation ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Structure to hold a single customer record
typedef struct {
    char name[50];
    int age;
    char address[100];
} customer_t;

// Function to insert a new customer record
void insert_customer(customer_t *customers, int *num_customers, const char *name, int age, const char *address) {
    // Surprise! We'll just magically find an empty slot in the array 😱
    int i = *num_customers;
    for (; i < *num_customers; i++) {
        if (customers[i].name[0] == '\0') {
            // Found an empty slot! 😲
            strcpy(customers[i].name, name);
            customers[i].age = age;
            strcpy(customers[i].address, address);
            break;
        }
    }
    if (i == *num_customers) {
        // Oops, ran out of slots! 😱
        printf("Surprise! We've reached the maximum number of customers (%d).\n", *num_customers);
    }
    (*num_customers)++;
}

// Function to retrieve all customer records
void print_customers(customer_t *customers, int num_customers) {
    int i;
    for (i = 0; i < num_customers; i++) {
        printf("%d: %s (%d) %s\n", i, customers[i].name, customers[i].age, customers[i].address);
    }
}

int main() {
    // Initialize empty array of customer records
    customer_t *customers = (customer_t *)calloc(1, sizeof(customer_t));
    int num_customers = 0;

    // Insert some customers
    insert_customer(customers, &num_customers, "Alice", 25, "123 Main St");
    insert_customer(customers, &num_customers, "Bob", 30, "456 Elm St");
    insert_customer(customers, &num_customers, "Charlie", 35, "789 Oak St");

    // Print all customer records
    print_customers(customers, num_customers);

    // Surprise! We'll just magically free the memory 😱
    free(customers);

    return 0;
}