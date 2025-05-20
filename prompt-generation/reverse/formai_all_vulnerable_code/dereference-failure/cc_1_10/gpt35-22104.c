//FormAI DATASET v1.0 Category: Data mining ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store information about a customer
typedef struct {
    int customer_id;
    char name[30];
    char address[50];
    char occupation[30];
    int age;
    float income;
    float credit_score;
} customer;

// Function to load customer data from comma-separated value files
int load_customer_data(FILE *csv_file, customer **customers_ptr) {
    char line[1000];
    int num_customers = 0;
    customer *customers = NULL;

    // Read each line of the file
    while (fgets(line, sizeof(line), csv_file)) {
        // Allocate memory for a new customer
        customer *new_customer = (customer*)malloc(sizeof(customer));

        // Parse the line into fields separated by commas
        char *token = strtok(line, ",");
        new_customer->customer_id = atoi(token);

        token = strtok(NULL, ",");
        strcpy(new_customer->name, token);

        token = strtok(NULL, ",");
        strcpy(new_customer->address, token);

        token = strtok(NULL, ",");
        strcpy(new_customer->occupation, token);

        token = strtok(NULL, ",");
        new_customer->age = atoi(token);

        token = strtok(NULL, ",");
        new_customer->income = atof(token);

        token = strtok(NULL, ",");
        new_customer->credit_score = atof(token);

        // Reallocate the customers array to hold the new customer
        customers = (customer*)realloc(customers, (num_customers+1)*sizeof(customer));
        customers[num_customers] = *new_customer;
        num_customers++;

        // Free memory for the new customer
        free(new_customer);
    }

    // Set the customers pointer to point to the customers array
    *customers_ptr = customers;

    return num_customers;
}

// Function to find the average income and credit score of customers with a specified occupation
void analyze_customer_data(customer *customers, int num_customers, char *occupation, float *avg_income, float *avg_credit_score) {
    float total_income = 0.0;
    float total_credit_score = 0.0;
    int num_matching_customers = 0;

    // Iterate through the customers to find matching customers
    for (int i=0; i<num_customers; i++) {
        if (strcmp(customers[i].occupation, occupation) == 0) {
            total_income += customers[i].income;
            total_credit_score += customers[i].credit_score;
            num_matching_customers++;
        }
    }

    // Compute the average income and credit score
    *avg_income = total_income / num_matching_customers;
    *avg_credit_score = total_credit_score / num_matching_customers;
}

int main() {
    // Load customer data from file
    FILE *csv_file = fopen("customers.csv", "r");
    if (csv_file == NULL) {
        printf("Error: could not open file.\n");
        return 1;
    }

    customer *customers = NULL;
    int num_customers = load_customer_data(csv_file, &customers);

    fclose(csv_file);

    // Analyze customer data by occupation
    float avg_income, avg_credit_score;

    analyze_customer_data(customers, num_customers, "Engineer", &avg_income, &avg_credit_score);
    printf("Average income for Engineers: %.2f\n", avg_income);
    printf("Average credit score for Engineers: %.2f\n", avg_credit_score);

    analyze_customer_data(customers, num_customers, "Doctor", &avg_income, &avg_credit_score);
    printf("Average income for Doctors: %.2f\n", avg_income);
    printf("Average credit score for Doctors: %.2f\n", avg_credit_score);

    // Free memory for the customers array
    free(customers);

    return 0;
}