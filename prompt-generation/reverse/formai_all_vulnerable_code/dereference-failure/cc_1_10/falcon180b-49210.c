//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LENGTH 64
#define MAX_VALUE_LENGTH 256

typedef struct {
    char key[MAX_KEY_LENGTH];
    char value[MAX_VALUE_LENGTH];
} Record;

typedef struct {
    Record *records;
    int count;
} Table;

void create_table(Table *table) {
    table->records = (Record *)malloc(sizeof(Record));
    table->count = 1;
}

void destroy_table(Table *table) {
    free(table->records);
}

void add_record(Table *table, char *key, char *value) {
    Record *record = (Record *)malloc(sizeof(Record));
    strcpy(record->key, key);
    strcpy(record->value, value);
    table->records = (Record *)realloc(table->records, sizeof(Record) * (table->count + 1));
    table->records[table->count - 1] = *record;
    free(record);
    table->count++;
}

void print_table(Table *table) {
    for (int i = 0; i < table->count; i++) {
        printf("%s: %s\n", table->records[i].key, table->records[i].value);
    }
}

int main() {
    Table table;
    create_table(&table);

    add_record(&table, "name", "John");
    add_record(&table, "age", "30");
    add_record(&table, "gender", "Male");

    print_table(&table);

    destroy_table(&table);

    return 0;
}