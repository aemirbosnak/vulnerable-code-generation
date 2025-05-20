//FormAI DATASET v1.0 Category: Database querying ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct record {
    int id;
    char name[50];
    char occupation[50];
    int age;
} Record;

int main() {
    FILE *database;
    database = fopen("cyberpunk.db", "rb");
    
    if (!database) {
        printf("Error opening database!\n");
        exit(1);
    }
    
    Record *records = malloc(sizeof(Record) * 100);
    int num_records = 0;
    
    while (fread(&records[num_records], sizeof(Record), 1, database)) {
        num_records++;
    }
    
    printf("Number of records: %d\n", num_records);
    
    // Query for all records where occupation is "hacker"
    printf("Hacker Records:\n");
    for (int i = 0; i < num_records; i++) {
        if (strcmp(records[i].occupation, "hacker") == 0) {
            printf("ID: %d\nName: %s\nOccupation: %s\nAge: %d\n\n", records[i].id, records[i].name, records[i].occupation, records[i].age);
        }
    }
    
    // Query for all records where age is greater than or equal to 30 and occupation is "cyber-enhanced mercenary"
    printf("Cyber-Enhanced Mercenary Records:\n");
    for (int i = 0; i < num_records; i++) {
        if (records[i].age >= 30 && strcmp(records[i].occupation, "cyber-enhanced mercenary") == 0) {
            printf("ID: %d\nName: %s\nOccupation: %s\nAge: %d\n\n", records[i].id, records[i].name, records[i].occupation, records[i].age);
        }
    }
    
    free(records);
    fclose(database);
    
    return 0;
}