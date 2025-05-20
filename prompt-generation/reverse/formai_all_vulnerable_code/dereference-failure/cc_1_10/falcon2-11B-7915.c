//Falcon2-11B DATASET v1.0 Category: Sudoku solver ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 9
#define M 9
#define MAX_NUM 9
#define ERROR -1
#define TRUE 1
#define FALSE 0

typedef struct node {
    int num;
    int isvalid;
    int parent;
    int row;
    int col;
    struct node* next;
} node;

node* initnode(int num, int isvalid) {
    node* n = (node*)malloc(sizeof(node));
    n->num = num;
    n->isvalid = isvalid;
    n->parent = -1;
    n->row = -1;
    n->col = -1;
    n->next = NULL;
    return n;
}

void freesol(node** head) {
    node* cur = *head;
    node* next = cur->next;
    free(cur);
    while (next!= NULL) {
        cur = next;
        next = cur->next;
        free(cur);
    }
}

int solve(node** head, int* grid) {
    int status = FALSE;
    node* cur = *head;
    node* next = cur->next;
    int i;
    for (i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (grid[i*M+j] == ERROR) {
                break;
            }
        }
        if (i == N) {
            status = TRUE;
            return status;
        }
    }
    if (status == FALSE) {
        return status;
    }

    node* cur2 = initnode(0, FALSE);
    cur2->parent = cur->num;
    cur2->row = cur->row;
    cur2->col = cur->col;
    cur2->next = *head;
    *head = cur2;

    for (i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (grid[i*M+j] == ERROR) {
                int num = 1;
                while (num <= MAX_NUM &&!solve(&cur2->next, grid)) {
                    num++;
                }
                if (num > MAX_NUM) {
                    printf("No solution\n");
                    return 0;
                }
                grid[i*M+j] = num;
                return status;
            }
        }
    }

    return FALSE;
}

void printgrid(int* grid) {
    int i, j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            printf("%d", grid[i*M+j]);
        }
        printf("\n");
    }
}

int main() {
    int grid[N*M] = {0};
    int status = solve(&grid, grid);
    if (status == TRUE) {
        printf("Solution:\n");
        printgrid(grid);
    } else {
        printf("No solution\n");
    }
    return 0;
}