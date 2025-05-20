//FormAI DATASET v1.0 Category: Interprocess communication ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>

#define SHM_SIZE 1024

int main() {
    key_t key;
    int shmid;
    char *data;
    char buffer[256];

    // generate a key for shared memory segment
    if ((key = ftok("ipc_program", 'R')) == -1) {
        perror("ftok error");
        exit(1);
    }

    // create shared memory segment
    if ((shmid = shmget(key, SHM_SIZE, 0644 | IPC_CREAT)) == -1) {
        perror("shmget error");
        exit(1);
    }

    // attach to shared memory segment
    data = shmat(shmid, (void *)0, 0);
    if (data == (char *)(-1)) {
        perror("shmat error");
        exit(1);
    }

    printf("Enter a message to share: ");
    fgets(buffer, sizeof(buffer), stdin);

    // copy message to shared memory segment
    strncpy(data, buffer, SHM_SIZE);

    printf("Message written to shared memory segment.\n");

    printf("Waiting for a response...\n");

    sleep(5);

    // read response from shared memory segment
    printf("Received response: %s\n", data);

    // detach from shared memory segment
    if (shmdt(data) == -1) {
        perror("shmdt error");
        exit(1);
    }

    return 0;
}