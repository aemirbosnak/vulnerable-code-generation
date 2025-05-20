//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>

#define MAX_THREADS 10

struct prime_thread_args {
    int start_num;
    int end_num;
};

bool is_prime(int num) {
    if (num < 2) {
        return false;
    }

    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false;
        }
    }

    return true;
}

void *calculate_primes(void *arg) {
    struct prime_thread_args *args = arg;
    int start_num = args->start_num;
    int end_num = args->end_num;

    for (int i = start_num; i <= end_num; i++) {
        if (is_prime(i)) {
            printf("%d ", i);
        }
    }

    pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s num_threads max_num\n", argv[0]);
        return 1;
    }

    int num_threads = atoi(argv[1]);
    if (num_threads > MAX_THREADS) {
        printf("Error: Maximum %d threads allowed.\n", MAX_THREADS);
        return 1;
    }

    int max_num = atoi(argv[2]);

    pthread_t threads[num_threads];
    struct prime_thread_args args[num_threads];

    int nums_per_thread = max_num / num_threads;
    int extra_nums = max_num % num_threads;

    int curr_num = 2;
    for (int i = 0; i < num_threads; i++) {
        args[i].start_num = curr_num;

        int nums_to_check = nums_per_thread;
        if (extra_nums > 0) {
            nums_to_check++;
            extra_nums--;
        }

        args[i].end_num = curr_num + nums_to_check - 1;
        curr_num = args[i].end_num + 1;

        pthread_create(&threads[i], NULL, calculate_primes, &args[i]);
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("\n");

    return 0;
}