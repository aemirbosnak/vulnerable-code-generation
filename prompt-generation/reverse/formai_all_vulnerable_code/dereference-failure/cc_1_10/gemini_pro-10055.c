//GEMINI-pro DATASET v1.0 Category: Procedurally Generated Maze ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the size of the maze
#define MAZE_WIDTH 20
#define MAZE_HEIGHT 20

// Define the directions in which the maze can be traversed
#define NORTH 0
#define EAST 1
#define SOUTH 2
#define WEST 3

// Define the type of cell in the maze
typedef struct
{
    int walls[4]; // 0 = no wall, 1 = wall
    int visited; // 0 = not visited, 1 = visited
} cell;

// Define the maze struct
typedef struct
{
    cell cells[MAZE_WIDTH][MAZE_HEIGHT];
} maze;

// Creates a new maze
maze *create_maze()
{
    maze *maze = malloc(sizeof(maze));
    for (int i = 0; i < MAZE_WIDTH; i++)
    {
        for (int j = 0; j < MAZE_HEIGHT; j++)
        {
            maze->cells[i][j].visited = 0;
            for (int k = 0; k < 4; k++)
            {
                maze->cells[i][j].walls[k] = 1;
            }
        }
    }
    return maze;
}

// Prints the maze to the console
void print_maze(maze *maze)
{
    for (int i = 0; i < MAZE_WIDTH; i++)
    {
        for (int j = 0; j < MAZE_HEIGHT; j++)
        {
            if (maze->cells[i][j].walls[NORTH])
            {
                printf("+---+");
            }
            else
            {
                printf("+   +");
            }
        }
        printf("\n");
        for (int j = 0; j < MAZE_HEIGHT; j++)
        {
            if (maze->cells[i][j].walls[WEST])
            {
                printf("|   |");
            }
            else
            {
                printf("    ");
            }
        }
        printf("\n");
    }
}

// Solves the maze using a depth-first search algorithm
int solve_maze(maze *maze, int x, int y)
{
    if (x == MAZE_WIDTH - 1 && y == MAZE_HEIGHT - 1)
    {
        return 1;
    }
    if (x < 0 || x >= MAZE_WIDTH || y < 0 || y >= MAZE_HEIGHT)
    {
        return 0;
    }
    if (maze->cells[x][y].visited)
    {
        return 0;
    }
    maze->cells[x][y].visited = 1;
    if (solve_maze(maze, x + 1, y))
    {
        return 1;
    }
    if (solve_maze(maze, x, y + 1))
    {
        return 1;
    }
    if (solve_maze(maze, x - 1, y))
    {
        return 1;
    }
    if (solve_maze(maze, x, y - 1))
    {
        return 1;
    }
    return 0;
}

// Generates a random maze
void generate_maze(maze *maze)
{
    // Set the starting cell
    int x = 0;
    int y = 0;

    // Create a stack to store the cells that have been visited
    int stack[MAZE_WIDTH * MAZE_HEIGHT];
    int top = 0;

    // While the stack is not empty
    while (top > 0)
    {
        // Pop the top cell from the stack
        int x = stack[top - 1];
        int y = stack[top - 2];
        top -= 2;

        // Mark the cell as visited
        maze->cells[x][y].visited = 1;

        // Get the list of unvisited neighbors
        int neighbors[4];
        int num_neighbors = 0;
        if (!maze->cells[x + 1][y].visited)
        {
            neighbors[num_neighbors++] = EAST;
        }
        if (!maze->cells[x][y + 1].visited)
        {
            neighbors[num_neighbors++] = SOUTH;
        }
        if (!maze->cells[x - 1][y].visited)
        {
            neighbors[num_neighbors++] = WEST;
        }
        if (!maze->cells[x][y - 1].visited)
        {
            neighbors[num_neighbors++] = NORTH;
        }

        // If there are any unvisited neighbors
        if (num_neighbors > 0)
        {
            // Choose a random neighbor
            int neighbor = neighbors[rand() % num_neighbors];

            // Break down the wall between the current cell and the neighbor
            switch (neighbor)
            {
            case EAST:
                maze->cells[x][y].walls[EAST] = 0;
                maze->cells[x + 1][y].walls[WEST] = 0;
                break;
            case SOUTH:
                maze->cells[x][y].walls[SOUTH] = 0;
                maze->cells[x][y + 1].walls[NORTH] = 0;
                break;
            case WEST:
                maze->cells[x][y].walls[WEST] = 0;
                maze->cells[x - 1][y].walls[EAST] = 0;
                break;
            case NORTH:
                maze->cells[x][y].walls[NORTH] = 0;
                maze->cells[x][y - 1].walls[SOUTH] = 0;
                break;
            }

            // Push the neighbor onto the stack
            stack[top++] = x + (neighbor == EAST ? 1 : 0) - (neighbor == WEST ? 1 : 0);
            stack[top++] = y + (neighbor == SOUTH ? 1 : 0) - (neighbor == NORTH ? 1 : 0);
        }
    }
}

// Main function
int main()
{
    // Seed the random number generator
    srand(time(NULL));

    // Create a new maze
    maze *maze = create_maze();

    // Generate the maze
    generate_maze(maze);

    // Print the maze to the console
    print_maze(maze);

    // Solve the maze
    if (solve_maze(maze, 0, 0))
    {
        printf("Maze solved!\n");
    }
    else
    {
        printf("Maze unsolvable!\n");
    }

    return 0;
}