//GEMINI-pro DATASET v1.0 Category: Digital Diary ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node
struct node {
    char *text;
    struct node *next;
};

// Diary
struct diary {
    struct node *head;
    struct node *tail;
    int count;
};

// Create a new node
struct node *new_node(char *text) {
    struct node *new = malloc(sizeof(struct node));
    new->text = strdup(text);
    new->next = NULL;
    return new;
}

// Create a new diary
struct diary *new_diary() {
    struct diary *d = malloc(sizeof(struct diary));
    d->head = NULL;
    d->tail = NULL;
    d->count = 0;
    return d;
}

// Add an entry to the diary
void add_entry(struct diary *d, char *text) {
    struct node *new = new_node(text);
    if (d->count == 0) {
        d->head = new;
        d->tail = new;
    } else {
        d->tail->next = new;
        d->tail = new;
    }
    d->count++;
}

// Print the diary
void print_diary(struct diary *d) {
    struct node *current = d->head;
    while (current != NULL) {
        printf("%s\n", current->text);
        current = current->next;
    }
}

// Free the diary
void free_diary(struct diary *d) {
    struct node *current = d->head;
    while (current != NULL) {
        struct node *next = current->next;
        free(current->text);
        free(current);
        current = next;
    }
    free(d);
}

// Main function
int main() {
    // Create a new diary
    struct diary *d = new_diary();

    // Add some entries to the diary
    add_entry(d, "Dear Diary,");
    add_entry(d, "Today was a great day!");
    add_entry(d, "I went to the park and played with my friends.");
    add_entry(d, "We had a lot of fun.");
    add_entry(d, "I can't wait to do it again tomorrow!");

    // Print the diary
    print_diary(d);

    // Free the diary
    free_diary(d);

    return 0;
}