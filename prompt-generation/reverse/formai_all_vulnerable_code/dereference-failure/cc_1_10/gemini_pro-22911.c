//GEMINI-pro DATASET v1.0 Category: Digital Diary ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct entry {
    char *title;
    char *content;
    struct entry *next;
} entry_t;

entry_t *head = NULL;
entry_t *tail = NULL;

void add_entry(char *title, char *content) {
    entry_t *new_entry = malloc(sizeof(entry_t));
    new_entry->title = strdup(title);
    new_entry->content = strdup(content);
    new_entry->next = NULL;

    if (head == NULL) {
        head = new_entry;
        tail = new_entry;
    } else {
        tail->next = new_entry;
        tail = new_entry;
    }
}

void print_entry(entry_t *entry) {
    printf("Title: %s\n", entry->title);
    printf("Content: %s\n", entry->content);
    printf("\n");
}

void print_all_entries() {
    entry_t *current_entry = head;

    while (current_entry != NULL) {
        print_entry(current_entry);
        current_entry = current_entry->next;
    }
}

void delete_entry(char *title) {
    entry_t *current_entry = head;
    entry_t *previous_entry = NULL;

    while (current_entry != NULL) {
        if (strcmp(current_entry->title, title) == 0) {
            if (current_entry == head) {
                head = current_entry->next;
            } else {
                previous_entry->next = current_entry->next;
            }
            free(current_entry->title);
            free(current_entry->content);
            free(current_entry);
            break;
        }
        previous_entry = current_entry;
        current_entry = current_entry->next;
    }
}

void edit_entry(char *title, char *new_content) {
    entry_t *current_entry = head;

    while (current_entry != NULL) {
        if (strcmp(current_entry->title, title) == 0) {
            free(current_entry->content);
            current_entry->content = strdup(new_content);
            break;
        }
        current_entry = current_entry->next;
    }
}

int main() {
    add_entry("My First Entry", "This is my first entry in my digital diary.");
    add_entry("My Second Entry", "This is my second entry in my digital diary.");
    add_entry("My Third Entry", "This is my third entry in my digital diary.");

    print_all_entries();

    delete_entry("My Second Entry");

    print_all_entries();

    edit_entry("My First Entry", "This is my updated first entry in my digital diary.");

    print_all_entries();

    return 0;
}