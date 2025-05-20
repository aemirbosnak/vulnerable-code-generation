//GEMINI-pro DATASET v1.0 Category: Database simulation ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

typedef struct {
    char *name;
    char *value;
} Entry;

typedef struct {
    int count;
    Entry *entries;
} Database;

Database *database = NULL;

void init_database() {
    database = (Database *)malloc(sizeof(Database));
    database->count = 0;
    database->entries = NULL;
}

void free_database() {
    for (int i = 0; i < database->count; i++) {
        free(database->entries[i].name);
        free(database->entries[i].value);
    }
    free(database->entries);
    free(database);
}

void add_entry(char *name, char *value) {
    database->entries = (Entry *)realloc(database->entries, (database->count + 1) * sizeof(Entry));
    database->entries[database->count].name = (char *)malloc(strlen(name) + 1);
    strcpy(database->entries[database->count].name, name);
    database->entries[database->count].value = (char *)malloc(strlen(value) + 1);
    strcpy(database->entries[database->count].value, value);
    database->count++;
}

void get_entry(char *name, char *buffer) {
    for (int i = 0; i < database->count; i++) {
        if (strcmp(database->entries[i].name, name) == 0) {
            strcpy(buffer, database->entries[i].value);
            return;
        }
    }
    strcpy(buffer, "");
}

int main() {
    init_database();
    add_entry("name", "John Doe");
    add_entry("age", "30");
    add_entry("occupation", "Software Engineer");
    char buffer[BUFFER_SIZE];
    get_entry("name", buffer);
    printf("Name: %s\n", buffer);
    get_entry("age", buffer);
    printf("Age: %s\n", buffer);
    get_entry("occupation", buffer);
    printf("Occupation: %s\n", buffer);
    free_database();
    return 0;
}