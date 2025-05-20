//Gemma-7B DATASET v1.0 Category: Procedural Space Adventure ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 20

typedef struct Starship {
    char name[MAX_NAME_LENGTH];
    int hull_strength;
    int crew_size;
    struct Starship* next;
} Starship;

Starship* create_starship(char* name, int hull_strength, int crew_size) {
    Starship* new_ship = malloc(sizeof(Starship));
    strcpy(new_ship->name, name);
    new_ship->hull_strength = hull_strength;
    new_ship->crew_size = crew_size;
    new_ship->next = NULL;
    return new_ship;
}

Starship* add_starship(Starship* head, char* name, int hull_strength, int crew_size) {
    Starship* new_ship = create_starship(name, hull_strength, crew_size);
    if (head == NULL) {
        return new_ship;
    }
    Starship* current = head;
    while (current->next) {
        current = current->next;
    }
    current->next = new_ship;
    return head;
}

void print_starship_list(Starship* head) {
    Starship* current = head;
    printf("Starship List:\n");
    while (current) {
        printf("Name: %s\n", current->name);
        printf("Hull Strength: %d\n", current->hull_strength);
        printf("Crew Size: %d\n", current->crew_size);
        printf("\n");
        current = current->next;
    }
}

int main() {
    Starship* head = NULL;
    head = add_starship(head, "The Enterprise", 10, 50);
    head = add_starship(head, "The Discovery", 8, 40);
    head = add_starship(head, "The Falcon", 6, 20);

    print_starship_list(head);

    return 0;
}