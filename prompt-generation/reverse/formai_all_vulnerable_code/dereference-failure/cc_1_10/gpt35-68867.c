//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node
{
    int x, y, f, g, h;
    bool traversable;
    struct node *parent;
};

typedef struct node node_t;

int **create_map(int rows, int cols)
{
    int **map = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++)
        map[i] = (int *)malloc(cols * sizeof(int));

    // initialize map with random values
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            map[i][j] = rand() % 2;

    return map;
}

void free_map(int **map, int rows)
{
    for (int i = 0; i < rows; i++)
        free(map[i]);
    free(map);
}

// euclidean distance heuristic
int heuristic(node_t *node, node_t *goal)
{
    int x_dist = abs(node->x - goal->x);
    int y_dist = abs(node->y - goal->y);
    return x_dist + y_dist;
}

node_t *create_node(int x, int y, bool traversable)
{
    node_t *node = (node_t *)malloc(sizeof(node_t));
    node->x = x;
    node->y = y;
    node->f = 0;
    node->g = 0;
    node->h = 0;
    node->traversable = traversable;
    node->parent = NULL;
    return node;
}

void free_node(node_t *node)
{
    free(node);
}

node_t *get_lowest_f_node(node_t **open_set, int open_set_size)
{
    int lowest_f = open_set[0]->f;
    int lowest_f_index = 0;

    for (int i = 1; i < open_set_size; i++)
    {
        if (open_set[i]->f < lowest_f)
        {
            lowest_f = open_set[i]->f;
            lowest_f_index = i;
        }
    }

    return open_set[lowest_f_index];
}

bool is_in_closed_set(node_t *node, node_t **closed_set, int closed_set_size)
{
    for (int i = 0; i < closed_set_size; i++)
    {
        if (node->x == closed_set[i]->x && node->y == closed_set[i]->y)
        {
            return true;
        }
    }

    return false;
}

bool is_in_open_set(node_t *node, node_t **open_set, int open_set_size)
{
    for (int i = 0; i < open_set_size; i++)
    {
        if (node->x == open_set[i]->x && node->y == open_set[i]->y)
        {
            return true;
        }
    }

    return false;
}

node_t **get_neighbours(node_t *node, int **map, int rows, int cols)
{
    static node_t *neighbours[8];

    int index = 0;

    for (int i = -1; i <= 1; i++)
    {
        for (int j = -1; j <= 1; j++)
        {
            if (i == 0 && j == 0)
                continue;

            int x = node->x + i;
            int y = node->y + j;

            if (x < 0 || x >= rows || y < 0 || y >= cols)
                continue;

            if (!map[x][y])
                continue;

            neighbours[index++] = create_node(x, y, true);
        }
    }

    return neighbours;
}

void reconstruct_path(node_t *current)
{
    node_t *p = current;
    while (p->parent)
    {
        printf("(%d,%d) -> ", p->x, p->y);
        p = p->parent;
    }
    printf("(%d,%d)\n", p->x, p->y);
}

node_t *a_star_search(int **map, int rows, int cols, node_t *start, node_t *goal)
{
    node_t *open_set[rows * cols];
    int open_set_size = 0;

    node_t *closed_set[rows * cols];
    int closed_set_size = 0;

    open_set[open_set_size++] = start;

    while (open_set_size > 0)
    {
        node_t *current = get_lowest_f_node(open_set, open_set_size);
        if (current->x == goal->x && current->y == goal->y)
        {
            return current;
        }

        open_set_size--;
        for (int i = 0; i < open_set_size; i++)
        {
            if (open_set[i] == current)
            {
                open_set[i] = open_set[open_set_size];
                break;
            }
        }

        closed_set[closed_set_size++] = current;

        node_t **neighbours = get_neighbours(current, map, rows, cols);
        int neighbours_size = sizeof(neighbours) / sizeof(node_t *);

        for (int i = 0; i < neighbours_size; i++)
        {
            node_t *neighbour = neighbours[i];

            if (is_in_closed_set(neighbour, closed_set, closed_set_size))
            {
                free_node(neighbour);
                continue;
            }

            int tentative_g_score = current->g + 1;

            if (!is_in_open_set(neighbour, open_set, open_set_size))
            {
                open_set[open_set_size++] = neighbour;
                neighbour->h = heuristic(neighbour, goal);
            }
            else if (tentative_g_score >= neighbour->g)
            {
                free_node(neighbour);
                continue;
            }

            neighbour->parent = current;
            neighbour->g = tentative_g_score;
            neighbour->f = neighbour->g + neighbour->h;
        }
    }

    return NULL;
}

int main()
{
    int rows = 10;
    int cols = 10;

    int **map = create_map(rows, cols);

    node_t *start = create_node(0, 0, true);
    node_t *goal = create_node(rows - 1, cols - 1, true);

    node_t *path = a_star_search(map, rows, cols, start, goal);

    if (path == NULL)
    {
        printf("No path found.\n");
    }
    else
    {
        printf("Path found:\n");
        reconstruct_path(path);
    }

    free_map(map, rows);
    free_node(start);
    free_node(goal);
    free_node(path);

    return 0;
}