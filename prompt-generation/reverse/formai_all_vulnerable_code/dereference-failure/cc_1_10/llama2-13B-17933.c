//LLAMA2-13B DATASET v1.0 Category: Interprocess communication ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/shm.h>

#define SHM_KEY 0xdeadbeef
#define SHM_SIZE (1024 * 1024 * 2)

void *shm_create(void) {
    int shmid = shmget(SHM_KEY, SHM_SIZE, IPC_CREAT | 0644);
    if (shmid < 0) {
        perror("shmget");
        exit(EXIT_FAILURE);
    }

    void *shm = mmap(NULL, SHM_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, shmid, 0);
    if (shm == MAP_FAILED) {
        perror("mmap");
        exit(EXIT_FAILURE);
    }

    return shm;
}

void shm_write(void *shm, const char *message) {
    char *ptr = shm;
    while (*message != '\0') {
        *ptr++ = *message++;
    }
}

char *shm_read(void *shm) {
    char *ptr = shm;
    char buffer[1024];
    memset(buffer, 0, sizeof(buffer));

    while (*ptr != '\0') {
        buffer[sizeof(buffer) - 1] = *ptr++;
    }

    return buffer;
}

int main() {
    void *shm = shm_create();
    shm_write(shm, "Hello from parent process!");

    // Fork a child process
    pid_t pid = fork();
    if (pid < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) {
        // Child process
        char *message = shm_read(shm);
        printf("%s\n", message);

        // Modify the shared memory
        char new_message[] = "Hello from child process!";
        strcpy(shm, new_message);

        // Exit the child process
        exit(EXIT_SUCCESS);
    } else {
        // Parent process
        char *message = shm_read(shm);
        printf("%s\n", message);
    }

    return 0;
}