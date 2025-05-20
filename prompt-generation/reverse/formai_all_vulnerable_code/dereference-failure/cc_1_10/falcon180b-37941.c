//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: futuristic
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

record_t database[MAX_RECORDS];
int num_records = 0;

void add_record(char *field1, char *field2, char *field3) {
    if (num_records >= MAX_RECORDS) {
        printf("Error: Database is full.\n");
        return;
    }
    record_t *new_record = &database[num_records];
    new_record->field1 = strdup(field1);
    new_record->field2 = strdup(field2);
    new_record->field3 = strdup(field3);
    num_records++;
}

void delete_record(int index) {
    if (index < 0 || index >= num_records) {
        printf("Error: Invalid record index.\n");
        return;
    }
    for (int i = 0; i < 3; i++) {
        free(database[index].field1);
    }
    num_records--;
}

void display_record(int index) {
    if (index < 0 || index >= num_records) {
        printf("Error: Invalid record index.\n");
        return;
    }
    printf("Record %d:\n", index + 1);
    printf("Field 1: %s\n", database[index].field1);
    printf("Field 2: %s\n", database[index].field2);
    printf("Field 3: %s\n", database[index].field3);
}

void search_record(char *field1, char *field2, char *field3) {
    int match_count = 0;
    for (int i = 0; i < num_records; i++) {
        if (strcmp(database[i].field1, field1) == 0 && strcmp(database[i].field2, field2) == 0 && strcmp(database[i].field3, field3) == 0) {
            display_record(i);
            match_count++;
        }
    }
    if (match_count == 0) {
        printf("No records found.\n");
    }
}

int main() {
    add_record("John", "Doe", "25");
    add_record("Jane", "Doe", "30");
    add_record("Bob", "Smith", "40");
    display_record(0);
    search_record("John", "Doe", "25");
    delete_record(0);
    return 0;
}