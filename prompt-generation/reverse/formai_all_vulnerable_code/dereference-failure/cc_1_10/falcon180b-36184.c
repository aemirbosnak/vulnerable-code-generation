//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 1000
#define MAX_FIELD_LENGTH 100

typedef struct {
    char *field1;
    char *field2;
    char *field3;
} Record;

Record records[MAX_RECORDS];
int num_records = 0;

void init() {
    num_records = 0;
}

void add_record(char *field1, char *field2, char *field3) {
    if (num_records >= MAX_RECORDS) {
        printf("Error: Maximum number of records reached.\n");
        return;
    }

    Record *record = &records[num_records];
    record->field1 = strdup(field1);
    record->field2 = strdup(field2);
    record->field3 = strdup(field3);
    num_records++;
}

void print_record(int index) {
    if (index < 0 || index >= num_records) {
        printf("Error: Invalid record index.\n");
        return;
    }

    Record *record = &records[index];
    printf("Record %d:\n", index + 1);
    printf("Field 1: %s\n", record->field1);
    printf("Field 2: %s\n", record->field2);
    printf("Field 3: %s\n", record->field3);
}

void search_records(char *field1_value, char *field2_value, char *field3_value) {
    int matches = 0;

    for (int i = 0; i < num_records; i++) {
        Record *record = &records[i];

        if (field1_value && strcmp(record->field1, field1_value)) {
            continue;
        }

        if (field2_value && strcmp(record->field2, field2_value)) {
            continue;
        }

        if (field3_value && strcmp(record->field3, field3_value)) {
            continue;
        }

        matches++;
        print_record(i);
    }

    if (!matches) {
        printf("No matching records found.\n");
    }
}

int main() {
    init();

    add_record("John", "Doe", "25");
    add_record("Jane", "Doe", "30");
    add_record("Bob", "Smith", "40");

    print_record(0);
    print_record(1);
    print_record(2);

    search_records("John", "Doe", "25");
    search_records("Jane", NULL, "30");
    search_records("Bob", "Smith", "40");

    return 0;
}