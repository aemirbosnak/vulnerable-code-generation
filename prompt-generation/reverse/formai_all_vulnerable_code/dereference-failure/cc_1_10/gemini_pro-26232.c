//GEMINI-pro DATASET v1.0 Category: Database simulation ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

// Database structure
typedef struct {
    char *name;
    char *type;
    char *data;
} Field;

typedef struct {
    char *name;
    Field *fields;
    int num_fields;
} Table;

// Database functions
Table *create_table(char *name, int num_fields) {
    Table *table = malloc(sizeof(Table));
    table->name = name;
    table->fields = malloc(sizeof(Field) * num_fields);
    table->num_fields = num_fields;
    return table;
}

void add_field(Table *table, Field field) {
    table->fields[table->num_fields++] = field;
}

void print_table(Table *table) {
    printf("Table: %s\n", table->name);
    for (int i = 0; i < table->num_fields; i++) {
        Field field = table->fields[i];
        printf("  Field: %s (%s)\n", field.name, field.type);
        printf("    Data: %s\n", field.data);
    }
}

// Main function
int main() {
    // Create a database
    Table *database = create_table("database", 3);

    // Add fields to the database
    add_field(database, (Field) {"name", "string", "John Doe"});
    add_field(database, (Field) {"age", "int", "30"});
    add_field(database, (Field) {"city", "string", "New York"});

    // Print the database
    print_table(database);

    return 0;
}