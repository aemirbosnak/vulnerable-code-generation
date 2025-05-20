//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

typedef struct {
    int num_disks;
    int source;
    int destination;
    int sleep_time;
} thread_data;

void move_disk(int num_disks, int source, int destination, int sleep_time) {
    printf("Moving %d disks from rod %d to rod %d...\n", num_disks, source, destination);
    sleep(sleep_time);
    printf("Done moving %d disks.\n", num_disks);
}

void* thread_function(void* data) {
    thread_data* tdata = (thread_data*) data;
    move_disk(tdata->num_disks, tdata->source, tdata->destination, tdata->sleep_time);
    pthread_exit(0);
}

int main() {
    int num_disks, sleep_time;
    printf("Enter number of disks: ");
    scanf("%d", &num_disks);
    printf("Enter sleep time (in seconds): ");
    scanf("%d", &sleep_time);

    // Initialize semaphores
    sem_t mutex;
    sem_t disk_available;
    sem_init(&mutex, 0, 1);
    sem_init(&disk_available, 0, num_disks);

    // Spawn threads
    pthread_t threads[num_disks];
    for (int i = num_disks - 1; i >= 0; i--) {
        thread_data data;
        data.num_disks = i + 1;
        data.source = 0;
        data.destination = 2;
        data.sleep_time = sleep_time;
        pthread_create(&threads[i], NULL, thread_function, &data);
    }

    // Wait for threads to finish
    for (int i = 0; i < num_disks; i++) {
        pthread_join(threads[i], NULL);
    }

    // Clean up semaphores
    sem_destroy(&mutex);
    sem_destroy(&disk_available);

    return 0;
}