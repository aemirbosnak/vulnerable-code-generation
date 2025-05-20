//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_ROWS 10
#define MAX_COLS 10
#define INF 1000000

typedef struct node
{
    int row, col;
    int f, g, h;
    struct node* parent;
} Node;

int terrain[MAX_ROWS][MAX_COLS] = {  // example terrain array
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 1, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 1, 1, 1, 1, 1, 1, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 1, 0, 1},
    {1, 1, 1, 0, 1, 1, 1, 1, 0, 1},
    {1, 0, 1, 0, 1, 0, 0, 0, 0, 1},
    {1, 0, 1, 1, 1, 1, 1, 1, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

bool closed_list[MAX_ROWS][MAX_COLS];  // list of visited nodes
Node* open_list[MAX_ROWS * MAX_COLS];  // list of discovered nodes
int open_list_size = 0;  // size of the open list

// returns true if the given row and column are within the bounds of the terrain array
bool in_bounds(int row, int col)
{
    return row >= 0 && row < MAX_ROWS && col >= 0 && col < MAX_COLS;
}

// returns true if the terrain at the given row and column is traversable
bool is_traversable(int row, int col)
{
    return terrain[row][col] == 0;
}

// returns the Manhattan distance between two nodes
int manhattan_distance(Node* a, Node* b)
{
    return abs(a->row - b->row) + abs(a->col - b->col);
}

// initializes a new node with the given row and column
Node* create_node(int row, int col)
{
    Node* node = malloc(sizeof(Node));
    node->row = row;
    node->col = col;
    node->f = INF;
    node->g = INF;
    node->h = INF;
    node->parent = NULL;
    return node;
}

// adds the given node to the open list and sorts the list by f value
void add_to_open_list(Node* node)
{
    open_list[open_list_size++] = node;
    for (int i = open_list_size - 1; i > 0; i--)
    {
        if (open_list[i]->f < open_list[i - 1]->f)
        {
            Node* temp = open_list[i];
            open_list[i] = open_list[i - 1];
            open_list[i - 1] = temp;
        }
        else
        {
            break;
        }
    }
}

// removes the node with the lowest f value from the open list and returns it
Node* pop_from_open_list()
{
    Node* node = open_list[--open_list_size];
    return node;
}

// returns true if the given row and column are in the closed list
bool is_closed(int row, int col)
{
    return closed_list[row][col];
}

// marks the given row and column as visited in the closed list
void mark_closed(int row, int col)
{
    closed_list[row][col] = true;
}

// calculates the f, g, and h values for the given node
void calculate_values(Node* node, Node* start_node, Node* end_node)
{
    node->g = start_node->g + manhattan_distance(node, start_node);
    node->h = manhattan_distance(node, end_node);
    node->f = node->g + node->h;
}

// returns true if the given node is the end node
bool is_end_node(Node* node, Node* end_node)
{
    return node->row == end_node->row && node->col == end_node->col;
}

// frees the memory allocated for the nodes in the open and closed lists
void free_lists()
{
    for (int i = 0; i < open_list_size; i++)
    {
        free(open_list[i]);
    }
}

// finds the shortest path from the given start node to the end node using A* pathfinding
void find_path(Node* start_node, Node* end_node)
{
    add_to_open_list(start_node);
    mark_closed(start_node->row, start_node->col);

    while (open_list_size > 0)
    {
        Node* current_node = pop_from_open_list();

        if (is_end_node(current_node, end_node))
        {
            Node* node = current_node;
            while (node != NULL)
            {
                printf("(%d, %d)\n", node->row, node->col);
                node = node->parent;
            }
            free_lists();
            return;
        }

        int row = current_node->row;
        int col = current_node->col;

        for (int r = row - 1; r <= row + 1; r++)
        {
            for (int c = col - 1; c <= col + 1; c++)
            {
                if (in_bounds(r, c) && !is_closed(r, c) && is_traversable(r, c))
                {
                    Node* neighbour = create_node(r, c);
                    calculate_values(neighbour, start_node, end_node);

                    int i;
                    for (i = 0; i < open_list_size; i++)
                    {
                        if (open_list[i]->row == neighbour->row && open_list[i]->col == neighbour->col)
                        {
                            if (open_list[i]->g > neighbour->g)
                            {
                                open_list[i]->f = neighbour->f;
                                open_list[i]->g = neighbour->g;
                                open_list[i]->h = neighbour->h;
                                open_list[i]->parent = current_node;
                            }
                            break;
                        }
                    }

                    if (i == open_list_size)
                    {
                        neighbour->parent = current_node;
                        mark_closed(neighbour->row, neighbour->col);
                        add_to_open_list(neighbour);
                    }
                }
            }
        }
    }

    printf("No path found.\n");
    free_lists();
}

int main()
{
    Node* start_node = create_node(1, 1);
    Node* end_node = create_node(8, 8);

    find_path(start_node, end_node);

    return 0;
}