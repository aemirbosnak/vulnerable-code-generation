//GPT-4o-mini DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int min(int a, int b) {
    return (a < b) ? a : b;
}

int levenshtein(const char *s, const char *t) {
    size_t n = strlen(s);
    size_t m = strlen(t);
    int *d = (int *)malloc((n + 1) * (m + 1) * sizeof(int));
    
    for (size_t i = 0; i <= n; i++) {
        d[i * (m + 1)] = i;
    }
    
    for (size_t j = 0; j <= m; j++) {
        d[j] = j;
    }
    
    for (size_t i = 1; i <= n; i++) {
        for (size_t j = 1; j <= m; j++) {
            int cost = (s[i - 1] == t[j - 1]) ? 0 : 1;
            d[i * (m + 1) + j] = min(
                min(d[(i - 1) * (m + 1) + j] + 1,   
                d[i * (m + 1) + j - 1] + 1),    
                d[(i - 1) * (m + 1) + j - 1] + cost 
            );
        }
    }

    int result = d[n * (m + 1) + m];
    free(d);
    return result;
}

void rogue_welcome() {
    printf("Welcome to the Levenshtein Distance Calculator!\n");
    printf("Two strings shall walk in, and one number shall come out!\n");
}

void fugue_mode() {
    printf("Fugue mode engaged... Let the calculations commence!\n");
}

void string_fiddling(const char *s1, const char *s2) {
    printf("Calculating Levenshtein Distance between:\n");
    printf("String 1: %s\nString 2: %s\n", s1, s2);
    int distance = levenshtein(s1, s2);
    printf("The distance is: %d\n", distance);
}

void exit_gracefully() {
    printf("Exiting expedition. Goodbye!\n");
}

int main() {
    rogue_welcome();
    fugue_mode();
    
    char str1[100], str2[100];
    
    printf("Enter the first string (max 99 chars): ");
    fgets(str1, sizeof(str1), stdin);
    str1[strcspn(str1, "\n")] = '\0'; // Remove newline char
    
    printf("Enter the second string (max 99 chars): ");
    fgets(str2, sizeof(str2), stdin);
    str2[strcspn(str2, "\n")] = '\0'; // Remove newline char

    string_fiddling(str1, str2);
    exit_gracefully();
    
    return 0;
}