//LLAMA2-13B DATASET v1.0 Category: Database simulation ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a customer
struct customer {
    char name[50];
    int age;
    char address[100];
};

// Function to read customer information from a file
struct customer *read_customer_file(const char *filename) {
    struct customer *customers = NULL;
    int i = 0;
    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error: Unable to open file %s\n", filename);
        return NULL;
    }

    while (fscanf(file, "%s %d %s", customers[i].name, &customers[i].age, customers[i].address) == 3) {
        i++;
    }

    fclose(file);
    return customers;
}

// Function to write customer information to a file
void write_customer_file(const char *filename, struct customer *customers) {
    int i = 0;
    FILE *file = fopen(filename, "w");

    if (file == NULL) {
        printf("Error: Unable to open file %s\n", filename);
        return;
    }

    for (; i < 10; i++) {
        fprintf(file, "%s %d %s\n", customers[i].name, customers[i].age, customers[i].address);
    }

    fclose(file);
}

int main() {
    // Load customers from a file
    struct customer *customers = read_customer_file("customers.dat");

    // Print the customers
    for (int i = 0; i < 10; i++) {
        printf("%d. %s %d %s\n", i + 1, customers[i].name, customers[i].age, customers[i].address);
    }

    // Add a new customer
    struct customer new_customer = {"Alice", 25, "123 Main St."};
    customers = realloc(customers, (10 + 1) * sizeof(struct customer));
    customers[10] = new_customer;

    // Write the customers to a file
    write_customer_file("customers.dat", customers);

    return 0;
}