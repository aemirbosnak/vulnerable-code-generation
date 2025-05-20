//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>
#include <unistd.h>

#define ROW 6
#define COL 7
#define INFINITY 99999

/* Task structure for A* algorithm */
struct Task {
    int x;
    int y;
    int f_score;
};
typedef struct Task Task;

/* Global variables */
int grid[ROW][COL] = {
    {0, 0, 0, 0, 0, 0, 0},
    {0, 0, 1, 1, 1, 0, 0},
    {0, 0, 1, 0, 1, 0, 0},
    {0, 0, 1, 0, 1, 0, 0},
    {0, 0, 1, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0}
};

int start_x = 1;
int start_y = 1;
int end_x = 4;
int end_y = 4;

bool visited[ROW][COL];
pthread_t threads[ROW*COL];
int thread_count = 0;

/* Helper function to get the minimum among two values */
int min(int a, int b) {
    return a < b ? a : b;
}

/* Helper function to calculate the heuristic value */
int heuristic(int x, int y) {
    return (abs(x - end_x) + abs(y - end_y));
}

/* Asynchronous implementation of A* pathfinding algorithm */
void* a_star(void* arg) {
    Task* current_task = (Task*)arg;
    int x = current_task->x;
    int y = current_task->y;
    int f_score = current_task->f_score;

    visited[x][y] = true;

    /* Check if this task reached the goal */
    if (x == end_x && y == end_y) {
        printf("\nGoal reached!\n");
        pthread_exit(NULL);
    }

    /* Check North neighbor */
    if (x-1 >= 0 && grid[x-1][y] != 1 && visited[x-1][y] == false) {
        Task* north_task = malloc(sizeof(Task));
        north_task->x = x-1;
        north_task->y = y;
        north_task->f_score = f_score + 1 + heuristic(x-1, y);
        pthread_create(&threads[thread_count++], NULL, a_star, (void*)north_task);
    }

    /* Check South neighbor */
    if (x+1 < ROW && grid[x+1][y] != 1 && visited[x+1][y] == false) {
        Task* south_task = malloc(sizeof(Task));
        south_task->x = x+1;
        south_task->y = y;
        south_task->f_score = f_score + 1 + heuristic(x+1, y);
        pthread_create(&threads[thread_count++], NULL, a_star, (void*)south_task);
    }

    /* Check West neighbor */
    if (y-1 >= 0 && grid[x][y-1] != 1 && visited[x][y-1] == false) {
        Task* west_task = malloc(sizeof(Task));
        west_task->x = x;
        west_task->y = y-1;
        west_task->f_score = f_score + 1 + heuristic(x, y-1);
        pthread_create(&threads[thread_count++], NULL, a_star, (void*)west_task);
    }

    /* Check East neighbor */
    if (y+1 < COL && grid[x][y+1] != 1 && visited[x][y+1] == false) {
        Task* east_task = malloc(sizeof(Task));
        east_task->x = x;
        east_task->y = y+1;
        east_task->f_score = f_score + 1 + heuristic(x, y+1);
        pthread_create(&threads[thread_count++], NULL, a_star, (void*)east_task);
    }

    /* Wait for all threads to finish */
    for (int i=0; i<thread_count; i++) {
        pthread_join(threads[i], NULL);
    }

    free(current_task);
    pthread_exit(NULL);
}

/* Main function */
int main() {
    printf("A* algorithm with asynchronous implementation\n");

    /* Initialize visited array */
    for (int i=0; i<ROW; i++) {
        for (int j=0; j<COL; j++) {
            visited[i][j] = false;
        }
    }

    /* Initialize start task */
    Task* start_task = malloc(sizeof(Task));
    start_task->x = start_x;
    start_task->y = start_y;
    start_task->f_score = heuristic(start_x, start_y);

    /* Call the A* function */
    a_star((void*)start_task);

    return 0;
}