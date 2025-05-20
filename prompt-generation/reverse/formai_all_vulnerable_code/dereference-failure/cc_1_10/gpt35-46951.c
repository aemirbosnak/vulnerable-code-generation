//FormAI DATASET v1.0 Category: Database simulation ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//define a structure for the database
typedef struct{
    int id;
    char name[20];
    char address[50];
    int age;
}Record;

//define a function to display the menu options
void display_menu() {
    printf("\n########################################\n");
    printf("######### Database Simulation #########\n");
    printf("########################################\n\n");
    printf("1. Add a new record\n");
    printf("2. Update an existing record\n");
    printf("3. Delete a record\n");
    printf("4. Display all records\n");
    printf("5. Exit program\n\n");
    printf("Please enter your selection: ");
}

int main() {
    //initialize variables
    int choice = 0, id = 0, i = 0, num_records = 0, record_index = -1;
    char name[20], address[50];
    int age = 0;
    Record *database = NULL;

    //display welcome message and menu
    printf("Welcome to the Database Simulation program!\n");
    display_menu();

    while (1) {
        //get user choice
        scanf("%d", &choice);

        switch (choice) {
            case 1://add a new record
                printf("\nEnter the following information for the new record:\n");
                //get user inputs for the new record
                printf("Enter ID: ");
                scanf("%d", &id);
                printf("Enter Name: ");
                scanf("%s", name);
                printf("Enter Address: ");
                scanf("%s", address);
                printf("Enter Age: ");
                scanf("%d", &age);

                //allocate memory for the new record
                database = (Record*) realloc(database, (num_records + 1) * sizeof(Record));

                //check for allocation error
                if (database == NULL) {
                    printf("Memory allocation error!\n");
                    return 1;
                }

                //add new record to the database
                database[num_records].id = id;
                strcpy(database[num_records].name, name);
                strcpy(database[num_records].address, address);
                database[num_records].age = age;

                printf("\nRecord added successfully!\n\n");

                //increment number of records
                num_records++;

                break;
            case 2://update an existing record
                printf("\nEnter the ID of the record you want to update: ");
                scanf("%d", &id);

                //search the database for the record with the specified ID
                for (i = 0; i < num_records; i++) {
                    if (database[i].id == id) {
                        record_index = i;
                        break;
                    }
                }

                //if record with specified ID is found, prompt user for new values
                if (record_index != -1) {
                    printf("\nThe current values of the record are:\n");
                    printf("ID: %d\nName: %s\nAddress: %s\nAge: %d\n\n", database[record_index].id, database[record_index].name, database[record_index].address, database[record_index].age);

                    printf("Enter new values for the record:\n");
                    printf("Enter Name: ");
                    scanf("%s", name);
                    printf("Enter Address: ");
                    scanf("%s", address);
                    printf("Enter Age: ");
                    scanf("%d", &age);

                    //update the record with the new values
                    strcpy(database[record_index].name, name);
                    strcpy(database[record_index].address, address);
                    database[record_index].age = age;

                    printf("\nRecord updated successfully!\n\n");
                }
                else {
                    printf("\nRecord with specified ID not found!\n\n");
                }

                break;
            case 3://delete a record
                printf("\nEnter the ID of the record you want to delete: ");
                scanf("%d", &id);

                //search the database for the record with the specified ID
                for (i = 0; i < num_records; i++) {
                    if (database[i].id == id) {
                        record_index = i;
                        break;
                    }
                }

                //if record with specified ID is found, delete it
                if (record_index != -1) {
                    //move all records after the deleted record up one index
                    for (i = record_index; i < num_records - 1; i++) {
                        database[i] = database[i + 1];
                    }

                    //decrement number of records
                    num_records--;

                    //reallocate memory to reflect the deleted record
                    database = (Record*) realloc(database, num_records * sizeof(Record));

                    printf("\nRecord deleted successfully!\n\n");
                }
                else {
                    printf("\nRecord with specified ID not found!\n\n");
                }

                break;
            case 4://display all records
                if (num_records == 0) {
                    printf("\nNo records found!\n\n");
                }
                else {
                    printf("\nID\tName\tAddress\tAge\n");
                    printf("-----------------------------------------\n");
                    for (i = 0; i < num_records; i++) {
                        printf("%d\t%s\t%s\t%d\n", database[i].id, database[i].name, database[i].address, database[i].age);
                    }
                    printf("\n");
                }

                break;
            case 5://exit program
                printf("\nThank you for using the Database Simulation program! Goodbye!\n");
                free(database);
                return 0;
            default://invalid input
                printf("\nInvalid input! Please enter a valid selection.\n\n");
                break;
        }

        display_menu();
    }

    return 0;
}