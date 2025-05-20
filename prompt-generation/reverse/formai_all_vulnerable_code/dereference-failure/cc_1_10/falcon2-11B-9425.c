//Falcon2-11B DATASET v1.0 Category: Database Indexing System ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TABLE_NAME_LEN 100
#define MAX_FIELD_NAME_LEN 50
#define MAX_FIELD_VALUE_LEN 100

struct Table {
    char name[MAX_TABLE_NAME_LEN];
    int num_fields;
    struct Field **fields;
};

struct Field {
    char name[MAX_FIELD_NAME_LEN];
    char type[10];
    int index;
};

void print_table(struct Table *table) {
    printf("Table: %s\n", table->name);
    printf("Number of fields: %d\n", table->num_fields);
    for (int i = 0; i < table->num_fields; i++) {
        printf("Field: %s, Type: %s, Index: %d\n", table->fields[i]->name, table->fields[i]->type, table->fields[i]->index);
    }
}

void print_field(struct Table *table, int index) {
    printf("Field: %s, Type: %s, Index: %d\n", table->fields[index]->name, table->fields[index]->type, table->fields[index]->index);
}

void add_field(struct Table *table, char *name, char *type, int index) {
    struct Field *new_field = (struct Field *)malloc(sizeof(struct Field));
    strcpy(new_field->name, name);
    strcpy(new_field->type, type);
    new_field->index = index;
    table->fields[index] = new_field;
    table->num_fields++;
}

int main() {
    struct Table *table = (struct Table *)malloc(sizeof(struct Table));
    table->num_fields = 0;
    table->fields = (struct Field **)malloc(MAX_TABLE_NAME_LEN * sizeof(struct Field *));
    
    add_field(table, "id", "int", 0);
    add_field(table, "name", "string", 1);
    add_field(table, "age", "int", 2);
    
    print_table(table);
    
    return 0;
}