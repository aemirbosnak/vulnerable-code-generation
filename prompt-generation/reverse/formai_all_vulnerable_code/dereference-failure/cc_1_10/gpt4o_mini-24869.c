//GPT-4o-mini DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_LEN 100

typedef struct {
    char *s1;
    char *s2;
    int start;
    int end;
    int **d;
} ThreadData;

int min(int a, int b) {
    return a < b ? a : b;
}

void *levenshtein_segment(void *arg) {
    ThreadData *data = (ThreadData *)arg;
    int i, j;
    int len1 = strlen(data->s1);
    int len2 = strlen(data->s2);

    for (i = data->start; i <= data->end; i++) {
        for (j = 0; j <= len2; j++) {
            if (i == 0) {
                data->d[i][j] = j; // If s1 is empty, all characters of s2 need to be added
            } else if (j == 0) {
                data->d[i][j] = i; // If s2 is empty, all characters of s1 need to be removed
            } else if (data->s1[i - 1] == data->s2[j - 1]) {
                data->d[i][j] = data->d[i - 1][j - 1]; // No operation needed
            } else {
                data->d[i][j] = min(min(data->d[i - 1][j] + 1,    // Deletion
                                        data->d[i][j - 1] + 1),   // Insertion
                                        data->d[i - 1][j - 1] + 1); // Substitution
            }
        }
    }

    return NULL;
}

int levenshtein_distance(char *s1, char *s2) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int **d = malloc((len1 + 1) * sizeof(int *));
    
    for (int i = 0; i <= len1; i++) {
        d[i] = malloc((len2 + 1) * sizeof(int));
    }

    // Storing threads to join them later
    pthread_t threads[2];
    ThreadData thread_data[2];

    // Launch thread 1
    thread_data[0] = (ThreadData){s1, s2, 0, len1 / 2, d};
    pthread_create(&threads[0], NULL, levenshtein_segment, &thread_data[0]);

    // Launch thread 2
    thread_data[1] = (ThreadData){s1, s2, len1 / 2 + 1, len1, d};
    pthread_create(&threads[1], NULL, levenshtein_segment, &thread_data[1]);

    // Wait for both threads to finish
    for (int i = 0; i < 2; i++) {
        pthread_join(threads[i], NULL);
    }

    int distance = d[len1][len2];

    // Free allocated memory
    for (int i = 0; i <= len1; i++) {
        free(d[i]);
    }
    free(d);

    return distance;
}

int main(void) {
    char s1[MAX_LEN], s2[MAX_LEN];

    printf("Enter first string: ");
    fgets(s1, MAX_LEN, stdin);
    s1[strcspn(s1, "\n")] = 0; // Remove newline character from the end

    printf("Enter second string: ");
    fgets(s2, MAX_LEN, stdin);
    s2[strcspn(s2, "\n")] = 0; // Remove newline character from the end

    int distance = levenshtein_distance(s1, s2);

    printf("The Levenshtein distance between \"%s\" and \"%s\" is: %d\n", s1, s2, distance);

    return 0;
}