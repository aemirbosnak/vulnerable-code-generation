//LLAMA2-13B DATASET v1.0 Category: Interprocess communication ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/mman.h>

#define BUFFER_SIZE 1024

void *shared_mem;

void *create_shared_mem(void) {
    shared_mem = mmap(NULL, BUFFER_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, -1, 0);
    if (shared_mem == MAP_FAILED) {
        perror("mmap() failed");
        exit(EXIT_FAILURE);
    }
    return shared_mem;
}

void write_to_shared_mem(char *message) {
    if (mprotect(shared_mem, BUFFER_SIZE, PROT_READ | PROT_WRITE) < 0) {
        perror("mprotect() failed");
        exit(EXIT_FAILURE);
    }
    memcpy(shared_mem, message, strlen(message));
}

char *read_from_shared_mem(void) {
    char *message = NULL;
    if (mprotect(shared_mem, BUFFER_SIZE, PROT_READ) < 0) {
        perror("mprotect() failed");
        exit(EXIT_FAILURE);
    }
    message = (char *)shared_mem;
    return message;
}

int main() {
    // Create a shared memory segment
    shared_mem = create_shared_mem();

    // Fork a child process
    pid_t pid = fork();
    if (pid < 0) {
        perror("fork() failed");
        exit(EXIT_FAILURE);
    }
    if (pid == 0) {
        // Child process
        char *message = "Hello from child!";
        write_to_shared_mem(message);
        exit(EXIT_SUCCESS);
    } else {
        // Parent process
        char *message = read_from_shared_mem();
        printf("Received message from child: %s\n", message);
        wait(NULL);
    }
    return 0;
}