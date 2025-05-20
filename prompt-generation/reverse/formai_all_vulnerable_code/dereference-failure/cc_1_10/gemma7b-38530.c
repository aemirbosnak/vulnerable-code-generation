//Gemma-7B DATASET v1.0 Category: Data mining ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *str1 = "The quick brown fox jumps over the lazy dog.";
    char *str2 = "The swift brown fox leaps over the slumbering lion.";
    char *str3 = "The agile fox races ahead of the cowardly goat.";

    int i = 0;
    int j = 0;
    int k = 0;

    char **arr = (char **)malloc(10 * sizeof(char *));

    for (i = 0; i < 3; i++) {
        arr[i] = (char *)malloc(100 * sizeof(char));
    }

    for (i = 0; str1[i] != '\0'; i++) {
        arr[0][j] = str1[i];
        j++;
    }

    for (i = 0; str2[i] != '\0'; i++) {
        arr[1][k] = str2[i];
        k++;
    }

    for (i = 0; str3[i] != '\0'; i++) {
        arr[2][k] = str3[i];
        k++;
    }

    printf("The words in the first sentence are:");
    for (i = 0; arr[0][i] != '\0'; i++) {
        printf("%c ", arr[0][i]);
    }

    printf("\nThe words in the second sentence are:");
    for (i = 0; arr[1][i] != '\0'; i++) {
        printf("%c ", arr[1][i]);
    }

    printf("\nThe words in the third sentence are:");
    for (i = 0; arr[2][i] != '\0'; i++) {
        printf("%c ", arr[2][i]);
    }

    free(arr);

    return 0;
}