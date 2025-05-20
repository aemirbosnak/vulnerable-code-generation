//GPT-4o-mini DATASET v1.0 Category: Interprocess communication ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <string.h>

#define SHM_SIZE 1024
#define SHM_KEY 1234
#define MSG_BUFFER_SIZE 100

void writer_process(int shmid) {
    char *shm_addr = shmat(shmid, NULL, 0);
    if (shm_addr == (char *)-1) {
        perror("Failed to attach shared memory");
        exit(EXIT_FAILURE);
    }

    char message[MSG_BUFFER_SIZE];
    for (int i = 0; i < 5; ++i) {
        snprintf(message, sizeof(message), "Message %d from writer", i + 1);
        strncpy(shm_addr, message, SHM_SIZE);
        printf("Writer: %s\n", message);
        sleep(1); // Simulate some delay
    }

    // Indicate completion
    strcpy(shm_addr, "END");

    if (shmdt(shm_addr) == -1) {
        perror("Failed to detach shared memory");
        exit(EXIT_FAILURE);
    }
}

void reader_process(int shmid) {
    char *shm_addr = shmat(shmid, NULL, 0);
    if (shm_addr == (char *)-1) {
        perror("Failed to attach shared memory");
        exit(EXIT_FAILURE);
    }

    char message[MSG_BUFFER_SIZE];
    while (1) {
        strncpy(message, shm_addr, MSG_BUFFER_SIZE);
        if (strcmp(message, "END") == 0) {
            printf("Reader: Received END signal, exiting...\n");
            break;
        }
        printf("Reader: %s\n", message);
        sleep(1); // Simulate some delay
    }

    if (shmdt(shm_addr) == -1) {
        perror("Failed to detach shared memory");
        exit(EXIT_FAILURE);
    }
}

int main() {
    int shmid = shmget(SHM_KEY, SHM_SIZE, IPC_CREAT | 0666);
    if (shmid == -1) {
        perror("Failed to create shared memory");
        exit(EXIT_FAILURE);
    }

    pid_t writer_pid = fork();
    if (writer_pid < 0) {
        perror("Failed to fork writer process");
        exit(EXIT_FAILURE);
    } else if (writer_pid == 0) {
        // Child process: Writer
        writer_process(shmid);
        exit(EXIT_SUCCESS);
    }

    pid_t reader_pid = fork();
    if (reader_pid < 0) {
        perror("Failed to fork reader process");
        exit(EXIT_FAILURE);
    } else if (reader_pid == 0) {
        // Child process: Reader
        reader_process(shmid);
        exit(EXIT_SUCCESS);
    }

    // Parent process: Wait for children to finish
    wait(NULL);
    wait(NULL);

    // Cleanup shared memory
    if (shmctl(shmid, IPC_RMID, NULL) == -1) {
        perror("Failed to delete shared memory");
        exit(EXIT_FAILURE);
    }

    printf("Main: Shared memory cleaned up.\n");
    return 0;
}