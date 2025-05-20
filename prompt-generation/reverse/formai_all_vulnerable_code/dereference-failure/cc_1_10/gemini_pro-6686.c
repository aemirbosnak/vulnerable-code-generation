//GEMINI-pro DATASET v1.0 Category: Threading Library Implementation ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct {
    int id;
    int *nums;
    int num_count;
    double sum;
} thread_data;

void *thread_function(void *args) {
    thread_data *data = (thread_data *)args;

    for (int i = 0; i < data->num_count; i++) {
        data->sum += data->nums[i];
    }

    pthread_exit(NULL);
}

int main(int argc, char **argv) {
    if (argc < 3) {
        printf("Usage: %s <num_threads> <num_elements>\n", argv[0]);
        return 1;
    }

    int num_threads = atoi(argv[1]);
    int num_elements = atoi(argv[2]);

    // Generate random numbers
    int *nums = (int *)malloc(num_elements * sizeof(int));
    for (int i = 0; i < num_elements; i++) {
        nums[i] = rand() % 100;
    }

    // Create threads
    pthread_t *threads = (pthread_t *)malloc(num_threads * sizeof(pthread_t));
    thread_data *data = (thread_data *)malloc(num_threads * sizeof(thread_data));

    for (int i = 0; i < num_threads; i++) {
        data[i].id = i;
        data[i].nums = nums;
        data[i].num_count = num_elements / num_threads;
        data[i].sum = 0;

        if (pthread_create(&threads[i], NULL, thread_function, &data[i]) != 0) {
            perror("pthread_create");
            return 1;
        }
    }

    // Join threads
    for (int i = 0; i < num_threads; i++) {
        if (pthread_join(threads[i], NULL) != 0) {
            perror("pthread_join");
            return 1;
        }
    }

    // Calculate total sum
    double total_sum = 0;
    for (int i = 0; i < num_threads; i++) {
        total_sum += data[i].sum;
    }

    printf("Total sum: %.2f\n", total_sum);

    // Free memory
    free(threads);
    free(data);
    free(nums);

    return 0;
}