//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SIZE 10

struct data {
    int id;
    char name[10];
    float value;
};

int main() {
    int shmid;
    struct data *ptr;
    key_t key = 12345;

    // create shared memory segment
    shmid = shmget(key, SIZE*sizeof(struct data), IPC_CREAT|0666);
    if (shmid == -1) {
        printf("Error creating shared memory segment\n");
        exit(1);
    }

    // attach to shared memory segment
    ptr = (struct data*)shmat(shmid, NULL, 0);
    if (ptr == (void*)-1) {
        printf("Error attaching to shared memory segment\n");
        exit(1);
    }

    // initialize shared memory segment
    for (int i = 0; i < SIZE; i++) {
        ptr[i].id = i+1;
        strcpy(ptr[i].name, "Name ");
        ptr[i].value = 0.0;
    }

    // detach from shared memory segment
    if (shmdt(ptr) == -1) {
        printf("Error detaching from shared memory segment\n");
        exit(1);
    }

    // wait for child process
    wait(NULL);

    return 0;
}