//Falcon2-11B DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: accurate
#include <stdio.h>
#include <string.h>

/* Function to calculate the Levenshtein Distance between two strings */
int levenshtein_distance(const char* str1, const char* str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    int** matrix = (int**) malloc(len1 + 1 * sizeof(int*));
    for (int i = 0; i <= len1; i++) {
        matrix[i] = (int*) malloc(len2 + 1 * sizeof(int));
    }

    // Initialize the first row
    for (int i = 0; i <= len2; i++) {
        matrix[0][i] = i;
    }

    // Initialize the first column
    for (int j = 0; j <= len1; j++) {
        matrix[j][0] = j;
    }

    // Fill in the remaining cells of the matrix
    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            if (str1[i - 1] == str2[j - 1]) {
                matrix[i][j] = matrix[i - 1][j - 1];
            } else {
                int deletion = matrix[i - 1][j] + 1;
                int insertion = matrix[i][j - 1] + 1;
                int substitution = matrix[i - 1][j - 1] + 1;
                matrix[i][j] = (deletion < insertion && deletion < substitution)? deletion :
                        (insertion < deletion && insertion < substitution)? insertion : substitution;
            }
        }
    }

    // Return the value in the bottom-right cell of the matrix
    free(matrix[0]);
    free(matrix[0]);
    return matrix[len1][len2];
}

int main() {
    const char* str1 = "kitten";
    const char* str2 = "sitting";

    int distance = levenshtein_distance(str1, str2);
    printf("Levenshtein Distance between \"%s\" and \"%s\" is %d\n", str1, str2, distance);

    return 0;
}