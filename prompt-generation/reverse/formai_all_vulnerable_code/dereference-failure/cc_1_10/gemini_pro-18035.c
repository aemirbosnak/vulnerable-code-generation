//GEMINI-pro DATASET v1.0 Category: Database simulation ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    char *value;
} Entry;

typedef struct {
    char *name;
    Entry *entries;
    int num_entries;
} Table;

Table *create_table(char *name) {
    Table *table = malloc(sizeof(Table));
    table->name = strdup(name);
    table->entries = NULL;
    table->num_entries = 0;
    return table;
}

void destroy_table(Table *table) {
    for (int i = 0; i < table->num_entries; i++) {
        free(table->entries[i].name);
        free(table->entries[i].value);
    }
    free(table->entries);
    free(table->name);
    free(table);
}

Entry *create_entry(char *name, char *value) {
    Entry *entry = malloc(sizeof(Entry));
    entry->name = strdup(name);
    entry->value = strdup(value);
    return entry;
}

void destroy_entry(Entry *entry) {
    free(entry->name);
    free(entry->value);
    free(entry);
}

void add_entry(Table *table, Entry *entry) {
    table->entries = realloc(table->entries, sizeof(Entry) * (table->num_entries + 1));
    table->entries[table->num_entries++] = *entry;
}

Entry *get_entry(Table *table, char *name) {
    for (int i = 0; i < table->num_entries; i++) {
        if (strcmp(table->entries[i].name, name) == 0) {
            return &table->entries[i];
        }
    }
    return NULL;
}

void print_table(Table *table) {
    printf("Table: %s\n", table->name);
    for (int i = 0; i < table->num_entries; i++) {
        printf("  %s: %s\n", table->entries[i].name, table->entries[i].value);
    }
}

int main() {
    Table *table = create_table("users");

    Entry *entry1 = create_entry("name", "John Doe");
    Entry *entry2 = create_entry("age", "30");
    Entry *entry3 = create_entry("email", "john.doe@example.com");

    add_entry(table, entry1);
    add_entry(table, entry2);
    add_entry(table, entry3);

    print_table(table);

    Entry *entry = get_entry(table, "email");
    if (entry != NULL) {
        printf("Email: %s\n", entry->value);
    }

    destroy_entry(entry1);
    destroy_entry(entry2);
    destroy_entry(entry3);
    destroy_table(table);

    return 0;
}