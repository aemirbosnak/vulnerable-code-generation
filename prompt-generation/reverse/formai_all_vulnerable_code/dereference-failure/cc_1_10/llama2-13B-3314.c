//LLAMA2-13B DATASET v1.0 Category: Interprocess communication ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/shm.h>

#define SHM_NAME "my_shared_memory"
#define SHM_SIZE (1024 * 1024)

int main(void) {
    // Create a shared memory segment
    int shm_id = shmget(SHM_NAME, SHM_SIZE, IPC_CREAT | 0644);
    if (shm_id == -1) {
        perror("shmget() failed");
        return 1;
    }

    // Attach to the shared memory segment
    void *shm_addr = mmap(NULL, SHM_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, shm_id, 0);
    if (shm_addr == MAP_FAILED) {
        perror("mmap() failed");
        return 1;
    }

    // Write a message to the shared memory
    char *message = "Hello from the first process!";
    strcpy(shm_addr, message);

    // Create a new process
    pid_t pid = fork();
    if (pid == 0) {
        // In the new process, read the message from the shared memory
        char *message_read = shm_addr;
        printf("Message from the first process: %s\n", message_read);

        // Write a new message to the shared memory
        char *new_message = "Hello from the second process!";
        strcpy(shm_addr, new_message);
    } else {
        // In the parent process, wait for the new process to finish
        wait(NULL);

        // Read the new message from the shared memory
        char *message_read = shm_addr;
        printf("Message from the second process: %s\n", message_read);
    }

    // Unmap the shared memory
    munmap(shm_addr, SHM_SIZE);

    return 0;
}