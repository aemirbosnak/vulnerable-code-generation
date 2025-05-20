//GPT-4o-mini DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int min(int a, int b) {
    return (a < b) ? a : b;
}

int levenshtein_distance(const char *s1, const char *s2) {
    int len_s1 = strlen(s1);
    int len_s2 = strlen(s2);
    int **d = (int **)malloc((len_s1 + 1) * sizeof(int *));
    
    for (int i = 0; i <= len_s1; i++) {
        d[i] = (int *)malloc((len_s2 + 1) * sizeof(int));
    }

    for (int i = 0; i <= len_s1; i++) {
        d[i][0] = i;  // deletion
    }

    for (int j = 0; j <= len_s2; j++) {
        d[0][j] = j;  // insertion
    }

    for (int i = 1; i <= len_s1; i++) {
        for (int j = 1; j <= len_s2; j++) {
            int cost = (s1[i - 1] == s2[j - 1]) ? 0 : 1;
            d[i][j] = min(d[i - 1][j] + 1,        // deletion
                          min(d[i][j - 1] + 1,  // insertion
                              d[i - 1][j - 1] + cost)); // substitution
        }
    }

    int result = d[len_s1][len_s2];

    for (int i = 0; i <= len_s1; i++) {
        free(d[i]);
    }
    free(d);
    
    return result;
}

void read_input(char **s1, char **s2) {
    printf("Enter first string: ");
    *s1 = (char *)malloc(256 * sizeof(char));
    fgets(*s1, 256, stdin);
    (*s1)[strcspn(*s1, "\n")] = '\0';  // Remove new line

    printf("Enter second string: ");
    *s2 = (char *)malloc(256 * sizeof(char));
    fgets(*s2, 256, stdin);
    (*s2)[strcspn(*s2, "\n")] = '\0';  // Remove new line
}

void cleanup(char *s1, char *s2) {
    free(s1);
    free(s2);
}

int main() {
    char *string1 = NULL;
    char *string2 = NULL;

    read_input(&string1, &string2);
    
    int distance = levenshtein_distance(string1, string2);
    printf("Levenshtein Distance: %d\n", distance);
    
    cleanup(string1, string2);
    
    return 0;
}