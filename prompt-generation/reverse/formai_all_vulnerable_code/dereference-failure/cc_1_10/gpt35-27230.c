//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_STRING_LENGTH 100

int dist[MAX_STRING_LENGTH][MAX_STRING_LENGTH];

/* function to calculate Levenshtein Distance */
void calculate_distance(char* s1, char* s2, int m, int n)
{
    /* Initialize first row and first column of matrix */
    for(int i=0; i<=m; i++) {
        dist[i][0] = i;
    }
    for(int j=0; j<=n; j++) {
        dist[0][j] = j;
    }

    /* Calculate the minimum cost to transform s1 into s2 */
    for(int i=1; i<=m; i++) {
        for(int j=1; j<=n; j++) {
            int cost = (s1[i-1] == s2[j-1]) ? 0 : 1;
            dist[i][j] = fmin(dist[i-1][j] + 1,
                            fmin(dist[i][j-1] + 1,
                            dist[i-1][j-1] + cost));
        }
    }
}

/* thread function */
void *levenshtein_distance(void *arg)
{
    char* s1 = (char*) arg;
    char s2[MAX_STRING_LENGTH];

    /* loop over strings to calculate distance */
    for(int i=0; i<MAX_STRING_LENGTH; i++) {
        sprintf(s2, "string%d", i+1);
        int len = strlen(s2);

        /* calculate distance between s1 and s2 */
        calculate_distance(s1, s2, strlen(s1), len);
        
        /* print results for current pair of strings */
        printf("Distance between %s and %s: %d\n", s1, s2, dist[strlen(s1)][len]);
    }
    pthread_exit(NULL);
}

/* main function */
int main(int argc, char** argv)
{
    if(argc < 2) {
        printf("Please provide a string as an argument.\n");
        exit(EXIT_FAILURE);
    }

    /* create thread */
    pthread_t thread;
    /* initialize thread attributes */
    pthread_attr_t attr;
    pthread_attr_init(&attr);

    /* create multiple threads for each input string */
    for(int i=1; i<argc; i++) {
        pthread_create(&thread, &attr, levenshtein_distance, argv[i]);
    }

    /* wait for threads to finish execution */
    pthread_join(thread, NULL);
    pthread_exit(NULL);
}