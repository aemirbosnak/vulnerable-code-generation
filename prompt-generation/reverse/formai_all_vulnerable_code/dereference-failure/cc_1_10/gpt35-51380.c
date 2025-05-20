//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

#define ROWS 10
#define COLS 10

// Struct for storing node information
typedef struct Node
{
    int row, col;
    int f, g, h; // f = g + h
    struct Node* parent;
    int is_obstacle;
} Node;

Node* get_node(int row, int col)
{
    Node* node = (Node*) malloc(sizeof(Node));
    node->row = row;
    node->col = col;
    node->f = 0;
    node->g = 0;
    node->h = 0;
    node->parent = NULL;
    node->is_obstacle = 0;
    return node;
}

// Calculate the distance between two nodes
int get_distance(Node* nodeA, Node* nodeB)
{
    int distX = abs(nodeA->row - nodeB->row);
    int distY = abs(nodeA->col - nodeB->col);
    if (distX > distY)
    {
        return 14 * distY + 10 * (distX - distY);
    }
    return 14 * distX + 10 * (distY - distX);
}

// Check if a node can be added to the open list
int can_add_to_open(Node* node, Node** open, int open_count)
{
    for (int i = 0; i < open_count; i++)
    {
        if (open[i]->row == node->row && open[i]->col == node->col)
        {
            return open[i]->g > node->g;
        }
    }
    return 1;
}

// Check if a node can be added to the closed list
int can_add_to_closed(Node* node, Node** closed, int closed_count)
{
    for (int i = 0; i < closed_count; i++)
    {
        if (closed[i]->row == node->row && closed[i]->col == node->col)
        {
            return closed[i]->g > node->g;
        }
    }
    return 1;
}

void print_map(Node** map)
{
    printf("\n");
    for (int row = 0; row < ROWS; row++)
    {
        for (int col = 0; col < COLS; col++)
        {
            printf("%c", map[row][col].is_obstacle ? 'X' : '.');
        }
        printf("\n");
    }
}

// A* pathfinding algorithm
Node** astar(Node** map, Node* start, Node* end)
{
    Node** open_list = (Node**) malloc(ROWS * COLS * sizeof(Node*));
    Node** closed_list = (Node**) malloc(ROWS * COLS * sizeof(Node*));
    int open_count = 0, closed_count = 0;
    open_list[open_count++] = start;
    
    while (open_count > 0)
    {
        // Find the node with the lowest f value
        int current_index = 0;
        for (int i = 1; i < open_count; i++)
        {
            if (open_list[i]->f < open_list[current_index]->f)
            {
                current_index = i;
            }
        }

        Node* current_node = open_list[current_index];

        // Remove current node from the open list
        for (int i = current_index; i < open_count - 1; i++)
        {
            open_list[i] = open_list[i + 1];
        }
        open_count--;

        // Add current node to the closed list
        closed_list[closed_count++] = current_node;

        // Check if we have reached the end node
        if (current_node->row == end->row && current_node->col == end->col)
        {
            Node** path = (Node**) malloc(ROWS * COLS * sizeof(Node*));
            int path_count = 0;
            Node* current = current_node;
            while (current != NULL)
            {
                path[path_count++] = current;
                current = current->parent;
            }
            return path;
        }

        // Add neighbors to the open list
        for (int i = -1; i <= 1; i++)
        {
            for (int j = -1; j <= 1; j++)
            {
                if (i == 0 && j == 0)
                {
                    continue;
                }

                int row = current_node->row + i;
                int col = current_node->col + j;

                // Check if the neighbor is out of bounds
                if (row < 0 || col < 0 || row >= ROWS || col >= COLS)
                {
                    continue;
                }

                Node* neighbor = &map[row][col];

                // Check if the neighbor is an obstacle
                if (neighbor->is_obstacle)
                {
                    continue;
                }

                // Calculate neighbor values
                int neighbor_g = current_node->g + get_distance(current_node, neighbor);
                int neighbor_h = get_distance(neighbor, end);
                int neighbor_f = neighbor_g + neighbor_h;

                if (!can_add_to_open(neighbor, open_list, open_count) &&
                    !can_add_to_closed(neighbor, closed_list, closed_count))
                {
                    // Add neighbor to the open list
                    neighbor->g = neighbor_g;
                    neighbor->h = neighbor_h;
                    neighbor->f = neighbor_f;
                    neighbor->parent = current_node;
                    open_list[open_count++] = neighbor;
                }
            }
        }
    }

    // No path found
    return NULL;
}

int main()
{
    Node** map = (Node**) malloc(ROWS * sizeof(Node*));
    for (int row = 0; row < ROWS; row++)
    {
        map[row] = (Node*) malloc(COLS * sizeof(Node));
        for (int col = 0; col < COLS; col++)
        {
            map[row][col] = *get_node(row, col);
        }
    }

    // Create obstacles
    map[2][2].is_obstacle = 1;
    map[2][3].is_obstacle = 1;
    map[2][4].is_obstacle = 1;
    map[3][4].is_obstacle = 1;
    map[4][4].is_obstacle = 1;
    map[5][4].is_obstacle = 1;
    map[6][4].is_obstacle = 1;
    map[7][4].is_obstacle = 1;
    map[8][4].is_obstacle = 1;

    print_map(map);

    Node* start = &map[0][0];
    Node* end = &map[ROWS - 1][COLS - 1];
    Node** path = astar(map, start, end);

    // Print path
    if (path != NULL)
    {
        printf("\n");
        for (int i = ROWS * COLS - 1; i >= 0; i--)
        {
            if (path[i] == NULL)
            {
                break;
            }
            printf("(%d,%d) ", path[i]->row, path[i]->col);
            if (i != 0 && (i + 1) % 10 == 0)
            {
                printf("\n");
            }
        }
        printf("\n");
    }
    else
    {
        printf("No path found.\n");
    }

    return 0;
}