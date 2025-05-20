//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: peaceful
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define ROW 10
#define COL 10

char maze[ROW][COL] = {
    {'#','#','#','#','#','#','#','#','#','#'},
    {'#',' ','#',' ',' ',' ','#',' ',' ','#'},
    {'#',' ','#',' ','#',' ','#','#',' ','#'},
    {'#',' ','#',' ','#',' ','#',' ',' ','#'},
    {'#',' ','#',' ','#',' ','#',' ','#','#'},
    {'#',' ','#',' ','#',' ','#',' ','#','#'},
    {'#',' ','#','#','#',' ',' ',' ','#','#'},
    {'#',' ',' ',' ','#',' ',' ',' ','#','#'},
    {'#','#','#',' ','#',' ','#','#','#','#'},
    {'#','#','#','#','#','#','#','#','#','#'}
};

int visited[ROW][COL];

int dx[] = {0, -1, 0, 1};
int dy[] = {1, 0, -1, 0};

int goal_x = 9;
int goal_y = 9;

struct node{
    int x;
    int y;
    struct node *next;
};

struct node *head = NULL;

int bfs(){
    head = (struct node *)malloc(sizeof(struct node));
    head->x = 0;
    head->y = 0;
    head->next = NULL;

    visited[0][0] = 1;

    struct node *tail = head;
    struct node *p = head;

    while(p != NULL){
        int x = p->x;
        int y = p->y;

        if(x == goal_x && y == goal_y){
            return 1;
        }

        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || ny < 0 || nx >= ROW || ny >= COL){
                continue;
            }

            if(maze[nx][ny] == '#' || visited[nx][ny] == 1){
                continue;
            }

            struct node *new_node = (struct node *)malloc(sizeof(struct node));
            new_node->x = nx;
            new_node->y = ny;
            new_node->next = NULL;

            tail->next = new_node;
            tail = new_node;
            visited[nx][ny] = 1;
        }
        
        struct node *temp = p;
        p = p->next;
        free(temp);
    }

    return 0;
}

void print_maze(){
    printf("\nMaze:\n");
    for(int i = 0; i < ROW; i++){
        for(int j = 0; j < COL; j++){
            if(visited[i][j] == 1){
                printf(" X");
            }
            else{
                printf("%2c", maze[i][j]);
            }
        }
        printf("\n");
    }
}

void print_route(){
    struct node *p = head;
    printf("\nRoute:\n");
    while(p != NULL){
        printf("(%d, %d)", p->x, p->y);
        if(p->next != NULL){
            printf(" -> ");
        }
        p = p->next;
    }
    printf("\n");
}

int main(){
    memset(visited, 0, sizeof(visited));
    memset(maze, 0, sizeof(maze));

    printf("Finding route in maze ...\n");
    if(bfs()){
        print_maze();
        print_route();
        printf("\nFound route!\n");
    }
    else{
        printf("\nNo route found!\n");
    }

    return 0;
}