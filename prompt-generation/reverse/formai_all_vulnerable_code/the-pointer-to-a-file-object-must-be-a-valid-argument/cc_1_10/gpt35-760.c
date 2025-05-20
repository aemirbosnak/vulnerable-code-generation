//FormAI DATASET v1.0 Category: Data recovery tool ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[50];
    float debt;
} customer;

int main() {
    customer *customer_list;
    int num_customers;

    // get number of customers from user
    printf("How many customers do you want to recover data for? ");
    scanf("%d", &num_customers);

    // allocate memory for customer list
    customer_list = (customer *) malloc(sizeof(customer) * num_customers);

    // read in customer data from file
    FILE *input_file = fopen("customer_data.txt", "r");
    char buffer[100];
    int customer_count = 0;
    while (fgets(buffer, 100, input_file) != NULL && customer_count < num_customers) {
        char *id_string = strtok(buffer, ",");
        char *name_string = strtok(NULL, ",");
        char *debt_string = strtok(NULL, ",");
        if (id_string == NULL || name_string == NULL || debt_string == NULL) {
            printf("Invalid customer data in file.\n");
            exit(1);
        }
        int id = atoi(id_string);
        strcpy(customer_list[customer_count].name, name_string);
        customer_list[customer_count].debt = atof(debt_string);
        customer_list[customer_count].id = id;
        customer_count++;
    }
    fclose(input_file);

    // print out recovered customer data
    printf("Recovered customer data:\n");
    for (int i = 0; i < num_customers; i++) {
        printf("ID: %d, Name: %s, Debt: $%.2f\n", customer_list[i].id, customer_list[i].name, customer_list[i].debt);
    }

    // free allocated memory
    free(customer_list);

    return 0;
}