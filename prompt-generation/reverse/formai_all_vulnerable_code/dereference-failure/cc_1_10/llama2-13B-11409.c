//LLAMA2-13B DATASET v1.0 Category: Database simulation ; Style: authentic
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

// Function to display all customers
void display_customers(customer_t *customers[]) {
    int i;
    for (i = 0; i < 10; i++) {
        printf("%d: %s, %d years old, %s\n", i, customers[i]->name, customers[i]->age, customers[i]->address);
    }
}

// Function to add a new customer
void add_customer(customer_t *customers[], int age, char *name, char *address) {
    customer_t *new_cust = create_customer(name, age, address);
    int i;
    for (i = 0; i < 10; i++) {
        if (strcmp(customers[i]->name, "") == 0) {
            break;
        }
    }
    if (i == 10) {
        printf("Database full, cannot add new customer\n");
        return;
    }
    customers[i] = new_cust;
    printf("New customer added: %d: %s, %d years old, %s\n", i, new_cust->name, new_cust->age, new_cust->address);
}

// Function to remove a customer
void remove_customer(customer_t *customers[], int index) {
    if (index < 0 || index >= 10) {
        printf("Invalid index\n");
        return;
    }
    if (customers[index] == NULL) {
        printf("Customer not found\n");
        return;
    }
    int i;
    for (i = index; i < 10; i++) {
        customers[i] = customers[i + 1];
    }
    free(customers[0]);
    customers[0] = NULL;
    printf("Customer removed: %d: %s, %d years old, %s\n", index, customers[0]->name, customers[0]->age, customers[0]->address);
}

int main() {
    customer_t *customers[10];
    srand(time(NULL));
    for (int i = 0; i < 10; i++) {
        char *name = (char *)malloc(50 * sizeof(char));
        int age = rand() % 50 + 1;
        char *address = (char *)malloc(100 * sizeof(char));
        snprintf(name, 50, "Customer %d", i);
        snprintf(address, 100, "Address %d", i);
        customers[i] = create_customer(name, age, address);
    }
    display_customers(customers);
    for (int i = 0; i < 10; i++) {
        add_customer(customers, 25, "John", "123 Main St");
    }
    for (int i = 0; i < 10; i++) {
        remove_customer(customers, i);
    }
    return 0;
}