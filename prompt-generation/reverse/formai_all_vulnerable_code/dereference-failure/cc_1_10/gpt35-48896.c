//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

#define ROWS 10
#define COLS 10

char maze[ROWS][COLS] ={
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
    {'#', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', '#'},
    {'#', ' ', '#', '#', '#', ' ', '#', ' ', '#', '#'}, 
    {'#', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#'},
    {'#', '#', ' ', '#', ' ', '#', '#', '#', ' ', '#'}, 
    {'#', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#'},
    {'#', '#', '#', '#', '#', '#', ' ', '#', ' ', '#'},
    {'#', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', '#'},
    {'#', ' ', '#', '#', '#', '#', '#', '#', ' ', '#'},
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}
};

typedef struct node {
    int x;
    int y;
    struct node *next;
}Node;

Node *current_node = NULL;
Node *start_node = NULL;
Node *end_node = NULL;
Node *path = NULL;

// function to print the maze
void print_maze() {
    for(int i = 0; i < ROWS; i++){
        for(int j = 0; j < COLS; j++){
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }
}

// function to initialize the start and end nodes
void init() {
    start_node = (Node*) malloc(sizeof(Node));
    start_node->x = 1;
    start_node->y = 1;
    start_node->next = NULL;
    
    end_node = (Node*) malloc(sizeof(Node));
    end_node->x = ROWS - 2 ;
    end_node->y = COLS - 2;
    end_node->next = NULL;
}

// function to push a node onto the stack
void push(Node **head, Node *node){
    if(*head == NULL) {
        *head = node;
        current_node = node;
    } else {
        current_node -> next = node;
        current_node = node;
    }
}

// function to pop a node from the stack
Node* pop(Node **head){
    Node *temp = NULL;
    if(*head == NULL) {
        printf("Stack Underflow\n");
    } else {
        temp = *head;
        *head = (*head)->next;
    }
    return temp;
}

//function to check if a given node has already been visited
int is_visited(Node *n) {
    Node *temp = path;
    while(temp != NULL) {
        if(temp->x == n->x && temp->y == n->y) {
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

//function to add a node to the path
void add_to_path(Node *n) {
    Node *new_node = (Node*) malloc(sizeof(Node));
    new_node->x = n->x;
    new_node->y = n->y;
    new_node->next = NULL;
    
    if(path == NULL) {
        path = new_node;
    } else {
        Node *temp = path;
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

//function to find a path through the maze
void maze_route_finder() {
    Node *current_pos = NULL;
    push(&current_pos, start_node);
    add_to_path(current_pos);
    
    while(current_pos != NULL) {
        int x = current_pos->x;
        int y = current_pos->y;
        
        if(x == end_node->x && y == end_node->y) {
            return;
        }
        
        // check north
        if(maze[x-1][y] == ' ' && !is_visited((Node*) &(Node){x-1, y, NULL})) {
            Node *next_pos = (Node*) malloc(sizeof(Node));
            next_pos->x = x-1;
            next_pos->y = y;
            next_pos->next = NULL;
            push(&current_pos, next_pos);
            add_to_path(next_pos);
        }
        
        // check south
        if(maze[x+1][y] == ' ' && !is_visited((Node*) &(Node){x+1, y, NULL})) {
            Node *next_pos = (Node*) malloc(sizeof(Node));
            next_pos->x = x+1;
            next_pos->y = y;
            next_pos->next = NULL;
            push(&current_pos, next_pos);
            add_to_path(next_pos);
        }
        
        // check west
        if(maze[x][y-1] == ' ' && !is_visited((Node*) &(Node){x, y-1, NULL})) {
            Node *next_pos = (Node*) malloc(sizeof(Node));
            next_pos->x = x;
            next_pos->y = y-1;
            next_pos->next = NULL;
            push(&current_pos, next_pos);
            add_to_path(next_pos);
        }
        
        // check east
        if(maze[x][y+1] == ' ' && !is_visited((Node*) &(Node){x, y+1, NULL})) {
            Node *next_pos = (Node*) malloc(sizeof(Node));
            next_pos->x = x;
            next_pos->y = y+1;
            next_pos->next = NULL;
            push(&current_pos, next_pos);
            add_to_path(next_pos);
        }
        
        if(current_pos == NULL) {
            break;
        }
        
        current_pos = pop(&current_pos);
    }
}

int main() {
    init(); //initialize start and end nodes
    maze_route_finder(); //find the path
    Node *temp = path;
    
    //mark the path in the maze
    while(temp != NULL){
        maze[temp->x][temp->y] = '*';
        temp = temp->next;
    }
    
    //print the result
    printf("The maze:\n");
    print_maze();
    
    free(start_node);
    free(end_node);
    free(path);
    return 0;
}