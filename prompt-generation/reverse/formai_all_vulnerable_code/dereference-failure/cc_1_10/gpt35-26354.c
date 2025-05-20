//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m;

    printf("Enter the number of jobs: ");
    scanf("%d", &n);

    printf("Enter the maximum size of each job: ");
    scanf("%d", &m);

    int *jobs = malloc(n * sizeof(int));

    printf("Enter the sizes of the jobs:\n");

    for (int i = 0; i < n; i++) {
        scanf("%d", &jobs[i]);
    }

    int *machines = calloc(m, sizeof(int));

    for (int i = 0; i < n; i++) {
        int min_index = 0;

        for (int j = 1; j < m; j++) {
            if (machines[j] < machines[min_index]) {
                min_index = j;
            }
        }

        machines[min_index] += jobs[i];
    }

    int max_time = 0;

    for (int i = 0; i < m; i++) {
        if (machines[i] > max_time) {
            max_time = machines[i];
        }
        printf("Machine %d finished all jobs at time %d\n", i+1, machines[i]);
    }

    printf("Total time taken to finish all jobs is %d\n", max_time);

    free(jobs);
    free(machines);

    return 0;
}