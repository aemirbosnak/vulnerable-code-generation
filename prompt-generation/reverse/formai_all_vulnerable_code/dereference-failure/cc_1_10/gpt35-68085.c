//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

typedef struct {
    char* str1;
    char* str2;
    int length1;
    int length2;
    int** memo;
} Params;

void* calculateDistance(void* param) {
    Params* params = (Params*) param;
    char* str1 = params -> str1;
    char* str2 = params -> str2;
    int length1 = params -> length1;
    int length2 = params -> length2;
    int** memo = params -> memo;

    // Base case when either of the strings is empty.
    for(int i = 0; i <= length1; i++) {
        memo[i][0] = i;
    }

    for(int j = 0; j <= length2; j++) {
        memo[0][j] = j;
    }

    for(int i = 1; i <= length1; i++) {
        for(int j = 1; j <= length2; j++) {
            int isMatch = (str1[i-1] == str2[j-1]) ? 0 : 1;
            int costReplace = memo[i-1][j-1] + isMatch;
            int costInsert = memo[i][j-1] + 1;
            int costDelete = memo[i-1][j] + 1;
            memo[i][j] = (costReplace < costInsert) ? costReplace : costInsert;
            memo[i][j] = (costDelete < memo[i][j]) ? costDelete : memo[i][j];
        }
    }

    pthread_exit(NULL);
}

int main(int argc, char* argv[]) {
    if(argc < 3) {
        printf("Usage: ./levenshtein <string1> <string2>\n");
        return 0;
    }

    char* str1 = argv[1];
    char* str2 = argv[2];
    int length1 = strlen(str1);
    int length2 = strlen(str2);

    // Create a memoization table.
    int** memo = (int**) malloc((length1 + 1) * sizeof(int*));
    for(int i = 0; i <= length1; i++) {
        memo[i] = (int*) malloc((length2 + 1) * sizeof(int));
    }

    Params* params = (Params*) malloc(sizeof(Params));
    params -> str1 = str1;
    params -> str2 = str2;
    params -> length1 = length1;
    params -> length2 = length2;
    params -> memo = memo;

    pthread_t thread;
    pthread_create(&thread, NULL, calculateDistance, params);
    pthread_join(thread, NULL);

    printf("Levenshtein Distance: %d\n", memo[length1][length2]);

    // Free memoization table.
    for(int i = 0; i <= length1; i++) {
        free(memo[i]);
    }
    free(memo);
    free(params);

    return 0;
}