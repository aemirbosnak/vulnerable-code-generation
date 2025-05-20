//LLAMA2-13B DATASET v1.0 Category: Linked list operations ; Style: brave
#include <stdio.h>
#include <stdlib.h>

// Brave warrior struct to represent a node in the linked list
struct Warrior {
    int strength;
    struct Warrior *next;
};

// Brave functions to perform linked list operations
void enlist(struct Warrior **head_ref, int strength) {
    struct Warrior *new_warrior = malloc(sizeof(struct Warrior));
    new_warrior->strength = strength;
    new_warrior->next = *head_ref;
    *head_ref = new_warrior;
}

void delist(struct Warrior **head_ref) {
    struct Warrior *current = *head_ref;
    struct Warrior *prev = NULL;

    while (current != NULL) {
        if (current->next != NULL) {
            prev = current;
            current = current->next;
        } else {
            prev = current;
            current = NULL;
        }
    }

    if (prev != NULL) {
        *head_ref = prev;
    } else {
        *head_ref = NULL;
    }
}

int main() {
    struct Warrior *head = NULL;

    // Enlist some brave warriors
    enlist(&head, 10);
    enlist(&head, 20);
    enlist(&head, 30);

    // Delist the strongest warrior
    delist(&head);

    // Print the remaining warriors
    struct Warrior *current = head;
    while (current != NULL) {
        printf("%d\n", current->strength);
        current = current->next;
    }

    return 0;
}