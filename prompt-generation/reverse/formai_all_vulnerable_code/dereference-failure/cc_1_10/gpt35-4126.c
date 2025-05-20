//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <sys/time.h>

#define N 10000000

// Compute the sum of squares of an array using direct method
double direct_sum_of_squares(double *arr, int n) {
    double sum = 0.0;
    for (int i = 0; i < n; i++) {
        sum += arr[i] * arr[i];
    }
    return sum;
}

// Compute the sum of squares of an array using divide-and-conquer method
double divide_and_conquer_sum_of_squares(double *arr, int left, int right) {
    if (left == right) {
        return arr[left] * arr[left];
    } else {
        int mid = (left + right) / 2;
        double left_sum = divide_and_conquer_sum_of_squares(arr, left, mid);
        double right_sum = divide_and_conquer_sum_of_squares(arr, mid+1, right);
        return left_sum + right_sum;
    }
}

int main() {
    double *arr = malloc(N * sizeof(double));
    for (int i = 0; i < N; i++) {
        arr[i] = sin(i);
    }

    struct timeval start_time, end_time;

    gettimeofday(&start_time, NULL);
    double direct_sum = direct_sum_of_squares(arr, N);
    gettimeofday(&end_time, NULL);
    printf("Direct method: %lf, time elapsed: %lf seconds\n", direct_sum, ((double) (end_time.tv_usec - start_time.tv_usec) / 1000000.0) + (end_time.tv_sec - start_time.tv_sec));

    gettimeofday(&start_time, NULL);
    double divide_and_conquer_sum = divide_and_conquer_sum_of_squares(arr, 0, N-1);
    gettimeofday(&end_time, NULL);
    printf("Divide-and-conquer method: %lf, time elapsed: %lf seconds\n", divide_and_conquer_sum, ((double) (end_time.tv_usec - start_time.tv_usec) / 1000000.0) + (end_time.tv_sec - start_time.tv_sec));

    free(arr);

    return 0;
}