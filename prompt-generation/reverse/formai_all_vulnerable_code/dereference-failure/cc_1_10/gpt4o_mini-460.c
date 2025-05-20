//GPT-4o-mini DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

typedef struct {
    const char *str1;
    const char *str2;
    int len1;
    int len2;
    int **dist_matrix;
} LevenshteinTask;

void *calculate_leven_distance(void *arg) {
    LevenshteinTask *task = (LevenshteinTask *)arg;
    int len1 = task->len1;
    int len2 = task->len2;
    int **dist = task->dist_matrix;

    for (int i = 0; i <= len1; i++) {
        for (int j = 0; j <= len2; j++) {
            if (i == 0) {
                dist[i][j] = j; // Min. operations = j
            } else if (j == 0) {
                dist[i][j] = i; // Min. operations = i
            } else if (task->str1[i - 1] == task->str2[j - 1]) {
                dist[i][j] = dist[i - 1][j - 1]; // No operation
            } else {
                dist[i][j] = 1 + ((dist[i - 1][j] < dist[i][j - 1]) ? (dist[i - 1][j] < dist[i - 1][j - 1] ? dist[i - 1][j] : dist[i - 1][j - 1]) : (dist[i][j - 1] < dist[i - 1][j - 1] ? dist[i][j - 1] : dist[i - 1][j - 1])); // Min. of Insert, Remove, Substitute
            }
        }
    }

    pthread_exit(NULL);
}

int **create_distance_matrix(int len1, int len2) {
    int **matrix = malloc((len1 + 1) * sizeof(int *));
    for (int i = 0; i <= len1; i++) {
        matrix[i] = malloc((len2 + 1) * sizeof(int));
    }
    return matrix;
}

void free_distance_matrix(int **matrix, int len1) {
    for (int i = 0; i <= len1; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

int main() {
    char str1[100], str2[100];
    
    printf("Enter first string: ");
    fgets(str1, sizeof(str1), stdin);
    str1[strcspn(str1, "\n")] = 0; // Remove newline character

    printf("Enter second string: ");
    fgets(str2, sizeof(str2), stdin);
    str2[strcspn(str2, "\n")] = 0; // Remove newline character

    int len1 = strlen(str1);
    int len2 = strlen(str2);

    int **dist_matrix = create_distance_matrix(len1, len2);
    
    LevenshteinTask task = {str1, str2, len1, len2, dist_matrix};

    pthread_t thread;
    pthread_create(&thread, NULL, calculate_leven_distance, (void *)&task);
    pthread_join(thread, NULL);

    printf("The Levenshtein distance between \"%s\" and \"%s\" is %d\n", str1, str2, dist_matrix[len1][len2]);

    free_distance_matrix(dist_matrix, len1);
    return 0;
}