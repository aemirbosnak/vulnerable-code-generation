//LLAMA2-13B DATASET v1.0 Category: Database simulation ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Structure to represent a customer
typedef struct {
    char name[50];
    char email[50];
    int age;
} customer_t;

// Function to read data from a file
customer_t *read_data(char *filename) {
    customer_t *customers = NULL;
    int i = 0;
    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        return NULL;
    }

    while (1) {
        char line[100];
        fgets(line, 100, file);
        if (feof(file)) {
            break;
        }

        // Parse the line and extract the name, email, and age
        sscanf(line, "%s %s %d", customers[i].name, customers[i].email, &customers[i].age);

        // Increment the index and allocate memory for the next customer
        i++;
        customers = realloc(customers, (i * sizeof(customer_t)));

        // Check for memory errors
        if (customers == NULL) {
            printf("Memory error\n");
            break;
        }
    }

    fclose(file);
    return customers;
}

// Function to write data to a file
void write_data(customer_t *customers, int count, char *filename) {
    int i = 0;
    FILE *file = fopen(filename, "w");

    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        return;
    }

    for (i = 0; i < count; i++) {
        fprintf(file, "%s %s %d\n", customers[i].name, customers[i].email, customers[i].age);
    }

    fclose(file);
}

int main() {
    // Read data from a file
    customer_t *customers = read_data("customers.txt");

    // Print the data
    for (int i = 0; i < 5; i++) {
        printf("%d. %s %s %d\n", i + 1, customers[i].name, customers[i].email, customers[i].age);
    }

    // Write the data to a new file
    write_data(customers, 10, "new_customers.txt");

    // Free the memory
    free(customers);

    return 0;
}