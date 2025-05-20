//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Cell
{
    int number;
    struct Cell* next;
} Cell;

Cell* InsertCell(Cell* head, int num)
{
    Cell* newCell = malloc(sizeof(Cell));
    newCell->number = num;
    newCell->next = NULL;

    if (head == NULL)
    {
        head = newCell;
    }
    else
    {
        head->next = newCell;
    }

    return head;
}

void PrintList(Cell* head)
{
    Cell* current = head;

    while (current)
    {
        printf("%d ", current->number);
        current = current->next;
    }

    printf("\n");
}

int main()
{
    srand(time(NULL));

    Cell* head = NULL;

    for (int i = 0; i < 20; i++)
    {
        InsertCell(head, rand() % 100);
    }

    PrintList(head);

    return 0;
}