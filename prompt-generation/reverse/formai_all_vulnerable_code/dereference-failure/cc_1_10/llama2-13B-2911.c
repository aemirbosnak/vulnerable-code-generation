//LLAMA2-13B DATASET v1.0 Category: Linked list operations ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

// Define the node structure
struct knight {
    int gold;  // Gold coins held by the knight
    struct knight *next; // Pointer to the next knight
};

// Define a function to create a new knight
struct knight *create_knight(int gold) {
    struct knight *new_knight = (struct knight *)malloc(sizeof(struct knight));
    new_knight->gold = gold;
    new_knight->next = NULL;
    return new_knight;
}

// Define a function to add a knight to the front of the list
void enlist_knight(struct knight **head_ptr, int gold) {
    struct knight *new_knight = create_knight(gold);
    new_knight->next = *head_ptr;
    *head_ptr = new_knight;
}

// Define a function to add a knight to the end of the list
void enlist_knight_tail(struct knight **head_ptr, int gold) {
    struct knight *current = *head_ptr;
    struct knight *new_knight = create_knight(gold);
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new_knight;
    new_knight->next = NULL;
}

// Define a function to remove the first knight from the list
void dismiss_knight(struct knight **head_ptr) {
    struct knight *current = *head_ptr;
    struct knight *next = current->next;
    free(current);
    *head_ptr = next;
}

// Define a function to remove the last knight from the list
void dismiss_knight_tail(struct knight **head_ptr) {
    struct knight *current = *head_ptr;
    struct knight *prev = NULL;
    while (current->next != NULL) {
        prev = current;
        current = current->next;
    }
    if (prev == NULL) {
        // List is empty, do nothing
        return;
    }
    prev->next = NULL;
    free(current);
}

// Define a function to print the list of knights
void print_knights(struct knight *head) {
    while (head != NULL) {
        printf("%d gold coins\n", head->gold);
        head = head->next;
    }
}

int main() {
    struct knight *head = NULL;

    // Add some knights to the list
    enlist_knight_tail(&head, 50);
    enlist_knight_tail(&head, 20);
    enlist_knight_tail(&head, 80);

    // Print the list of knights
    print_knights(head);

    // Remove the first knight from the list
    dismiss_knight(&head);

    // Print the list of knights again
    print_knights(head);

    // Remove the last knight from the list
    dismiss_knight_tail(&head);

    // Print the list of knights again
    print_knights(head);

    return 0;
}