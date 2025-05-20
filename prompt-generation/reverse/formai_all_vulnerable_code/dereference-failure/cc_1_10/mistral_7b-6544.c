//MISTRAL-7B DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 100

void print_matrix(int **matrix, int length1, int length2) {
    int i, j;
    for (i = 0; i <= length1; i++) {
        for (j = 0; j <= length2; j++) {
            printf("%2d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int min(int a, int b, int c) {
    if (a <= b && a <= c)
        return a;
    if (b <= a && b <= c)
        return b;
    return c;
}

int levenshtein_distance(char *str1, char *str2, int length1, int length2) {
    int **matrix = (int **)calloc((length1 + 1), sizeof(int *));
    for (int i = 0; i <= length1; i++) {
        matrix[i] = (int *)calloc((length2 + 1), sizeof(int));
    }

    for (int i = 0; i <= length1; i++) {
        for (int j = 0; j <= length2; j++) {
            if (i == 0)
                matrix[i][j] = j;
            else if (j == 0)
                matrix[i][j] = i;
            else if (tolower(str1[i - 1]) == tolower(str2[j - 1])) {
                matrix[i][j] = matrix[i - 1][j - 1];
            } else {
                matrix[i][j] =
                    1 + min(matrix[i - 1][j], matrix[i][j - 1], matrix[i - 1][j - 1]);
            }
        }
    }

    int distance = matrix[length1][length2];
    for (int i = 0; i <= length1; i++)
        free(matrix[i]);
    free(matrix);

    return distance;
}

int main() {
    char str1[MAX_LENGTH], str2[MAX_LENGTH];
    int length1 = 0, length2 = 0;

    printf("Enter first string: ");
    scanf("%s", str1);
    length1 = strlen(str1);

    printf("Enter second string: ");
    scanf("%s", str2);
    length2 = strlen(str2);

    printf("\nLevenshtein Distance Matrix:\n");
    levenshtein_distance(str1, str2, length1, length2);
    print_matrix((int **)calloc(length1 + 1, sizeof(int *)), length1 + 1,
                 length2 + 1);

    int distance = levenshtein_distance(str1, str2, length1, length2);
    printf("\nLevenshtein Distance: %d", distance);

    return 0;
}