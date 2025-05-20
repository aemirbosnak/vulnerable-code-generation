//Falcon2-11B DATASET v1.0 Category: Interprocess communication ; Style: visionary
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <string.h>

#define SHMKEY "my_shared_memory"
#define SHMSIZE 4096

void* shared_memory(int shmid) {
    void* shm = shmat(shmid, NULL, 0);
    if (shm == (void*)-1) {
        printf("ERROR: Failed to attach shared memory segment.\n");
        return NULL;
    }
    return shm;
}

int main() {
    int shmid = shmget(IPC_PRIVATE, SHMSIZE, 0777 | IPC_CREAT);
    if (shmid == -1) {
        printf("ERROR: Failed to allocate shared memory segment.\n");
        return 1;
    }

    void* shm = shared_memory(shmid);
    if (shm == NULL) {
        return 1;
    }

    char* message = "Hello, World!";
    strcpy(shm, message);

    int pid = fork();
    if (pid == 0) {
        printf("Child process: %s\n", shm);
        exit(0);
    } else if (pid > 0) {
        wait(NULL);
        printf("Parent process: %s\n", shm);
        exit(0);
    } else {
        printf("Fork failed.\n");
        return 1;
    }

    return 0;
}