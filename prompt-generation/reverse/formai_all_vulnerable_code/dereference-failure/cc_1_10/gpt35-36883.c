//FormAI DATASET v1.0 Category: Interprocess communication ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>

#define SHARED_MEMORY_NAME "/example_shared_memory"
#define MESSAGE_MAX_LEN 256

typedef struct
{
    int message_counter;
    char message[MESSAGE_MAX_LEN];
} shared_data_t;

int main()
{
    shared_data_t *shared_memory_ptr;
    int shared_memory_fd;

    // Create shared memory object
    shared_memory_fd = shm_open(SHARED_MEMORY_NAME, O_CREAT | O_RDWR, S_IRUSR | S_IWUSR);
    if (shared_memory_fd < 0)
    {
        perror("Shared memory creation failed");
        exit(1);
    }

    // Allocate shared memory
    if (ftruncate(shared_memory_fd, sizeof(shared_data_t)) < 0)
    {
        perror("Shared memory resize failed");
        exit(1);
    }

    // Map shared memory to process address space
    shared_memory_ptr = mmap(NULL, sizeof(shared_data_t), PROT_READ | PROT_WRITE, MAP_SHARED, shared_memory_fd, 0);
    if (shared_memory_ptr == MAP_FAILED)
    {
        perror("Shared memory mapping failed");
        exit(1);
    }

    // Initialize shared memory
    shared_memory_ptr->message_counter = 0;
    memset(shared_memory_ptr->message, 0, MESSAGE_MAX_LEN);

    // Write message to shared memory
    strcpy(shared_memory_ptr->message, "Hello, world!");
    shared_memory_ptr->message_counter++;

    // Print message from shared memory
    printf("Message: %s (counter: %d)\n", shared_memory_ptr->message, shared_memory_ptr->message_counter);

    // Unmap shared memory
    munmap(shared_memory_ptr, sizeof(shared_data_t));

    // Close shared memory file descriptor
    close(shared_memory_fd);

    // Remove shared memory object
    shm_unlink(SHARED_MEMORY_NAME);

    return 0;
}