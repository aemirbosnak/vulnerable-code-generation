//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define MAX_FIELD_SIZE 50

typedef struct {
    char *field1;
    char *field2;
    int field3;
} Record;

Record records[MAX_RECORDS];
int num_records = 0;

void add_record(char *field1, char *field2, int field3) {
    if (num_records >= MAX_RECORDS) {
        printf("Error: Maximum number of records reached.\n");
        return;
    }

    records[num_records].field1 = strdup(field1);
    records[num_records].field2 = strdup(field2);
    records[num_records].field3 = field3;

    num_records++;
}

void search_records(char *field1, char *field2) {
    int i;

    for (i = 0; i < num_records; i++) {
        if (strcmp(records[i].field1, field1) == 0 && strcmp(records[i].field2, field2) == 0) {
            printf("Record found:\n");
            printf("Field1: %s\n", records[i].field1);
            printf("Field2: %s\n", records[i].field2);
            printf("Field3: %d\n", records[i].field3);
        }
    }
}

void delete_record(char *field1, char *field2) {
    int i;

    for (i = 0; i < num_records; i++) {
        if (strcmp(records[i].field1, field1) == 0 && strcmp(records[i].field2, field2) == 0) {
            free(records[i].field1);
            free(records[i].field2);

            records[i] = records[num_records - 1];
            num_records--;

            return;
        }
    }

    printf("Record not found.\n");
}

int main() {
    add_record("John", "Doe", 25);
    add_record("Jane", "Doe", 30);
    add_record("Bob", "Smith", 40);

    search_records("John", "Doe");
    search_records("Jane", "Doe");
    search_records("Bob", "Smith");

    delete_record("John", "Doe");

    return 0;
}