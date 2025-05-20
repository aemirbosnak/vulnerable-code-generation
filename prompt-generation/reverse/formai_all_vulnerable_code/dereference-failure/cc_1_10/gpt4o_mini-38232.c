//GPT-4o-mini DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_LENGTH 100

typedef struct {
    char *s1;
    char *s2;
    int start;
    int end;
    int **dp;
} ThreadData;

void *levenshtein_thread(void *arg) {
    ThreadData *data = (ThreadData *)arg;
    int i, j;
    int len1 = strlen(data->s1);
    int len2 = strlen(data->s2);
    
    for (i = data->start; i <= data->end; i++) {
        for (j = 0; j <= len2; j++) {
            if (i == 0) {
                data->dp[i][j] = j; // Deletion
            } else if (j == 0) {
                data->dp[i][j] = i; // Insertion
            } else if (data->s1[i - 1] == data->s2[j - 1]) {
                data->dp[i][j] = data->dp[i - 1][j - 1]; // No change
            } else {
                int insert = data->dp[i][j - 1] + 1;
                int delete = data->dp[i - 1][j] + 1;
                int replace = data->dp[i - 1][j - 1] + 1;
                data->dp[i][j] = insert < delete ? (insert < replace ? insert : replace) : (delete < replace ? delete : replace);
            }
        }
    }
    return NULL;
}

int levenshtein_distance(const char *s1, const char *s2) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    
    int **dp = (int **)malloc((len1 + 1) * sizeof(int *));
    for (int i = 0; i <= len1; i++) {
        dp[i] = (int *)malloc((len2 + 1) * sizeof(int));
    }

    pthread_t thread1, thread2;
    ThreadData data1 = { (char *)s1, (char *)s2, 0, len1 / 2, dp };
    ThreadData data2 = { (char *)s1, (char *)s2, (len1 / 2) + 1, len1, dp };

    pthread_create(&thread1, NULL, levenshtein_thread, (void *)&data1);
    pthread_create(&thread2, NULL, levenshtein_thread, (void *)&data2);
    
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    int distance = dp[len1][len2];
    
    for (int i = 0; i <= len1; i++) {
        free(dp[i]);
    }
    free(dp);
    
    return distance;
}

int main() {
    char str1[MAX_LENGTH], str2[MAX_LENGTH];

    printf("Enter first string: ");
    fgets(str1, MAX_LENGTH, stdin);
    str1[strcspn(str1, "\n")] = 0; // Remove newline

    printf("Enter second string: ");
    fgets(str2, MAX_LENGTH, stdin);
    str2[strcspn(str2, "\n")] = 0; // Remove newline

    int distance = levenshtein_distance(str1, str2);
    printf("Levenshtein Distance: %d\n", distance);

    return 0;
}