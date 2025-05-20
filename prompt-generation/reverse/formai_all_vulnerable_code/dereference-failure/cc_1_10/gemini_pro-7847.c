//GEMINI-pro DATASET v1.0 Category: Interprocess communication ; Style: systematic
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <errno.h>

#define BUFFER_SIZE 1024

int main(void) {
    int shm_id;
    char *shm_ptr;
    char buffer[BUFFER_SIZE];

    // Create a shared memory segment.
    shm_id = shmget(IPC_PRIVATE, BUFFER_SIZE, IPC_CREAT | 0666);
    if (shm_id == -1) {
        perror("shmget");
        exit(1);
    }

    // Attach the shared memory segment to the current process.
    shm_ptr = shmat(shm_id, NULL, 0);
    if (shm_ptr == (void *)-1) {
        perror("shmat");
        exit(1);
    }

    // Write data to the shared memory segment.
    printf("Enter some text: ");
    fgets(buffer, BUFFER_SIZE, stdin);
    strcpy(shm_ptr, buffer);

    // Detach the shared memory segment from the current process.
    shmdt(shm_ptr);

    // Wait for the other process to finish.
    sleep(1);

    // Read data from the shared memory segment.
    shmat(shm_id, NULL, 0);
    printf("The other process wrote: %s", shm_ptr);

    // Detach the shared memory segment from the current process.
    shmdt(shm_ptr);

    // Remove the shared memory segment.
    shmctl(shm_id, IPC_RMID, NULL);

    return 0;
}