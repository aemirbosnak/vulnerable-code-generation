//FormAI DATASET v1.0 Category: Database Indexing System ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 50
#define MAX_NAME_LEN 100
#define MAX_ID_LEN 10

typedef struct {
    char name[MAX_NAME_LEN];
    char id[MAX_ID_LEN];
} Entry;

typedef struct {
    Entry entries[MAX_ENTRIES];
    int count;
} Table;

Table *createTable() {
    Table *table = (Table*)malloc(sizeof(Table));
    table->count = 0;
    memset(table->entries, 0, sizeof(table->entries));
    return table;
}

void addEntry(Table *table, const char *name, const char *id) {
    if (table->count < MAX_ENTRIES) {
        strcpy(table->entries[table->count].name, name);
        strcpy(table->entries[table->count].id, id);
        table->count++;
    } else {
        printf("Table is full.\n");
    }
}

void printTable(Table *table) {
    printf("ID\t Name\n");
    for (int i = 0; i < table->count; i++) {
        printf("%s\t %s\n", table->entries[i].id, table->entries[i].name);
    }
}

int main() {
    Table *table = createTable();
    
    addEntry(table, "Alice", "1001");
    addEntry(table, "Bob", "1002");
    addEntry(table, "Charlie", "1003");
    addEntry(table, "Dave", "1004");
    addEntry(table, "Eve", "1005");
    
    printTable(table);

    free(table);
    return 0;
}