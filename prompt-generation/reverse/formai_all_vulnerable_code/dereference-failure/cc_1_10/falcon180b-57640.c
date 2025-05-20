//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 1000
#define MAX_FIELD_SIZE 100

typedef struct {
    char *field1;
    char *field2;
    char *field3;
} Record;

Record database[MAX_RECORDS];
int numRecords = 0;

void addRecord(char *field1, char *field2, char *field3) {
    if (numRecords >= MAX_RECORDS) {
        printf("Database is full!\n");
        return;
    }

    Record *record = &database[numRecords];
    record->field1 = malloc(strlen(field1) + 1);
    strcpy(record->field1, field1);

    record->field2 = malloc(strlen(field2) + 1);
    strcpy(record->field2, field2);

    record->field3 = malloc(strlen(field3) + 1);
    strcpy(record->field3, field3);

    numRecords++;
}

void deleteRecord(int recordId) {
    if (recordId < 0 || recordId >= numRecords) {
        printf("Record not found!\n");
        return;
    }

    Record *record = &database[recordId];

    free(record->field1);
    free(record->field2);
    free(record->field3);

    memset(record, 0, sizeof(Record));
}

void searchRecord(int recordId) {
    if (recordId < 0 || recordId >= numRecords) {
        printf("Record not found!\n");
        return;
    }

    Record *record = &database[recordId];

    printf("Record ID: %d\n", recordId);
    printf("Field 1: %s\n", record->field1);
    printf("Field 2: %s\n", record->field2);
    printf("Field 3: %s\n", record->field3);
}

int main() {
    addRecord("John", "Doe", "25");
    addRecord("Jane", "Doe", "30");
    addRecord("Bob", "Smith", "40");

    searchRecord(0);
    searchRecord(1);
    searchRecord(2);

    deleteRecord(1);

    searchRecord(0);
    searchRecord(1);
    searchRecord(2);

    return 0;
}