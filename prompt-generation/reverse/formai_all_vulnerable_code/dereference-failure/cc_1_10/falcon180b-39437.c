//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX 10

int graph[MAX][MAX];
int visited[MAX][MAX];

void printGraph(int graph[MAX][MAX]) {
    int i, j;
    for (i = 0; i < MAX; i++) {
        for (j = 0; j < MAX; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

void *runner(void *param) {
    int start_row = *(int *) param;
    int end_row = start_row + 3;
    int start_col = 0;
    int end_col = MAX - 1;

    int i, j;

    for (i = start_row; i < end_row; i++) {
        for (j = start_col; j < end_col; j++) {
            graph[i][j] = 1;
        }
    }
}

int main() {
    int i, j;

    for (i = 0; i < MAX; i++) {
        for (j = 0; j < MAX; j++) {
            graph[i][j] = 0;
        }
    }

    int num_threads = 4;
    pthread_t threads[num_threads];

    for (i = 0; i < num_threads; i++) {
        int start_row = i * (MAX / num_threads);
        int end_row = (i + 1) * (MAX / num_threads);
        pthread_create(&threads[i], NULL, runner, &start_row);
    }

    for (i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    printGraph(graph);

    return 0;
}