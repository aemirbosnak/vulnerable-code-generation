//FormAI DATASET v1.0 Category: Banking Record System ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for the customer record.
struct customer {
    int account_number;
    char name[50];
    double balance;
};

// Function prototypes.
void add_customer(struct customer* bank_record, int* num_customers);
void view_customer(struct customer* bank_record, int num_customers);
void search_customer(struct customer* bank_record, int num_customers);
void update_customer(struct customer* bank_record, int num_customers);

// Main function.
int main() {
    // Initialize variables.
    int option, num_customers = 0;
    struct customer* bank_record = NULL;

    // Display menu options.
    printf("Welcome to the Bank Record System\n");
    printf("1. Add Customer\n");
    printf("2. View All Customers\n");
    printf("3. Search for Customer\n");
    printf("4. Update Customer Information\n");
    printf("5. Exit\n");

    do {
        // Prompt user to select an option.
        printf("Enter your option (1-5): ");
        scanf("%d", &option);

        switch(option) {
            case 1:
                add_customer(bank_record, &num_customers);
                break;
            case 2:
                view_customer(bank_record, num_customers);
                break;
            case 3:
                search_customer(bank_record, num_customers);
                break;
            case 4:
                update_customer(bank_record, num_customers);
                break;
            case 5:
                printf("Exiting Bank Record System\n");
                break;
            default:
                printf("Invalid option\n");
                break;
        }
    } while(option != 5);

    // Deallocate memory.
    free(bank_record);

    return 0;
}

// Function to add a customer to the record.
void add_customer(struct customer* bank_record, int* num_customers) {
    // Allocate memory for the new customer.
    struct customer* new_customer = (struct customer*) malloc(sizeof(struct customer));
    if(new_customer == NULL) {
        printf("Error: Unable to allocate memory for new customer\n");
        return;
    }

    // Prompt user for customer information.
    printf("Enter account number: ");
    scanf("%d", &new_customer->account_number);

    printf("Enter name: ");
    getchar(); // Clear input buffer.
    fgets(new_customer->name, 50, stdin);
    new_customer->name[strcspn(new_customer->name, "\n")] = 0; // Remove newline character.

    printf("Enter balance: ");
    scanf("%lf", &new_customer->balance);

    // Increase number of customers.
    *num_customers += 1;

    // Reallocate memory for the updated bank record.
    bank_record = (struct customer*) realloc(bank_record, (*num_customers) * sizeof(struct customer));
    if(bank_record == NULL) {
        printf("Error: Unable to reallocate memory for bank record\n");
        return;
    }

    // Add the new customer to the bank record.
    bank_record[(*num_customers) - 1] = *new_customer;

    // Free memory.
    free(new_customer);

    printf("Customer added successfully\n");
}

// Function to view all customers in the record.
void view_customer(struct customer* bank_record, int num_customers) {
    if(num_customers == 0) {
        printf("No customers in record\n");
        return;
    }

    printf("Account Number | Name                      | Balance\n");
    printf("-----------------------------------------------------\n");
    for(int i = 0; i < num_customers; i++) {
        printf("%-14d | %-25s | $%.2lf\n", bank_record[i].account_number, bank_record[i].name, bank_record[i].balance);
    }
}

// Function to search for a customer in the record.
void search_customer(struct customer* bank_record, int num_customers) {
    if(num_customers == 0) {
        printf("No customers in record\n");
        return;
    }

    int account_number;
    printf("Enter account number to search for: ");
    scanf("%d", &account_number);

    for(int i = 0; i < num_customers; i++) {
        if(bank_record[i].account_number == account_number) {
            printf("Account Number | Name                      | Balance\n");
            printf("-----------------------------------------------------\n");
            printf("%-14d | %-25s | $%.2lf\n", bank_record[i].account_number, bank_record[i].name, bank_record[i].balance);
            return;
        }
    }

    printf("Customer not found\n");
}

// Function to update a customer's information in the record.
void update_customer(struct customer* bank_record, int num_customers) {
    if(num_customers == 0) {
        printf("No customers in record\n");
        return;
    }

    int account_number;
    printf("Enter account number to update: ");
    scanf("%d", &account_number);

    for(int i = 0; i < num_customers; i++) {
        if(bank_record[i].account_number == account_number) {
            printf("Enter new information for customer:\n");

            printf("Name (blank to keep existing name): ");
            getchar(); // Clear input buffer.
            fgets(bank_record[i].name, 50, stdin);
            bank_record[i].name[strcspn(bank_record[i].name, "\n")] = 0; // Remove newline character.

            printf("Balance (0 to keep existing balance): ");
            scanf("%lf", &bank_record[i].balance);

            printf("Customer information updated successfully\n");
            return;
        }
    }

    printf("Customer not found\n");
}