//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

// Define the maximum number of records
#define MAX_RECORDS 100

// Define the record structure
typedef struct Record
{
    char name[50];
    int account_number;
    double balance;
} Record;

// Function to insert a record
void insert_record(Record **records, int *num_records)
{
    // Allocate memory for the new record
    Record *new_record = (Record *)malloc(sizeof(Record));

    // Get the record details from the user
    printf("Enter name: ");
    scanf("%s", new_record->name);

    printf("Enter account number: ");
    scanf("%d", &new_record->account_number);

    printf("Enter balance: ");
    scanf("%lf", &new_record->balance);

    // Add the new record to the array
    records[*num_records] = new_record;

    // Increment the number of records
    (*num_records)++;
}

// Function to search for a record
void search_record(Record **records, int num_records, char *name)
{
    // Iterate over the records
    for (int i = 0; i < num_records; i++)
    {
        // Compare the record name with the search name
        if (strcmp(records[i]->name, name) == 0)
        {
            // Print the record details
            printf("Name: %s\n", records[i]->name);
            printf("Account number: %d\n", records[i]->account_number);
            printf("Balance: %.2lf\n", records[i]->balance);
            return;
        }
    }

    // Record not found
    printf("Record not found.\n");
}

// Function to update a record
void update_record(Record **records, int num_records, char *name, double new_balance)
{
    // Iterate over the records
    for (int i = 0; i < num_records; i++)
    {
        // Compare the record name with the search name
        if (strcmp(records[i]->name, name) == 0)
        {
            // Update the record balance
            records[i]->balance = new_balance;

            // Print the updated record details
            printf("Name: %s\n", records[i]->name);
            printf("Account number: %d\n", records[i]->account_number);
            printf("Balance: %.2lf\n", records[i]->balance);
            return;
        }
    }

    // Record not found
    printf("Record not found.\n");
}

int main()
{
    // Create an array of records
    Record *records = NULL;

    // Initialize the number of records
    int num_records = 0;

    // Insert some records
    insert_record(&records, &num_records);
    insert_record(&records, &num_records);
    insert_record(&records, &num_records);

    // Search for a record
    search_record(&records, num_records, "John Doe");

    // Update a record
    update_record(&records, num_records, "Jane Doe", 1000.0);

    // Print the updated record
    search_record(&records, num_records, "Jane Doe");

    return 0;
}