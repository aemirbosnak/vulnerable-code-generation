//GPT-4o-mini DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

// Function to calculate Levenshtein distance between two strings
int levenshtein_distance(const char *str1, const char *str2) {
    int len_str1 = strlen(str1);
    int len_str2 = strlen(str2);
    int **distance_matrix = (int **)malloc((len_str1 + 1) * sizeof(int *));
    
    for (int i = 0; i <= len_str1; i++) {
        distance_matrix[i] = (int *)malloc((len_str2 + 1) * sizeof(int));
    }

    // Initialize the distance matrix
    for (int i = 0; i <= len_str1; i++) {
        distance_matrix[i][0] = i;
    }
    for (int j = 0; j <= len_str2; j++) {
        distance_matrix[0][j] = j;
    }

    // Compute the Levenshtein distance
    for (int i = 1; i <= len_str1; i++) {
        for (int j = 1; j <= len_str2; j++) {
            int cost = (str1[i - 1] == str2[j - 1]) ? 0 : 1;
            distance_matrix[i][j] = MIN(MIN(distance_matrix[i - 1][j] + 1, distance_matrix[i][j - 1] + 1),
                                         distance_matrix[i - 1][j - 1] + cost);
        }
    }
    
    int distance = distance_matrix[len_str1][len_str2];
    
    // Free the memory allocated for the distance matrix
    for (int i = 0; i <= len_str1; i++) {
        free(distance_matrix[i]);
    }
    free(distance_matrix);
    
    return distance;
}

// Function for getting input strings from the user
void get_input(char **str1, char **str2) {
    size_t size1 = 100;
    size_t size2 = 100;
    
    *str1 = (char *)malloc(size1 * sizeof(char));
    *str2 = (char *)malloc(size2 * sizeof(char));
    
    printf("Enter the first string: ");
    getline(str1, &size1, stdin);
    (*str1)[strcspn(*str1, "\n")] = '\0'; // Remove the newline character
    
    printf("Enter the second string: ");
    getline(str2, &size2, stdin);
    (*str2)[strcspn(*str2, "\n")] = '\0'; // Remove the newline character
}

// Main function for running the Levenshtein distance calculation
int main() {
    char *str1, *str2;
    
    get_input(&str1, &str2);
    
    // Calculate the Levenshtein distance
    int distance = levenshtein_distance(str1, str2);
    
    printf("The Levenshtein distance between \"%s\" and \"%s\" is: %d\n", str1, str2, distance);
    
    // Free allocated memory for strings
    free(str1);
    free(str2);
    
    return 0;
}