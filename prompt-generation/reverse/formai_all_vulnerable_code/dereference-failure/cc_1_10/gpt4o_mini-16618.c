//GPT-4o-mini DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int min(int a, int b, int c) {
    if (a <= b && a <= c) return a;
    if (b <= a && b <= c) return b;
    return c;
}

int levenshtein_distance(const char* s, const char* t) {
    size_t len_s = strlen(s);
    size_t len_t = strlen(t);
  
    // Create distance matrix
    int **d = (int **)malloc((len_s + 1) * sizeof(int *));
    for (size_t i = 0; i <= len_s; i++) {
        d[i] = (int *)malloc((len_t + 1) * sizeof(int));
    }

    // Initialize distance matrix
    for (size_t i = 0; i <= len_s; i++) {
        d[i][0] = i;  // deletion
    }
    for (size_t j = 0; j <= len_t; j++) {
        d[0][j] = j;  // insertion
    }

    // Compute Levenshtein distance
    for (size_t i = 1; i <= len_s; i++) {
        for (size_t j = 1; j <= len_t; j++) {
            int cost = (s[i - 1] == t[j - 1]) ? 0 : 1;
            d[i][j] = min(d[i - 1][j] + 1,      // deletion
                          d[i][j - 1] + 1,      // insertion
                          d[i - 1][j - 1] + cost);  // substitution
        }
    }

    int distance = d[len_s][len_t];

    // Free allocated memory
    for (size_t i = 0; i <= len_s; i++) {
        free(d[i]);
    }
    free(d);

    return distance;
}

void get_input_strings(char **s1, char **s2) {
    size_t buffer_size = 1024;

    *s1 = (char *)malloc(buffer_size * sizeof(char));
    *s2 = (char *)malloc(buffer_size * sizeof(char));

    printf("Enter the first string: ");
    getline(s1, &buffer_size, stdin);
    (*s1)[strcspn(*s1, "\n")] = 0;  // Remove the newline character

    printf("Enter the second string: ");
    getline(s2, &buffer_size, stdin);
    (*s2)[strcspn(*s2, "\n")] = 0;  // Remove the newline character
}

int main() {
    char *str1 = NULL;
    char *str2 = NULL;

    get_input_strings(&str1, &str2);

    int distance = levenshtein_distance(str1, str2);

    printf("The Levenshtein distance between \"%s\" and \"%s\" is: %d\n", str1, str2, distance);

    free(str1);
    free(str2);

    return 0;
}