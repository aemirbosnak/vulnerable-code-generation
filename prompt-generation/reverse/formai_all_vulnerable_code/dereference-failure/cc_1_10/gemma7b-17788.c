//Gemma-7B DATASET v1.0 Category: Space Invaders Game Clone ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LEFT_BOUND 0
#define RIGHT_BOUND 63
#define UP_BOUND 0
#define DOWN_BOUND 29

// Define the invader structure
typedef struct invader {
    int x;
    int y;
    int direction;
    struct invader* next;
} invader;

// Function to initialize the invader list
invader* initialize_invaders() {
    invader* head = malloc(sizeof(invader));
    head->x = RIGHT_BOUND;
    head->y = UP_BOUND;
    head->direction = 1;
    head->next = NULL;

    return head;
}

// Function to move the invaders
void move_invaders(invader* head) {
    switch (head->direction) {
        case 1:
            head->x++;
            break;
        case 2:
            head->x--;
            break;
        case 3:
            head->y++;
            break;
        case 4:
            head->y--;
            break;
    }

    // If the invader reaches the left or right boundary, change direction
    if (head->x == LEFT_BOUND || head->x == RIGHT_BOUND) {
        head->direction *= -1;
    }

    // If the invader reaches the top or bottom boundary, move down
    if (head->y == UP_BOUND || head->y == DOWN_BOUND) {
        head->direction = 3;
    }
}

// Function to draw the invaders
void draw_invaders(invader* head) {
    invader* current = head;

    while (current) {
        // Draw the invader at its current position
        printf("%c", current->x + 1, current->y + 1, '.');
        current = current->next;
    }

    // Draw the border
    for (int x = 0; x <= RIGHT_BOUND; x++) {
        printf("%c", x + 1, UP_BOUND, '-');
    }

    printf("\n");
}

int main() {
    // Initialize the invader list
    invader* head = initialize_invaders();

    // Move and draw the invaders
    for (int i = 0; i < 10; i++) {
        move_invaders(head);
        draw_invaders(head);
    }

    return 0;
}