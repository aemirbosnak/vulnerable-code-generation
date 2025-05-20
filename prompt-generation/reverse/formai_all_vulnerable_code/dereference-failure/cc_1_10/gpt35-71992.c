//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 10
#define HEIGHT 10

#define EMPTY 0
#define WALL 1

// Stack structure
typedef struct stack
{
    int x, y;
    struct stack* next;
} Stack;

// Maze structure
typedef struct maze
{
    int cells[WIDTH][HEIGHT];
} Maze;

// Stack functions
void push(Stack** top, int x, int y)
{
    Stack* new = (Stack*)malloc(sizeof(Stack));
    new->x = x;
    new->y = y;
    new->next = *top;
    *top = new;
}

void pop(Stack** top)
{
    Stack* temp = *top;
    *top = (*top)->next;
    free(temp);
}

int is_empty(Stack* top)
{
    return top == NULL;
}

// Maze functions
int is_valid(Maze* maze, int x, int y)
{
    return x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT && maze->cells[x][y] != WALL;
}

int is_exit(int x, int y)
{
    return x == 0 || x == WIDTH - 1 || y == 0 || y == HEIGHT - 1;
}

void print_maze(Maze* maze)
{
    for (int y = 0; y < HEIGHT; y++)
    {
        for (int x = 0; x < WIDTH; x++)
        {
            printf("%c ", maze->cells[x][y] == EMPTY ? ' ' : '#');
        }
        printf("\n");
    }
}

// Main function
int main()
{
    Maze maze = {{
        {WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL},
        {WALL, EMPTY, EMPTY, EMPTY, WALL, EMPTY, WALL, EMPTY, EMPTY, WALL},
        {WALL, WALL, WALL, EMPTY, WALL, EMPTY, WALL, WALL, EMPTY, WALL},
        {WALL, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, WALL},
        {WALL, WALL, WALL, EMPTY, WALL, WALL, WALL, EMPTY, WALL, WALL},
        {WALL, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, WALL},
        {WALL, WALL, WALL, EMPTY, WALL, WALL, WALL, WALL, EMPTY, WALL},
        {WALL, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, WALL, EMPTY, EMPTY, WALL},
        {WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL},
        {WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL},
    }};

    Stack* path = NULL;
    push(&path, 1, 1);

    while (!is_empty(path))
    {
        int x = path->x;
        int y = path->y;
        pop(&path);

        if (is_exit(x, y))
        {
            printf("Exit found at (%d, %d)!\n", x, y);
            break;
        }

        // Try moving in all directions
        if (is_valid(&maze, x - 1, y)) push(&path, x - 1, y); // Left
        if (is_valid(&maze, x + 1, y)) push(&path, x + 1, y); // Right
        if (is_valid(&maze, x, y - 1)) push(&path, x, y - 1); // Up
        if (is_valid(&maze, x, y + 1)) push(&path, x, y + 1); // Down

        // Mark as visited
        maze.cells[x][y] = WALL;

        // Print current state
        printf("Current state:\n");
        print_maze(&maze);
        printf("\n");
    }

    return 0;
}