//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SIZE 20

typedef struct {
    int value;
    char name[10];
} data_t;

int main(int argc, char *argv[]) {
    int shmid;
    key_t key;
    int i;
    data_t *data;

    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <process_id>\n", argv[0]);
        exit(1);
    }

    key = ftok(argv[1], 65);
    shmid = shmget(key, SIZE * sizeof(data_t), IPC_CREAT | 0777);

    if (shmid == -1) {
        fprintf(stderr, "Failed to create shared memory segment.\n");
        exit(1);
    }

    data = (data_t *) shmat(shmid, NULL, 0);

    if (data == (void *) -1) {
        fprintf(stderr, "Failed to attach to shared memory segment.\n");
        exit(1);
    }

    for (i = 0; i < SIZE; i++) {
        sprintf(data[i].name, "Process %d", i+1);
        data[i].value = i;
    }

    sleep(5);

    for (i = 0; i < SIZE; i++) {
        printf("Name: %s, Value: %d\n", data[i].name, data[i].value);
    }

    shmdt(data);
    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}