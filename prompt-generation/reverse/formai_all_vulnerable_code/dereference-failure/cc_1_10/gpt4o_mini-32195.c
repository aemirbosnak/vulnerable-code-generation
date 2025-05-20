//GPT-4o-mini DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: Romeo and Juliet
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int min(int a, int b) {
    return a < b ? a : b;
}

int levenshtein_distance(char *s1, char *s2) {
    int len1 = strlen(s1) + 1;
    int len2 = strlen(s2) + 1;
    int **d = (int **)malloc(len1 * sizeof(int *));
    
    for (int i = 0; i < len1; i++) {
        d[i] = (int *)malloc(len2 * sizeof(int));
    }

    for (int i = 0; i < len1; i++) {
        d[i][0] = i; // Distance of any string to an empty string
    }
    
    for (int j = 0; j < len2; j++) {
        d[0][j] = j; // Likewise, distance from empty string is the length of s2
    }

    for (int i = 1; i < len1; i++) {
        for (int j = 1; j < len2; j++) {
            int cost = (s1[i - 1] == s2[j - 1]) ? 0 : 1;
            d[i][j] = min(d[i - 1][j] + 1,      // Deletion
                          min(d[i][j - 1] + 1, // Insertion
                              d[i - 1][j - 1] + cost)); // Substitution
        }
    }

    int distance = d[len1 - 1][len2 - 1];

    for (int i = 0; i < len1; i++) {
        free(d[i]);
    }
    free(d);

    return distance;
}

void speak_to_the_moon(const char *str1, const char *str2) {
    printf("Oh glorious moon, bear witness to this tale,\n");
    printf("As we embark on a quest to measure love’s frail.\n");
    
    printf("Between yon words, '%s' and '%s',\n", str1, str2);
    int distance = levenshtein_distance((char *)str1, (char *)str2);

    printf("Behold, the Levenshtein Distance, %d,\n", distance);
    printf("A number that echoes love’s crossing thread.\n");
}

int main() {
    char *romeo = "Juliet, oh my love!";
    char *juliet = "Romeo, my dear heart!";

    speak_to_the_moon(romeo, juliet);
    
    return 0;
}