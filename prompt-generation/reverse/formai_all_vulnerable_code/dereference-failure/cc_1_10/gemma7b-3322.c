//Gemma-7B DATASET v1.0 Category: Graph representation ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_Players 2

typedef struct Player {
    char name[20];
    int x, y;
    int color;
    struct Player* next;
} Player;

Player* head = NULL;

void addPlayer(char* name, int x, int y, int color) {
    Player* newPlayer = (Player*)malloc(sizeof(Player));
    strcpy(newPlayer->name, name);
    newPlayer->x = x;
    newPlayer->y = y;
    newPlayer->color = color;
    newPlayer->next = NULL;

    if (head == NULL) {
        head = newPlayer;
    } else {
        head->next = newPlayer;
        head = newPlayer;
    }
}

void movePlayer(char* name, int dx, int dy) {
    Player* currentPlayer = head;
    while (currentPlayer) {
        if (strcmp(currentPlayer->name, name) == 0) {
            currentPlayer->x += dx;
            currentPlayer->y += dy;
            break;
        }
        currentPlayer = currentPlayer->next;
    }
}

void drawBoard() {
    for (int y = 0; y < 10; y++) {
        for (int x = 0; x < 10; x++) {
            Player* currentPlayer = head;
            while (currentPlayer) {
                if (currentPlayer->x == x && currentPlayer->y == y) {
                    printf("%c ", currentPlayer->color);
                } else {
                    printf(" ");
                }
            }
            printf("\n");
        }
        printf("\n");
    }
}

int main() {
    addPlayer("John", 0, 0, 1);
    addPlayer("Mary", 0, 9, 2);

    movePlayer("John", 1, 0);
    movePlayer("Mary", 1, 0);

    drawBoard();

    return 0;
}