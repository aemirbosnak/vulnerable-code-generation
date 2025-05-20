//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>

#define ROW_SIZE 10
#define COL_SIZE 10

int map[ROW_SIZE][COL_SIZE] = {
    {1,1,1,1,1,1,1,1,1,1},
    {1,0,0,0,1,1,0,0,0,1},
    {1,0,1,0,0,0,0,1,0,1},
    {1,0,1,0,1,1,1,1,0,1},
    {1,0,1,0,0,0,0,0,0,1},
    {1,0,1,1,1,0,1,1,1,1},
    {1,0,1,0,0,0,0,0,0,1},
    {1,0,1,0,1,1,1,1,0,1},
    {1,0,0,0,0,0,0,0,0,1},
    {1,1,1,1,1,1,1,1,1,1},
};
// This map represents a maze, with "1"s representing walls and "0"s representing walkable paths.

void print_map() // This function prints the maze, with "X" representing the chosen path and " " representing walkable paths.
{
    for(int i = 0; i < ROW_SIZE; i++)
    {
        for(int j = 0; j < COL_SIZE; j++)
        {
            if(map[i][j] == 1)
            {
                printf("X");
            }
            else if(map[i][j] == 2)
            {
                printf("*");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
}

typedef struct Node
{
    int x;
    int y;
    struct Node* parent;
    int g;
    int h;
    int f;
} Node;

int manhattan_distance(int start_x, int start_y, int end_x, int end_y) // This function calculates the heuristic value (Manhattan distance) for a given starting coordinate and ending coordinate.
{
    int dx = abs(start_x - end_x);
    int dy = abs(start_y - end_y);
    return dx + dy;
}

Node* create_node(int x, int y, Node* parent, int g, int h) // This function creates a new node with the given parameters.
{
    Node* node = (Node*)malloc(sizeof(Node));
    node->x = x;
    node->y = y;
    node->parent = parent;
    node->g = g;
    node->h = h;
    node->f = g + h;
    return node;
}

int is_valid_move(int x, int y) // This function checks if a given coordinate is a valid move (within the bounds of the map and not a wall).
{
    if(x < 0 || x >= ROW_SIZE || y < 0 || y >= COL_SIZE)
    {
        return 0;
    }
    return !map[x][y];
}

Node* find_best_node(Node** open_list) // This function finds the node with the lowest f value in the open list.
{
    Node* best_node = open_list[0];
    for(int i = 1; i < ROW_SIZE * COL_SIZE; i++)
    {
        if(open_list[i] != NULL && open_list[i]->f < best_node->f)
        {
            best_node = open_list[i];
        }
    }
    return best_node;
}

void generate_path(Node* end_node) // This function generates the final path by following the parent pointers of the end node.
{
    Node* node = end_node;
    while(node != NULL)
    {
        map[node->x][node->y] = 2;
        node = node->parent;
    }
}

void find_path(int start_x, int start_y, int end_x, int end_y) // This function finds the shortest path from the starting coordinate to the ending coordinate using the A* algorithm.
{
    Node* start_node = create_node(start_x, start_y, NULL, 0, manhattan_distance(start_x, start_y, end_x, end_y));
    Node* open_list[ROW_SIZE * COL_SIZE];
    Node* closed_list[ROW_SIZE * COL_SIZE];
    for(int i = 0; i < ROW_SIZE * COL_SIZE; i++)
    {
        open_list[i] = NULL;
        closed_list[i] = NULL;
    }
    open_list[start_x * ROW_SIZE + start_y] = start_node;
    while(1)
    {
        Node* current_node = find_best_node(open_list);
        if(current_node == NULL)
        {
            break;
        }
        if(current_node->x == end_x && current_node->y == end_y)
        {
            generate_path(current_node);
            break;
        }
        open_list[current_node->x * ROW_SIZE + current_node->y] = NULL;
        closed_list[current_node->x * ROW_SIZE + current_node->y] = current_node;
        for(int x = current_node->x - 1; x <= current_node->x + 1; x++)
        {
            for(int y = current_node->y - 1; y <= current_node->y + 1; y++)
            {
                if(x == current_node->x && y == current_node->y)
                {
                    continue;
                }
                if(!is_valid_move(x, y))
                {
                    continue;
                }
                int g = current_node->g + manhattan_distance(current_node->x, current_node->y, x, y);
                int h = manhattan_distance(x, y, end_x, end_y);
                Node* child_node = create_node(x, y, current_node, g, h);
                int index = x * ROW_SIZE + y;
                if(closed_list[index] != NULL)
                {
                    free(child_node);
                    continue;
                }
                if(open_list[index] == NULL)
                {
                    open_list[index] = child_node;
                }
                else if(open_list[index]->g > g)
                {
                    open_list[index] = child_node;
                }
                else
                {
                    free(child_node);
                }
            }
        }
    }
}

int main()
{
    print_map();
    find_path(1, 1, 8, 8);
    printf("\n");
    print_map();
    return 0;
}