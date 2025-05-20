//Falcon-180B DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to calculate the Levenshtein distance between two strings
int levenshtein(char *str1, char *str2)
{
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    // Initialize the distance matrix
    int **distance = (int **)malloc(len1 * sizeof(int *));
    for (int i = 0; i < len1; i++) {
        distance[i] = (int *)malloc(len2 * sizeof(int));
        for (int j = 0; j < len2; j++) {
            distance[i][j] = 0;
        }
    }

    // Fill the distance matrix
    for (int i = 0; i < len1; i++) {
        distance[i][0] = i;
    }
    for (int j = 0; j < len2; j++) {
        distance[0][j] = j;
    }

    for (int i = 1; i < len1; i++) {
        for (int j = 1; j < len2; j++) {
            if (str1[i - 1] == str2[j - 1]) {
                distance[i][j] = distance[i - 1][j - 1];
            } else {
                distance[i][j] = 1 + min(distance[i - 1][j], distance[i][j - 1], distance[i - 1][j - 1]);
            }
        }
    }

    // Free the distance matrix
    for (int i = 0; i < len1; i++) {
        free(distance[i]);
    }
    free(distance);

    return distance[len1 - 1][len2 - 1];
}

// Function to find the minimum of three integers
int min(int a, int b, int c)
{
    return (a < b)? ((a < c)? a : c) : ((b < c)? b : c);
}

int main()
{
    char str1[100], str2[100];

    // Get the input strings from the user
    printf("Enter the first string: ");
    scanf("%s", str1);
    printf("Enter the second string: ");
    scanf("%s", str2);

    // Calculate the Levenshtein distance between the strings
    int distance = levenshtein(str1, str2);

    // Print the result
    printf("The Levenshtein distance between \"%s\" and \"%s\" is %d.\n", str1, str2, distance);

    return 0;
}