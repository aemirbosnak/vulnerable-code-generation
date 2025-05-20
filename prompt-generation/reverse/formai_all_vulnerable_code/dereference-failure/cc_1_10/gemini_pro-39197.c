//GEMINI-pro DATASET v1.0 Category: Digital Diary ; Style: surrealist
#include <stdio.h>
#include <string.h>

// A surrealist diary entry
struct diary_entry {
    char *text;
    int date;
    struct diary_entry *next;
};

// Initialize a new diary entry
struct diary_entry *new_entry(char *text, int date) {
    struct diary_entry *entry = malloc(sizeof(struct diary_entry));
    entry->text = strdup(text);
    entry->date = date;
    entry->next = NULL;
    return entry;
}

// Add a new entry to the diary
void add_entry(struct diary_entry **head, struct diary_entry *new) {
    new->next = *head;
    *head = new;
}

// Print the diary
void print_diary(struct diary_entry *head) {
    while (head != NULL) {
        printf("%s\n", head->text);
        head = head->next;
    }
}

// Free the diary
void free_diary(struct diary_entry *head) {
    while (head != NULL) {
        struct diary_entry *next = head->next;
        free(head->text);
        free(head);
        head = next;
    }
}

int main() {

    // Create a new diary
    struct diary_entry *head = NULL;

    // Add some entries to the diary
    add_entry(&head, new_entry("I dreamed of a flying elephant.", 20230308));
    add_entry(&head, new_entry("I saw a talking tree.", 20230309));
    add_entry(&head, new_entry("I met a man with a green beard.", 20230310));

    // Print the diary
    print_diary(head);

    // Free the diary
    free_diary(head);

    return 0;
}