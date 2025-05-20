//Gemma-7B DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_SIZE 10
#define MAX_ROOM_COUNT 5

typedef struct Room
{
    int x, y;
    char **walls;
    struct Room* next;
} Room;

Room* generateRooms(int roomCount)
{
    srand(time(NULL));
    Room* head = NULL;
    for (int i = 0; i < roomCount; i++)
    {
        Room* newRoom = malloc(sizeof(Room));
        newRoom->x = rand() % MAP_SIZE;
        newRoom->y = rand() % MAP_SIZE;
        newRoom->walls = malloc(4 * sizeof(char*));
        newRoom->walls[0] = malloc(MAP_SIZE * sizeof(char));
        newRoom->walls[1] = malloc(MAP_SIZE * sizeof(char));
        newRoom->walls[2] = malloc(MAP_SIZE * sizeof(char));
        newRoom->walls[3] = malloc(MAP_SIZE * sizeof(char));

        for (int j = 0; j < MAP_SIZE; j++)
        {
            newRoom->walls[0][j] = rand() % 2;
            newRoom->walls[1][j] = rand() % 2;
            newRoom->walls[2][j] = rand() % 2;
            newRoom->walls[3][j] = rand() % 2;
        }

        newRoom->next = head;
        head = newRoom;
    }

    return head;
}

int main()
{
    Room* rooms = generateRooms(MAX_ROOM_COUNT);

    for (Room* room = rooms; room; room = room->next)
    {
        printf("Room at (%d, %d):\n", room->x, room->y);
        for (int i = 0; i < MAP_SIZE; i++)
        {
            for (int j = 0; j < MAP_SIZE; j++)
            {
                printf("%c ", room->walls[0][j] ? '#' : '.');
            }
            printf("\n");
        }
        printf("\n");
    }

    return 0;
}