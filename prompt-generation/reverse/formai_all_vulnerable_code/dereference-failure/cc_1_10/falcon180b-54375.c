//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define MAX_FIELD_SIZE 50

typedef struct {
    char *field1;
    char *field2;
    char *field3;
} record_t;

record_t records[MAX_RECORDS];
int num_records = 0;

void add_record(char *field1, char *field2, char *field3) {
    if (num_records >= MAX_RECORDS) {
        printf("Error: maximum number of records reached\n");
        return;
    }

    records[num_records].field1 = malloc(strlen(field1) + 1);
    strcpy(records[num_records].field1, field1);

    records[num_records].field2 = malloc(strlen(field2) + 1);
    strcpy(records[num_records].field2, field2);

    records[num_records].field3 = malloc(strlen(field3) + 1);
    strcpy(records[num_records].field3, field3);

    num_records++;
}

void search_records(char *search_field, char *search_value) {
    int i;
    for (i = 0; i < num_records; i++) {
        if (strcmp(records[i].field1, search_value) == 0) {
            printf("Record found:\n");
            printf("Field 1: %s\n", records[i].field1);
            printf("Field 2: %s\n", records[i].field2);
            printf("Field 3: %s\n", records[i].field3);
        }
    }
}

int main() {
    add_record("John", "Doe", "123 Main St");
    add_record("Jane", "Doe", "456 Elm St");
    add_record("Bob", "Smith", "789 Oak St");

    search_records("Doe", "Doe");
    search_records("Smith", "Smith");
    search_records("Zorblatt", "Zorblatt");

    return 0;
}