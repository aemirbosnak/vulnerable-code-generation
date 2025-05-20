//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

// Define the maze size
#define ROWS 10
#define COLS 10

// Maze represented as a 2D array
char Maze[ROWS][COLS] = {
    {'S', '#', '#', '#', '#', '#', '#', '#', '.', '#'},
    {'.', '.', '.', '.', '.', '.', '.', '#', '.', '#'},
    {'.', '#', '.', '#', '#', '#', '.', '#', '.', '#'},
    {'.', '#', '.', '.', '.', '.', '.', '.', '.', '.'},
    {'.', '#', '#', '#', '.', '#', '#', '#', '#', '.'},
    {'.', '.', '.', '#', '.', '#', '.', '.', '.', '.'},
    {'#', '#', '#', '#', '.', '#', '.', '#', '#', '.'},
    {'.', '.', '.', '.', '.', '#', '.', '.', '.', '.'},
    {'.', '#', '#', '#', '.', '#', '#', '#', '.', '#'},
    {'.', '.', '.', '.', '.', '.', '.', '.', '.', 'E'}
};

// Define the position struct
typedef struct Position
{
    int x;
    int y;
} Position;

// Define the queue as a linked list
typedef struct QueueNode
{
    Position data;
    struct QueueNode* next;
} QueueNode;

// Enqueue a new position into the queue
void Enqueue(QueueNode** head, Position data)
{
    QueueNode* new_node = (QueueNode*)malloc(sizeof(QueueNode));
    new_node->data = data;
    new_node->next = NULL;

    if (*head == NULL)
    {
        *head = new_node;
        return;
    }

    QueueNode* cur = *head;
    while (cur->next != NULL)
    {
        cur = cur->next;
    }

    cur->next = new_node;
}

// Dequeue a position from the queue
Position Dequeue(QueueNode** head)
{
    if (*head == NULL)
    {
        Position p = {-1,-1};
        return p;
    }

    QueueNode* temp = *head;
    Position data = (*head)->data;
    *head = (*head)->next;
    free(temp);

    return data;
}

// Check if a position is valid in the maze
int IsValid(Position p)
{
    if (p.x < 0 || p.x >= ROWS || p.y < 0 || p.y >= COLS)
    {
        return 0;
    }

    if (Maze[p.x][p.y] == '#' || Maze[p.x][p.y] == '.')
    {
        return 0;
    }

    return 1;
}

// Find the shortest path from start to end using BFS
void BFS(Position start, Position end)
{
    // Create the visited array
    int visited[ROWS][COLS] = {0};

    // Create the queue
    QueueNode* queue = NULL;

    // Enqueue the starting position
    Enqueue(&queue, start);

    // Mark the starting position as visited
    visited[start.x][start.y] = 1;

    // Keep track of the distance from the start position
    int distance = 0;

    // BFS loop
    while (queue != NULL)
    {
        // Dequeue a position from the queue
        Position cur_pos = Dequeue(&queue);

        // If we have reached the end position, print the distance and return
        if (cur_pos.x == end.x && cur_pos.y == end.y)
        {
            printf("Shortest distance from start to end is %d\n", distance);
            return;
        }

        // Get the neighbors of the current position
        Position neighbors[4] = {
            {cur_pos.x-1, cur_pos.y},
            {cur_pos.x+1, cur_pos.y},
            {cur_pos.x, cur_pos.y-1},
            {cur_pos.x, cur_pos.y+1}
        };

        // Check if the neighbors are valid and enqueue them
        for (int i = 0; i < 4; i++)
        {
            Position neighbor = neighbors[i];
            if (IsValid(neighbor) && !visited[neighbor.x][neighbor.y])
            {
                Enqueue(&queue, neighbor);
                visited[neighbor.x][neighbor.y] = 1;
            }
        }

        // Increment the distance for the next level of nodes
        distance++;
    }

    // If we have reached here, there is no path from start to end
    printf("There is no path from start to end\n");
}

// Main function to run the program
int main()
{
    // Define the start and end positions
    Position start = {0,0};
    Position end = {9,9};

    // Run the BFS algorithm to find the shortest path from start to end
    BFS(start, end);

    return 0;
}