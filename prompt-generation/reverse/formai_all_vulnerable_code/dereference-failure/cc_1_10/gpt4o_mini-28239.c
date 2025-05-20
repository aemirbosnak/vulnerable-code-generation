//GPT-4o-mini DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to get the minimum of three integers
int min(int a, int b, int c) {
    if (a <= b && a <= c) return a;
    if (b <= a && b <= c) return b;
    return c;
}

// Function to calculate the Levenshtein Distance between two strings
int levenshtein_distance(const char *str1, const char *str2) {
    int len_str1 = strlen(str1);
    int len_str2 = strlen(str2);
    int **d = malloc((len_str1 + 1) * sizeof(int *));
    
    for (int i = 0; i <= len_str1; i++) {
        d[i] = malloc((len_str2 + 1) * sizeof(int));
        d[i][0] = i; // Deletion cost
    }
    for (int j = 0; j <= len_str2; j++) {
        d[0][j] = j; // Insertion cost
    }

    for (int i = 1; i <= len_str1; i++) {
        for (int j = 1; j <= len_str2; j++) {
            int cost = (str1[i - 1] == str2[j - 1]) ? 0 : 1;

            d[i][j] = min(d[i - 1][j] + 1,      // Deletion
                          d[i][j - 1] + 1,      // Insertion
                          d[i - 1][j - 1] + cost); // Substitution
        }
    }

    int distance = d[len_str1][len_str2];

    for (int i = 0; i <= len_str1; i++) {
        free(d[i]);
    }
    free(d);

    return distance;
}

// Function to read input strings with error handling
void read_input(char *prompt, char *buffer, size_t size) {
    printf("%s", prompt);
    if (fgets(buffer, size, stdin) != NULL) {
        buffer[strcspn(buffer, "\n")] = 0; // Remove the newline character
    } else {
        fprintf(stderr, "Error reading input. Exiting.\n");
        exit(EXIT_FAILURE);
    }
}

// Main function
int main() {
    char str1[100];
    char str2[100];

    printf("Welcome to the Levenshtein Distance Calculator!\n");
    printf("Let's find out how far apart two strings are.\n");

    read_input("Enter the first string: ", str1, sizeof(str1));
    read_input("Enter the second string: ", str2, sizeof(str2));

    int distance = levenshtein_distance(str1, str2);
    printf("The Levenshtein Distance between \"%s\" and \"%s\" is: %d\n", str1, str2, distance);
    
    printf("Thank you for using the Levenshtein Distance Calculator!\n");
    return 0;
}