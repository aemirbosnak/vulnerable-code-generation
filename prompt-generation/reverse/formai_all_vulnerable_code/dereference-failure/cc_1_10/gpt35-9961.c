//FormAI DATASET v1.0 Category: Interprocess communication ; Style: secure
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_SIZE 1024

struct message {
    int type;
    char buffer[512];
};

int main() {
    int shmid;
    key_t key;
    struct message *shm, *s;

    // Generate unique key
    key = ftok(".", 's');

    // Create shared memory segment
    if ((shmid = shmget(key, SHM_SIZE, IPC_CREAT | 0666)) < 0) {
        perror("shmget");
        exit(1);
    }

    // Attach shared memory segment to process address space
    if ((shm = shmat(shmid, NULL, 0)) == (struct message *) -1) {
        perror("shmat");
        exit(1);
    }

    // Write messages to shared memory
    s = shm;
    s->type = 1;
    strcpy(s->buffer, "Hello, this is process 1 writing to shared memory.");

    s++;
    s->type = 2;
    strcpy(s->buffer, "Hello, this is process 2 writing to shared memory.");

    // Wait for other process to read shared memory
    sleep(5);

    // Read messages from shared memory
    s = shm;
    while (s < shm + SHM_SIZE) {
        if (s->type == 1) {
            printf("Process 1 says: %s\n", s->buffer);
        } else if (s->type == 2) {
            printf("Process 2 says: %s\n", s->buffer);
        } else {
            break;
        }
        s++;
    }

    // Detach and remove shared memory segment
    shmdt(shm);
    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}