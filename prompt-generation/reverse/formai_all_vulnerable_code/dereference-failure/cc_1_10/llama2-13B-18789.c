//LLAMA2-13B DATASET v1.0 Category: Linked list operations ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

// Structure for a knight's node in the list
struct knight {
    int id;
    char name[20];
    struct knight *next;
};

// Function to create a new knight node
struct knight *create_knight(int id, char name[]) {
    struct knight *new_knight = (struct knight *)malloc(sizeof(struct knight));
    new_knight->id = id;
    strcpy(new_knight->name, name);
    new_knight->next = NULL;
    return new_knight;
}

// Function to add a knight to the beginning of the list
void enlist(struct knight **head_ref, int id, char name[]) {
    struct knight *new_knight = create_knight(id, name);
    new_knight->next = *head_ref;
    *head_ref = new_knight;
}

// Function to remove the knight at the given index
void dismiss(struct knight **head_ref, int index) {
    struct knight *current = *head_ref;
    struct knight *prev = NULL;

    if (index == 0) {
        *head_ref = current->next;
    } else {
        for (int i = 0; i < index - 1; i++) {
            prev = current->next;
            current = current->next->next;
        }
        prev->next = current->next;
    }

    free(current);
}

// Function to traverse the list
void tourney(struct knight **head_ref) {
    struct knight *current = *head_ref;

    while (current != NULL) {
        printf("%d - %s\n", current->id, current->name);
        current = current->next;
    }
}

int main() {
    struct knight *head = NULL;

    enlist(&head, 1, "Sir Lancelot");
    enlist(&head, 2, "Sir Gawain");
    enlist(&head, 3, "Sir Percival");

    dismiss(&head, 1);

    tourney(&head);

    return 0;
}