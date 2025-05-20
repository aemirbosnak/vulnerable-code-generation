//Falcon-180B DATASET v1.0 Category: Pattern printing ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 1000

typedef struct {
    int row;
    int col;
} Point;

void print_pattern(int n, Point* pattern, char (*p)[MAX_SIZE]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (pattern[i].row == i && pattern[i].col == j) {
                printf("%s", p[i]);
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main() {
    int n, m;
    printf("Enter the size of the pattern: ");
    scanf("%d", &n);

    Point pattern[n];
    printf("Enter the coordinates of the pattern (row col):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &pattern[i].row, &pattern[i].col);
    }

    char (*p)[MAX_SIZE] = (char (*)[MAX_SIZE]) malloc(n * sizeof(char[MAX_SIZE]));
    if (p == NULL) {
        printf("Memory error\n");
        return 1;
    }

    printf("Enter the pattern:\n");
    for (int i = 0; i < n; i++) {
        scanf("%s", p[i]);
    }

    print_pattern(n, pattern, p);

    free(p);
    return 0;
}