//FormAI DATASET v1.0 Category: Database simulation ; Style: modular
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Define structure for database
typedef struct {
    int id;
    char name[20];
    int age;
} record;

// Define function to print menu and get user choice
int menu() {
    int choice;
    printf("\nDatabase Simulation\n");
    printf("-------------------\n");
    printf("1. Add record\n");
    printf("2. Display all records\n");
    printf("3. Search record by id\n");
    printf("4. Delete record by id\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    fflush(stdin);
    return choice;
}

// Define function to add record
void addRecord(record **data, int *count) {
    (*count)++;
    *data = (record*)realloc(*data, (*count)*sizeof(record));
    printf("\nEnter record details:\n");
    printf("ID: ");
    scanf("%d", &((*data)[*count-1].id));
    fflush(stdin);
    printf("Name: ");
    fgets((*data)[*count-1].name, 20, stdin);
    (*data)[*count-1].name[strcspn((*data)[*count-1].name, "\n")] = 0;
    printf("Age: ");
    scanf("%d", &((*data)[*count-1].age));
    printf("Record added successfully!\n");
}

// Define function to display all records
void displayRecords(record *data, int count) {
    if (count == 0) {
        printf("\nNo records found.\n");
        return;
    }
    printf("\nAll Records:\n");
    printf("------------\n");
    printf("| %-5s| %-20s| %-5s|\n", "ID", "Name", "Age");
    printf("|-----|--------------------|-----|\n");
    for (int i=0; i<count; i++) {
        printf("| %-5d| %-20s| %-5d|\n", data[i].id, data[i].name, data[i].age);
    }
}

// Define function to search record by id
void searchRecord(record *data, int count, int id) {
    for (int i=0; i<count; i++) {
        if (data[i].id == id) {
            printf("\nRecord found:\n");
            printf("| %-5s| %-20s| %-5s|\n", "ID", "Name", "Age");
            printf("|-----|--------------------|-----|\n");
            printf("| %-5d| %-20s| %-5d|\n", data[i].id, data[i].name, data[i].age);
            return;
        }
    }
    printf("\nRecord not found.\n");
}

// Define function to delete record by id
void deleteRecord(record **data, int *count, int id) {
    int index = -1;
    for (int i=0; i<*count; i++) {
        if ((*data)[i].id == id) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("\nRecord not found.\n");
        return;
    }
    for (int i=index; i<*count; i++) {
        (*data)[i] = (*data)[i+1];
    }
    (*count)--;
    *data = (record*)realloc(*data, (*count)*sizeof(record));
    printf("\nRecord deleted successfully!\n");
}

int main() {
    record *data = NULL;
    int count = 0;
    int choice;
    int id;
    do {
        choice = menu();
        switch(choice) {
            case 1:
                addRecord(&data, &count);
                break;
            case 2:
                displayRecords(data, count);
                break;
            case 3:
                printf("\nEnter record ID to search: ");
                scanf("%d", &id);
                searchRecord(data, count, id);
                break;
            case 4:
                printf("\nEnter record ID to delete: ");
                scanf("%d", &id);
                deleteRecord(&data, &count, id);
                break;
            case 5:
                printf("\nExiting...\n");
                break;
            default:
                printf("\nInvalid choice. Try again.\n");
        }
    } while (choice != 5);
    free(data);
    return 0;
}