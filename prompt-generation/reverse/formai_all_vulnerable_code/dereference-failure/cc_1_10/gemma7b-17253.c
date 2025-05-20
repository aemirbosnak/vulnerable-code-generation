//Gemma-7B DATASET v1.0 Category: Pathfinding algorithms ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int x;
    int y;
    struct Node* next;
} Node;

typedef struct Map
{
    int** data;
    int width;
    int height;
} Map;

void initializeMap(Map* map, int w, int h)
{
    map->data = (int**)malloc(h * sizeof(int*));
    for (int i = 0; i < h; i++)
    {
        map->data[i] = (int*)malloc(w * sizeof(int));
    }
    map->width = w;
    map->height = h;
}

void setObstacle(Map* map, int x, int y)
{
    map->data[y][x] = 1;
}

int isFree(Map* map, int x, int y)
{
    return map->data[y][x] == 0;
}

void findPath(Map* map, int x, int y, Node** path)
{
    if (x < 0 || x >= map->width || y < 0 || y >= map->height)
    {
        return;
    }
    if (map->data[y][x] == 1)
    {
        return;
    }

    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->x = x;
    newNode->y = y;
    newNode->next = NULL;

    *path = newNode;

    findPath(map, x - 1, y, path);
    findPath(map, x + 1, y, path);
    findPath(map, x, y - 1, path);
    findPath(map, x, y + 1, path);
}

int main()
{
    Map* map = NULL;
    initializeMap(map, 5, 5);
    setObstacle(map, 2, 2);
    setObstacle(map, 3, 2);

    Node** path = NULL;
    findPath(map, 0, 0, path);

    for (Node* node = path; node; node = node->next)
    {
        printf("(%d, %d)\n", node->x, node->y);
    }

    return 0;
}