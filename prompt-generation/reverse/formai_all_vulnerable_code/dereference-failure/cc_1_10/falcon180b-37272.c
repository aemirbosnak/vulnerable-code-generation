//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    char *key;
    int value;
} Record;

Record database[MAX_SIZE];
int numRecords = 0;

void insertRecord(char *key, int value) {
    if (numRecords >= MAX_SIZE) {
        printf("Error: Database is full\n");
        return;
    }
    Record *newRecord = (Record *)malloc(sizeof(Record));
    newRecord->key = (char *)malloc((strlen(key) + 1) * sizeof(char));
    strcpy(newRecord->key, key);
    newRecord->value = value;
    database[numRecords] = *newRecord;
    numRecords++;
}

void searchRecord(char *key) {
    int i;
    for (i = 0; i < numRecords; i++) {
        if (strcmp(database[i].key, key) == 0) {
            printf("Record found: key = %s, value = %d\n", database[i].key, database[i].value);
            return;
        }
    }
    printf("Record not found\n");
}

int main() {
    char input[100];
    int choice;

    do {
        printf("1. Insert record\n");
        printf("2. Search record\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter key: ");
            scanf("%s", input);
            printf("Enter value: ");
            scanf("%d", &database[numRecords].value);
            insertRecord(input, database[numRecords].value);
            break;
        case 2:
            printf("Enter key to search: ");
            scanf("%s", input);
            searchRecord(input);
            break;
        case 3:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice\n");
        }
    } while (choice!= 3);

    return 0;
}