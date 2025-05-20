//LLAMA2-13B DATASET v1.0 Category: Database simulation ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure to store customer information
struct customer {
    char name[20];
    int age;
    char address[50];
};

// Define a function to read customer information from a file
void read_customer(struct customer *customer, FILE *file) {
    char line[100];
    int i = 0;

    while (fgets(line, 100, file)) {
        // Check if the line is a name
        if (strncmp(line, "Name:", 4) == 0) {
            // Read the name
            strcpy(customer->name, line + 4);
        } else if (strncmp(line, "Age:", 3) == 0) {
            // Read the age
            customer->age = atoi(line + 3);
        } else if (strncmp(line, "Address:", 6) == 0) {
            // Read the address
            strcpy(customer->address, line + 6);
        }
        i++;
    }
}

// Define a function to write customer information to a file
void write_customer(struct customer customer, FILE *file) {
    fprintf(file, "Name: %s\n", customer.name);
    fprintf(file, "Age: %d\n", customer.age);
    fprintf(file, "Address: %s\n", customer.address);
}

int main() {
    // Open a file for reading and writing
    FILE *file = fopen("customers.dat", "r+");

    // Read the first customer from the file
    struct customer customer;
    read_customer(&customer, file);

    // Print the customer information
    printf("Name: %s\n", customer.name);
    printf("Age: %d\n", customer.age);
    printf("Address: %s\n", customer.address);

    // Write the customer information back to the file
    write_customer(customer, file);

    // Close the file
    fclose(file);

    return 0;
}