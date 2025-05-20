//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include <string.h>

// global variables
int fortune_len = 50; // length of each fortune
char *fortunes[10]; // array of different fortunes
pthread_mutex_t lock; // mutex lock for thread synchronization

// function to get a random fortune
void *get_fortune(void *arg) {
    pthread_mutex_lock(&lock); // lock mutex to avoid conflicts
    int index = rand() % 10; // get random index for fortunes array
    char *fortune = malloc(fortune_len * sizeof(char)); // allocate memory for fortune string
    strcpy(fortune, fortunes[index]); // copy the fortune into the string
    pthread_mutex_unlock(&lock); // unlock mutex
    return (void*) fortune; // return the fortune as a void pointer
}

int main() {
    // initialize mutex lock
    if (pthread_mutex_init(&lock, NULL) != 0) {
        printf("\nMutex init failed\n");
        return 1;
    }

    // initialize array of fortunes
    fortunes[0] = "Good things come to those who wait.";
    fortunes[1] = "You will receive a surprise in the mail.";
    fortunes[2] = "The best things in life are free.";
    fortunes[3] = "You will have a great day today!";
    fortunes[4] = "Your hard work will pay off soon.";
    fortunes[5] = "Luck is on your side today.";
    fortunes[6] = "You will make a new friend soon.";
    fortunes[7] = "Your creativity will be rewarded.";
    fortunes[8] = "Today is the first day of the rest of your life.";
    fortunes[9] = "You will find something you lost soon.";

    // seed random number generator with current time
    srand((unsigned int) time(NULL));

    // create threads to get fortunes
    pthread_t threads[5];
    void *result;
    for (int i = 0; i < 5; i++) {
        pthread_create(&threads[i], NULL, get_fortune, NULL);
    }

    // join threads and print fortunes
    for (int i = 0; i < 5; i++) {
        pthread_join(threads[i], &result);
        printf("Fortune %d: %s\n", i+1, (char*) result);
        free(result); // free memory allocated for fortune string
    }

    // destroy mutex lock
    pthread_mutex_destroy(&lock);

    return 0;
}