//Gemma-7B DATASET v1.0 Category: Pac-Man Game Clone ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 20
#define PACMAN_SIZE 5

typedef struct Pacman
{
    int x;
    int y;
    int direction;
    struct Pacman* next;
} Pacman;

Pacman* initializePacman(int x, int y, int direction)
{
    Pacman* pacman = malloc(sizeof(Pacman));
    pacman->x = x;
    pacman->y = y;
    pacman->direction = direction;
    pacman->next = NULL;
    return pacman;
}

void movePacman(Pacman* pacman)
{
    switch (pacman->direction)
    {
        case 0:
            pacman->x++;
            break;
        case 1:
            pacman->y++;
            break;
        case 2:
            pacman->x--;
            break;
        case 3:
            pacman->y--;
            break;
    }
}

void drawPacman(Pacman* pacman)
{
    for (int x = pacman->x - PACMAN_SIZE / 2; x < pacman->x + PACMAN_SIZE / 2; x++)
    {
        for (int y = pacman->y - PACMAN_SIZE / 2; y < pacman->y + PACMAN_SIZE / 2; y++)
        {
            printf("%c", '#');
        }
    }
    printf("\n");
}

int main()
{
    Pacman* head = initializePacman(10, 10, 0);
    drawPacman(head);

    movePacman(head);
    drawPacman(head);

    return 0;
}