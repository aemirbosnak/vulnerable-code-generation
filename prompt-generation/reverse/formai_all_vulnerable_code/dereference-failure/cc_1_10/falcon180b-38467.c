//Falcon-180B DATASET v1.0 Category: Pattern printing ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_ROWS 100
#define MAX_COLS 100

int main() {
    int rows, cols;
    char **pattern;
    char ch;

    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    pattern = (char **)malloc(rows * sizeof(char *));
    if (pattern == NULL) {
        printf("Memory error\n");
        exit(1);
    }

    for (int i = 0; i < rows; i++) {
        pattern[i] = (char *)malloc(cols * sizeof(char));
        if (pattern[i] == NULL) {
            printf("Memory error\n");
            exit(1);
        }
    }

    printf("Enter the pattern:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%c", &ch);
            pattern[i][j] = ch;
        }
    }

    printf("Pattern:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%c", pattern[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < rows; i++) {
        free(pattern[i]);
    }
    free(pattern);

    return 0;
}