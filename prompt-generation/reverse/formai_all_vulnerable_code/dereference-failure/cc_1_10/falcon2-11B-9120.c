//Falcon2-11B DATASET v1.0 Category: Database Indexing System ; Style: careful
#include <stdio.h>
#include <stdlib.h>

struct Record {
    char* name;
    char* address;
};

int numRecords = 0;
struct Record records[100];

void addRecord(struct Record* record) {
    records[numRecords] = *record;
    numRecords++;
}

void printRecords() {
    printf("Database Records:\n");
    for (int i = 0; i < numRecords; i++) {
        printf("%d. %s - %s\n", i+1, records[i].name, records[i].address);
    }
}

struct Record* searchRecord(char* name) {
    for (int i = 0; i < numRecords; i++) {
        if (strcmp(records[i].name, name) == 0) {
            return &records[i];
        }
    }
    return NULL;
}

void updateRecord(struct Record* record) {
    record->address = "Updated Address";
}

void deleteRecord(char* name) {
    for (int i = 0; i < numRecords; i++) {
        if (strcmp(records[i].name, name) == 0) {
            for (int j = i; j < numRecords - 1; j++) {
                records[j] = records[j+1];
            }
            numRecords--;
            break;
        }
    }
}

void exitProgram() {
    printf("Program exiting...\n");
    return;
}

int main(void) {
    addRecord(&records[0]);
    addRecord(&records[1]);
    addRecord(&records[2]);

    printRecords();

    struct Record* record = searchRecord("John");
    if (record!= NULL) {
        updateRecord(record);
    }

    deleteRecord("John");

    printRecords();

    exitProgram();

    return 0;
}