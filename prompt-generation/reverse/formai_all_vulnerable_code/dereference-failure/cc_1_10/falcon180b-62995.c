//Falcon-180B DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 100

int levenshtein_distance(char* str1, char* str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int* matrix = (int*)malloc(sizeof(int) * (len1 + 1) * (len2 + 1));

    for (int i = 0; i <= len1; i++) {
        matrix[i * (len2 + 1)] = i;
    }

    for (int j = 0; j <= len2; j++) {
        matrix[(len1 + 1) * j] = j;
    }

    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            if (str1[i - 1] == str2[j - 1]) {
                matrix[(i - 1) * (len2 + 1) + j] = matrix[(i - 1) * (len2 + 1) + j - 1] + 1;
            } else {
                matrix[(i - 1) * (len2 + 1) + j] = matrix[(i - 1) * (len2 + 1) + j] + 1;
            }
        }
    }

    int distance = matrix[(len1) * (len2 + 1)];

    free(matrix);

    return distance;
}

int main() {
    char str1[MAX_STRING_LENGTH];
    char str2[MAX_STRING_LENGTH];

    printf("Enter first string: ");
    scanf("%s", str1);

    printf("Enter second string: ");
    scanf("%s", str2);

    int distance = levenshtein_distance(str1, str2);

    printf("Levenshtein distance between '%s' and '%s' is %d\n", str1, str2, distance);

    return 0;
}