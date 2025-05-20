//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: surprised
#include<stdio.h>
#include<stdlib.h>

// global variables
#define ROWS 10
#define COLS 10
char maze[ROWS][COLS] = {
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},  
    {'#', ' ', '#', '#', '#', ' ', '#', '#', ' ', '#'},
    {'#', ' ', '#', ' ', ' ', ' ', '#', '#', ' ', '#'},
    {'#', ' ', '#', '#', ' ', '#', ' ', ' ', ' ', '#'},
    {'#', ' ', ' ', '#', ' ', '#', ' ', '#', ' ', '#'},
    {'#', '#', ' ', ' ', ' ', ' ', '#', '#', ' ', '#'},
    {'#', ' ', '#', '#', '#', ' ', ' ', ' ', ' ', '#'},
    {'#', ' ', ' ', '#', '#', '#', '#', ' ', '#', '#'},
    {'#', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}
};
struct Node{
    int row, col;
    struct Node *next;
} *head, *tail;

/* function declarations */
struct Node* createNode(int row, int col);
void push(int row, int col);
void pop();
void printMaze();
struct Node* findSolution(int startX, int startY, int endX, int endY);
void printSolution(struct Node *solution);

int main(){
    // initialize the queue
    head = tail = NULL;

    // find the solution to the maze from (1, 1) to (8, 8)
    struct Node *solution = findSolution(1, 1, 8, 8);

    // print the solution
    printSolution(solution);

    return 0;
}

/* create a new Node */
struct Node* createNode(int row, int col){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->row = row;
    newNode->col = col;
    newNode->next = NULL;

    return newNode;
}

/* push a new Node onto the queue */
void push(int row, int col){
    struct Node *newNode = createNode(row, col);
    if(head == NULL){ // if the queue is empty
        head = tail = newNode;
    }else{
        tail->next = newNode;
        tail = newNode;
    }
}

/* pop the first Node off the queue */
void pop(){
    struct Node *temp = head;
    if(head == NULL){ // if the queue is empty
        return;
    }else if(head == tail){ // if there is only one Node in the queue
        head = tail = NULL;
    }else{
        head = head->next;
    }

    free(temp);
}

/* print the maze */
void printMaze(){
    for(int i=0; i<ROWS; i++){
        for(int j=0; j<COLS; j++){
            printf("%c ", maze[i][j]);
        }
        printf("\n");
    }
}

/* find the solution to the maze */
struct Node* findSolution(int startX, int startY, int endX, int endY){
    push(startX, startY); // add the starting location to the queue
    maze[startX][startY] = '+'; // mark the starting location as visited
    
    while(head != NULL){
        // get the current position from the front of the queue
        int row = head->row;
        int col = head->col;
        
        // check if we have reached the end of the maze
        if(row == endX && col == endY){
            return head; // return the solution path
        }

        // check if we can move up
        if(maze[row-1][col] == ' ' || maze[row-1][col] == 'E'){
            push(row-1, col); // add the new position to the queue
            maze[row-1][col] = '+'; // mark the new position as visited
        }
        // check if we can move down
        if(maze[row+1][col] == ' ' || maze[row+1][col] == 'E'){
            push(row+1, col); // add the new position to the queue
            maze[row+1][col] = '+'; // mark the new position as visited
        }
        // check if we can move left
        if(maze[row][col-1] == ' ' || maze[row][col-1] == 'E'){
            push(row, col-1); // add the new position to the queue
            maze[row][col-1] = '+'; // mark the new position as visited
        }
        // check if we can move right
        if(maze[row][col+1] == ' ' || maze[row][col+1] == 'E'){
            push(row, col+1); // add the new position to the queue
            maze[row][col+1] = '+'; // mark the new position as visited
        }

        pop(); // remove the current position from the queue
    }

    return NULL; // no solution was found
}

/* print the solution path */
void printSolution(struct Node *solution){
    if(solution == NULL){
        printf("No solution was found.\n");
        return;
    }

    // mark the solution path with '#'
    while(solution != NULL){
        int row = solution->row;
        int col = solution->col;

        if(maze[row][col] != 'S' && maze[row][col] != 'E'){
            maze[row][col] = '#';
        }

        solution = solution->next;
    }

    // print the maze with the solution path
    printMaze();
}