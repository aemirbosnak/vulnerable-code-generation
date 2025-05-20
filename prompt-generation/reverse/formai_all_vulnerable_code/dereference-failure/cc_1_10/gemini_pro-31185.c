//GEMINI-pro DATASET v1.0 Category: Tower of Hanoi Problem ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int size;
    int *elements;
} stack;

void push(stack *s, int element)
{
    s->elements = realloc(s->elements, (s->size + 1) * sizeof(int));
    s->elements[s->size++] = element;
}

int pop(stack *s)
{
    if (s->size == 0)
    {
        return -1;
    }
    return s->elements[--s->size];
}

int main()
{
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);

    stack *towers[3];
    for (int i = 0; i < 3; i++)
    {
        towers[i] = malloc(sizeof(stack));
        towers[i]->size = 0;
        towers[i]->elements = NULL;
    }

    for (int i = n; i >= 1; i--)
    {
        push(towers[0], i);
    }

    int moves = 0;
    while (towers[2]->size < n)
    {
        int from, to;
        printf("Move disk from tower: ");
        scanf("%d", &from);
        printf("Move disk to tower: ");
        scanf("%d", &to);

        if (from < 1 || from > 3 || to < 1 || to > 3)
        {
            printf("Invalid input. Please enter a valid tower number (1-3).");
            continue;
        }

        if (towers[from - 1]->size == 0)
        {
            printf("There is no disk on tower %d.", from);
            continue;
        }

        if (towers[to - 1]->size > 0 && towers[from - 1]->elements[towers[from - 1]->size - 1] > towers[to - 1]->elements[towers[to - 1]->size - 1])
        {
            printf("Cannot move disk from tower %d to tower %d. The disk on tower %d is larger.", from, to, to);
            continue;
        }

        push(towers[to - 1], pop(towers[from - 1]));
        moves++;
    }

    printf("Minimum number of moves: %d", moves);

    for (int i = 0; i < 3; i++)
    {
        free(towers[i]->elements);
        free(towers[i]);
    }

    return 0;
}