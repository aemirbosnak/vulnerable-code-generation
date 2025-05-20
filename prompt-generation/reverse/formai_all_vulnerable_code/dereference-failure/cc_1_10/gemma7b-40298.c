//Gemma-7B DATASET v1.0 Category: Space Invaders Game Clone ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SCREEN_WIDTH 50
#define SCREEN_HEIGHT 20

// Define the shape-shifting invader
typedef struct ShapeShifter {
    int x;
    int y;
    char direction;
    struct ShapeShifter* next;
} ShapeShifter;

// Function to move the invader
void moveInvader(ShapeShifter* invader) {
    switch (invader->direction) {
        case 'r':
            invader->x++;
            break;
        case 'l':
            invader->x--;
            break;
        case 'u':
            invader->y--;
            break;
        case 'd':
            invader->y++;
            break;
    }
}

// Function to draw the invader
void drawInvader(ShapeShifter* invader) {
    printf(" ");
    for (int i = 0; i < invader->x; i++) {
        printf("=");
    }
    printf("O");
    for (int i = 0; i < invader->x; i++) {
        printf("=");
    }
    printf("\n");
}

int main() {
    // Initialize the invader
    ShapeShifter* head = malloc(sizeof(ShapeShifter));
    head->x = 0;
    head->y = 0;
    head->direction = 'r';
    head->next = NULL;

    // Create a list of invaders
    ShapeShifter* invaderList = head;
    for (int i = 1; i < 10; i++) {
        invaderList->next = malloc(sizeof(ShapeShifter));
        invaderList = invaderList->next;
        invaderList->x = i;
        invaderList->y = 0;
        invaderList->direction = 'r';
        invaderList->next = NULL;
    }

    // Game loop
    int gameRunning = 1;
    while (gameRunning) {
        // Move the invaders
        moveInvader(head);

        // Draw the invaders
        drawInvader(head);

        // Check if the invaders have reached the edge of the screen
        if (invaderList->x >= SCREEN_WIDTH - 1) {
            invaderList->direction = 'u';
        } else if (invaderList->x <= 0) {
            invaderList->direction = 'r';
        }

        // Pause the game
        sleep(1);
    }

    return 0;
}