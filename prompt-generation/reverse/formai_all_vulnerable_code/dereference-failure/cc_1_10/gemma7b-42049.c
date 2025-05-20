//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CELLS 20

typedef struct Cell
{
    int state;
    struct Cell* next;
} Cell;

void initialize_game(Cell** head)
{
    *head = NULL;
    for (int i = 0; i < MAX_CELLS; i++)
    {
        *head = malloc(sizeof(Cell));
        (*head)->state = 0;
        (*head)->next = NULL;
        head = &((*head)->next);
    }
}

void simulate_game(Cell* head)
{
    int alive_cells = 0;
    for (Cell* cell = head; cell; cell = cell->next)
    {
        int num_alive_neighbors = 0;
        for (Cell* neighbor = head; neighbor; neighbor = neighbor->next)
        {
            if (cell != neighbor && cell->state == 1 && neighbor->state == 1)
            {
                num_alive_neighbors++;
            }
        }

        if (num_alive_neighbors < 2)
        {
            cell->state = 0;
        }
        else if (num_alive_neighbors == 2)
        {
            cell->state = 1;
        }
        else if (num_alive_neighbors > 2)
        {
            cell->state = 0;
        }
        alive_cells++;
    }

    printf("Number of alive cells: %d\n", alive_cells);
}

int main()
{
    Cell* head = NULL;
    initialize_game(&head);

    simulate_game(head);

    return 0;
}