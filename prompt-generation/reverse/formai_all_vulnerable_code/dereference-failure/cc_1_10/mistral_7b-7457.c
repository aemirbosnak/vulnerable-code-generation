//MISTRAL-7B DATASET v1.0 Category: Database simulation ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TABLE_SIZE 101

typedef struct {
    int id;
    char name[50];
    char address[100];
} Record;

unsigned long hash(char *str) {
    unsigned long hash = 5381;
    int c;

    while ((c = *str++))
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return hash % TABLE_SIZE;
}

struct HashNode {
    Record record;
    struct HashNode *next;
};

struct HashTable {
    struct HashNode **data;
};

struct HashTable *create_hash_table() {
    struct HashTable *table = (struct HashTable *) malloc(sizeof(struct HashTable));
    table->data = (struct HashNode **) calloc(TABLE_SIZE, sizeof(struct HashNode *));
    return table;
}

void insert_record(struct HashTable *table, Record record) {
    unsigned long index = hash(record.name);
    struct HashNode *new_node = (struct HashNode *) malloc(sizeof(struct HashNode));

    new_node->record = record;
    new_node->next = table->data[index];
    table->data[index] = new_node;
}

Record *search_record(struct HashTable *table, char *name) {
    unsigned long index = hash(name);
    struct HashNode *current = table->data[index];

    while (current != NULL) {
        if (strcmp(current->record.name, name) == 0)
            return &current->record;
        current = current->next;
    }

    return NULL;
}

void delete_record(struct HashTable *table, char *name) {
    unsigned long index = hash(name);
    struct HashNode **prev, *current = table->data[index];

    while (current != NULL && strcmp(current->record.name, name) != 0) {
        prev = &table->data[index];
        current = current->next;
    }

    if (current == NULL)
        return;

    if (*prev == NULL)
        table->data[index] = current->next;
    else
        (*prev)->next = current->next;

    free(current);
}

void display_records(struct HashTable *table) {
    int i;

    printf("ID\tName\tAddress\n");

    for (i = 0; i < TABLE_SIZE; i++) {
        struct HashNode *current = table->data[i];

        while (current != NULL) {
            printf("%d\t%s\t%s\n", current->record.id, current->record.name, current->record.address);
            current = current->next;
        }
    }
}

int main() {
    struct HashTable *table = create_hash_table();

    Record new_record = {.id = 1, .name = "John Doe", .address = "123 Main St"};
    insert_record(table, new_record);

    Record *found_record = search_record(table, "John Doe");
    if (found_record != NULL)
        printf("Found record: ID: %d, Name: %s, Address: %s\n", found_record->id, found_record->name, found_record->address);

    delete_record(table, "John Doe");

    display_records(table);

    free(table->data);
    free(table);

    return 0;
}