//FormAI DATASET v1.0 Category: Database Indexing System ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Constants */
#define MAX_NAME_LEN 50
#define NUM_RECORDS 10

/* Structures */
typedef struct Record {
    int id;
    char name[MAX_NAME_LEN];
    int age;
} Record;

/* Prototypes */
void build_index(Record* records[], int num_records);
int find_record(Record* records[], int num_records, int id);

/* Main function */
int main() {
    Record* records[NUM_RECORDS];

    int i;
    for (i = 0; i < NUM_RECORDS; i++) {
        records[i] = (Record*) malloc(sizeof(Record));
        records[i]->id = i;
        sprintf(records[i]->name, "Name%d", i);
        records[i]->age = 10 + i;
    }

    build_index(records, NUM_RECORDS);

    int found_index = find_record(records, NUM_RECORDS, 5);

    if (found_index == -1) {
        printf("Record not found.\n");
    } else {
        printf("Record found at index %d.\n", found_index);
        printf("ID: %d\tName: %s\tAge: %d\n",
        records[found_index]->id,
        records[found_index]->name,
        records[found_index]->age);
    }

    return 0;
}

/* Build the index */
void build_index(Record* records[], int num_records) {
    int i;
    for (i = 0; i < num_records; i++) {
        int id = records[i]->id;
        records[id] = records[i];
    }
}

/* Find a record by ID */
int find_record(Record* records[], int num_records, int id) {
    return (id >= 0 && id < num_records) ? id : -1;
}