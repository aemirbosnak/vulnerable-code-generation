//Falcon2-11B DATASET v1.0 Category: Database simulation ; Style: cheerful
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char name[50];
    int age;
    char address[100];
} Record;

int main() {
    // Create an array to store records
    Record records[5];

    // Initialize the array
    int i;
    for (i = 0; i < 5; i++) {
        strcpy(records[i].name, "Record");
        records[i].age = i + 1;
        strcpy(records[i].address, "Happy Street");
    }

    // Print the records
    printf("Database Simulation\n");
    printf("=======================================\n");
    printf("| Name | Age | Address |\n");
    printf("=======================================\n");
    printf("| %s | %d | %s |\n", records[0].name, records[0].age, records[0].address);
    printf("| %s | %d | %s |\n", records[1].name, records[1].age, records[1].address);
    printf("| %s | %d | %s |\n", records[2].name, records[2].age, records[2].address);
    printf("| %s | %d | %s |\n", records[3].name, records[3].age, records[3].address);
    printf("| %s | %d | %s |\n", records[4].name, records[4].age, records[4].address);
    printf("=======================================\n");

    // Add a new record
    Record newRecord;
    strcpy(newRecord.name, "Happy");
    newRecord.age = 10;
    strcpy(newRecord.address, "Street");
    strcpy(records[5].name, newRecord.name);
    strcpy(records[5].address, newRecord.address);

    // Print the updated records
    printf("=======================================\n");
    printf("| Name | Age | Address |\n");
    printf("=======================================\n");
    printf("| %s | %d | %s |\n", records[0].name, records[0].age, records[0].address);
    printf("| %s | %d | %s |\n", records[1].name, records[1].age, records[1].address);
    printf("| %s | %d | %s |\n", records[2].name, records[2].age, records[2].address);
    printf("| %s | %d | %s |\n", records[3].name, records[3].age, records[3].address);
    printf("| %s | %d | %s |\n", records[4].name, records[4].age, records[4].address);
    printf("| %s | %d | %s |\n", records[5].name, records[5].age, records[5].address);
    printf("=======================================\n");

    return 0;
}