//GPT-4o-mini DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to find the minimum of three integers
int min(int a, int b, int c) {
    if (a <= b && a <= c) return a;
    if (b <= a && b <= c) return b;
    return c;
}

// Function to calculate the Levenshtein distance between two strings
int levenshtein_distance(const char *str1, const char *str2) {
    int len_str1 = strlen(str1);
    int len_str2 = strlen(str2);
    int **d = malloc((len_str1 + 1) * sizeof(int *));
    
    for (int i = 0; i <= len_str1; i++) {
        d[i] = malloc((len_str2 + 1) * sizeof(int));
    }

    for (int i = 0; i <= len_str1; i++) {
        d[i][0] = i; // Distance from str1 to empty str2
    }
    for (int j = 0; j <= len_str2; j++) {
        d[0][j] = j; // Distance from empty str1 to str2
    }

    for (int i = 1; i <= len_str1; i++) {
        for (int j = 1; j <= len_str2; j++) {
            int cost = (str1[i - 1] == str2[j - 1]) ? 0 : 1;
            d[i][j] = min(d[i - 1][j] + 1,      // Deletion
                          d[i][j - 1] + 1,      // Insertion
                          d[i - 1][j - 1] + cost); // Substitution
        }
    }

    int result = d[len_str1][len_str2];

    for (int i = 0; i <= len_str1; i++) {
        free(d[i]);
    }
    free(d);
    return result;
}

// Function to read strings from user input
void read_input(char *str1, char *str2, int size) {
    printf("Enter the first string: ");
    fgets(str1, size, stdin);
    str1[strcspn(str1, "\n")] = 0; // Remove trailing newline

    printf("Enter the second string: ");
    fgets(str2, size, stdin);
    str2[strcspn(str2, "\n")] = 0; // Remove trailing newline
}

// Function to display the Levenshtein distance
void display_results(const char *str1, const char *str2, int distance) {
    printf("\nLevenshtein Distance between \"%s\" and \"%s\" is: %d\n", str1, str2, distance);
}

// Main function
int main() {
    const int MAX_LENGTH = 100; // Maximum length for input strings
    char str1[MAX_LENGTH];
    char str2[MAX_LENGTH];
    
    read_input(str1, str2, MAX_LENGTH);
    int distance = levenshtein_distance(str1, str2);
    display_results(str1, str2, distance);
    
    return 0;
}