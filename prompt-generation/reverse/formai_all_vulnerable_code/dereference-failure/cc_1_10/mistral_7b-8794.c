//MISTRAL-7B DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: inquisitive
// The Enigma of String Similarity: A Whimsical C Quest for the Levenshtein Distance

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_STRING_LENGTH 100

// The Mystic Function that Calculates the Distance Between Two Strings
// Using the Wise Teachings of the Honorable Vladimir Levenshtein
// (But with a Bit of a Modern Twist, You Understand)
int levenshtein_distance(char *str1, char *str2, int length1, int length2) {
    int matrix[length1 + 1][length2 + 1];
    int i, j, cost;

    // Initialize the Matrix with Infinite Distances
    for (i = 0; i <= length1; i++) {
        for (j = 0; j <= length2; j++) {
            matrix[i][j] = i > 0 ? i - 1 : j > 0 ? j - 1 : 0;
        }
    }

    // Update the Matrix with the Cost of Each Character Edit Operation
    for (i = 1; i <= length1; i++) {
        for (j = 1; j <= length2; j++) {
            cost = (str1[i - 1] == str2[j - 1]) ? 0 : 1;
            matrix[i][j] = 1 + min(matrix[i - 1][j], // Deletion
                                   matrix[i][j - 1], // Insertion
                                   matrix[i - 1][j - 1] + cost); // Substitution
        }
    }

    return matrix[length1][length2];
}

// The Humble Helper Function that Finds the Minimum of Three Integers
int min(int a, int b, int c) {
    return (a < b) ? ((a < c) ? a : c) : ((b < c) ? b : c);
}

// The Curious Main Function that Solves the Enigma of Two Given Strings
int main(int argc, char *argv[]) {
    char string1[MAX_STRING_LENGTH], string2[MAX_STRING_LENGTH];
    int length1, length2;

    if (argc != 3) {
        printf("Usage: %s <string1> <string2>\n", argv[0]);
        return 1;
    }

    strcpy(string1, argv[1]);
    strcpy(string2, argv[2]);

    length1 = strlen(string1);
    length2 = strlen(string2);

    printf("The Levenshtein Distance Between '%s' and '%s' is %d.\n", string1, string2, levenshtein_distance(string1, string2, length1, length2));

    return 0;
}