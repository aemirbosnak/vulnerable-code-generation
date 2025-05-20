//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_DISKS 10
#define NUM_THREADS 3

struct disk_t {
    int position;
    int destination;
};

void *move_disk(void *param);

int main() {
    int num_disks = 3;
    int source = 0;
    int destination = 2;
    int position[MAX_DISKS] = {0, 1, 2};
    pthread_t threads[NUM_THREADS];

    for (int i = 0; i < num_disks; i++) {
        struct disk_t disk;
        disk.position = source;
        disk.destination = destination;
        pthread_create(&threads[i], NULL, move_disk, &disk);
        source = destination;
        destination = (destination == 0)? 2 : 0;
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}

void *move_disk(void *param) {
    struct disk_t *disk = param;

    printf("Moving disk %d from %d to %d\n", disk->position, disk->position, disk->destination);

    int steps = 0;
    int temp_position = (disk->destination == 2)? 1 : 0;

    while (disk->position!= disk->destination) {
        printf("Disk %d is at position %d\n", disk->position, disk->position);
        fflush(stdout);
        steps++;

        if (disk->position == temp_position) {
            temp_position = (temp_position == 1)? 2 : 0;
        }

        disk->position = temp_position;
        usleep(100000);
    }

    printf("Disk %d has reached its destination\n", disk->position);
    fflush(stdout);

    return NULL;
}