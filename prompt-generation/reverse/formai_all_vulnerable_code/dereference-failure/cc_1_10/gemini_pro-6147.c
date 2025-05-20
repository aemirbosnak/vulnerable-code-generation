//GEMINI-pro DATASET v1.0 Category: Performance-Critical Component ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

#define IS_ALIVE 1
#define IS_DEAD 0
#define MAX_NAME_LENGTH 100

typedef struct survivor {
    char name[MAX_NAME_LENGTH];
    int is_alive;
    struct survivor *next;
} survivor_t;

// Create a new survivor
survivor_t *create_survivor(char *name) {
    survivor_t *new_survivor = (survivor_t *) malloc(sizeof(survivor_t));
    strcpy(new_survivor->name, name);
    new_survivor->is_alive = IS_ALIVE;
    new_survivor->next = NULL;
    return new_survivor;
}

// Add a survivor to the list
void add_survivor(survivor_t **head, survivor_t *new_survivor) {
    new_survivor->next = *head;
    *head = new_survivor;
}

// Remove a survivor from the list
void remove_survivor(survivor_t **head, char *name) {
    survivor_t *current = *head;
    survivor_t *previous = NULL;

    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            if (previous == NULL) {
                *head = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
            break;
        }
        previous = current;
        current = current->next;
    }
}

// Print the list of survivors
void print_survivors(survivor_t *head) {
    survivor_t *current = head;
    while (current != NULL) {
        printf("%s\n", current->name);
        current = current->next;
    }
}

// Check if a survivor is alive
int is_survivor_alive(survivor_t *survivor) {
    return survivor->is_alive;
}

// Kill a survivor
void kill_survivor(survivor_t *survivor) {
    survivor->is_alive = IS_DEAD;
}

// Main function
int main() {
    // Create a list of survivors
    survivor_t *head = NULL;

    // Add some survivors to the list
    add_survivor(&head, create_survivor("Alice"));
    add_survivor(&head, create_survivor("Bob"));
    add_survivor(&head, create_survivor("Carol"));

    // Print the list of survivors
    printf("Survivors:\n");
    print_survivors(head);

    // Kill a survivor
    kill_survivor(head);

    // Print the list of survivors again
    printf("Survivors after killing Bob:\n");
    print_survivors(head);

    return 0;
}