//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: multi-threaded
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_ROWS 10
#define MAX_COLS 10

// Define the grid for the algorithm
int grid[MAX_ROWS][MAX_COLS] = {
    {0, 0, 1, 0, 0, 0, 0, 1, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
    {0, 0, 1, 0, 1, 0, 0, 0, 0, 0},
    {0, 0, 1, 0, 1, 0, 0, 0, 0, 0},
    {0, 0, 1, 0, 1, 0, 0, 0, 0, 0},
    {0, 0, 1, 0, 1, 0, 0, 0, 0, 0},
    {0, 0, 1, 0, 1, 0, 0, 0, 0, 0},
    {0, 0, 1, 0, 1, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
    {0, 0, 1, 0, 0, 0, 0, 1, 0, 0},
};

// Define the start and end points
int start_row = 0;
int start_col = 0;
int end_row = 9;
int end_col = 9;

bool visited[MAX_ROWS][MAX_COLS] = {{false}};

void* pathfinding_algorithm(void* arg)
{
    int current_row = start_row;
    int current_col = start_col;
    int* path_length = (int*)malloc(sizeof(int));
    *path_length = 0;
    int x_dir[4] = {0, 1, 0, -1};
    int y_dir[4] = {1, 0, -1, 0};

    while (current_row != end_row || current_col != end_col)
    {
        visited[current_row][current_col] = true;

        int next_row = -1;
        int next_col = -1;
        int min_distance = MAX_ROWS * MAX_COLS;

        for (int i = 0; i < 4; i++)
        {
            int row = current_row + x_dir[i];
            int col = current_col + y_dir[i];

            if (row >= 0 && row < MAX_ROWS &&
                col >= 0 && col < MAX_COLS &&
                grid[row][col] == 0 && !visited[row][col])
            {
                int distance = (row - end_row) * (row - end_row) + (col - end_col) * (col - end_col);

                if (distance < min_distance)
                {
                    min_distance = distance;
                    next_row = row;
                    next_col = col;
                }
            }
        }

        if (next_row == -1 || next_col == -1)
        {
            *path_length = -1;
            break;
        }

        current_row = next_row;
        current_col = next_col;
        *path_length += 1;
    }

    pthread_exit(path_length);
}

int main()
{
    pthread_t thread_id;
    pthread_create(&thread_id, NULL, pathfinding_algorithm, NULL);

    int* path_length;
    pthread_join(thread_id, (void**)&path_length);

    if (*path_length == -1)
    {
        printf("No path found!\n");
        return -1;
    }

    printf("Path length: %d\n", *path_length);

    return 0;
}