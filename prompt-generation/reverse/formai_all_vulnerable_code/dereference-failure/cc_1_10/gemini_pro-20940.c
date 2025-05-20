//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: intelligent
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Define the maximum number of records
#define MAX_RECORDS 100

// Define the structure of a banking record
struct banking_record {
  char name[50];       // Name of the account holder
  char address[100];    // Address of the account holder
  int age;             // Age of the account holder
  double balance;       // Balance in the account
};

// Function to create a new banking record
struct banking_record *create_record(char *name, char *address, int age, double balance) {
  // Allocate memory for the new record
  struct banking_record *record = malloc(sizeof(struct banking_record));

  // Copy the data into the new record
  strcpy(record->name, name);
  strcpy(record->address, address);
  record->age = age;
  record->balance = balance;

  // Return the new record
  return record;
}

// Function to print a banking record
void print_record(struct banking_record *record) {
  // Print the data in the record
  printf("Name: %s\n", record->name);
  printf("Address: %s\n", record->address);
  printf("Age: %d\n", record->age);
  printf("Balance: %f\n", record->balance);
}

// Function to search for a banking record by name
struct banking_record *search_record(char *name, struct banking_record *records[], int num_records) {
  // Iterate over the records
  for (int i = 0; i < num_records; i++) {
    // Check if the name matches the search term
    if (strcmp(records[i]->name, name) == 0) {
      // Return the record if the name matches
      return records[i];
    }
  }

  // Return NULL if the record is not found
  return NULL;
}

// Function to delete a banking record by name
void delete_record(char *name, struct banking_record *records[], int *num_records) {
  // Find the record to delete
  struct banking_record *record = search_record(name, records, *num_records);

  // If the record is found, delete it
  if (record != NULL) {
    // Free the memory allocated for the record
    free(record);

    // Remove the record from the array
    for (int i = 0; i < *num_records; i++) {
      if (records[i] == record) {
        records[i] = records[*num_records - 1];
        *num_records -= 1;
        break;
      }
    }
  }
}

// Function to update a banking record by name
void update_record(char *name, struct banking_record *records[], int *num_records) {
  // Find the record to update
  struct banking_record *record = search_record(name, records, *num_records);

  // If the record is found, update it
  if (record != NULL) {
    // Get the new data for the record
    char new_name[50];
    char new_address[100];
    int new_age;
    double new_balance;
    printf("Enter the new name: ");
    scanf("%s", new_name);
    printf("Enter the new address: ");
    scanf("%s", new_address);
    printf("Enter the new age: ");
    scanf("%d", &new_age);
    printf("Enter the new balance: ");
    scanf("%lf", &new_balance);

    // Update the data in the record
    strcpy(record->name, new_name);
    strcpy(record->address, new_address);
    record->age = new_age;
    record->balance = new_balance;
  }
}

// Main function
int main() {
  // Create an array of banking records
  struct banking_record *records[MAX_RECORDS];

  // Initialize the number of records to 0
  int num_records = 0;

  // Create some sample records
  records[num_records++] = create_record("John Doe", "123 Main Street", 30, 1000.00);
  records[num_records++] = create_record("Jane Doe", "456 Elm Street", 25, 500.00);
  records[num_records++] = create_record("John Smith", "789 Oak Street", 40, 2000.00);

  // Print the records
  printf("Here are the current records:\n");
  for (int i = 0; i < num_records; i++) {
    print_record(records[i]);
    printf("\n");
  }

  // Search for a record by name
  char search_name[50];
  printf("Enter the name of the account holder to search for: ");
  scanf("%s", search_name);
  struct banking_record *record = search_record(search_name, records, num_records);
  if (record != NULL) {
    printf("Record found:\n");
    print_record(record);
    printf("\n");
  } else {
    printf("Record not found.\n");
  }

  // Delete a record by name
  char delete_name[50];
  printf("Enter the name of the account holder to delete: ");
  scanf("%s", delete_name);
  delete_record(delete_name, records, &num_records);
  printf("Record deleted.\n");

  // Update a record by name
  char update_name[50];
  printf("Enter the name of the account holder to update: ");
  scanf("%s", update_name);
  update_record(update_name, records, &num_records);
  printf("Record updated.\n");

  // Print the updated records
  printf("Here are the updated records:\n");
  for (int i = 0; i < num_records; i++) {
    print_record(records[i]);
    printf("\n");
  }

  return 0;
}