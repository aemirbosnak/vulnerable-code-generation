//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct Node
{
    int x, y;
    struct Node* next;
} Node;

void createMaze(int** maze, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            maze[i][j] = rand() % MAX;
        }
    }
}

void printMaze(int** maze, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }
}

void findRoute(Node* head, int** maze, int n, int m)
{
    while (head)
    {
        if (head->x >= n || head->x < 0 || head->y >= m || head->y < 0)
        {
            return;
        }

        if (maze[head->x][head->y] == 0)
        {
            return;
        }

        maze[head->x][head->y] = 0;

        findRoute(head->next, maze, n, m);
    }
}

int main()
{
    int n, m;
    scanf("Enter the number of rows: ", &n);
    scanf("Enter the number of columns: ", &m);

    int** maze = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++)
    {
        maze[i] = (int*)malloc(m * sizeof(int));
    }

    createMaze(maze, n, m);
    printMaze(maze, n, m);

    Node* head = (Node*)malloc(sizeof(Node));
    head->x = 0;
    head->y = 0;
    head->next = NULL;

    findRoute(head, maze, n, m);

    printMaze(maze, n, m);

    free(maze);
    free(head);

    return 0;
}