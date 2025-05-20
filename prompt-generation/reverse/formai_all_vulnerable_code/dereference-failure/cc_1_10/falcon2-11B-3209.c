//Falcon2-11B DATASET v1.0 Category: Database Indexing System ; Style: satisfied
#include <stdio.h>
#include <string.h>

#define MAX_TABLE_SIZE 10
#define MAX_ENTRY_SIZE 100
#define MAX_NUM_FIELDS 10

typedef struct {
    char name[MAX_ENTRY_SIZE];
    int age;
    char gender;
} Entry;

typedef struct {
    int table_size;
    Entry *entries;
    int num_fields;
} Table;

void initialize_table(Table *table) {
    table->table_size = 0;
    table->entries = NULL;
    table->num_fields = 0;
}

void add_entry_to_table(Table *table, Entry entry) {
    if (table->table_size == MAX_TABLE_SIZE) {
        printf("Table is full. Cannot add new entry.\n");
        return;
    }

    Entry *new_entry = (Entry *)malloc(sizeof(Entry));
    if (new_entry == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    memset(new_entry, 0, sizeof(Entry));
    strcpy(new_entry->name, entry.name);
    new_entry->age = entry.age;
    new_entry->gender = entry.gender;

    table->entries = realloc(table->entries, (table->table_size + 1) * sizeof(Entry));
    if (table->entries == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    table->entries[table->table_size] = *new_entry;
    table->table_size++;
}

void print_table(Table *table) {
    printf("Table:\n");
    for (int i = 0; i < table->table_size; i++) {
        Entry entry = table->entries[i];
        printf("Name: %s, Age: %d, Gender: %c\n", entry.name, entry.age, entry.gender);
    }
}

void search_table(Table *table, char *name) {
    for (int i = 0; i < table->table_size; i++) {
        Entry entry = table->entries[i];
        if (strcmp(entry.name, name) == 0) {
            printf("Found entry: Name: %s, Age: %d, Gender: %c\n", entry.name, entry.age, entry.gender);
            return;
        }
    }

    printf("Entry not found.\n");
}

int main() {
    Table table;
    initialize_table(&table);

    Entry entry1 = {"John", 25, 'M'};
    Entry entry2 = {"Jane", 30, 'F'};

    add_entry_to_table(&table, entry1);
    add_entry_to_table(&table, entry2);

    print_table(&table);

    search_table(&table, "Jane");

    return 0;
}