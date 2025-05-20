//Gemma-7B DATASET v1.0 Category: Breakout Game Clone ; Style: Cryptic
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX_WIDTH 20
#define MAX_HEIGHT 20

#define SNAKES_HEAD_SIZE 3
#define SNAKES_BODY_SIZE 5

typedef struct Snake {
    int x;
    int y;
    int direction;
    struct Snake *next;
} Snake;

void initialize_snake(Snake **head) {
    *head = malloc(sizeof(Snake));
    (*head)->x = MAX_WIDTH / 2;
    (*head)->y = MAX_HEIGHT / 2;
    (*head)->direction = 0;
    (*head)->next = NULL;
}

void move_snake(Snake *head) {
    switch (head->direction) {
        case 0:
            head->x--;
            break;
        case 1:
            head->x++;
            break;
        case 2:
            head->y--;
            break;
        case 3:
            head->y++;
            break;
    }
}

void draw_snake(Snake *head) {
    for (Snake *snake = head; snake; snake = snake->next) {
        printf("%c", ' ');
        switch (snake->direction) {
            case 0:
                printf("|\n");
                break;
            case 1:
                printf("/\n");
                break;
            case 2:
                printf("\\\n");
                break;
            case 3:
                printf("|\n");
                break;
        }
        printf("  ");
    }
}

int main() {
    Snake *head = NULL;
    initialize_snake(&head);

    // Game loop
    while (1) {
        move_snake(head);
        draw_snake(head);

        // Check if game is over
        if (head->x < 0 || head->x >= MAX_WIDTH || head->y < 0 || head->y >= MAX_HEIGHT) {
            break;
        }

        // Sleep
        sleep(0.1);
    }

    return 0;
}