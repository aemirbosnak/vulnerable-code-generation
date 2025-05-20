//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define TRUE   1
#define FALSE  0
#define MAX    100

/* structure for shared memory */
typedef struct {
    int count;
    char string[MAX];
} shared_data;

int main(int argc, char *argv[]) {
    int shmid, shm_size;
    key_t key;
    shared_data *ptr;

    /* generate a unique key */
    key = ftok("shared_memory.c", 65);

    /* check if the shared memory already exists */
    shmid = shmget(key, sizeof(shared_data), IPC_CREAT | 0666);

    /* if shared memory doesn't exist, create it */
    if (shmid == -1) {
        printf("shared memory does not exist. creating...\n");
        shm_size = sizeof(shared_data);
        shmid = shmget(key, shm_size, IPC_CREAT | 0666);

        /* attach the shared memory to the data segment */
        ptr = (shared_data *) shmat(shmid, NULL, 0);

        /* initialize the shared data */
        ptr->count = 0;
        strcpy(ptr->string, "hello, world!");
    } else {
        printf("shared memory already exists.\n");
    }

    /* attach the shared memory to the data segment */
    ptr = (shared_data *) shmat(shmid, NULL, 0);

    /* display the initial shared data */
    printf("shared data: %s\n", ptr->string);

    /* update the shared data */
    ptr->count++;
    strcat(ptr->string, " interprocess communication!");

    /* detach the shared memory */
    shmdt(ptr);

    return 0;
}