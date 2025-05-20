//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_GHOSTS 10

struct Ghost {
    char name[20];
    int room_num;
    int active;
    struct Ghost *next;
};

void add_ghost(struct Ghost **head) {
    struct Ghost *new_ghost = malloc(sizeof(struct Ghost));
    new_ghost->active = 1;
    new_ghost->next = NULL;

    if (*head == NULL) {
        *head = new_ghost;
    } else {
        (*head)->next = new_ghost;
    }
}

int main() {
    struct Ghost *head = NULL;
    int i;

    // Create a list of ghosts
    for (i = 0; i < MAX_GHOSTS; i++) {
        add_ghost(&head);
    }

    // Randomly activate ghosts
    for (i = 0; i < MAX_GHOSTS; i++) {
        head->next->active = rand() % 2;
    }

    // Start the haunted house simulation
    printf("Welcome to the Haunted House of Doom!\n");

    // Loop until the user escapes
    while (!head->next->active) {
        // Display the haunted house
        printf("You are in room %d.\n", head->next->room_num);

        // Listen for the sound of a ghost
        printf("Listen for any sounds... ");
        sleep(rand() % 3);

        // If a ghost is detected, flee the house
        if (head->next->active) {
            printf("BOO! A ghost has been detected! Flee the house!\n");
            break;
        }

        // Move to the next room
        printf("Move to the next room (1/2): ");
        int direction = rand() % 2;

        // Go to the next room
        if (direction == 0) {
            head = head->next->next;
        } else {
            head = head->next;
        }
    }

    // Escape the haunted house
    printf("You have escaped the Haunted House of Doom! Congratulations!\n");

    return 0;
}