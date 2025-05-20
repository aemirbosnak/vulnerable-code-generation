//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_GHOSTS 10

typedef struct Ghost {
    char name[20];
    int room_num;
    int activity_level;
    struct Ghost* next;
} Ghost;

void addGhost(Ghost** head, char* name, int room_num, int activity_level) {
    Ghost* newGhost = malloc(sizeof(Ghost));
    strcpy(newGhost->name, name);
    newGhost->room_num = room_num;
    newGhost->activity_level = activity_level;
    newGhost->next = NULL;

    if (*head == NULL) {
        *head = newGhost;
    } else {
        (*head)->next = newGhost;
    }
}

void hauntHouse(Ghost* head) {
    time_t t = time(NULL);
    srand(t);

    while (head) {
        int rand_num = rand() % MAX_GHOSTS;
        Ghost* currentGhost = head;

        for (int i = 0; i < rand_num; i++) {
            currentGhost = currentGhost->next;
        }

        switch (currentGhost->activity_level) {
            case 1:
                printf("You hear a shuffling sound.\n");
                break;
            case 2:
                printf("You smell a faint scent of burning flesh.\n");
                break;
            case 3:
                printf("You see a ghostly figure moving through the halls.\n");
                break;
            case 4:
                printf("You hear voices whispering your name.\n");
                break;
            case 5:
                printf("You feel a cold hand brush against your skin.\n");
                break;
            case 6:
                printf("You hear a scream and a piercing cry.\n");
                break;
        }
    }
}

int main() {
    Ghost* head = NULL;

    addGhost(&head, "John Doe", 1, 3);
    addGhost(&head, "Jane Doe", 2, 2);
    addGhost(&head, "Mary Smith", 3, 4);

    hauntHouse(head);

    return 0;
}