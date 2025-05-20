//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct entry_t {
    char name[20];
    char number[12];
} entry;

entry * create_entry(const char *name, const char *number) {
    entry * new_entry = malloc(sizeof(entry));
    strcpy(new_entry->name, name);
    strcpy(new_entry->number, number);
    return new_entry;
}

void print_entry(const entry *e) {
    printf("%s: %s\n", e->name, e->number);
}

typedef struct node_t {
    struct node_t *next;
    entry *data;
} node;

typedef struct table_t {
    node *head;
} table;

table * create_table() {
    table * new_table = malloc(sizeof(table));
    new_table->head = NULL;
    return new_table;
}

void insert_entry(table *t, entry *e) {
    node * new_node = malloc(sizeof(node));
    new_node->next = t->head;
    new_node->data = e;
    t->head = new_node;
}

entry * lookup_entry(table *t, const char *name) {
    node * current = t->head;
    while (current != NULL) {
        if (strcmp(current->data->name, name) == 0) {
            return current->data;
        }
        current = current->next;
    }
    return NULL;
}

void delete_entry(table *t, entry *e) {
    node * current = t->head;
    node * previous = NULL;
    while (current != NULL) {
        if (strcmp(current->data->name, e->name) == 0) {
            if (previous == NULL) {
                t->head = current->next;
            } else {
                previous->next = current->next;
            }
            free(current->data);
            free(current);
            return;
        }
        previous = current;
        current = current->next;
    }
}

void print_table(table *t) {
    node * current = t->head;
    while (current != NULL) {
        print_entry(current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    table *t = create_table();
    insert_entry(t, create_entry("John", "555-1212"));
    insert_entry(t, create_entry("Mary", "555-1213"));
    insert_entry(t, create_entry("Bob", "555-1214"));
    print_table(t);
    entry * e = lookup_entry(t, "John");
    if (e != NULL) {
        print_entry(e);
    } else {
        printf("Entry not found.\n");
    }
    delete_entry(t, e);
    print_table(t);
    return 0;
}