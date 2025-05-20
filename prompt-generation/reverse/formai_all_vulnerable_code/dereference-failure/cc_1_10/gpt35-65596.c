//FormAI DATASET v1.0 Category: Data mining ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define structure to hold customer data
typedef struct {
    int customer_id;
    char name[30];
    int age;
    float total_spent;
} customer;

int main() {
    // read input file
    FILE *fp;
    fp = fopen("customer_data.txt", "r");

    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    // create array to hold customer data
    customer customers[100];

    int i = 0;
    char line[100];

    while (fgets(line, sizeof(line), fp)) {
        // tokenize line to get customer data
        char *token = strtok(line, ":");
        customers[i].customer_id = atoi(token);

        token = strtok(NULL, ":");
        strcpy(customers[i].name, token);

        token = strtok(NULL, ":");
        customers[i].age = atoi(token);

        token = strtok(NULL, ":");
        customers[i].total_spent = atof(token);

        i++;
    }

    fclose(fp);

    // calculate average age and total spent
    int num_customers = i;
    int total_age = 0;
    float total_spent = 0;

    for (i = 0; i < num_customers; i++) {
        total_age += customers[i].age;
        total_spent += customers[i].total_spent;
    }

    float avg_age = (float)total_age / num_customers;
    float avg_spent = total_spent / num_customers;

    printf("Average age of customers: %.2f\n", avg_age);
    printf("Average amount spent by customers: $%.2f\n", avg_spent);

    // find customers with total spent above average
    printf("Customers who spent above the average:\n");

    for (i = 0; i < num_customers; i++) {
        if (customers[i].total_spent > avg_spent) {
            printf("%d %s\n", customers[i].customer_id, customers[i].name);
        }
    }

    return 0;
}