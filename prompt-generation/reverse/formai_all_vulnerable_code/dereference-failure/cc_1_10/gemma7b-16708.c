//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROOM_COUNT 5

typedef struct Room {
    char name[20];
    struct Room* next;
    struct Room* prev;
    int haunted_level;
} Room;

void generate_rooms(Room** head) {
    for (int i = 0; i < ROOM_COUNT; i++) {
        *head = malloc(sizeof(Room));
        (*head)->name[0] = 'A' + i;
        (*head)->next = NULL;
        (*head)->prev = NULL;
        (*head)->haunted_level = rand() % 3;
        head = &((*head)->next);
    }
}

void wander_through(Room* current) {
    printf("You are in the %s room. The air is thick with the scent of %s.\n", current->name, current->haunted_level == 0 ? "roses" : "decay");
    if (current->prev) {
        printf("You can hear whispers coming from the %s room.\n", current->prev->name);
    }
    if (current->next) {
        printf("You hear a door slam shut in the %s room.\n", current->next->name);
    }
    if (current->haunted_level > 0) {
        printf("Suddenly, a cold wind blows through the room, and you feel a presence watching you.\n");
    }
    printf("What do you want to do? (c) continue, (q) quit\n");
    char input;
    scanf("%c", &input);
    switch (input) {
        case 'c':
            wander_through(current->next);
            break;
        case 'q':
            exit(0);
            break;
        default:
            printf("Invalid input. Please try again.\n");
            wander_through(current);
    }
}

int main() {
    Room* head = NULL;
    generate_rooms(&head);
    wander_through(head);
    return 0;
}