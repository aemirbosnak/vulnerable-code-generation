//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

#define ROW 5
#define COL 5
#define OPEN 1
#define CLOSED 2

typedef struct node{
    int row;
    int col;
    int f;
    int g;
    int h;
    struct node* parent;
    int state;
}node;

node** create_map();
void print_map(node** map);
void free_map(node** map);
node* create_start_node(int start_row, int start_col);
node* create_end_node(int end_row, int end_col);
int heuristic(node* n1, node* n2);
node* find_lowest_f(node** closed_list);
void print_path(node* curr);

int main(){
    int start_row = 1;
    int start_col = 1;
    int end_row = 3;
    int end_col = 3;

    node** map = create_map();
    print_map(map);

    node* start = create_start_node(start_row, start_col);
    node* end = create_end_node(end_row, end_col);

    node** open_list = (node**) malloc(ROW * COL * sizeof(node*));
    node** closed_list = (node**) malloc(ROW * COL * sizeof(node*));
    int open_index = 0;
    int closed_index = 0;

    start->h = heuristic(start, end);
    start->f = start->g + start->h;
    open_list[open_index++] = start;

    while(open_index > 0){
        node* curr = find_lowest_f(open_list);
        if(curr->row == end->row && curr->col == end->col){
            print_path(curr);
            free_map(map);
            free(open_list);
            free(closed_list);
            return 0;
        }
        for(int i = -1; i <= 1; i++){
            for(int j = -1; j <= 1; j++){
                if(i == 0 && j == 0){
                    continue;
                }
                int neighbor_row = curr->row + i;
                int neighbor_col = curr->col + j;
                if(neighbor_row < 0 || neighbor_row >= ROW || neighbor_col < 0 || neighbor_col >= COL){
                    continue;
                }
                if(map[neighbor_row][neighbor_col].state == CLOSED){
                    continue;
                }
                if(i != 0 && j != 0){
                    if(map[curr->row][neighbor_col].state == CLOSED || map[neighbor_row][curr->col].state == CLOSED){
                        continue;
                    }
                }
                int tentative_g = curr->g + ((i == 0) ? 10 : 14);
                node* neighbor = &map[neighbor_row][neighbor_col];
                if(!neighbor->state == OPEN || tentative_g < neighbor->g){
                    neighbor->parent = curr;
                    neighbor->g = tentative_g;
                    neighbor->h = heuristic(neighbor, end);
                    neighbor->f = neighbor->g + neighbor->h;
                    if(!neighbor->state == OPEN){
                        open_list[open_index++] = neighbor;
                        neighbor->state = OPEN;
                    } else {
                        for(int k = 0; k < open_index; k++){
                            if(open_list[k]->row == neighbor->row && open_list[k]->col == neighbor->col){
                                open_list[k] = neighbor;
                            }
                        }
                    }
                }
            }
        }
        closed_list[closed_index++] = curr;
        curr->state = CLOSED;
    }
    printf("No valid path found!\n");
    free_map(map);
    free(open_list);
    free(closed_list);
    return 0;
}

//Create a 2D map with randomly placed obstacles
node** create_map(){
    node** map = (node**) malloc(ROW * sizeof(node*));
    for(int i = 0; i < ROW; i++){
        map[i] = (node*) malloc(COL * sizeof(node));
        for(int j = 0; j < COL; j++){
            map[i][j].row = i;
            map[i][j].col = j;
            map[i][j].f = 0;
            map[i][j].g = 0;
            map[i][j].h = 0;
            map[i][j].parent = NULL;
            if(rand() % 5 == 0){
                map[i][j].state = CLOSED;
            } else {
                map[i][j].state = 0;
            }
        }
    }
    return map;
}

//Prints the map in a grid formation to the console
void print_map(node** map){
    printf("Map:\n");
    for(int i = 0; i < ROW; i++){
        for(int j = 0; j < COL; j++){
            if(map[i][j].state == CLOSED){
                printf("X ");
            } else {
                printf("O ");
            }
        }
        printf("\n");
    }
}

//Frees the map memory
void free_map(node** map){
    for(int i = 0; i < ROW; i++){
        free(map[i]);
    }
    free(map);
}

//Creates the start node for the pathfinding
node* create_start_node(int start_row, int start_col){
    node* start = (node*) malloc(sizeof(node));
    start->row = start_row;
    start->col = start_col;
    start->f = 0;
    start->g = 0;
    start->h = 0;
    start->parent = NULL;
    start->state = OPEN;
    return start;
}

//Creates the end node for the pathfinding
node* create_end_node(int end_row, int end_col){
    node* end = (node*) malloc(sizeof(node));
    end->row = end_row;
    end->col = end_col;
    end->f = 0;
    end->g = 0;
    end->h = 0;
    end->parent = NULL;
    end->state = 0;
    return end;
}

//Calculates the heuristic distance between two nodes
int heuristic(node* n1, node* n2){
    int dx = abs(n1->col - n2->col);
    int dy = abs(n1->row - n2->row);
    return (dx + dy) * 10;
}

//Finds the node with the lowest F value in the open list
node* find_lowest_f(node** open_list){
    node* lowest = open_list[0];
    for(int i = 1; i < ROW * COL && open_list[i] != NULL; i++){
        if(open_list[i]->f < lowest->f){
            lowest = open_list[i];
        }
    }
    return lowest;
}

//Prints the path from the end node to the start node
void print_path(node* curr){
    if(curr == NULL){
        return;
    }
    print_path(curr->parent);
    printf("(%d,%d) ", curr->row, curr->col);
}