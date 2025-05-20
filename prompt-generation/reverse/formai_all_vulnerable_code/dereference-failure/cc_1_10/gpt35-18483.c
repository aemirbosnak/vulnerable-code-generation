//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

#define NUM_THREADS 5

// function to simulate time travel
void *time_travel(void *thread_id){
    int *tid = (int*)thread_id;
    printf("Thread %d is time traveling...\n", *tid);

    // get current time
    time_t current_time;
    time(&current_time);

    // randomly jump to a time between 2000 and 3000 AD
    srand((unsigned)time(NULL));
    int year = rand() % 1000 + 2000;
    struct tm *travel_time;
    travel_time = localtime(&current_time);
    travel_time->tm_year = year - 1900;

    // set the travel time
    time_t travel_time_t = mktime(travel_time);
    printf("Thread %d has arrived in year %d\n", *tid, year);

    // wait for 3 seconds before returning to the present time
    sleep(3);
    printf("Thread %d is returning to the present time...\n", *tid);

    // set the current time as the return time
    time(&current_time);

    // wait for another 3 seconds before ending the thread
    sleep(3);
    printf("Thread %d has returned to the present time.\n", *tid);
    pthread_exit(NULL);
}

int main(){
    pthread_t threads[NUM_THREADS];
    int thread_ids[NUM_THREADS];
    int rc, t;

    // create the threads
    for(t=0; t<NUM_THREADS; t++){
        thread_ids[t] = t+1;
        printf("Creating thread %d\n", thread_ids[t]);
        rc = pthread_create(&threads[t], NULL, time_travel, (void*)&thread_ids[t]);
        if(rc){
            printf("Error creating thread %d, error code: %d\n", thread_ids[t], rc);
            exit(-1);
        }
    }

    // wait for the threads to finish
    for(t=0; t<NUM_THREADS; t++){
        pthread_join(threads[t], NULL);
    }

    printf("All threads have finished executing.\n");
    pthread_exit(NULL);
}