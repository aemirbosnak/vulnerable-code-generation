//FormAI DATASET v1.0 Category: Dice Roller ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

// Struct for passing arguments to the thread function
typedef struct {
    int rolls;          // Number of rolls to be made
    int sides;          // Number of sides on the dice
    int *results;       // Results of the rolls stored in an array
} ThreadArgs;

// Maximum number of threads that can be created
#define MAX_THREADS 10

// Function that simulates rolling a dice of the given number of sides
int roll_dice(int sides) {
    return (rand() % sides) + 1;
}

// Thread function that executes the dice rolls
void *thread_func(void *arg) {
    ThreadArgs *targs = (ThreadArgs*)arg;
    int rolls = targs->rolls;
    int sides = targs->sides;
    int i;
    for (i = 0; i < rolls; i++) {
        int result = roll_dice(sides);
        targs->results[i] = result;
    }
    pthread_exit(NULL);
}

// Function that prints out the results of the rolls
void print_results(int rolls, int *results) {
    int i;
    printf("Results: ");
    for (i = 0; i < rolls; i++) {
        printf("%d ", results[i]);
    }
    printf("\n");
}

int main() {
    srand(time(NULL));
    int num_threads, rolls, sides, i, j;
    printf("Enter the number of threads (1-%d): ", MAX_THREADS);
    scanf("%d", &num_threads);
    printf("Enter the number of rolls: ");
    scanf("%d", &rolls);
    printf("Enter the number of sides on the dice: ");
    scanf("%d", &sides);
    int results[rolls];
    pthread_t threads[num_threads];
    ThreadArgs targs[num_threads];
    int rolls_per_thread = rolls / num_threads;
    int remaining_rolls = rolls % num_threads;
    // Create threads
    for (i = 0; i < num_threads; i++) {
        targs[i].rolls = rolls_per_thread;
        if (i < remaining_rolls) {
            targs[i].rolls++;
        }
        targs[i].sides = sides;
        targs[i].results = &results[i*rolls_per_thread];
        pthread_create(&threads[i], NULL, thread_func, &targs[i]);
    }
    // Wait for threads to complete
    for (i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }
    print_results(rolls, results);
    return 0;
}