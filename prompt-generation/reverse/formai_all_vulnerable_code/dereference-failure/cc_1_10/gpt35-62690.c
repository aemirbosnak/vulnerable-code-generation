//FormAI DATASET v1.0 Category: Data mining ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

// Structure for a data record
struct Record {
    int id;
    char name[20];
    float value1;
    float value2;
};

int main() {
    // Generate random data records
    int numRecords = 1000;
    struct Record *records = malloc(numRecords * sizeof(struct Record));
    for (int i = 0; i < numRecords; i++) {
        records[i].id = i;
        sprintf(records[i].name, "Record %d", i);
        records[i].value1 = rand() % 100;
        records[i].value2 = rand() % 100;
    }

    // Find the record with the highest value1
    float highestValue1 = 0.0;
    int highestValue1Index = 0;
    for (int i = 0; i < numRecords; i++) {
        if (records[i].value1 > highestValue1) {
            highestValue1 = records[i].value1;
            highestValue1Index = i;
        }
    }

    printf("Record with highest value1:\n");
    printf("ID: %d\nName: %s\nValue 1: %.2f\nValue 2: %.2f\n", 
        records[highestValue1Index].id,
        records[highestValue1Index].name,
        records[highestValue1Index].value1,
        records[highestValue1Index].value2);
    
    // Sort the records by value2 in descending order
    for (int i = 0; i < numRecords-1; i++) {
        for (int j = i+1; j < numRecords; j++) {
            if (records[j].value2 > records[i].value2) {
                struct Record temp = records[i];
                records[i] = records[j];
                records[j] = temp;
            }
        }
    }

    printf("\nRecords sorted by value2 in descending order:\n");
    for (int i = 0; i < numRecords; i++) {
        printf("ID: %d\nName: %s\nValue 1: %.2f\nValue 2: %.2f\n", 
            records[i].id,
            records[i].name,
            records[i].value1,
            records[i].value2);
    }

    // Calculate the average value1
    float totalValue1 = 0.0;
    for (int i = 0; i < numRecords; i++) {
        totalValue1 += records[i].value1;
    }
    float averageValue1 = totalValue1 / numRecords;

    printf("\nAverage value1: %.2f\n", averageValue1);

    // Free memory
    free(records);

    return 0;
}