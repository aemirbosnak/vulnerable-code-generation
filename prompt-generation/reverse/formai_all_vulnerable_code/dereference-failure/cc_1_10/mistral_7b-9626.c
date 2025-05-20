//MISTRAL-7B DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: romantic
#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100

void print_matrix(int matrix[MAX_LENGTH][MAX_LENGTH], int row, int col) {
    int i, j;

    printf("\nDistance Matrix:\n");

    for (i = 0; i <= row; i++) {
        printf("\n");
        for (j = 0; j <= col; j++) {
            printf("%d ", matrix[i][j]);
        }
    }
}

int min(int a, int b, int c) {
    if (a <= b && a <= c)
        return a;
    else if (b <= a && b <= c)
        return b;
    else
        return c;
}

int calculate_distance(char str1[MAX_LENGTH], char str2[MAX_LENGTH], int length1, int length2) {
    int distance_matrix[length1 + 1][length2 + 1];
    int i, j;

    for (i = 0; i <= length1; i++) {
        for (j = 0; j <= length2; j++) {
            if (i == 0)
                distance_matrix[i][j] = j;

            else if (j == 0)
                distance_matrix[i][j] = i;

            else if (str1[i - 1] == str2[j - 1]) {
                distance_matrix[i][j] = distance_matrix[i - 1][j - 1];
            } else {
                distance_matrix[i][j] =
                    1 + min(distance_matrix[i - 1][j],
                           distance_matrix[i][j - 1],
                           distance_matrix[i - 1][j - 1]);
            }
        }
    }

    return distance_matrix[length1][length2];
}

int main() {
    char Love[MAX_LENGTH] = "Love";
    char Passion[MAX_LENGTH] = "Passion";

    int length_Love = strlen(Love);
    int length_Passion = strlen(Passion);

    int distance = calculate_distance(Love, Passion, length_Love, length_Passion);

    printf("\nThe distance between Love and Passion is %d.\n", distance);

    int matrix[length_Love + 1][length_Passion + 1];

    for (int i = 0; i <= length_Love; i++) {
        for (int j = 0; j <= length_Passion; j++) {
            matrix[i][j] = calculate_distance(Love, Passion, i, j);
        }
    }

    print_matrix(matrix, length_Love, length_Passion);

    return 0;
}