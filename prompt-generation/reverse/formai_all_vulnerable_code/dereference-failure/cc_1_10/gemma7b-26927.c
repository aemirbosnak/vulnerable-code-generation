//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_GHOULS 5

typedef struct Ghost Ghost;
struct Ghost {
    char name[20];
    int room;
    int health;
    int strength;
    Ghost *next;
};

void initializeGhosts(Ghost **head) {
    *head = NULL;
    for (int i = 0; i < MAX_GHOULS; i++) {
        Ghost *ghost = malloc(sizeof(Ghost));
        ghost->name[0] = 'A' + i;
        ghost->room = rand() % 5 + 1;
        ghost->health = rand() % 10 + 1;
        ghost->strength = rand() % 3 + 1;
        ghost->next = *head;
        *head = ghost;
    }
}

void hauntHouse(Ghost *head) {
    while (head) {
        printf("The ghostly figure of %s appears in room %d!\n", head->name, head->room);
        printf("It is weak, with only %d health remaining.\n", head->health);
        printf("Prepare for a fight!\n");

        // Simulate a fight between the ghost and the player
        int player_damage = rand() % 5 + 1;
        int ghost_damage = rand() % 3 + 1;

        printf("You deal %d damage to the ghost.\n", player_damage);
        head->health -= player_damage;

        if (head->health <= 0) {
            printf("The ghost of %s has been defeated!\n", head->name);
            free(head);
            head = head->next;
        } else {
            printf("The ghost of %s strikes you for %d damage.\n", head->name, ghost_damage);
            int player_health = rand() % 5 + 1;
            player_health -= ghost_damage;
            printf("Your health is now %d.\n", player_health);
        }
    }
}

int main() {
    Ghost *head = NULL;
    initializeGhosts(&head);
    hauntHouse(head);
    return 0;
}