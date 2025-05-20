//GPT-4o-mini DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LEN 100

// Function prototypes
void getInput(char *str1, char *str2);
int min(int a, int b, int c);
int levenshteinDistance(const char *str1, const char *str2);
void printResult(const char *str1, const char *str2, int distance);

int main() {
    char str1[MAX_STR_LEN];
    char str2[MAX_STR_LEN];

    getInput(str1, str2);

    int distance = levenshteinDistance(str1, str2);
    
    printResult(str1, str2, distance);

    return 0;
}

// Function to get input from the user
void getInput(char *str1, char *str2) {
    printf("Enter the first string: ");
    fgets(str1, MAX_STR_LEN, stdin);
    str1[strcspn(str1, "\n")] = 0; // Remove newline character

    printf("Enter the second string: ");
    fgets(str2, MAX_STR_LEN, stdin);
    str2[strcspn(str2, "\n")] = 0; // Remove newline character
}

// Helper function to find the minimum of three integers
int min(int a, int b, int c) {
    int min_value = a < b ? a : b;
    return min_value < c ? min_value : c;
}

// Function to calculate the Levenshtein distance
int levenshteinDistance(const char *str1, const char *str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    int **d = (int**)malloc((len1 + 1) * sizeof(int*));
    
    for (int i = 0; i <= len1; i++)
        d[i] = (int*)malloc((len2 + 1) * sizeof(int));

    for (int i = 0; i <= len1; i++)
        d[i][0] = i;
    for (int j = 0; j <= len2; j++)
        d[0][j] = j;

    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            int cost = (str1[i - 1] == str2[j - 1]) ? 0 : 1;
            d[i][j] = min(d[i - 1][j] + 1,      // Deletion
                          d[i][j - 1] + 1,      // Insertion
                          d[i - 1][j - 1] + cost); // Substitution
        }
    }

    int result = d[len1][len2];

    for (int i = 0; i <= len1; i++)
        free(d[i]);
    free(d);

    return result;
}

// Function to print the result
void printResult(const char *str1, const char *str2, int distance) {
    printf("The Levenshtein distance between \"%s\" and \"%s\" is: %d\n", str1, str2, distance);
}