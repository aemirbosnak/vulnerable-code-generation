//MISTRAL-7B DATASET v1.0 Category: Interprocess communication ; Style: Dennis Ritchie
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>

#define SHM_KEY 0x1234
#define SHM_SIZE 1024

typedef struct {
    int pid;
    char msg[100];
} ShmData;

int main(int argc, char *argv[]) {
    key_t shm_id;
    int shm_size;
    ShmData *shm_ptr;

    // Fork child process
    pid_t child_pid = fork();

    if (child_pid < 0) { // Error handling
        perror("Fork failed");
        exit(EXIT_FAILURE);
    } else if (child_pid > 0) { // Parent process
        shm_id = shmget(SHM_KEY, SHM_SIZE, IPC_CREAT | 0666);

        if (shm_id < 0) { // Error handling
            perror("Shared memory get failed");
            exit(EXIT_FAILURE);
        }

        shm_size = shmget(SHM_KEY, SHM_SIZE, 0);
        shm_ptr = (ShmData *) shmget(SHM_KEY, SHM_SIZE, 0);

        if (shm_ptr == NULL) { // Error handling
            perror("Shared memory attach failed");
            exit(EXIT_FAILURE);
        }

        strcpy(shm_ptr->msg, "Hello from Parent!");
        shm_ptr->pid = getpid();

        printf("Parent wrote to shared memory: %s\n", shm_ptr->msg);

        wait(NULL); // Wait for child to finish

        shmdt(shm_ptr);
        shmctl(shm_id, IPC_RMID, NULL);
    } else { // Child process
        shm_id = shmget(SHM_KEY, SHM_SIZE, 0);

        if (shm_id < 0) { // Error handling
            perror("Shared memory get failed");
            exit(EXIT_FAILURE);
        }

        shm_ptr = (ShmData *) shmget(SHM_KEY, SHM_SIZE, 0);

        if (shm_ptr == NULL) { // Error handling
            perror("Shared memory attach failed");
            exit(EXIT_FAILURE);
        }

        printf("Child read from shared memory: %s\n", shm_ptr->msg);

        shmdt(shm_ptr);
        shmctl(shm_id, IPC_RMID, NULL);

        exit(EXIT_SUCCESS);
    }

    return EXIT_SUCCESS;
}