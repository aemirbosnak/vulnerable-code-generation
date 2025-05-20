//Gemma-7B DATASET v1.0 Category: Breakout Game Clone ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAP_SIZE 20

typedef struct Cell
{
    int x, y;
    struct Cell* next;
} Cell;

void drawMap(Cell* head)
{
    system("clear");
    for (Cell* cell = head; cell; cell = cell->next)
    {
        if (cell->x == 0)
        {
            printf("____________________\n");
        }
        else if (cell->y == 0)
        {
            printf("  |---" " " " |" "\n");
        }
        else
        {
            printf("  |   | " " |" "\n");
        }

    }
    printf("\n");
}

int main()
{
    Cell* head = NULL;
    head = malloc(sizeof(Cell));
    head->x = 0;
    head->y = 0;
    head->next = NULL;

    for (int x = 0; x < MAP_SIZE; x++)
    {
        for (int y = 0; y < MAP_SIZE; y++)
        {
            Cell* cell = malloc(sizeof(Cell));
            cell->x = x;
            cell->y = y;
            cell->next = NULL;

            if (head == NULL)
            {
                head = cell;
            }
            else
            {
                head->next = cell;
                head = cell;
            }
        }
    }

    drawMap(head);

    return 0;
}