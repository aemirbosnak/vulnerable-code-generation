//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_GHOSTS 10

typedef struct Ghost {
    char name[20];
    int room_num;
    int is_active;
    struct Ghost *next;
} Ghost;

void add_ghost(Ghost **head) {
    Ghost *new_ghost = (Ghost *)malloc(sizeof(Ghost));
    new_ghost->name[0] = '\0';
    new_ghost->room_num = 0;
    new_ghost->is_active = 0;
    new_ghost->next = NULL;

    if (*head == NULL) {
        *head = new_ghost;
    } else {
        (*head)->next = new_ghost;
    }
}

void haunt_house(Ghost *head) {
    time_t t = time(NULL);
    srand(t);

    for (Ghost *ghost = head; ghost; ghost = ghost->next) {
        if (ghost->is_active && rand() % MAX_GHOSTS == ghost->room_num) {
            printf("%s has appeared in room %d!\n", ghost->name, ghost->room_num);
        }
    }
}

int main() {
    Ghost *head = NULL;

    // Add some ghosts to the house
    add_ghost(&head);
    add_ghost(&head);
    add_ghost(&head);

    // Haunt the house
    haunt_house(head);

    return 0;
}