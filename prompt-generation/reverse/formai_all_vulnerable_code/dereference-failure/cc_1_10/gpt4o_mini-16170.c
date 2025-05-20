//GPT-4o-mini DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to find the minimum of three integers
int min(int a, int b, int c) {
    return (a < b) ? (a < c ? a : c) : (b < c ? b : c);
}

// Function to calculate Levenshtein distance
int levenshtein_distance(const char *str1, const char *str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int **distance = malloc((len1 + 1) * sizeof(int *));
    
    for (int i = 0; i <= len1; i++) {
        distance[i] = malloc((len2 + 1) * sizeof(int));
        distance[i][0] = i; // Distance from str1 to empty str2
    }
    
    for (int j = 0; j <= len2; j++) {
        distance[0][j] = j; // Distance from empty str1 to str2
    }

    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            int cost = (str1[i - 1] == str2[j - 1]) ? 0 : 1;
            distance[i][j] = min(distance[i - 1][j] + 1, 
                                 distance[i][j - 1] + 1, 
                                 distance[i - 1][j - 1] + cost);
        }
    }
    
    int result = distance[len1][len2];
    
    for (int i = 0; i <= len1; i++) {
        free(distance[i]);
    }
    free(distance);
    
    return result;
}

// Function to prompt user for strings with whimsical twists
void prompt_user_for_strings(char *str1, char *str2, size_t size) {
    printf("Enter the first word as if it's a portal to another dimension:\n");
    fgets(str1, size, stdin);
    str1[strcspn(str1, "\n")] = 0; // Remove newline character
    
    printf("Now, cast your spell for the second word:\n");
    fgets(str2, size, stdin);
    str2[strcspn(str2, "\n")] = 0; // Remove newline character
}

// The grand main function - an odyssey begins here!
int main() {
    const size_t BUFFER_SIZE = 1024;
    char str1[BUFFER_SIZE];
    char str2[BUFFER_SIZE];
    
    prompt_user_for_strings(str1, str2, BUFFER_SIZE);
    
    // Whirling vortex of calculation
    int distance = levenshtein_distance(str1, str2);
    
    // Enter the Dimensions of Creativity
    printf("\nIn the kaleidoscope of words, the Levenshtein distance between ");
    printf("\"%s\" and \"%s\" is a staggering %d\n", str1, str2, distance);
    
    printf("What a voyage through the realms of strings! ");
    printf("May your next adventure be even more enlightening!\n");

    return 0;
}