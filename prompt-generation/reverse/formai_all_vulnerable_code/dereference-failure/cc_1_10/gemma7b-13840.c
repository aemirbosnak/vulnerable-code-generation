//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int x;
    int y;
    struct Node* next;
} Node;

void createMaze(int **maze, int n, int m)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            maze[i][j] = 0;
        }
    }

    maze[2][2] = 1;
    maze[2][3] = 1;
    maze[3][2] = 1;
    maze[3][3] = 1;
    maze[4][2] = 1;
}

void findRoute(Node* head, int **maze, int n, int m)
{
    head->x = 2;
    head->y = 2;

    while(head->x != n-1 || head->y != m-1)
    {
        int dx[] = {1, 0, -1, 0};
        int dy[] = {0, 1, 0, -1};

        for(int i = 0; i < 4; i++)
        {
            int newX = head->x + dx[i];
            int newY = head->y + dy[i];

            if(newX >= 0 && newX < n && newY >= 0 && newY < m && maze[newX][newY] == 0)
            {
                head->x = newX;
                head->y = newY;
                maze[newX][newY] = 2;
                break;
            }
        }

        if(head->x == n-1 && head->y == m-1)
        {
            printf("No route found.\n");
            exit(0);
        }

        head = head->next;
    }

    printf("Route found.\n");
}

int main()
{
    int n = 5;
    int m = 5;
    int** maze = (int**)malloc(n * sizeof(int*));
    for(int i = 0; i < n; i++)
    {
        maze[i] = (int*)malloc(m * sizeof(int));
    }

    createMaze(maze, n, m);
    findRoute(NULL, maze, n, m);

    return 0;
}