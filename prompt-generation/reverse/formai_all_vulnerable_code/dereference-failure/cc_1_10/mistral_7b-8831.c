//MISTRAL-7B DATASET v1.0 Category: Linked list operations ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Creature {
    const char *name;
    int strength;
    int agility;
    int intelligence;
    struct Creature *next;
} Creature;

void print_creature(const Creature *creature) {
    printf("%s (Strength: %d, Agility: %d, Intelligence: %d)\n", creature->name, creature->strength, creature->agility, creature->intelligence);
}

Creature *create_creature(const char *name, int strength, int agility, int intelligence) {
    Creature *new_creature = (Creature *) malloc(sizeof(Creature));
    if (new_creature == NULL) {
        printf("Error: Could not allocate memory for new creature.\n");
        return NULL;
    }

    new_creature->name = strdup(name);
    new_creature->strength = strength;
    new_creature->agility = agility;
    new_creature->intelligence = intelligence;
    new_creature->next = NULL;

    return new_creature;
}

void add_creature(Creature **head, Creature *new_creature) {
    if (*head == NULL) {
        *head = new_creature;
        return;
    }

    Creature *current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new_creature;
}

Creature *find_creature(const Creature *head, const char *name) {
    Creature *current = head;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

void remove_creature(Creature **head, const char *name) {
    Creature *current = *head;
    Creature *previous = NULL;

    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            if (previous == NULL) {
                *head = current->next;
            } else {
                previous->next = current->next;
            }
            free(current->name);
            free(current);
            return;
        }
        previous = current;
        current = current->next;
    }

    printf("Error: Creature not found.\n");
}

int main() {
    Creature *head = NULL;

    add_creature(&head, create_creature("Dragon", 100, 80, 90));
    add_creature(&head, create_creature("Unicorn", 50, 120, 110));
    add_creature(&head, create_creature("Griffin", 150, 70, 100));
    add_creature(&head, create_creature("Phoenix", 200, 60, 130));

    print_creature(head);

    Creature *creature_to_find = find_creature(head, "Unicorn");
    if (creature_to_find != NULL) {
        print_creature(creature_to_find);
        remove_creature(&head, "Unicorn");
    }

    print_creature(head);

    return 0;
}