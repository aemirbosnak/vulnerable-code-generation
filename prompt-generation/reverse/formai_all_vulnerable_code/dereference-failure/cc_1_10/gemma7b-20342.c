//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_GHOULS 10

typedef struct Ghost {
    char name[20];
    int room;
    int health;
    struct Ghost* next;
} Ghost;

void createGhost(Ghost** head) {
    *head = malloc(sizeof(Ghost));
    (*head)->name[0] = '\0';
    (*head)->room = 0;
    (*head)->health = 100;
    (*head)->next = NULL;
}

void addGhost(Ghost** head, char* name, int room, int health) {
    Ghost* newGhost = malloc(sizeof(Ghost));
    newGhost->name[0] = '\0';
    strcpy(newGhost->name, name);
    newGhost->room = room;
    newGhost->health = health;
    newGhost->next = NULL;

    if (*head) {
        (*head)->next = newGhost;
    } else {
        *head = newGhost;
    }
}

void haunt(Ghost* head) {
    while (head) {
        printf("The wind whispers secrets through the crumbling tower of %d...\n", head->room);
        printf("%s emerges from the shadows...\n", head->name);
        printf("Its eyes glow with an unholy light...\n");
        printf("A chilling scream echoes through the halls...\n");
        printf("You feel a cold hand brush against your skin...\n");
        printf("What will you do? (Press any key) ");

        char input;
        scanf("%c", &input);

        switch (input) {
            case 'f':
                printf("You flee in terror...\n");
                break;
            case 'a':
                printf("You attack...\n");
                head->health -= 10;
                if (head->health <= 0) {
                    printf("The ghost crumbles to dust...\n");
                    free(head);
                }
                break;
            default:
                printf("You are paralyzed with fear...\n");
                break;
        }

        printf("\n");
        head = head->next;
    }
}

int main() {
    Ghost* head = NULL;

    createGhost(&head);
    addGhost(&head, "Mortimer", 1, 100);
    addGhost(&head, "Gertrude", 2, 80);
    addGhost(&head, "The Bloody Countess", 3, 60);

    haunt(head);

    return 0;
}