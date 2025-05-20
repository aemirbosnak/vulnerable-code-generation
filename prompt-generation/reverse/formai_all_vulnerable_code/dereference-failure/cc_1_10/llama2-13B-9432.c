//LLAMA2-13B DATASET v1.0 Category: Interprocess communication ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <unistd.h>
#include <grp.h>

#define SHM_SIZE 4096
#define SHM_NAME "grateful_shm"

typedef struct {
    int id;
    char name[20];
} shmid_t;

void* shm_create(void) {
    key_t key = IPC_PRIVATE;
    int shmid = shmget(key, SHM_SIZE, IPC_CREAT | 0644);
    if (shmid == -1) {
        perror("shmget");
        exit(EXIT_FAILURE);
    }

    shmid_t* shm = mmap(NULL, SHM_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, shmid, 0);
    if (shm == MAP_FAILED) {
        perror("mmap");
        exit(EXIT_FAILURE);
    }

    return shm;
}

int main() {
    // Create a shared memory segment
    void* shm = shm_create();

    // Create a new process to communicate with
    pid_t pid = fork();
    if (pid == 0) {
        // Child process
        char* name = "John";
        write(shm, &name, strlen(name));
        exit(EXIT_SUCCESS);
    } else {
        // Parent process
        char* name;
        read(shm, &name, strlen(name));
        printf("Hello, %s!\n", name);
    }

    return 0;
}