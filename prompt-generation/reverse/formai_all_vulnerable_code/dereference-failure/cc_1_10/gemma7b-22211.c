//Gemma-7B DATASET v1.0 Category: Database simulation ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_RECORD_NUM 100
#define MAX_RECORD_LEN 20

typedef struct Record {
    char name[MAX_RECORD_LEN];
    int age;
    float salary;
} Record;

void initializeRecords(Record **records, int numRecords) {
    for (int i = 0; i < numRecords; i++) {
        records[i] = malloc(sizeof(Record));
        records[i]->name[0] = '\0';
        records[i]->age = 0;
        records[i]->salary = 0.0f;
    }
}

void printRecords(Record **records, int numRecords) {
    for (int i = 0; i < numRecords; i++) {
        printf("Name: %s, Age: %d, Salary: %.2f\n", records[i]->name, records[i]->age, records[i]->salary);
    }
}

int main() {
    Record **records = NULL;
    int numRecords = 0;

    initializeRecords(&records, numRecords);

    // Add some sample records
    records[numRecords++] = malloc(sizeof(Record));
    strcpy(records[numRecords - 1]->name, "John Doe");
    records[numRecords - 1]->age = 25;
    records[numRecords - 1]->salary = 50000.0f;

    records[numRecords++] = malloc(sizeof(Record));
    strcpy(records[numRecords - 1]->name, "Jane Doe");
    records[numRecords - 1]->age = 30;
    records[numRecords - 1]->salary = 60000.0f;

    records[numRecords++] = malloc(sizeof(Record));
    strcpy(records[numRecords - 1]->name, "Peter Pan");
    records[numRecords - 1]->age = 12;
    records[numRecords - 1]->salary = 20000.0f;

    printRecords(records, numRecords);

    // Free the allocated memory
    for (int i = 0; i < numRecords; i++) {
        free(records[i]);
    }
    free(records);

    return 0;
}