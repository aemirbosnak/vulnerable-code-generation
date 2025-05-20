//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

#define ROW 10
#define COL 10

int maze[ROW][COL] = {
    {0,0,0,0,0,0,0,0,0,0},
    {0,1,1,0,0,1,1,1,1,0},
    {0,0,1,1,1,1,0,0,0,0},
    {0,0,1,0,0,0,0,1,1,0},
    {0,0,1,1,1,1,1,1,0,0},
    {0,1,0,0,0,0,0,0,0,0},
    {0,1,1,1,1,0,1,1,1,0},
    {0,0,0,0,1,1,0,0,0,0},
    {0,1,1,0,0,0,0,1,1,0},
    {0,0,0,0,0,0,0,0,0,0}
};

typedef struct node{
    int row;
    int col;
    struct node *next;
}Node;

typedef struct list{
    Node *head;
}List;

void init_list(List *list);
void insert_list(List *list, int row, int col);
void delete_list(List *list);
int search_list(List *list, int row, int col);

void a_star_algorithm();

int heuristic(int row, int col);
int min_f_cost_index();
int get_f_cost(int row, int col);
int get_g_cost(int row, int col);
Node *get_nearest_node();
void print_list(List *list);

int open_list[ROW * COL][2];
int closed_list[ROW][COL];

int parent_node[ROW][COL][2];

int g_cost[ROW][COL];
int f_cost[ROW][COL];

int start_row = 1;
int start_col = 1;

int end_row = 8;
int end_col = 8;

int open_size = 0;

List optimal_path;

int main()
{
    init_list(&optimal_path);
    a_star_algorithm();
    print_list(&optimal_path);
    delete_list(&optimal_path);
    return 0;
}

void init_list(List *list)
{
    list->head = NULL;
}

void delete_list(List *list)
{
    while(list->head != NULL)
    {
        Node *temp = list->head;
        list->head = list->head->next;
        free(temp);
    }
}

void insert_list(List *list, int row, int col)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->row = row;
    new_node->col = col;
    new_node->next = NULL;

    if(list->head == NULL)
    {
        list->head = new_node;
    }
    else{
        Node *temp = list->head;
        while(temp->next != NULL)
            temp = temp->next;
        temp->next = new_node;
    }
}

int search_list(List *list, int row, int col)
{
    Node *temp = list->head;
    while(temp != NULL){
        if(temp->row == row && temp->col == col)
            return 1;
        temp = temp->next;
    }
    return 0;
}

void a_star_algorithm(){
    int current_row = start_row, current_col = start_col;
    int i, j;

    for(i=0; i<ROW; i++)
        for(j=0; j<COL; j++)
        {
            parent_node[i][j][0] = -1;
            parent_node[i][j][1] = -1;
            closed_list[i][j] = 0;
            g_cost[i][j] = 10000;
            f_cost[i][j] = 10000;
        }

    g_cost[current_row][current_col] = 0;
    f_cost[current_row][current_col] = heuristic(current_row, current_col);

    insert_list(&optimal_path, current_row, current_col);

    while(current_row != end_row || current_col != end_col)
    {
        int c_row, c_col;
        closed_list[current_row][current_col] = 1;

        c_row = current_row - 1;
        c_col = current_col;
        if(c_row >= 0 && maze[c_row][c_col] == 0)
        {
            int g = get_g_cost(current_row, current_col) + 1;
            int h = heuristic(c_row, c_col);
            int f = g + h;

            if(search_list(&optimal_path, c_row, c_col))
            {
                if(f < get_f_cost(c_row, c_col))
                {
                    g_cost[c_row][c_col] = g;
                    f_cost[c_row][c_col] = f;
                    parent_node[c_row][c_col][0] = current_row;
                    parent_node[c_row][c_col][1] = current_col;
                }
            }
            else if(closed_list[c_row][c_col] == 0)
            {
                g_cost[c_row][c_col] = g;
                f_cost[c_row][c_col] = f;
                parent_node[c_row][c_col][0] = current_row;
                parent_node[c_row][c_col][1] = current_col;
                insert_list(&optimal_path, c_row, c_col);
            }
        }

        c_row = current_row;
        c_col = current_col - 1;
        if(c_col >= 0 && maze[c_row][c_col] == 0)
        {
            int g = get_g_cost(current_row, current_col) + 1;
            int h = heuristic(c_row, c_col);
            int f = g + h;

            if(search_list(&optimal_path, c_row, c_col))
            {
                if(f < get_f_cost(c_row, c_col))
                {
                    g_cost[c_row][c_col] = g;
                    f_cost[c_row][c_col] = f;
                    parent_node[c_row][c_col][0] = current_row;
                    parent_node[c_row][c_col][1] = current_col;
                }
            }
            else if(closed_list[c_row][c_col] == 0)
            {
                g_cost[c_row][c_col] = g;
                f_cost[c_row][c_col] = f;
                parent_node[c_row][c_col][0] = current_row;
                parent_node[c_row][c_col][1] = current_col;
                insert_list(&optimal_path, c_row, c_col);
            }
        }

        c_row = current_row + 1;
        c_col = current_col;
        if(c_row < ROW && maze[c_row][c_col] == 0)
        {
            int g = get_g_cost(current_row, current_col) + 1;
            int h = heuristic(c_row, c_col);
            int f = g + h;

            if(search_list(&optimal_path, c_row, c_col))
            {
                if(f < get_f_cost(c_row, c_col))
                {
                    g_cost[c_row][c_col] = g;
                    f_cost[c_row][c_col] = f;
                    parent_node[c_row][c_col][0] = current_row;
                    parent_node[c_row][c_col][1] = current_col;
                }
            }
            else if(closed_list[c_row][c_col] == 0)
            {
                g_cost[c_row][c_col] = g;
                f_cost[c_row][c_col] = f;
                parent_node[c_row][c_col][0] = current_row;
                parent_node[c_row][c_col][1] = current_col;
                insert_list(&optimal_path, c_row, c_col);
            }
        }

        c_row = current_row;
        c_col = current_col + 1;
        if(c_col < COL && maze[c_row][c_col] == 0)
        {
            int g = get_g_cost(current_row, current_col) + 1;
            int h = heuristic(c_row, c_col);
            int f = g + h;

            if(search_list(&optimal_path, c_row, c_col))
            {
                if(f < get_f_cost(c_row, c_col))
                {
                    g_cost[c_row][c_col] = g;
                    f_cost[c_row][c_col] = f;
                    parent_node[c_row][c_col][0] = current_row;
                    parent_node[c_row][c_col][1] = current_col;
                }
            }
            else if(closed_list[c_row][c_col] == 0)
            {
                g_cost[c_row][c_col] = g;
                f_cost[c_row][c_col] = f;
                parent_node[c_row][c_col][0] = current_row;
                parent_node[c_row][c_col][1] = current_col;
                insert_list(&optimal_path, c_row, c_col);
            }
        }

        if(open_size == 0){
            printf("No Path Found!");
            return;
        }
        Node *min_node = get_nearest_node();
        current_row = min_node->row;
        current_col = min_node->col;
        free(min_node);
    }

    int opt_row = end_row;
    int opt_col = end_col;
    while(opt_row != start_row || opt_col != start_col)
    {
        insert_list(&optimal_path, opt_row, opt_col);
        int temp_row = parent_node[opt_row][opt_col][0];
        int temp_col = parent_node[opt_row][opt_col][1];
        opt_row = temp_row;
        opt_col = temp_col;
    }
    insert_list(&optimal_path, opt_row, opt_col);
}

int heuristic(int row, int col)
{
    return abs(row - end_row) + abs(col - end_col);
}

int min_f_cost_index(){
    int i, min_f_index, min_f_value;
    min_f_index = 0;
    min_f_value = f_cost[open_list[min_f_index][0]][open_list[min_f_index][1]];
    for(i=1; i<open_size; i++)
    {
        if(min_f_value > f_cost[open_list[i][0]][open_list[i][1]])
        {
            min_f_index = i;
            min_f_value = f_cost[open_list[min_f_index][0]][open_list[min_f_index][1]];
        }
    }
    return min_f_index;
}

int get_f_cost(int row, int col)
{
    return f_cost[row][col];
}

int get_g_cost(int row, int col)
{
    return g_cost[row][col];
}

Node *get_nearest_node(){
    int index = min_f_cost_index();
    int row = open_list[index][0];
    int col = open_list[index][1];
    int i, j;

    for(i=index; i<open_size-1; i++)
    {
        open_list[i][0] = open_list[i+1][0];
        open_list[i][1] = open_list[i+1][1];
    }
    open_size--;

    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->row = row;
    new_node->col = col;
    new_node->next = NULL;

    return new_node;
}

void print_list(List *list)
{
    Node *temp = list->head;
    printf("Optimal Path:\n");
    while(temp != NULL)
    {
        printf("(%d, %d) ", temp->row, temp->col);
        temp = temp->next;
    }
}