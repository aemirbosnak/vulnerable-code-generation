//FormAI DATASET v1.0 Category: Banking Record System ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

// Define a structure representing a bank record entry
typedef struct {
    int account_number;
    char customer_name[100];
    float balance;
} BankRecord;

// Define a function for initializing a bank record
void initialize_record(BankRecord *record, int account_number, char *customer_name, float balance) {
    record->account_number = account_number;
    strcpy(record->customer_name, customer_name);
    record->balance = balance;
}

// Define a function for adding a new record to the database
void add_record(BankRecord *database, int *num_records, int account_number, char *customer_name, float balance) {
    initialize_record(&database[*num_records], account_number, customer_name, balance);
    (*num_records)++;
}

// Define a function for finding a record by account number
BankRecord *find_record_by_account_number(BankRecord *database, int num_records, int account_number) {
    for (int i = 0; i < num_records; i++) {
        if (database[i].account_number == account_number) {
            return &database[i];
        }
    }
    return NULL;
}

// Define a function for updating a record
void update_record(BankRecord *database, int num_records, int account_number, float new_balance) {
    BankRecord *record = find_record_by_account_number(database, num_records, account_number);
    if (record != NULL) {
        record->balance = new_balance;
    }
}

// Define a function for printing all the records in the database
void print_database(BankRecord *database, int num_records) {
    printf("Bank Record Database\n");
    printf("Account Number | Customer Name   | Balance\n");
    for (int i = 0; i < num_records; i++) {
        printf("%-14d | %-15s | $%.2f\n", database[i].account_number, database[i].customer_name, database[i].balance);
    }
}

// Main function for testing the database
int main() {
    // Initialize the database with room for 10 records
    BankRecord *database = malloc(10 * sizeof(BankRecord));
    int num_records = 0;
    
    // Add some sample records to the database
    add_record(database, &num_records, 1001, "John Smith", 1000.00);
    add_record(database, &num_records, 1002, "Mary Johnson", 2000.00);
    add_record(database, &num_records, 1003, "Mark Davis", 5000.00);
    
    // Print the original database
    printf("Original Database:\n");
    print_database(database, num_records);
    
    // Update the balance for account 1002
    update_record(database, num_records, 1002, 2500.00);
    
    // Print the updated database
    printf("\nUpdated Database:\n");
    print_database(database, num_records);
    
    // Free the memory allocated for the database
    free(database);
    
    return 0;
}