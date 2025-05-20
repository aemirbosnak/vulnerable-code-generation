//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 100

int levenshtein_distance(char *s1, char *s2);

int main()
{
    char str1[MAX_LENGTH], str2[MAX_LENGTH];

    printf("Welcome to the Levenshtein Distance Calculator!\n");
    printf("Please enter two strings to calculate their Levenshtein Distance.\n");

    // Get input strings from user
    printf("Enter the first string: ");
    fgets(str1, MAX_LENGTH, stdin);

    printf("Enter the second string: ");
    fgets(str2, MAX_LENGTH, stdin);

    // Remove newline characters from input strings
    str1[strcspn(str1, "\n")] = 0;
    str2[strcspn(str2, "\n")] = 0;

    // Calculate and print the Levenshtein Distance between the two strings
    printf("The Levenshtein Distance between \"%s\" and \"%s\" is %d.\n", str1, str2, levenshtein_distance(str1, str2));

    return 0;
}

// Function to calculate the Levenshtein Distance between two strings
int levenshtein_distance(char *s1, char *s2)
{
    int len1 = strlen(s1), len2 = strlen(s2);
    int *v0, *v1, *tmp;
    int i, j, cost, distance;

    // Allocate memory for the arrays
    v0 = (int *) calloc(len2 + 1, sizeof(int));
    v1 = (int *) calloc(len2 + 1, sizeof(int));

    // Initialize the first row of the v0 array to 0..len2
    for (i = 0; i <= len2; i++)
    {
        v0[i] = i;
    }

    // Calculate the Levenshtein Distance
    for (i = 0; i < len1; i++)
    {
        // Set the first element of the v1 array to the current row number
        v1[0] = i + 1;

        for (j = 0; j < len2; j++)
        {
            cost = tolower(s1[i]) == tolower(s2[j]) ? 0 : 1;
            v1[j + 1] = fmin(fmin(v1[j] + 1, v0[j + 1] + 1), v0[j] + cost);
        }

        // Swap the v0 and v1 arrays
        tmp = v0;
        v0 = v1;
        v1 = tmp;
    }

    // Get the final Levenshtein Distance from the last element of the v0 array
    distance = v0[len2];

    // Free the memory allocated for the arrays
    free(v0);
    free(v1);

    return distance;
}