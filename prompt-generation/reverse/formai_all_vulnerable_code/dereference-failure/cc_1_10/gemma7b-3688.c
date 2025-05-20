//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_GHOULS 10

struct Ghost {
    char name[20];
    int room_num;
    int is_active;
    struct Ghost* next;
};

void addGhost(struct Ghost** head, char* name, int room_num) {
    struct Ghost* newGhost = (struct Ghost*)malloc(sizeof(struct Ghost));
    strcpy(newGhost->name, name);
    newGhost->room_num = room_num;
    newGhost->is_active = 1;
    newGhost->next = NULL;

    if (*head == NULL) {
        *head = newGhost;
    } else {
        (*head)->next = newGhost;
    }
}

void hauntHouse(struct Ghost* head) {
    srand(time(NULL));
    int random_room = rand() % MAX_GHOULS;
    struct Ghost* currentGhost = head;

    while (currentGhost) {
        if (currentGhost->is_active && currentGhost->room_num == random_room) {
            printf("%s is haunting you in room %d!\n", currentGhost->name, currentGhost->room_num);
            currentGhost->is_active = 0;
        }
        currentGhost = currentGhost->next;
    }
}

int main() {
    struct Ghost* head = NULL;
    addGhost(&head, "Jack", 1);
    addGhost(&head, "Mary", 2);
    addGhost(&head, "Bob", 3);

    hauntHouse(head);

    return 0;
}