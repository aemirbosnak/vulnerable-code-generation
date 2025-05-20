//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Entry {
    char name[50];
    char email[50];
    struct Entry *next;
};

typedef struct Entry Entry;

struct List {
    Entry *head;
    Entry *tail;
};

typedef struct List List;

List *create_list() {
    List *list = malloc(sizeof(List));
    list->head = NULL;
    list->tail = NULL;
    return list;
}

void add_entry(List *list, char *name, char *email) {
    Entry *entry = malloc(sizeof(Entry));
    strcpy(entry->name, name);
    strcpy(entry->email, email);
    entry->next = NULL;
    if (list->head == NULL) {
        list->head = entry;
    } else {
        list->tail->next = entry;
    }
    list->tail = entry;
}

void print_list(List *list) {
    Entry *current = list->head;
    while (current != NULL) {
        printf("%s %s\n", current->name, current->email);
        current = current->next;
    }
}

void delete_list(List *list) {
    Entry *current = list->head;
    while (current != NULL) {
        Entry *next = current->next;
        free(current);
        current = next;
    }
    free(list);
}

int main() {
    List *list = create_list();
    add_entry(list, "Alice", "alice@example.com");
    add_entry(list, "Bob", "bob@example.com");
    add_entry(list, "Carol", "carol@example.com");
    print_list(list);
    delete_list(list);
    return 0;
}