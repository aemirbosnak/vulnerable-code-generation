//FormAI DATASET v1.0 Category: Database Indexing System ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the struct for the database
struct Database {
    int id;
    char name[50];
    int age;
};

// Define the struct for the index table
struct IndexTable {
    int id;
    int offset;
};

// Define the function to add a record to the database
void addRecord(FILE * fp) {
    struct Database record;

    printf("Enter ID: ");
    scanf("%d", &record.id);
    printf("Enter name: ");
    scanf("%s", record.name);
    printf("Enter age: ");
    scanf("%d", &record.age);

    // Move the file pointer to the end of the file
    fseek(fp, 0, SEEK_END);

    // Write the record to the file
    fwrite(&record, sizeof(struct Database), 1, fp);
}

// Define the function to create the index table
void createIndexTable(FILE * fp, FILE * index) {
    int i = 0;
    struct Database record;
    struct IndexTable indexRecord;

    while (fread(&record, sizeof(struct Database), 1, fp)) {
        indexRecord.id = record.id;
        indexRecord.offset = i * sizeof(struct Database);

        // Write the index record to the file
        fwrite(&indexRecord, sizeof(struct IndexTable), 1, index);

        i++;
    }
}

// Define the function to search for a record by ID
void searchByID(FILE * fp, FILE * index) {
    int id, offset;
    struct IndexTable indexRecord;
    struct Database record;

    printf("Enter ID to search for: ");
    scanf("%d", &id);

    // Move the file pointer to the beginning of the index table
    fseek(index, 0, SEEK_SET);

    // Search for the ID in the index table
    while (fread(&indexRecord, sizeof(struct IndexTable), 1, index)) {
        if (indexRecord.id == id) {
            offset = indexRecord.offset;
            break;
        }
    }

    // Move the file pointer to the offset of the record
    fseek(fp, offset, SEEK_SET);

    // Read the record and print it to the console
    fread(&record, sizeof(struct Database), 1, fp);
    printf("Record found:\nID: %d\nName: %s\nAge: %d\n", record.id, record.name, record.age);
}

int main() {
    FILE * fp, * index;

    // Open the database file in binary read/write mode
    fp = fopen("database.bin", "rb+");

    // If the file doesn't exist, create it
    if (fp == NULL) {
        fp = fopen("database.bin", "wb");
        if (fp == NULL) {
            printf("Error creating database file.\n");
            return 1;
        }
    }

    // Open the index file in binary read/write mode
    index = fopen("index.bin", "rb+");

    // If the file doesn't exist, create it and populate the index table
    if (index == NULL) {
        index = fopen("index.bin", "wb");
        if (index == NULL) {
            printf("Error creating index file.\n");
            return 1;
        }
        createIndexTable(fp, index);
    }

    // Display the menu options
    int choice;
    do {
        printf("\n1. Add record\n2. Search by ID\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addRecord(fp);
                createIndexTable(fp, index);
                break;
            case 2:
                searchByID(fp, index);
                break;
            case 3:
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    } while (choice != 3);

    // Close the files
    fclose(fp);
    fclose(index);

    return 0;
}