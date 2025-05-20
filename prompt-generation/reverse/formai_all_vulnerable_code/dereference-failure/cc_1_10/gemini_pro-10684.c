//GEMINI-pro DATASET v1.0 Category: Pathfinding algorithms ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// The map is represented as a 2D array of characters.
char map[10][10] = {
    {'#', '#', '#', '#', '#'},
    {'#', ' ', ' ', ' ', '#'},
    {'#', ' ', '#', ' ', '#'},
    {'#', ' ', ' ', ' ', '#'},
    {'#', '#', '#', '#', '#'}
};

// The start and end points are represented as coordinates.
int start_x = 1;
int start_y = 1;
int end_x = 3;
int end_y = 3;

// The queue is used to store the cells that need to be explored.
struct Queue {
    int x;
    int y;
    struct Queue *next;
};

// The queue is initially empty.
struct Queue *head = NULL;
struct Queue *tail = NULL;

// The visited array is used to keep track of the cells that have already been explored.
int visited[10][10] = {0};

// The distance array is used to store the distance from the start cell to each cell.
int distance[10][10] = {0};

// This function adds a cell to the queue.
void enqueue(int x, int y) {
    struct Queue *new_cell = malloc(sizeof(struct Queue));
    new_cell->x = x;
    new_cell->y = y;
    new_cell->next = NULL;

    if (head == NULL) {
        head = new_cell;
        tail = new_cell;
    } else {
        tail->next = new_cell;
        tail = new_cell;
    }
}

// This function removes a cell from the queue.
struct Queue *dequeue() {
    if (head == NULL) {
        return NULL;
    } else {
        struct Queue *temp = head;
        head = head->next;
        return temp;
    }
}

// This function checks if a cell is valid.
int is_valid(int x, int y) {
    return (x >= 0 && x < 10 && y >= 0 && y < 10 && map[x][y] != '#');
}

// This function checks if a cell has been visited.
int is_visited(int x, int y) {
    return (visited[x][y] == 1);
}

// This function marks a cell as visited.
void mark_visited(int x, int y) {
    visited[x][y] = 1;
}

// This function calculates the distance from the start cell to a cell.
int calculate_distance(int x, int y) {
    return (abs(x - start_x) + abs(y - start_y));
}

// This function finds the shortest path from the start cell to the end cell.
int find_shortest_path() {
    // Enqueue the start cell.
    enqueue(start_x, start_y);

    while (head != NULL) {
        // Dequeue the next cell.
        struct Queue *current_cell = dequeue();

        // Mark the cell as visited.
        mark_visited(current_cell->x, current_cell->y);

        // Check if the cell is the end cell.
        if (current_cell->x == end_x && current_cell->y == end_y) {
            return distance[current_cell->x][current_cell->y];
        }

        // Explore the adjacent cells.
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                int x = current_cell->x + i;
                int y = current_cell->y + j;

                // Check if the cell is valid and has not been visited.
                if (is_valid(x, y) && !is_visited(x, y)) {
                    // Calculate the distance from the start cell to the cell.
                    int new_distance = calculate_distance(x, y);

                    // Update the distance array.
                    if (new_distance < distance[x][y] || distance[x][y] == 0) {
                        distance[x][y] = new_distance;
                    }

                    // Enqueue the cell.
                    enqueue(x, y);
                }
            }
        }
    }

    // No path was found.
    return -1;
}

int main() {
    // Find the shortest path from the start cell to the end cell.
    int shortest_path = find_shortest_path();

    // Print the shortest path.
    if (shortest_path == -1) {
        printf("No path was found.\n");
    } else {
        printf("The shortest path is %d.\n", shortest_path);
    }

    return 0;
}