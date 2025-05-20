//LLAMA2-13B DATASET v1.0 Category: Database simulation ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Structure to represent a customer
struct customer {
    char name[50];
    char address[100];
    int age;
};

// Function to read customer information from the database
struct customer *read_customer(const char *filename) {
    struct customer *customer = malloc(sizeof(struct customer));
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        return NULL;
    }
    char line[100];
    int age, i;
    for (i = 0; i < 3; i++) {
        fscanf(file, "%s %d %s", line, &age, customer->name + i * 50);
        customer->address[i * 100] = line[0];
    }
    fclose(file);
    return customer;
}

// Function to write customer information to the database
void write_customer(const char *filename, struct customer *customer) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        return;
    }
    char line[100];
    int i;
    for (i = 0; i < 3; i++) {
        sprintf(line, "%s %d %s", customer->name + i * 50, customer->age, customer->address + i * 100);
        fprintf(file, "%s\n", line);
    }
    fclose(file);
}

// Function to main function
int main() {
    struct customer *customer = read_customer("customer_data.txt");
    if (customer == NULL) {
        printf("Error reading customer data\n");
        return 1;
    }
    printf("Customer name: %s\n", customer->name);
    printf("Customer address: %s\n", customer->address);
    printf("Customer age: %d\n", customer->age);

    // Modify customer information
    customer->age++;
    customer->name[0] = 'J';
    customer->address[0] = 'N';

    // Write modified customer information to the database
    write_customer("customer_data.txt", customer);

    return 0;
}