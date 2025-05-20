//GEMINI-pro DATASET v1.0 Category: Database Indexing System ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 1000
#define MAX_FIELDS 10
#define MAX_FIELD_SIZE 100

typedef struct {
    char *name;
    char *type;
    int size;
} field_t;

typedef struct {
    field_t fields[MAX_FIELDS];
    int num_fields;
    char *data;
    int size;
} record_t;

typedef struct {
    char *name;
    int field_index;
} index_t;

record_t records[MAX_RECORDS];
int num_records;

index_t indexes[MAX_FIELDS];
int num_indexes;

void create_index(char *name, int field_index) {
    indexes[num_indexes].name = name;
    indexes[num_indexes].field_index = field_index;
    num_indexes++;
}

int find_record(char *name, char *value) {
    int i;
    for (i = 0; i < num_records; i++) {
        if (strcmp(records[i].data, value) == 0) {
            return i;
        }
    }
    return -1;
}

int main() {
    // Create a database table with three fields: name, age, and salary.
    field_t fields[] = {
        {"name", "char", 100},
        {"age", "int", 4},
        {"salary", "int", 4}
    };
    int num_fields = sizeof(fields) / sizeof(field_t);

    // Create a record.
    record_t record;
    record.num_fields = num_fields;
    record.data = malloc(100);
    strcpy(record.data, "John Doe,30,100000");

    // Add the record to the database.
    records[num_records] = record;
    num_records++;

    // Create an index on the name field.
    create_index("name", 0);

    // Find the record using the index.
    int record_index = find_record("name", "John Doe");

    // Print the record.
    printf("%s\n", records[record_index].data);

    return 0;
}