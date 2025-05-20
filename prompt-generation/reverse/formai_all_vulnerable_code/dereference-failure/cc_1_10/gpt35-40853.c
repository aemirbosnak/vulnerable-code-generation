//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int row;
    int col;
} Point;

typedef struct {
    Point *s;
    int top;
    int size;
} Stack;

void init_stack(Stack *st, int size) {
    st->s = (Point *) malloc(sizeof(Point) * size);
    st->top = -1;
    st->size = size;
}

void push(Stack *st, Point p) {
    if (st->top == st->size - 1) {
        printf("Error: Stack overflow\n");
        exit(1);
    }
    st->top++;
    st->s[st->top] = p;
}

Point pop(Stack *st) {
    if (st->top < 0) {
        printf("Error: Stack underflow\n");
        exit(1);
    }
    Point p = st->s[st->top];
    st->top--;
    return p;
}

Point peek(Stack *st) {
    if (st->top < 0) {
        printf("Error: Stack underflow\n");
        exit(1);
    }
    return st->s[st->top];
}

int is_stack_empty(Stack *st) {
    return st->top == -1;
}

void print_stack(Stack *st) {
    printf("[");
    for (int i = 0; i <= st->top; i++) {
        printf("(%d,%d)", st->s[i].row, st->s[i].col);
        if (i != st->top) printf(",");
    }
    printf("]\n");
}

void find_path(int rows, int cols, int maze[rows][cols]) {
    Stack st;
    Point start, end;
    init_stack(&st, rows*cols);
    printf("Enter starting point (row col): ");
    scanf("%d %d", &start.row, &start.col);
    printf("Enter ending point (row col): ");
    scanf("%d %d", &end.row, &end.col);
    push(&st, start);
    while (!is_stack_empty(&st)) {
        Point curr = pop(&st);
        if (curr.row == end.row && curr.col == end.col) {
            printf("Found path:\n");
            print_stack(&st);
            return;
        }
        maze[curr.row][curr.col] = 1;
        if (curr.row > 0 && maze[curr.row-1][curr.col] == 0) {
            Point up = {curr.row-1, curr.col};
            push(&st, up);
        }
        if (curr.row < rows-1 && maze[curr.row+1][curr.col] == 0) {
            Point down = {curr.row+1, curr.col};
            push(&st, down);
        }
        if (curr.col > 0 && maze[curr.row][curr.col-1] == 0) {
            Point left = {curr.row, curr.col-1};
            push(&st, left);
        }
        if (curr.col < cols-1 && maze[curr.row][curr.col+1] == 0) {
            Point right = {curr.row, curr.col+1};
            push(&st, right);
        }
    }
    printf("No path found\n");
}

int main() {
    int rows, cols;
    printf("Enter number of rows and columns: ");
    scanf("%d %d", &rows, &cols);
    int maze[rows][cols];
    printf("Enter maze (0 for open, 1 for blocked):\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &maze[i][j]);
        }
    }
    find_path(rows, cols, maze);
    return 0;
}