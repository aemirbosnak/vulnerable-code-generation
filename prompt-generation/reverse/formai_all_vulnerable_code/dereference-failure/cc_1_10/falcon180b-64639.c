//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SIZE 5
#define MAX_TRIES 100

void print_tower(int *tower, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", tower[i]);
    }
    printf("\n");
}

int main(int argc, char **argv) {
    if (argc!= 2) {
        printf("Usage: %s <player_id>\n", argv[0]);
        return 1;
    }
    int player_id = atoi(argv[1]);
    int shmid;
    int *tower = NULL;
    int *tower_ptr = NULL;
    int n = SIZE;
    int tries = 0;

    shmid = shmget(IPC_PRIVATE, sizeof(int) * SIZE, IPC_CREAT | 0666);
    if (shmid == -1) {
        printf("Error creating shared memory segment\n");
        return 1;
    }

    tower_ptr = shmat(shmid, NULL, 0);
    if (tower_ptr == (void *) -1) {
        printf("Error attaching to shared memory segment\n");
        return 1;
    }

    for (int i = 0; i < SIZE; i++) {
        tower_ptr[i] = i + 1;
    }

    while (n > 1) {
        print_tower(tower_ptr, n);
        printf("Player %d, enter your move (from 1 to %d): ", player_id, n);
        scanf("%d", &tower_ptr[n - 1]);
        if (tower_ptr[n - 1] < 1 || tower_ptr[n - 1] > n) {
            printf("Invalid move\n");
            continue;
        }
        n--;
        tries++;
        if (tries >= MAX_TRIES) {
            printf("Too many tries\n");
            return 1;
        }
    }

    printf("Player %d wins!\n", player_id);

    return 0;
}