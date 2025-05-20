//FormAI DATASET v1.0 Category: Temperature monitor ; Style: multi-threaded
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

#define NUM_THREADS 5 //number of threads
#define TEMP_LIMIT 100 //temperature limit

pthread_t threads[NUM_THREADS]; //initialize threads array
pthread_mutex_t mutex; //initialize mutex

int current_temp = 70; //initialize temperature

//function to monitor temperature
void* temp_monitor(void* arg) {

    while(1) {
        pthread_mutex_lock(&mutex); //lock mutex
        int id = *((int*)arg); //get thread id
        printf("Thread %d: Current Temperature: %d\n", id, current_temp); //print current temperature
        current_temp = current_temp + rand() % 10 - 5; //simulate some temperature change
        if(current_temp >= TEMP_LIMIT) { //check temperature limit reached
            printf("Thread %d: Temperature limit %d reached. Exit.\n", id, TEMP_LIMIT); //print message
            pthread_mutex_unlock(&mutex); //unlock mutex
            pthread_exit(NULL); //exit thread
        }
        pthread_mutex_unlock(&mutex); //unlock mutex
        sleep(2); //sleep for 2 seconds
    }
}

int main(void) {
    srand(time(NULL)); //initialize rand
    pthread_mutex_init(&mutex, NULL); //initialize mutex

    printf("Starting Temperature Monitor...\n");
    
    // create threads
    for(int i=0; i<NUM_THREADS; i++) {
        int* id = (int*)malloc(sizeof(int)); //allocate memory for id
        *id = i;
        pthread_create(&threads[i], NULL, temp_monitor, (void*)id); //create thread
    }

    // join threads
    for(int i=0; i<NUM_THREADS; i++) {
        pthread_join(threads[i], NULL); //join thread
    }

    pthread_mutex_destroy(&mutex); //destroy mutex

    printf("All threads finished.\n");

    return 0;
}