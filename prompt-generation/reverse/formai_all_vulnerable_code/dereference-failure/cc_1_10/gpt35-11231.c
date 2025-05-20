//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

#define ROWS 5
#define COLS 5

struct Node{
    int x, y;
    int f, g, h;
    struct Node* parent;
};

int is_valid(int x, int y){
    return (x >= 0 && x < ROWS && y >= 0 && y < COLS);
}

int is_barrier(int** matrix, int x, int y){
    return matrix[x][y] == 1;
}

int is_visited(int** matrix, int x, int y, int cost){
    return matrix[x][y] == cost;
}

void print_path(int** matrix, struct Node* node){
    while (node != NULL){
        printf("(%d,%d) -> ", node->x, node->y);
        matrix[node->x][node->y] = -2;
        node = node->parent;
    }
    printf("\n");
}

void print_matrix(int** matrix){
    for (int i = 0; i < ROWS; i++){
        for (int j = 0; j < COLS; j++){
            if (matrix[i][j] == -1){
                printf(". ");
            }else if (matrix[i][j] == -2){
                printf("* ");
            }else{
                printf("%d ", matrix[i][j]);
            }
        }
        printf("\n");
    }
}

struct Node* create_node(int x, int y, int f, int g, int h, struct Node* parent){
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->x = x;
    node->y = y;
    node->f = f;
    node->g = g;
    node->h = h;
    node->parent = parent;
    return node;
}

void delete_node(struct Node* node){
    free(node);
}

int calculate_h(int x, int y, int tx, int ty){
    return abs(x - tx) + abs(y - ty);
}

int a_star_search(int** matrix, int sx, int sy, int tx, int ty){
    int found = 0;
    int cost = 0;
    int directions_x[] = {-1, 0, 1, 0};
    int directions_y[] = {0, 1, 0, -1};
    struct Node* start = create_node(sx, sy, 0, 0, 0, NULL);
    start->f = start->g + calculate_h(sx, sy, tx, ty);
    struct Node* end = create_node(tx, ty, 0, 0, 0, NULL);
    struct Node* open_list[ROWS * COLS];
    int open_list_size = 0;
    struct Node* closed_list[ROWS][COLS];
    for (int i = 0; i < ROWS; i++){
        for (int j = 0; j < COLS; j++){
            closed_list[i][j] = NULL;
        }
    }
    open_list[open_list_size++] = start;
    matrix[sx][sy] = cost;
    while (open_list_size > 0){
        struct Node* current = open_list[0];
        int current_index = 0;
        for (int i = 1; i < open_list_size; i++){
            if (open_list[i]->f < current->f){
                current = open_list[i];
                current_index = i;
            }
        }
        open_list[current_index] = open_list[open_list_size - 1];
        open_list_size--;
        closed_list[current->x][current->y] = current;
        if (current->x == end->x && current->y == end->y){
            found = 1;
            break;
        }
        for (int i = 0; i < 4; i++){
            int nx = current->x + directions_x[i];
            int ny = current->y + directions_y[i];
            if (!is_valid(nx, ny)){
                continue;
            }
            if (is_barrier(matrix, nx, ny)){
                continue;
            }
            int new_g = current->g + 1;
            if (is_visited(matrix, nx, ny, cost) && new_g >= matrix[nx][ny]){
                continue;
            }
            int new_h = calculate_h(nx, ny, tx, ty);
            int new_f = new_g + new_h;
            struct Node* neighbor = create_node(nx, ny, new_f, new_g, new_h, current);
            int in_open_list = 0;
            for (int j = 0; j < open_list_size; j++){
                if (open_list[j]->x == neighbor->x && open_list[j]->y == neighbor->y){
                    in_open_list = 1;
                    break;
                }
            }
            if (!in_open_list){
                open_list[open_list_size++] = neighbor;
            }else{
                delete_node(neighbor);
            }
            matrix[nx][ny] = new_g;
        }
    }
    if (found){
        print_path(matrix, end);
        cost = end->g;
        delete_node(end);
    }else{
        printf("Path not found\n");
    }
    delete_node(start);
    for (int i = 0; i < open_list_size; i++){
        delete_node(open_list[i]);
    }
    for (int i = 0; i < ROWS; i++){
        for (int j = 0; j < COLS; j++){
            if (closed_list[i][j] != NULL){
                delete_node(closed_list[i][j]);
            }
        }
    }
    return cost;
}

int main(){
    int matrix[ROWS][COLS] = {
        {0, 0, 0, 1, 0},
        {0, 1, 0, 1, 0},
        {0, 1, 0, 1, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 0, 0, 0}
    };
    int sx = 0, sy = 0;
    int tx = 4, ty = 4;
    printf("Initial matrix:\n");
    print_matrix(matrix);
    printf("Calculating path from (%d,%d) to (%d,%d)\n", sx, sy, tx, ty);
    int cost = a_star_search(matrix, sx, sy, tx, ty);
    printf("Total path cost: %d\n", cost);
    printf("Final matrix:\n");
    print_matrix(matrix);
    return 0;
}