//LLAMA2-13B DATASET v1.0 Category: Database simulation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_RECORDS 1000
#define MAX_FIELDS 5

// Structure to store a single record
typedef struct {
    char name[50];
    int age;
    float salary;
} record_t;

// Function to create a new record
record_t* new_record(void) {
    record_t* rec = (record_t*) malloc(sizeof(record_t));
    srand(time(NULL));
    int i;
    for (i = 0; i < MAX_FIELDS; i++) {
        switch (i) {
            case 0:
                strcpy(rec->name, "Alice");
                break;
            case 1:
                rec->age = rand() % 50 + 25;
                break;
            case 2:
                rec->salary = (float) rand() / RAND_MAX;
                break;
            default:
                break;
        }
    }
    return rec;
}

// Function to display all records
void display_records(record_t** records) {
    int i;
    for (i = 0; i < MAX_RECORDS; i++) {
        printf("%d: %s, %d, %f\n", i, records[i]->name, records[i]->age, records[i]->salary);
    }
}

int main(void) {
    record_t** records = (record_t**) malloc(MAX_RECORDS * sizeof(record_t*));
    int i;
    for (i = 0; i < MAX_RECORDS; i++) {
        records[i] = new_record();
    }
    display_records(records);
    return 0;
}