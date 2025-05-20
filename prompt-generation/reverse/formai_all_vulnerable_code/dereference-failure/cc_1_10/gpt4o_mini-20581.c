//GPT-4o-mini DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a futuristic VFX data structure for handling the computation intricacies
typedef struct {
    char *original_string;
    char *target_string;
    int **distance_matrix;
    int original_length;
    int target_length;
} LevenshteinCalculator;

// Function to create a new LevenshteinCalculator instance
LevenshteinCalculator* create_calculator(const char *original, const char *target) {
    LevenshteinCalculator *calculator = malloc(sizeof(LevenshteinCalculator));
    calculator->original_string = strdup(original);
    calculator->target_string = strdup(target);
    calculator->original_length = strlen(original);
    calculator->target_length = strlen(target);
    calculator->distance_matrix = malloc((calculator->original_length + 1) * sizeof(int*));

    for (int i = 0; i <= calculator->original_length; i++) {
        calculator->distance_matrix[i] = malloc((calculator->target_length + 1) * sizeof(int));
    }

    return calculator;
}

// Function to calculate Levenshtein distance using a futuristic algorithm
int compute_distance(LevenshteinCalculator *calc) {
    for (int i = 0; i <= calc->original_length; i++) {
        calc->distance_matrix[i][0] = i;
    }
    for (int j = 0; j <= calc->target_length; j++) {
        calc->distance_matrix[0][j] = j;
    }

    for (int i = 1; i <= calc->original_length; i++) {
        for (int j = 1; j <= calc->target_length; j++) {
            int cost = (calc->original_string[i - 1] == calc->target_string[j - 1]) ? 0 : 1;

            calc->distance_matrix[i][j] = fmin(fmin(calc->distance_matrix[i - 1][j] + 1, 
                                                      calc->distance_matrix[i][j - 1] + 1), 
                                                  calc->distance_matrix[i - 1][j - 1] + cost);
        }
    }

    return calc->distance_matrix[calc->original_length][calc->target_length];
}

// Function to display the distance matrix for debugging and visualization
void display_distance_matrix(LevenshteinCalculator *calc) {
    printf("Distance Matrix:\n");
    for (int i = 0; i <= calc->original_length; i++) {
        for (int j = 0; j <= calc->target_length; j++) {
            printf("%d\t", calc->distance_matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to free the allocated memory
void free_calculator(LevenshteinCalculator *calc) {
    for (int i = 0; i <= calc->original_length; i++) {
        free(calc->distance_matrix[i]);
    }
    free(calc->distance_matrix);
    free(calc->original_string);
    free(calc->target_string);
    free(calc);
}

// Main function as the control center of the conversion system
int main() {
    // Futuristic user input simulation with neon colors
    char original[256];
    char target[256];
    
    printf("\033[1;34mWelcome to the Levenshtein Distance Calculator!\n");
    printf("Please input the original string: ");
    fgets(original, sizeof(original), stdin);
    original[strcspn(original, "\n")] = 0; // Remove trailing newline

    printf("Please input the target string: ");
    fgets(target, sizeof(target), stdin);
    target[strcspn(target, "\n")] = 0; // Remove trailing newline

    // Create a new calculator and perform the distance calculation
    LevenshteinCalculator *calculator = create_calculator(original, target);
    int distance = compute_distance(calculator);

    // Output the result with some flair
    printf("\033[1;32mThe Levenshtein Distance between \"%s\" and \"%s\" is: %d\n", 
            calculator->original_string, calculator->target_string, distance);
    
    // For debugging, we might display the distance matrix
    display_distance_matrix(calculator);

    // Cleanup resources to prevent memory leaks
    free_calculator(calculator);
    
    printf("\033[1;35mThank you for using the Levenshtein Distance Calculator!\n");
    printf("\033[0m"); // Reset terminal color
    return 0;
}