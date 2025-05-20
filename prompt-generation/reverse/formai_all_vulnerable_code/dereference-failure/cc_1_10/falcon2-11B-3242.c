//Falcon2-11B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int n = rand() % 10 + 1;
    printf("Number of processes: %d\n", n);
    int* p = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        p[i] = rand() % 1000;
        printf("Process %d: %d\n", i+1, p[i]);
    }

    int total_burst_time = 0;
    int* burst_time = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        int bt = rand() % 1000;
        burst_time[i] = bt;
        total_burst_time += bt;
    }

    int* start_time = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        int st = rand() % 1000;
        start_time[i] = st;
    }

    int* end_time = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        int et = start_time[i] + burst_time[i];
        end_time[i] = et;
    }

    printf("Burst times:\n");
    for (int i = 0; i < n; i++) {
        printf("Process %d: %d\n", i+1, burst_time[i]);
    }

    printf("Start times:\n");
    for (int i = 0; i < n; i++) {
        printf("Process %d: %d\n", i+1, start_time[i]);
    }

    printf("End times:\n");
    for (int i = 0; i < n; i++) {
        printf("Process %d: %d\n", i+1, end_time[i]);
    }

    free(p);
    free(burst_time);
    free(start_time);
    free(end_time);

    return 0;
}