//GPT-4o-mini DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

// Error handling
void handleError(const char *message) {
    fprintf(stderr, "%s\n", message);
    exit(EXIT_FAILURE);
}

// Function to calculate the Levenshtein distance
int levenshteinDistance(const char *s1, const char *s2) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    
    // Create a distance matrix
    int **dist = malloc((len1 + 1) * sizeof(int *));
    if (dist == NULL) handleError("Memory allocation failed.");

    for (int i = 0; i <= len1; i++) {
        dist[i] = malloc((len2 + 1) * sizeof(int));
        if (dist[i] == NULL) handleError("Memory allocation failed.");
    }

    // Initialize the matrix
    for (int i = 0; i <= len1; i++) {
        dist[i][0] = i;
    }
    for (int j = 0; j <= len2; j++) {
        dist[0][j] = j;
    }

    // Calculate the distances
    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            int cost = (s1[i - 1] == s2[j - 1]) ? 0 : 1;
            dist[i][j] = fmin(fmin(dist[i - 1][j] + 1, dist[i][j - 1] + 1), dist[i - 1][j - 1] + cost);
        }
    }

    int distance = dist[len1][len2];

    // Free allocated memory
    for (int i = 0; i <= len1; i++) {
        free(dist[i]);
    }
    free(dist);
    
    return distance;
}

// Function to read input from the survivor's journal
void readInput(char *buffer, size_t size) {
    printf("In this harsh world, words are often scarce. Input your message (up to %zu characters): ", size - 1);
    if (fgets(buffer, size, stdin) == NULL) {
        handleError("Failed to read input.");
    }
    buffer[strcspn(buffer, "\n")] = '\0'; // Remove trailing newline
}

// Welcome message to survivors still fighting for survival
void welcomeSurvivor() {
    printf("Welcome, weary traveler, to the Levenshtein Distance Calculator.\n");
    printf("In these dark times, we must communicate clearly to continue our fight against the wasteland.\n");
}

// Main function
int main() {
    char message1[MAX_LENGTH];
    char message2[MAX_LENGTH];

    welcomeSurvivor();

    // Read two messages from the survivor
    readInput(message1, sizeof(message1));
    readInput(message2, sizeof(message2));

    // Calculate the Levenshtein distance between the two messages
    int distance = levenshteinDistance(message1, message2);

    // Output the distance
    printf("\nThe cost of miscommunication in this bleak world is %d.\n", distance);
    printf("Keep your words sharp and your spirits high, survivor.\n");

    return 0;
}