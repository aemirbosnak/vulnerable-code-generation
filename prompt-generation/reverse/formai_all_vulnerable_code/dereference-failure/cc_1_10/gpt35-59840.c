//FormAI DATASET v1.0 Category: Banking Record System ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// define constants for program
#define MAX_RECORDS 1000
#define MAX_NAME_LENGTH 50
#define MAX_ADDRESS_LENGTH 100

// define structure for record
typedef struct {
    char accountNumber[10];
    char firstName[MAX_NAME_LENGTH];
    char lastName[MAX_NAME_LENGTH];
    char address[MAX_ADDRESS_LENGTH];
    float balance;
} Record;

// declare functions
void addRecord(Record records[], int *numRecords);
void deleteRecord(Record records[], int *numRecords);
void modifyRecord(Record records[], int *numRecords);
void displayRecords(Record records[], int *numRecords);
void writeToFile(Record records[], int *numRecords);
void readFromFile(Record records[], int *numRecords);

int main() {
    Record records[MAX_RECORDS];
    int numRecords = 0;
    int choice;

    // read data from file if it exists
    readFromFile(records, &numRecords);

    // loop until user exits
    while (1) {
        printf("\nWelcome to the Banking Record System!\n");
        printf("1 - Add a record\n");
        printf("2 - Delete a record\n");
        printf("3 - Modify a record\n");
        printf("4 - Display all records\n");
        printf("5 - Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addRecord(records, &numRecords);
                break;
            case 2:
                deleteRecord(records, &numRecords);
                break;
            case 3:
                modifyRecord(records, &numRecords);
                break;
            case 4:
                displayRecords(records, &numRecords);
                break;
            case 5:
                // write data to file before exiting
                writeToFile(records, &numRecords);
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}

// function to add a new record
void addRecord(Record records[], int *numRecords) {
    char accountNumber[10];
    char firstName[MAX_NAME_LENGTH];
    char lastName[MAX_NAME_LENGTH];
    char address[MAX_ADDRESS_LENGTH];
    float balance;

    // prompt user for data
    printf("\nEnter account number (max 10 digits): ");
    scanf("%s", accountNumber);
    printf("Enter first name: ");
    scanf("%s", firstName);
    printf("Enter last name: ");
    scanf("%s", lastName);
    printf("Enter address: ");
    scanf("%s", address);
    printf("Enter balance: ");
    scanf("%f", &balance);

    // validate input
    if (strlen(accountNumber) > 10) {
        printf("Error: Account number must be 10 digits or less.\n");
        return;
    }
    if (strlen(firstName) > MAX_NAME_LENGTH || strlen(lastName) > MAX_NAME_LENGTH || strlen(address) > MAX_ADDRESS_LENGTH) {
        printf("Error: Name or address is too long.\n");
        return;
    }
    if (balance < 0) {
        printf("Error: Balance cannot be negative.\n");
        return;
    }

    // add record to array
    strcpy(records[*numRecords].accountNumber, accountNumber);
    strcpy(records[*numRecords].firstName, firstName);
    strcpy(records[*numRecords].lastName, lastName);
    strcpy(records[*numRecords].address, address);
    records[*numRecords].balance = balance;
    (*numRecords)++;

    printf("Record added successfully!\n");
}

// function to delete a record
void deleteRecord(Record records[], int *numRecords) {
    char accountNumber[10];
    int i, found = 0;

    // prompt user for account number to delete
    printf("\nEnter account number to delete: ");
    scanf("%s", accountNumber);

    // search for record with matching account number
    for (i = 0; i < *numRecords; i++) {
        if (strcmp(records[i].accountNumber, accountNumber) == 0) {
            found = 1;
            break;
        }
    }

    if (found) {
        // remove record from array
        for (; i < *numRecords - 1; i++) {
            records[i] = records[i+1];
        }
        (*numRecords)--;
        printf("Record deleted successfully!\n");
    } else {
        printf("Record not found.\n");
    }
}

// function to modify a record
void modifyRecord(Record records[], int *numRecords) {
    char accountNumber[10];
    int i, found = 0;
    char choice;
    char firstName[MAX_NAME_LENGTH];
    char lastName[MAX_NAME_LENGTH];
    char address[MAX_ADDRESS_LENGTH];
    float balance;

    // prompt user for account number to modify
    printf("\nEnter account number to modify: ");
    scanf("%s", accountNumber);

    // search for record with matching account number
    for (i = 0; i < *numRecords; i++) {
        if (strcmp(records[i].accountNumber, accountNumber) == 0) {
            found = 1;
            break;
        }
    }

    if (found) {
        // prompt user for changes
        printf("\nRecord found:\n");
        printf("Account number: %s\n", records[i].accountNumber);
        printf("First name: %s\n", records[i].firstName);
        printf("Last name: %s\n", records[i].lastName);
        printf("Address: %s\n", records[i].address);
        printf("Balance: %.2f\n", records[i].balance);
        printf("\nWhich field would you like to modify?\n");
        printf("1 - First name\n");
        printf("2 - Last name\n");
        printf("3 - Address\n");
        printf("4 - Balance\n");
        printf("5 - Cancel\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        switch (choice) {
            case '1':
                printf("Enter new first name: ");
                scanf("%s", firstName);
                if (strlen(firstName) > MAX_NAME_LENGTH) {
                    printf("Error: Name is too long.\n");
                    return;
                }
                strcpy(records[i].firstName, firstName);
                printf("Record modified successfully!\n");
                break;
            case '2':
                printf("Enter new last name: ");
                scanf("%s", lastName);
                if (strlen(lastName) > MAX_NAME_LENGTH) {
                    printf("Error: Name is too long.\n");
                    return;
                }
                strcpy(records[i].lastName, lastName);
                printf("Record modified successfully!\n");
                break;
            case '3':
                printf("Enter new address: ");
                scanf("%s", address);
                if (strlen(address) > MAX_ADDRESS_LENGTH) {
                    printf("Error: Address is too long.\n");
                    return;
                }
                strcpy(records[i].address, address);
                printf("Record modified successfully!\n");
                break;
            case '4':
                printf("Enter new balance: ");
                scanf("%f", &balance);
                if (balance < 0) {
                    printf("Error: Balance cannot be negative.\n");
                    return;
                }
                records[i].balance = balance;
                printf("Record modified successfully!\n");
                break;
            case '5':
                printf("No changes made.\n");
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    } else {
        printf("Record not found.\n");
    }
}

// function to display all records
void displayRecords(Record records[], int *numRecords) {
    int i;

    if (*numRecords == 0) {
        printf("\nNo records found.\n");
    } else {
        printf("\n%-15s %-15s %-15s %-20s %s\n", "Account Number", "First Name", "Last Name", "Address", "Balance");
        for (i = 0; i < *numRecords; i++) {
            printf("%-15s %-15s %-15s %-20s $%.2f\n", records[i].accountNumber, records[i].firstName, records[i].lastName, records[i].address, records[i].balance);
        }
    }
}

// function to write records to file
void writeToFile(Record records[], int *numRecords) {
    FILE *fptr;
    int i;

    // open file for writing
    fptr = fopen("records.txt", "w");

    if (fptr != NULL) {
        // write each record to file
        for (i = 0; i < *numRecords; i++) {
            fprintf(fptr, "%s;%s;%s;%s;%.2f\n", records[i].accountNumber, records[i].firstName, records[i].lastName, records[i].address, records[i].balance);
        }
        fclose(fptr);
        printf("Records saved to file.\n");
    } else {
        printf("Error: Failed to save records to file.\n");
    }
}

// function to read records from file
void readFromFile(Record records[], int *numRecords) {
    char line[200], *token;
    char accountNumber[10];
    char firstName[MAX_NAME_LENGTH];
    char lastName[MAX_NAME_LENGTH];
    char address[MAX_ADDRESS_LENGTH];
    float balance;
    FILE *fptr;

    // open file for reading
    fptr = fopen("records.txt", "r");

    if (fptr != NULL) {
        // read each line from file and create record
        while (fgets(line, sizeof(line), fptr) != NULL) {
            token = strtok(line, ";");
            strcpy(accountNumber, token);
            token = strtok(NULL, ";");
            strcpy(firstName, token);
            token = strtok(NULL, ";");
            strcpy(lastName, token);
            token = strtok(NULL, ";");
            strcpy(address, token);
            token = strtok(NULL, ";");
            balance = atof(token);
            strcpy(records[*numRecords].accountNumber, accountNumber);
            strcpy(records[*numRecords].firstName, firstName);
            strcpy(records[*numRecords].lastName, lastName);
            strcpy(records[*numRecords].address, address);
            records[*numRecords].balance = balance;
            (*numRecords)++;
        }
        fclose(fptr);
        printf("%d records loaded from file.\n", *numRecords);
    }
}