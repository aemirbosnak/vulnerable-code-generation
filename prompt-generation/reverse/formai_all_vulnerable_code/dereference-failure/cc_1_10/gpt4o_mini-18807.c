//GPT-4o-mini DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int min(int a, int b, int c) {
    int minimum = a < b ? a : b;
    return minimum < c ? minimum : c;
}

int levenshtein_distance(const char *str1, const char *str2) {
    size_t len1 = strlen(str1);
    size_t len2 = strlen(str2);
    int **d = malloc((len1 + 1) * sizeof(int *));
    
    if (d == NULL) {
        perror("Failed to allocate memory");
        exit(EXIT_FAILURE);
    }

    for (size_t i = 0; i <= len1; i++) {
        d[i] = malloc((len2 + 1) * sizeof(int));
        if (d[i] == NULL) {
            perror("Failed to allocate memory");
            exit(EXIT_FAILURE);
        }
    }

    for (size_t i = 0; i <= len1; i++) {
        d[i][0] = i;
    }
    for (size_t j = 0; j <= len2; j++) {
        d[0][j] = j;
    }

    for (size_t i = 1; i <= len1; i++) {
        for (size_t j = 1; j <= len2; j++) {
            int cost = (str1[i - 1] == str2[j - 1]) ? 0 : 1;
            d[i][j] = min(d[i - 1][j] + 1,      // Deletion
                          d[i][j - 1] + 1,      // Insertion
                          d[i - 1][j - 1] + cost); // Substitution
        }
    }

    int distance = d[len1][len2];

    for (size_t i = 0; i <= len1; i++) {
        free(d[i]);
    }
    free(d);

    return distance;
}

void get_input_strings(char **str1, char **str2) {
    size_t size = 100;
    *str1 = malloc(size * sizeof(char));
    *str2 = malloc(size * sizeof(char));

    if (*str1 == NULL || *str2 == NULL) {
        perror("Failed to allocate memory for strings");
        exit(EXIT_FAILURE);
    }

    printf("Enter the first string: ");
    if (fgets(*str1, size, stdin) == NULL) {
        perror("Error reading first string");
        exit(EXIT_FAILURE);
    }
    (*str1)[strcspn(*str1, "\n")] = '\0';  // Remove newline character

    printf("Enter the second string: ");
    if (fgets(*str2, size, stdin) == NULL) {
        perror("Error reading second string");
        exit(EXIT_FAILURE);
    }
    (*str2)[strcspn(*str2, "\n")] = '\0';  // Remove newline character
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