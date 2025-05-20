//FormAI DATASET v1.0 Category: Database Indexing System ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Define a structure to represent each record in the database */
typedef struct Record {
    int id;
    char name[50];
    int age;
    char address[100];
} Record;

/* Define a structure to represent the index for the database */
typedef struct Index {
    int id;
    long offset;
} Index;

/* Define a function to add a new record to the database and update the index */
void addRecord(FILE *dbFile, FILE *indexFile, int *count) {
    /* Get input from user for record fields */
    Record r;
    printf("Enter record ID: ");
    scanf("%d", &(r.id));
    printf("Enter name: ");
    scanf("%s", r.name);
    printf("Enter age: ");
    scanf("%d", &(r.age));
    printf("Enter address: ");
    scanf("%s", r.address);

    /* Write record to end of database file */
    long offset = sizeof(Record) * (*count);
    fseek(dbFile, offset, SEEK_SET);
    fwrite(&r, sizeof(Record), 1, dbFile);

    /* Update index file with new index */
    Index i = {r.id, offset};
    fseek(indexFile, sizeof(Index) * (*count), SEEK_SET);
    fwrite(&i, sizeof(Index), 1, indexFile);

    /* Increment count of records in database */
    (*count)++;
}

/* Define a function to find a record by ID and print it to the console */
void findRecordByID(FILE *dbFile, FILE *indexFile, int count) {
    /* Get ID to search for from user input */
    int searchID;
    printf("Enter ID of record to find: ");
    scanf("%d", &searchID);

    /* Binary search the index for the ID */
    int left = 0, right = count - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        Index curIndex;
        fseek(indexFile, sizeof(Index) * mid, SEEK_SET);
        fread(&curIndex, sizeof(Index), 1, indexFile);
        if (curIndex.id == searchID) {
            /* Found the ID in the index, so read the record from the database and print it to the console */
            Record r;
            fseek(dbFile, curIndex.offset, SEEK_SET);
            fread(&r, sizeof(Record), 1, dbFile);
            printf("Record found: ID=%d, Name=%s, Age=%d, Address=%s\n", r.id, r.name, r.age, r.address);
            return;
        } else if (curIndex.id < searchID) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    /* ID not found */
    printf("Record not found.\n");
}

int main() {
    /* Open the database and index files for reading and writing */
    FILE *dbFile = fopen("database.dat", "r+b");
    if (dbFile == NULL) {
        printf("Error: could not open database file.\n");
        return 1;
    }
    FILE *indexFile = fopen("index.dat", "r+b");
    if (indexFile == NULL) {
        printf("Error: could not open index file.\n");
        return 1;
    }

    /* Read the count of records from the database file */
    int count = 0;
    fseek(dbFile, 0, SEEK_END);
    long fileSize = ftell(dbFile);
    if (fileSize % sizeof(Record) == 0) {
        count = fileSize / sizeof(Record);
    }

    /* If the index file is empty, initialize it with the IDs and offsets of each record in the database */
    fseek(indexFile, 0, SEEK_END);
    long indexSize = ftell(indexFile);
    if (indexSize == 0) {
        /* Sort the records in the database by ID */
        for (int i = 0; i < count; i++) {
            for (int j = i + 1; j < count; j++) {
                Record r1, r2;
                fseek(dbFile, i * sizeof(Record), SEEK_SET);
                fread(&r1, sizeof(Record), 1, dbFile);
                fseek(dbFile, j * sizeof(Record), SEEK_SET);
                fread(&r2, sizeof(Record), 1, dbFile);
                if (r1.id > r2.id) {
                    /* Swap the two records */
                    fseek(dbFile, i * sizeof(Record), SEEK_SET);
                    fwrite(&r2, sizeof(Record), 1, dbFile);
                    fseek(dbFile, j * sizeof(Record), SEEK_SET);
                    fwrite(&r1, sizeof(Record), 1, dbFile);
                }
            }
        }

        /* Initialize the index with the IDs and offsets of each record in the database */
        for (int i = 0; i < count; i++) {
            Index curIndex;
            fseek(dbFile, i * sizeof(Record), SEEK_SET);
            fread(&(curIndex.id), sizeof(int), 1, dbFile);
            curIndex.offset = i * sizeof(Record);
            fwrite(&curIndex, sizeof(Index), 1, indexFile);
        }
    }

    /* Allow the user to interact with the database */
    while (1) {
        printf("\n");
        printf("Options:\n");
        printf("  1. Add record\n");
        printf("  2. Find record by ID\n");
        printf("  3. Quit\n");
        printf("Enter choice: ");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addRecord(dbFile, indexFile, &count);
                break;
            case 2:
                findRecordByID(dbFile, indexFile, count);
                break;
            case 3:
                fclose(dbFile);
                fclose(indexFile);
                return 0;
        }
    }
}