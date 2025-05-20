//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct Cell
{
    int x, y;
    struct Cell* next;
} Cell;

void create_map(Cell** head)
{
    *head = NULL;
    for (int i = 0; i < MAX_SIZE; i++)
    {
        for (int j = 0; j < MAX_SIZE; j++)
        {
            Cell* new_cell = malloc(sizeof(Cell));
            new_cell->x = i;
            new_cell->y = j;
            new_cell->next = NULL;

            if (*head == NULL)
            {
                *head = new_cell;
            }
            else
            {
                (*head)->next = new_cell;
                *head = new_cell;
            }
        }
    }
}

void print_map(Cell* head)
{
    while (head)
    {
        printf("(%d, %d) ", head->x, head->y);
        head = head->next;
    }
    printf("\n");
}

int main()
{
    Cell* head = NULL;
    create_map(&head);
    print_map(head);

    return 0;
}