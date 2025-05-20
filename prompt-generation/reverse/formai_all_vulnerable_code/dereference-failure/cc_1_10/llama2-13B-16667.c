//LLAMA2-13B DATASET v1.0 Category: Interprocess communication ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/shm.h>
#include <sys/ipc.h>

#define SHM_SIZE 1024
#define SHM_KEY 0xdeadbeef

typedef struct {
    char name[10];
    int age;
} person_t;

int main() {
    key_t key = SHM_KEY;
    int shmid = shmget(key, SHM_SIZE, IPC_CREAT | 0644);
    if (shmid < 0) {
        perror("shmget failed");
        return 1;
    }

    // Create a shared memory segment
    person_t *shm = mmap(NULL, SHM_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, shmid, 0);
    if (shm == MAP_FAILED) {
        perror("mmap failed");
        return 1;
    }

    // Fill the shared memory with some data
    strcpy(shm->name, "Alice");
    shm->age = 25;

    // Create a second process
    pid_t pid = fork();
    if (pid < 0) {
        perror("fork failed");
        return 1;
    }

    // In the parent process, wait for the child to finish
    if (pid > 0) {
        wait(NULL);
    }

    // In the child process, read the shared memory
    shm = mmap(NULL, SHM_SIZE, PROT_READ, MAP_SHARED, shmid, 0);
    if (shm == MAP_FAILED) {
        perror("mmap failed");
        return 1;
    }

    printf("Name: %s, Age: %d\n", shm->name, shm->age);

    // Modify the shared memory in the child process
    shm->age++;

    // Write the modified shared memory back to disk
    munmap(shm, SHM_SIZE);

    return 0;
}