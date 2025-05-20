//FormAI DATASET v1.0 Category: Benchmarking ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 100000000

double diff_in_second(struct timespec t1, struct timespec t2)
{
    struct timespec diff;
    if (t2.tv_nsec-t1.tv_nsec < 0) {
        diff.tv_sec = t2.tv_sec - t1.tv_sec-1;
        diff.tv_nsec = t2.tv_nsec - t1.tv_nsec + 1000000000;
    } else {
        diff.tv_sec = t2.tv_sec - t1.tv_sec;
        diff.tv_nsec = t2.tv_nsec - t1.tv_nsec;
    }
    return (diff.tv_sec + diff.tv_nsec / 1000000000.0);
}

int main()
{
    struct timespec start, end;
    double cpu_time1, cpu_time2, cpu_time3, cpu_time4;

    int* array = (int*)malloc(sizeof(int) * MAX);
    for (int i = 0; i < MAX; i++) {
        array[i] = rand();
    }

    clock_gettime(CLOCK_REALTIME, &start);
    for (int i = 0; i < MAX; i++) {
        if (array[i] % 2 == 0) {
            array[i] *= 2;
        } else {
            array[i] += 1;
        }
    }
    clock_gettime(CLOCK_REALTIME, &end);
    cpu_time1 = diff_in_second(start, end);

    clock_gettime(CLOCK_REALTIME, &start);
    for (int i = 0; i < MAX; i += 2) {
        array[i] *= 2;
        array[i + 1] += 1;
    }
    clock_gettime(CLOCK_REALTIME, &end);
    cpu_time2 = diff_in_second(start, end);

    int sum = 0;
    clock_gettime(CLOCK_REALTIME, &start);
    for (int i = 0; i < MAX; i++) {
        sum += array[i];
    }
    clock_gettime(CLOCK_REALTIME, &end);
    cpu_time3 = diff_in_second(start, end);

    sum = 0;
    clock_gettime(CLOCK_REALTIME, &start);
    for (int i = 0; i < MAX; i += 4) {
        sum += array[i] + array[i + 1] + array[i + 2] + array[i + 3];
    }
    clock_gettime(CLOCK_REALTIME, &end);
    cpu_time4 = diff_in_second(start, end);

    printf("Method 1 CPU time: %lf sec.\n", cpu_time1);
    printf("Method 2 CPU time: %lf sec.\n", cpu_time2);
    printf("Method 3 CPU time: %lf sec.\n", cpu_time3);
    printf("Method 4 CPU time: %lf sec.\n", cpu_time4);

    free(array);
    return 0;
}