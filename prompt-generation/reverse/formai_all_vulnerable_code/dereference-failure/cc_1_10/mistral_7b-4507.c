//MISTRAL-7B DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: Sherlock Holmes
#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100

char string1[MAX_LENGTH], string2[MAX_LENGTH];
int matrix[MAX_LENGTH][MAX_LENGTH];

void init_matrix() {
    int i, j;

    for (i = 0; i < MAX_LENGTH; i++) {
        for (j = 0; j < MAX_LENGTH; j++) {
            matrix[i][j] = i;
        }
    }

    matrix[0][0] = 0;
}

int min(int a, int b, int c) {
    if (a <= b && a <= c) {
        return a;
    }
    if (b <= a && b <= c) {
        return b;
    }
    return c;
}

int calculate_distance() {
    int i, j;

    for (i = 0; string1[i] != '\0'; i++) {
        for (j = 0; string2[j] != '\0'; j++) {
            if (string1[i] == string2[j]) {
                matrix[i+1][j+1] = matrix[i][j];
            } else {
                matrix[i+1][j+1] = 1 + min(matrix[i+1][j], matrix[i][j+1], matrix[i][j]);
            }
        }
    }

    return matrix[strlen(string1)][strlen(string2)];
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <string1> <string2>\n", argv[0]);
        return 1;
    }

    strcpy(string1, argv[1]);
    strcpy(string2, argv[2]);

    init_matrix();

    printf("The Levenshtein Distance between '%s' and '%s' is %d.\n", string1, string2, calculate_distance());

    return 0;
}