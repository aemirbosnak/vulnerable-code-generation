//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_DISKS 10

struct disk {
    int from;
    int to;
};

void move_disk(int n, int from, int to, int *current)
{
    printf("Moving disk %d from peg %d to peg %d\n", n, from, to);
    *current = to;
}

void *tower_of_hanoi(void *arg)
{
    int n = *(int *) arg;
    struct disk disks[n];
    int source = 0;
    int destination = 2;
    int current = source;

    for (int i = n; i >= 1; i--) {
        disks[i - 1].from = source;
        disks[i - 1].to = destination;
        move_disk(i, source, destination, &current);
    }
}

int main()
{
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);

    pthread_t threads[n];

    for (int i = 0; i < n; i++) {
        pthread_create(&threads[i], NULL, tower_of_hanoi, (void *) &i);
    }

    for (int i = 0; i < n; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}