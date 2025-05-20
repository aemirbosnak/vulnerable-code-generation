//LLAMA2-13B DATASET v1.0 Category: Database simulation ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_RECORDS 1000
#define MAX_FIELDS 5

// Structure to represent a record
typedef struct {
    int id;
    double x;
    double y;
    double z;
    char name[20];
} record_t;

// Function to generate random records
record_t* generate_records(int num_records) {
    record_t* records = malloc(num_records * sizeof(record_t));
    for (int i = 0; i < num_records; i++) {
        records[i].id = i % 10;
        records[i].x = (double)i / 10.0 + (double)rand() / RAND_MAX * 2 - 1;
        records[i].y = (double)i / 10.0 + (double)rand() / RAND_MAX * 2 - 1;
        records[i].z = (double)i / 10.0 + (double)rand() / RAND_MAX * 2 - 1;
        strcpy(records[i].name, "Record #");
        strcat(records[i].name, (i + 1) < 10 ? "1" : "2");
    }
    return records;
}

// Function to print a record
void print_record(record_t* record) {
    printf("%d (%g, %g, %g) - %s\n", record->id, record->x, record->y, record->z, record->name);
}

// Function to search for a record
record_t* search_record(record_t* records, int num_records, double x, double y, double z) {
    for (int i = 0; i < num_records; i++) {
        if (fabs(records[i].x - x) < 0.1 && fabs(records[i].y - y) < 0.1 && fabs(records[i].z - z) < 0.1) {
            return &records[i];
        }
    }
    return NULL;
}

int main() {
    srand(time(NULL));
    record_t* records = generate_records(MAX_RECORDS);
    int num_records = sizeof(records) / sizeof(records[0]);

    // Search for records
    record_t* found_record = search_record(records, num_records, 2.5, 3.5, 4.5);
    if (found_record != NULL) {
        print_record(found_record);
    } else {
        printf("No records found.\n");
    }

    // Insert a new record
    record_t new_record = {12, 2.5, 3.5, 4.5, "Record #12"};
    records = realloc(records, (num_records + 1) * sizeof(record_t));
    records[num_records] = new_record;
    num_records++;

    // Search for records again
    found_record = search_record(records, num_records, 2.5, 3.5, 4.5);
    if (found_record != NULL) {
        print_record(found_record);
    } else {
        printf("No records found.\n");
    }

    free(records);
    return 0;
}