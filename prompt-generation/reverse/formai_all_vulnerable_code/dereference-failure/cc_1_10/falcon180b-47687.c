//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_SIZE 100
#define MAX_VALUE_SIZE 1000

typedef struct {
    char name[MAX_NAME_SIZE];
    char value[MAX_VALUE_SIZE];
} Record;

typedef struct {
    Record *records;
    int num_records;
    int max_records;
} Table;

void table_init(Table *table, int max_records) {
    table->records = malloc(max_records * sizeof(Record));
    table->num_records = 0;
    table->max_records = max_records;
}

void table_free(Table *table) {
    free(table->records);
}

void table_add_record(Table *table, const char *name, const char *value) {
    if (table->num_records >= table->max_records) {
        printf("Error: Table is full.\n");
        return;
    }

    Record *record = &table->records[table->num_records];
    strcpy(record->name, name);
    strcpy(record->value, value);

    table->num_records++;
}

void table_print(Table *table) {
    for (int i = 0; i < table->num_records; i++) {
        printf("%s = %s\n", table->records[i].name, table->records[i].value);
    }
}

void table_sort(Table *table, int (*cmp_func)(const void *, const void *)) {
    qsort(table->records, table->num_records, sizeof(Record), cmp_func);
}

int string_cmp(const void *a, const void *b) {
    char *str1 = *(char **)a;
    char *str2 = *(char **)b;

    return strcmp(str1, str2);
}

int main() {
    Table table;
    table_init(&table, 10);

    table_add_record(&table, "Name", "Alice");
    table_add_record(&table, "Age", "25");
    table_add_record(&table, "City", "New York");
    table_add_record(&table, "Country", "USA");

    table_sort(&table, string_cmp);

    table_print(&table);

    table_free(&table);

    return 0;
}