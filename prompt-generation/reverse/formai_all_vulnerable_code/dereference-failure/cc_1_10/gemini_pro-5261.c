//GEMINI-pro DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>

#define min(x, y) ((x) < (y) ? (x) : (y))

struct args {
    char *str1;
    char *str2;
    int len1;
    int len2;
    int **matrix;
    int dist;
};

void *calc_distance(void *arg) {
    struct args *args = (struct args *)arg;
    int i, j;

    for (i = 1; i <= args->len1; i++) {
        args->matrix[i][0] = i;
    }
    for (j = 0; j <= args->len2; j++) {
        args->matrix[0][j] = j;
    }

    for (i = 1; i <= args->len1; i++) {
        for (j = 1; j <= args->len2; j++) {
            if (args->str1[i-1] == args->str2[j-1]) {
                args->matrix[i][j] = args->matrix[i-1][j-1];
            } else {
                args->matrix[i][j] = min(min(args->matrix[i-1][j], args->matrix[i][j-1]), args->matrix[i-1][j-1]) + 1;
            }
        }
    }

    args->dist = args->matrix[args->len1][args->len2];
    pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <string1> <string2>\n", argv[0]);
        return 1;
    }

    char *str1 = argv[1];
    char *str2 = argv[2];
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int **matrix = malloc((len1 + 1) * sizeof(int *));
    for (int i = 0; i <= len1; i++) {
        matrix[i] = malloc((len2 + 1) * sizeof(int));
    }

    struct args args = {
        .str1 = str1,
        .str2 = str2,
        .len1 = len1,
        .len2 = len2,
        .matrix = matrix,
        .dist = 0
    };

    pthread_t thread;
    pthread_create(&thread, NULL, calc_distance, &args);
    pthread_join(thread, NULL);

    printf("Levenshtein distance: %d\n", args.dist);

    for (int i = 0; i <= len1; i++) {
        free(matrix[i]);
    }
    free(matrix);
    return 0;
}