//MISTRAL-7B DATASET v1.0 Category: Data structures visualization ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

typedef struct Creature {
    char name[30];
    int strength;
    int intelligence;
    int agility;
    struct Creature *next;
} Creature;

void print_creature(Creature *creature) {
    printf("\n%s the %s", creature->name, creature->next ? "apprentice" : "mystic");
    printf("\nStrength: %d\n", creature->strength);
    printf("Intelligence: %d\n", creature->intelligence);
    printf("Agility: %d\n", creature->agility);
    if (creature->next) {
        printf("\nConnected to %s the %s\n",
               creature->next->name, creature->next->next ? "apprentice" : "mystic");
    }
}

void visualize_list(Creature *head) {
    Creature *current = head;
    while (current != NULL) {
        printf("\n--------------------\n");
        print_creature(current);
        current = current->next;
    }
}

int main() {
    Creature *dragon = malloc(sizeof(Creature));
    strcpy(dragon->name, "Draco");
    dragon->strength = 100;
    dragon->intelligence = 80;
    dragon->agility = 90;
    dragon->next = NULL;

    Creature *elf = malloc(sizeof(Creature));
    strcpy(elf->name, "Elvin");
    elf->strength = 40;
    elf->intelligence = 120;
    elf->agility = 110;
    elf->next = dragon;

    Creature *goblin = malloc(sizeof(Creature));
    strcpy(goblin->name, "Gobbo");
    goblin->strength = 50;
    goblin->intelligence = 50;
    goblin->agility = 70;
    goblin->next = elf;

    Creature *head = dragon;
    visualize_list(head);

    free(dragon);
    free(elf);
    free(goblin);

    return 0;
}