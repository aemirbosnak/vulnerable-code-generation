//GPT-4o-mini DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int min(int a, int b, int c) {
    int m = a < b ? a : b;
    return m < c ? m : c;
}

int levenshtein_distance(const char *s1, const char *s2) {
    int len_s1 = strlen(s1);
    int len_s2 = strlen(s2);
    int **d = (int **)malloc((len_s1 + 1) * sizeof(int *));
    
    for (int i = 0; i <= len_s1; i++) {
        d[i] = (int *)malloc((len_s2 + 1) * sizeof(int));
    }

    for (int i = 0; i <= len_s1; i++) {
        d[i][0] = i;  // Deletion cost
    }
    
    for (int j = 0; j <= len_s2; j++) {
        d[0][j] = j;  // Insertion cost
    }

    for (int i = 1; i <= len_s1; i++) {
        for (int j = 1; j <= len_s2; j++) {
            int cost = (s1[i - 1] == s2[j - 1]) ? 0 : 1;
            d[i][j] = min(d[i - 1][j] + 1,      // Deletion
                          d[i][j - 1] + 1,      // Insertion
                          d[i - 1][j - 1] + cost); // Substitution
        }
    }

    int result = d[len_s1][len_s2];
    
    // Free allocated memory
    for (int i = 0; i <= len_s1; i++) {
        free(d[i]);
    }
    free(d);

    return result;
}

void input_strings(char **s1, char **s2) {
    printf("Enter the first string: ");
    *s1 = (char *)malloc(256 * sizeof(char)); // Allocating memory for string 1
    fgets(*s1, 256, stdin);
    (*s1)[strcspn(*s1, "\n")] = 0; // Removing newline character

    printf("Enter the second string: ");
    *s2 = (char *)malloc(256 * sizeof(char)); // Allocating memory for string 2
    fgets(*s2, 256, stdin);
    (*s2)[strcspn(*s2, "\n")] = 0; // Removing newline character
}

void display_result(const char *s1, const char *s2, int distance) {
    printf("Levenshtein Distance between \"%s\" and \"%s\" is: %d\n", s1, s2, distance);
}

int main() {
    char *string1, *string2;

    input_strings(&string1, &string2); // Input strings from user

    int distance = levenshtein_distance(string1, string2); // Calculate distance

    // Display result
    display_result(string1, string2, distance);

    // Free allocated memory for strings
    free(string1);
    free(string2);

    return 0;
}