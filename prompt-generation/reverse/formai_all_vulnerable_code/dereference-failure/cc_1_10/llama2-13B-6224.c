//LLAMA2-13B DATASET v1.0 Category: Interprocess communication ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/mman.h>

#define NPROC 4
#define BUFFER_SIZE 1024

void *my_mmap(void *addr, size_t len) {
    int ret;
    ret = mmap(addr, len, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    if (ret == MAP_FAILED) {
        perror("mmap failed");
        exit(EXIT_FAILURE);
    }
    return addr;
}

void *create_message(char *msg) {
    void *addr = my_mmap(NULL, BUFFER_SIZE);
    memset(addr, 0, BUFFER_SIZE);
    snprintf(addr, BUFFER_SIZE, "%s", msg);
    return addr;
}

int main() {
    // Create 4 processes
    pid_t pids[NPROC];
    for (int i = 0; i < NPROC; i++) {
        pids[i] = fork();
        if (pids[i] == 0) {
            // Child process
            char *msg = "Hello from child process!";
            void *addr = create_message(msg);
            // Communicate with parent process
            write(1, addr, strlen(msg));
            exit(EXIT_SUCCESS);
        } else {
            // Parent process
            wait(pids[i]);
        }
    }

    // Communicate with child processes
    for (int i = 0; i < NPROC; i++) {
        char buffer[BUFFER_SIZE];
        read(i + 1, buffer, BUFFER_SIZE);
        printf("Received message from child process %d: %s\n", i + 1, buffer);
    }

    return 0;
}