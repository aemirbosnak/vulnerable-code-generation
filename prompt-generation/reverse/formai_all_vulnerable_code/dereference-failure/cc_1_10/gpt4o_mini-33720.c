//GPT-4o-mini DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to compute the Levenshtein distance between two strings
int levenshtein_distance(const char *s1, const char *s2) {
    int len_s1 = strlen(s1);
    int len_s2 = strlen(s2);
    int **d = malloc((len_s1 + 1) * sizeof(int *));
    
    for (int i = 0; i <= len_s1; i++) {
        d[i] = malloc((len_s2 + 1) * sizeof(int));
    }

    for (int i = 0; i <= len_s1; i++) {
        d[i][0] = i;
    }
    for (int j = 0; j <= len_s2; j++) {
        d[0][j] = j;
    }

    for (int i = 1; i <= len_s1; i++) {
        for (int j = 1; j <= len_s2; j++) {
            int cost = (s1[i - 1] == s2[j - 1]) ? 0 : 1;
            d[i][j] = fmin(fmin(d[i - 1][j] + 1, d[i][j - 1] + 1), d[i - 1][j - 1] + cost);
        }
    }

    int result = d[len_s1][len_s2];

    for (int i = 0; i <= len_s1; i++) {
        free(d[i]);
    }
    free(d);

    return result;
}

// Function to read string input
char* read_input(const char* prompt) {
    printf("%s", prompt);
    char *input = malloc(100 * sizeof(char));
    fgets(input, 100, stdin);
    input[strcspn(input, "\n")] = '\0'; // remove newline character
    return input;
}

// Main function
int main() {
    printf("Welcome to the Levenshtein Distance Calculator!\n");
    char *string1 = read_input("Please enter the first string: ");
    char *string2 = read_input("Please enter the second string: ");

    int distance = levenshtein_distance(string1, string2);
    
    printf("The Levenshtein distance between \"%s\" and \"%s\" is: %d\n", string1, string2, distance);
    
    free(string1);
    free(string2);
    
    printf("Thank you for using the Levenshtein Distance Calculator.\n");
    return 0;
}