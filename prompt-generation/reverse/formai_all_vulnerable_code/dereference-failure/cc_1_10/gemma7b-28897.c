//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 20
#define HEIGHT 20

#define MAX_Rooms 10

typedef struct room
{
    int x, y;
    struct room* next;
} room;

room* createRoom(int x, int y)
{
    room* newRoom = (room*)malloc(sizeof(room));
    newRoom->x = x;
    newRoom->y = y;
    newRoom->next = NULL;
    return newRoom;
}

void generateMaze()
{
    room* head = createRoom(0, 0);
    room* current = head;
    int i, j;

    for (i = 0; i < WIDTH; i++)
    {
        for (j = 0; j < HEIGHT; j++)
        {
            current->next = createRoom(i, j);
            current = current->next;
        }
    }

    current = head;
    while (current)
    {
        printf("%c ", current->x + 1);
        printf("%c ", current->y + 1);
        printf("\n");
        current = current->next;
    }
}

int main()
{
    generateMaze();

    return 0;
}