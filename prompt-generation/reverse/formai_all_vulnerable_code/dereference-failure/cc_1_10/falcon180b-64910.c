//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NUM_RECORDS 100
#define MAX_FIELD_WIDTH 50

typedef struct {
    char *field1;
    char *field2;
    int field3;
} Record;

Record records[MAX_NUM_RECORDS];
int numRecords = 0;

void addRecord() {
    if (numRecords >= MAX_NUM_RECORDS) {
        printf("Error: Maximum number of records reached.\n");
        return;
    }

    Record newRecord;
    newRecord.field1 = (char *) malloc((MAX_FIELD_WIDTH + 1) * sizeof(char));
    if (newRecord.field1 == NULL) {
        printf("Error: Out of memory.\n");
        return;
    }

    newRecord.field2 = (char *) malloc((MAX_FIELD_WIDTH + 1) * sizeof(char));
    if (newRecord.field2 == NULL) {
        printf("Error: Out of memory.\n");
        free(newRecord.field1);
        return;
    }

    newRecord.field3 = 0;

    records[numRecords++] = newRecord;
}

void removeRecord(int index) {
    if (index < 0 || index >= numRecords) {
        printf("Error: Invalid record index.\n");
        return;
    }

    free(records[index].field1);
    free(records[index].field2);

    for (int i = index; i < numRecords - 1; i++) {
        records[i] = records[i + 1];
    }

    numRecords--;
}

void printRecords() {
    printf("Record 1:\n");
    printf("Field 1: %s\n", records[0].field1);
    printf("Field 2: %s\n", records[0].field2);
    printf("Field 3: %d\n\n", records[0].field3);

    for (int i = 1; i < numRecords; i++) {
        printf("Record %d:\n", i + 1);
        printf("Field 1: %s\n", records[i].field1);
        printf("Field 2: %s\n", records[i].field2);
        printf("Field 3: %d\n\n", records[i].field3);
    }
}

int main() {
    addRecord();
    addRecord();
    addRecord();
    printRecords();

    removeRecord(1);
    printRecords();

    return 0;
}