//GPT-4o-mini DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_INPUT 100
#define NUM_PLAYERS 2

typedef struct {
    char str1[MAX_INPUT];
    char str2[MAX_INPUT];
    int player_id;
    int distance;
} LevenshteinArgs;

// Function to calculate the Levenshtein distance
int levenshtein_distance(const char *s1, const char *s2) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int **d = malloc((len1 + 1) * sizeof(int *));
    
    for (int i = 0; i <= len1; i++) {
        d[i] = malloc((len2 + 1) * sizeof(int));
    }

    for (int i = 0; i <= len1; i++) {
        d[i][0] = i;
    }
    for (int j = 0; j <= len2; j++) {
        d[0][j] = j;
    }
    
    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            int substitution_cost = (s1[i - 1] == s2[j - 1]) ? 0 : 1;
            d[i][j] = fmin(fmin(d[i - 1][j] + 1, d[i][j - 1] + 1), d[i - 1][j - 1] + substitution_cost);
        }
    }
    
    int distance = d[len1][len2];
    
    for (int i = 0; i <= len1; i++) {
        free(d[i]);
    }
    free(d);
    
    return distance;
}

// Thread function for each player to calculate distance
void *calculate_distance(void *args) {
    LevenshteinArgs *lev_args = (LevenshteinArgs *)args;
    lev_args->distance = levenshtein_distance(lev_args->str1, lev_args->str2);
    printf("Player %d: The Levenshtein distance between \"%s\" and \"%s\" is %d\n", 
           lev_args->player_id, lev_args->str1, lev_args->str2, lev_args->distance);
    return NULL;
}

int main() {
    pthread_t threads[NUM_PLAYERS];
    LevenshteinArgs lev_args[NUM_PLAYERS];

    // Getting input from players
    for (int i = 0; i < NUM_PLAYERS; i++) {
        printf("Player %d, enter the first string: ", i + 1);
        fgets(lev_args[i].str1, MAX_INPUT, stdin);
        lev_args[i].str1[strcspn(lev_args[i].str1, "\n")] = 0; // Remove newline

        printf("Player %d, enter the second string: ", i + 1);
        fgets(lev_args[i].str2, MAX_INPUT, stdin);
        lev_args[i].str2[strcspn(lev_args[i].str2, "\n")] = 0; // Remove newline

        lev_args[i].player_id = i + 1;

        // Starting a thread for each player
        pthread_create(&threads[i], NULL, calculate_distance, (void *)&lev_args[i]);
    }

    // Waiting for all threads to finish
    for (int i = 0; i < NUM_PLAYERS; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("All calculations are complete!\n");
    return 0;
}