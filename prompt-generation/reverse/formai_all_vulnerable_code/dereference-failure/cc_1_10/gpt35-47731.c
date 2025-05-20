//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Node
{
    int x, y;
    int g, h, f;
    struct Node *parent;
} Node;

typedef struct List
{
    Node *data;
    struct List *next;
} List;

int heuristic(Node *start, Node *goal)
{
    int x = abs(goal->x - start->x);
    int y = abs(goal->y - start->y);
    return sqrt(x*x + y*y);
}

List *insert(List *list, Node *data)
{
    List *new = (List *) malloc(sizeof(List));
    new->data = data;
    new->next = list;
    return new;
}

void remove_item(List **list, Node *data)
{
    List *tmp = *list, *prev = NULL;
    while (tmp != NULL)
    {
        if (tmp->data == data)
        {
            if (prev == NULL)
            {
                *list = tmp->next;
            }
            else
            {
                prev->next = tmp->next;
            }
            free(tmp);
            return;
        }
        prev = tmp;
        tmp = tmp->next;
    }
}

Node *find_lowest_f(List *list)
{
    Node *lowest_f_node = list->data;
    List *tmp = list->next;
    while (tmp != NULL)
    {
        if (tmp->data->f < lowest_f_node->f)
        {
            lowest_f_node = tmp->data;
        }
        tmp = tmp->next;
    }
    return lowest_f_node;
}

List *get_neighbors(Node *node, Node *map, int n, int m)
{
    List *result = NULL;
    int x = node->x, y = node->y;
    if (x > 0 && map[(x-1)*m+y].g != -1)
    {
        result = insert(result, &map[(x-1)*m+y]);
    }
    if (y > 0 && map[x*m+(y-1)].g != -1)
    {
        result = insert(result, &map[x*m+(y-1)]);
    }
    if (x < n-1 && map[(x+1)*m+y].g != -1)
    {
        result = insert(result, &map[(x+1)*m+y]);
    }
    if (y < m-1 && map[x*m+(y+1)].g != -1)
    {
        result = insert(result, &map[x*m+(y+1)]);
    }
    return result;
}

void reconstruct_path(Node *current, Node *start)
{
    if (current->parent == NULL)
    {
        printf("(%d,%d)", current->x, current->y);
        return;
    }
    reconstruct_path(current->parent, start);
    printf(" -> (%d,%d)", current->x, current->y);
}

void A_star(Node *start, Node *goal, Node *map, int n, int m)
{
    List *open_set = insert(NULL, start);
    start->g = 0;
    start->h = heuristic(start, goal);
    start->f = start->g + start->h;
    while (open_set != NULL)
    {
        Node *current = find_lowest_f(open_set);
        if (current == goal)
        {
            reconstruct_path(current, start);
            return;
        }
        remove_item(&open_set, current);
        List *neighbors = get_neighbors(current, map, n, m);
        List *tmp = neighbors;
        while (tmp != NULL)
        {
            Node *neighbor = tmp->data;
            int tentative_g_score = current->g + 1;
            if (tentative_g_score < neighbor->g || neighbor->g == -1)
            {
                neighbor->parent = current;
                neighbor->g = tentative_g_score;
                neighbor->h = heuristic(neighbor, goal);
                neighbor->f = neighbor->g + neighbor->h;
                if (open_set == NULL)
                {
                    open_set = insert(open_set, neighbor);
                }
                else 
                {
                    List *open_tmp = open_set;
                    while (open_tmp != NULL && open_tmp->data->f < neighbor->f)
                    {
                        open_tmp = open_tmp->next;
                    }
                    if (open_tmp == NULL)
                    {
                        open_set = insert(open_set, neighbor);
                    }
                    else 
                    {
                        List *new = (List *) malloc(sizeof(List));
                        new->data = neighbor;
                        new->next = open_tmp->next;
                        open_tmp->next = new;
                    }
                }
            }
            tmp = tmp->next;
        }
        free(neighbors);
    }
    printf("No path found!\n");
}

int main()
{
    int n = 5, m = 5;
    Node *map = (Node *) malloc(n * m * sizeof(Node));
    Node *start = &map[0];
    start->x = 0;
    start->y = 0;
    start->parent = NULL;
    start->g = 0;
    start->h = 0; 
    start->f = 0;
    Node *goal = &map[24];
    goal->x = 4;
    goal->y = 4;
    goal->parent = NULL;
    goal->g = -1;
    goal->h = 0;
    goal->f = -1;
    for (int i = 0; i < n * m; i++)
    {
        Node *node = &map[i];
        node->x = i / m;
        node->y = i % m;
        node->parent = NULL;
        node->g = -1;
        node->h = 0;
        node->f = -1;
    }
    map[1*m+1].g = -1;
    map[2*m+1].g = -1;
    map[3*m+1].g = -1;
    map[1*m+2].g = -1;
    map[2*m+3].g = -1;
    map[3*m+3].g = -1;
    A_star(start, goal, map, n, m);
    free(map);
    return 0;
}