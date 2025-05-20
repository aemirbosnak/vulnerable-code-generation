//Gemma-7B DATASET v1.0 Category: Space Invaders Game Clone ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

#define ROWS 5
#define COLS 11

typedef struct invader {
    int x;
    int y;
    int dir;
    struct invader* next;
} invader;

invader* head = NULL;

void addInvader() {
    invader* newInvader = (invader*)malloc(sizeof(invader));
    newInvader->x = rand() % COLS;
    newInvader->y = rand() % ROWS;
    newInvader->dir = rand() % 2;
    newInvader->next = head;
    head = newInvader;
}

void moveInvaders() {
    invader* current = head;
    while (current) {
        switch (current->dir) {
            case 0:
                current->x++;
                break;
            case 1:
                current->x--;
                break;
            case 2:
                current->y++;
                break;
            case 3:
                current->y--;
                break;
        }

        if (current->x >= COLS - 1) {
            current->dir = 1;
        } else if (current->x <= 0) {
            current->dir = 0;
        }

        if (current->y >= ROWS - 1) {
            current->dir = 3;
        } else if (current->y <= 0) {
            current->dir = 2;
        }

        current = current->next;
    }
}

void drawInvaders() {
    system("cls");
    invader* current = head;
    while (current) {
        printf(" ");
        for (int i = 0; i < current->x; i++) {
            printf(".");
        }
        printf("o");
        for (int i = current->x + 1; i < COLS; i++) {
            printf(".");
        }
        printf("\n");
        current = current->next;
    }
}

int main() {
    addInvader();
    addInvader();
    addInvader();
    drawInvaders();
    moveInvaders();
    drawInvaders();

    return 0;
}