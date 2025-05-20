//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A mailing list entry
struct entry {
    char *email;
    char *name;
    struct entry *next;
};

// The mailing list
struct list {
    struct entry *head;
    struct entry *tail;
    int size;
};

// Create a new mailing list
struct list *create_list() {
    struct list *list = malloc(sizeof(struct list));
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return list;
}

// Add an entry to the mailing list
void add_entry(struct list *list, char *email, char *name) {
    struct entry *entry = malloc(sizeof(struct entry));
    entry->email = strdup(email);
    entry->name = strdup(name);
    entry->next = NULL;
    if (list->head == NULL) {
        list->head = entry;
        list->tail = entry;
    } else {
        list->tail->next = entry;
        list->tail = entry;
    }
    list->size++;
}

// Print the mailing list
void print_list(struct list *list) {
    struct entry *entry = list->head;
    while (entry != NULL) {
        printf("%s (%s)\n", entry->email, entry->name);
        entry = entry->next;
    }
}

// Free the mailing list
void free_list(struct list *list) {
    struct entry *entry = list->head;
    while (entry != NULL) {
        struct entry *next = entry->next;
        free(entry->email);
        free(entry->name);
        free(entry);
        entry = next;
    }
    free(list);
}

// The main function
int main() {
    // Create a new mailing list
    struct list *list = create_list();

    // Add some entries to the mailing list
    add_entry(list, "alice@example.com", "Alice");
    add_entry(list, "bob@example.com", "Bob");
    add_entry(list, "charlie@example.com", "Charlie");

    // Print the mailing list
    printf("The mailing list:\n");
    print_list(list);

    // Free the mailing list
    free_list(list);

    return 0;
}