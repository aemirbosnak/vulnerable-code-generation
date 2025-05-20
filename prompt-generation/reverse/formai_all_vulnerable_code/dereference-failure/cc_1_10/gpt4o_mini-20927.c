//GPT-4o-mini DATASET v1.0 Category: Interprocess communication ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <semaphore.h>

#define SHM_NAME "/my_shm"
#define SEM_EMPTY "/sem_empty"
#define SEM_FULL "/sem_full"
#define SIZE 256

void child_process() {
    // Open shared memory
    int shm_fd = shm_open(SHM_NAME, O_CREAT | O_RDWR, 0666);
    ftruncate(shm_fd, SIZE);
    char *ptr = mmap(0, SIZE, PROT_WRITE, MAP_SHARED, shm_fd, 0);
    
    // Open semaphores
    sem_t *sem_empty = sem_open(SEM_EMPTY, O_CREAT, 0666, 1);
    sem_t *sem_full = sem_open(SEM_FULL, O_CREAT, 0666, 0);
    
    const char *message = "Hello from the child process!";
    
    // Write to shared memory
    sem_wait(sem_empty);
    strcpy(ptr, message);
    printf("Child: wrote message to shared memory: %s\n", message);
    sem_post(sem_full);
    
    // Cleanup
    munmap(ptr, SIZE);
    close(shm_fd);
    sem_close(sem_empty);
    sem_close(sem_full);
}

void parent_process() {
    // Open shared memory
    int shm_fd = shm_open(SHM_NAME, O_RDONLY, 0666);
    char *ptr = mmap(0, SIZE, PROT_READ, MAP_SHARED, shm_fd, 0);
    
    // Open semaphores
    sem_t *sem_empty = sem_open(SEM_EMPTY, 0);
    sem_t *sem_full = sem_open(SEM_FULL, 0);
    
    // Read from shared memory
    sem_wait(sem_full);
    printf("Parent: read message from shared memory: %s\n", ptr);
    sem_post(sem_empty);
    
    // Cleanup
    munmap(ptr, SIZE);
    close(shm_fd);
    sem_close(sem_empty);
    sem_close(sem_full);
    shm_unlink(SHM_NAME); // Remove shared memory
}

int main() {
    // Create semaphores
    sem_t *sem_empty = sem_open(SEM_EMPTY, O_CREAT, 0666, 1);
    sem_t *sem_full = sem_open(SEM_FULL, O_CREAT, 0666, 0);
    
    pid_t pid = fork();
    
    if (pid < 0) {
        perror("Fork failed");
        exit(1);
    }
    
    if (pid == 0) { // Child process
        child_process();
    } else { // Parent process
        parent_process();
        wait(NULL); // Wait for child process to terminate
    }
    
    // Cleanup semaphores
    sem_unlink(SEM_EMPTY);
    sem_unlink(SEM_FULL);
    
    return 0;
}