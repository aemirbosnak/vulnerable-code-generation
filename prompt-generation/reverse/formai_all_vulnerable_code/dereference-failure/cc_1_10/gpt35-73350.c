//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>

#define MAX_X 10
#define MAX_Y 10

typedef struct node
{
    int x, y;
    int g, h, f;
    struct node *parent;
} Node;

Node *start, *end;
int grid[MAX_X][MAX_Y];
Node *open_list[MAX_X * MAX_Y];
int open_list_size = 0;
Node *closed_list[MAX_X * MAX_Y];
int closed_list_size = 0;

int heuristic(Node *n)
{
    int dx = abs(n->x - end->x);
    int dy = abs(n->y - end->y);
    return dx + dy;
}

void add_open_list(Node *n)
{
    open_list[open_list_size] = n;
    open_list_size++;
}

Node *get_lowest_f()
{
    int lowest_i = 0;
    for (int i = 1; i < open_list_size; i++)
    {
        if (open_list[i]->f < open_list[lowest_i]->f)
        {
            lowest_i = i;
        }
    }
    Node *lowest_node = open_list[lowest_i];
    open_list_size--;
    open_list[lowest_i] = open_list[open_list_size];
    return lowest_node;
}

int is_node_in_closed_list(Node *n)
{
    for (int i = 0; i < closed_list_size; i++)
    {
        if (closed_list[i]->x == n->x && closed_list[i]->y == n->y)
        {
            return 1;
        }
    }
    return 0;
}

void add_closed_list(Node *n)
{
    closed_list[closed_list_size] = n;
    closed_list_size++;
}

Node *create_node(int x, int y)
{
    Node *n = (Node *)malloc(sizeof(Node));
    n->x = x;
    n->y = y;
    n->g = 0;
    n->h = heuristic(n);
    n->f = n->g + n->h;
    n->parent = NULL;
    return n;
}

void print_path(Node *n)
{
    if (n->parent)
    {
        print_path(n->parent);
    }
    printf("(%d, %d) -> ", n->x, n->y);
}

void print_grid()
{
    for (int y = 0; y < MAX_Y; y++)
    {
        for (int x = 0; x < MAX_X; x++)
        {
            if (grid[x][y])
            {
                printf(" x ");
            }
            else
            {
                printf(" o ");
            }
        }
        printf("\n");
    }
}

void find_path()
{
    add_open_list(start);

    while (open_list_size > 0)
    {
        Node *current_node = get_lowest_f();
        if (current_node == end)
        {
            print_path(current_node);
            printf("(%d, %d)\n", current_node->x, current_node->y);
            return;
        }
        add_closed_list(current_node);

        for (int dx = -1; dx <= 1; dx++)
        {
            for (int dy = -1; dy <= 1; dy++)
            {
                int x = current_node->x + dx;
                int y = current_node->y + dy;
                if (x >= 0 && x < MAX_X && y >= 0 && y < MAX_Y)
                {
                    if (grid[x][y] || is_node_in_closed_list(create_node(x, y)))
                    {
                        continue;
                    }
                    int g = current_node->g + 1;
                    Node *successor = create_node(x, y);
                    if (!is_node_in_closed_list(successor))
                    {
                        int in_open_list = 0;
                        for (int i = 0; i < open_list_size; i++)
                        {
                            if (open_list[i]->x == successor->x && open_list[i]->y == successor->y)
                            {
                                in_open_list = 1;
                                break;
                            }
                        }
                        if (!in_open_list || g < successor->g)
                        {
                            successor->parent = current_node;
                            successor->g = g;
                            successor->f = g + heuristic(successor);
                            if (!in_open_list)
                            {
                                add_open_list(successor);
                            }
                        }
                    }
                }
            }
        }
    }
    printf("No path found.\n");
}

int main()
{
    printf("Welcome to the surreal A* pathfinding algorithm!\n\n");
    printf("Enter the start location (x, y): ");
    int start_x, start_y;
    scanf("%d %d", &start_x, &start_y);
    start = create_node(start_x, start_y);
    printf("Enter the end location (x, y): ");
    int end_x, end_y;
    scanf("%d %d", &end_x, &end_y);
    end = create_node(end_x, end_y);
    printf("Enter the grid (0 - empty, 1 - obstacle):\n");
    for (int y = 0; y < MAX_Y; y++)
    {
        for (int x = 0; x < MAX_X; x++)
        {
            scanf("%d", &grid[x][y]);
        }
    }
    printf("\n");
    printf("Here is the grid:\n\n");
    print_grid();

    printf("\n");
    printf("Finding the path...\n\n");
    find_path();

    return 0;
}