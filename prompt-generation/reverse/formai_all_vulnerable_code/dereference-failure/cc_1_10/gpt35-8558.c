//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: ultraprecise
#include<stdio.h>
#include<stdlib.h>

// maze size
#define ROW 11
#define COL 11

// maze
char maze[ROW][COL] = {
    "+-+-+-+-+-+-+-+-+-+",
    "| |     |     |   |",
    "+ +-+ +-+ +-+ + +-+",
    "|   | |   | | |   |",
    "+-+ + + + + + + + +",
    "|   | | |   | |   |",
    "+ +-+ + + +-+ +-+ +",
    "|     |   | |     |",
    "+-+ +-+-+-+ +-+-+ +",
    "|   |       | |   |",
    "+-+-+-+-+-+-+-+ +-+"
};

// structure for a cell in the maze
struct Cell {
    int row;
    int col;
};

// stack for backtracking
struct Stack {
    struct Cell* arr[ROW*COL];
    int top;
};

// function to create a new cell
struct Cell* newCell(int row, int col) {
    struct Cell* cell = (struct Cell*) malloc(sizeof(struct Cell));
    cell->row = row;
    cell->col = col;
    return cell;
}

// function to initialize a stack
struct Stack* initStack() {
    struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));
    stack->top = -1;
    return stack;
}

// function to push a cell to the stack
void push(struct Stack* stack, struct Cell* cell) {
    stack->arr[++stack->top] = cell;
}

// function to pop a cell from the stack
struct Cell* pop(struct Stack* stack) {
    return stack->arr[stack->top--];
}

// function to check if the cell is valid
int isValidCell(int row, int col) {
    if(row >= 0 && row < ROW && col >= 0 && col < COL && maze[row][col] == ' ') {
        return 1;
    }
    return 0;
}

// function to check if the cell is the destination
int isDestination(int row, int col) {
    if(row == ROW-2 && col == COL-2) {
        return 1;
    }
    return 0;
}

// function to find the route in the maze
void findRoute() {
    struct Stack* stack = initStack();
    struct Cell* start = newCell(1, 1);
    push(stack, start);
    
    while(stack->top != -1) {
        struct Cell* current = pop(stack);
        int row = current->row;
        int col = current->col;
        maze[row][col] = '+';
        
        // check if the current cell is the destination
        if(isDestination(row, col)) {
            printf("Route found!\n");
            maze[row][col] = 'X';
            for(int i=0; i<ROW; i++) {
                for(int j=0; j<COL; j++) {
                    printf("%c", maze[i][j]);
                }
                printf("\n");
            }
            return;
        }
        
        // add adjacent cells to the stack
        if(isValidCell(row+1, col)) { // down
            struct Cell* down = newCell(row+1, col);
            push(stack, down);
        }
        if(isValidCell(row, col+1)) { // right
            struct Cell* right = newCell(row, col+1);
            push(stack, right);
        }
        if(isValidCell(row-1, col)) { // up
            struct Cell* up = newCell(row-1, col);
            push(stack, up);
        }
        if(isValidCell(row, col-1)) { // left
            struct Cell* left = newCell(row, col-1);
            push(stack, left);
        }
    }
    
    printf("Route not found!\n");
}

// main function
int main() {
    findRoute();
    return 0;
}