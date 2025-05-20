//GPT-4o-mini DATASET v1.0 Category: Greedy Algorithms ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_COINS 6

// Coin denominations
int coins[NUM_COINS] = {1, 3, 4, 5, 10, 25};

// Thread argument structure
typedef struct {
    int amount;
    int *result;
    int *coin_count;
} ThreadArg;

// Greedy algorithm to determine the minimum number of coins
void* coin_change(void* arg) {
    ThreadArg* t_arg = (ThreadArg*)arg;
    int amount = t_arg->amount;
    int count = 0;
    int value = amount;

    printf("Thread started for amount: %d\n", amount);
    for (int i = NUM_COINS - 1; i >= 0; i--) {
        while (value >= coins[i]) {
            value -= coins[i];
            t_arg->result[count++] = coins[i];
            t_arg->coin_count[i]++;
        }
    }
    printf("Thread finished for amount: %d with coins used: ", amount);
    for (int i = 0; i < count; i++) {
        printf("%d ", t_arg->result[i]);
    }
    printf("\n");

    pthread_exit(NULL);
}

// Main function to create threads for different amounts
int main(int argc, char* argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <amount1> <amount2> ... <amountN>\n", argv[0]);
        return 1;
    }

    int num_amounts = argc - 1;
    pthread_t threads[num_amounts];

    // To store results and coin counts for each thread
    int* results[num_amounts];
    int coin_counts[NUM_COINS] = {0};

    for (int i = 0; i < num_amounts; i++) {
        int amount = atoi(argv[i + 1]);
        results[i] = malloc(sizeof(int) * amount);  // Allocate response array

        ThreadArg* t_arg = malloc(sizeof(ThreadArg));
        t_arg->amount = amount;
        t_arg->result = results[i];
        t_arg->coin_count = coin_counts;

        // Create the thread for the current amount
        if (pthread_create(&threads[i], NULL, coin_change, (void*)t_arg) != 0) {
            fprintf(stderr, "Error creating thread for amount: %d\n", amount);
            return 1;
        }
    }

    // Wait for all threads to finish
    for (int i = 0; i < num_amounts; i++) {
        pthread_join(threads[i], NULL);
        free(results[i]);  // Free the allocated result array
    }

    printf("Total coins used across all amounts: ");
    for (int i = 0; i < NUM_COINS; i++) {
        if (coin_counts[i] > 0) {
            printf("Denomination %d: %d times; ", coins[i], coin_counts[i]);
        }
    }
    printf("\n");

    return 0;
}