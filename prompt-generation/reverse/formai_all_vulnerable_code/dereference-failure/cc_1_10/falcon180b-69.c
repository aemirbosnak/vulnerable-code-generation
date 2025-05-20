//Falcon-180B DATASET v1.0 Category: Pattern printing ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ROWS 10
#define MAX_COLS 10

typedef struct {
    int rows;
    int cols;
    char pattern[MAX_ROWS][MAX_COLS];
} Pattern;

Pattern* createPattern(int rows, int cols) {
    Pattern* pattern = (Pattern*)malloc(sizeof(Pattern));
    pattern->rows = rows;
    pattern->cols = cols;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            pattern->pattern[i][j] = '*';
        }
    }
    return pattern;
}

void printPattern(Pattern* pattern) {
    for (int i = 0; i < pattern->rows; i++) {
        for (int j = 0; j < pattern->cols; j++) {
            printf("%c", pattern->pattern[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int rows, cols;
    printf("Enter number of rows: ");
    scanf("%d", &rows);
    printf("Enter number of columns: ");
    scanf("%d", &cols);

    Pattern* pattern = createPattern(rows, cols);

    int choice;
    do {
        printf("\n");
        printf("1. Fill pattern with random characters\n");
        printf("2. Fill pattern with user input characters\n");
        printf("3. Print pattern\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                for (int i = 0; i < pattern->rows; i++) {
                    for (int j = 0; j < pattern->cols; j++) {
                        pattern->pattern[i][j] = rand() % 26 + 'a';
                    }
                }
                break;
            case 2:
                printf("Enter characters to fill pattern: ");
                scanf(" %[^\n]", pattern->pattern[0]);
                for (int i = 1; i < pattern->rows; i++) {
                    strcpy(pattern->pattern[i], pattern->pattern[0]);
                }
                break;
            case 3:
                printPattern(pattern);
                break;
            case 4:
                free(pattern);
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    } while (choice!= 4);

    return 0;
}