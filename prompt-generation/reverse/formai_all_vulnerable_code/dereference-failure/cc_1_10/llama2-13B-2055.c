//LLAMA2-13B DATASET v1.0 Category: Interprocess communication ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/mman.h>

#define BUFFER_SIZE 1024

void* shared_mem;

void create_shared_mem(void) {
    shared_mem = mmap(NULL, BUFFER_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, -1, 0);
    if (shared_mem == MAP_FAILED) {
        perror("mmap() failed");
        exit(EXIT_FAILURE);
    }
}

void write_to_shared_mem(char* message) {
    if (shared_mem != MAP_FAILED) {
        memcpy(shared_mem, message, strlen(message));
    }
}

char* read_from_shared_mem(void) {
    char* message = NULL;
    if (shared_mem != MAP_FAILED) {
        message = (char*)shared_mem;
    }
    return message;
}

int main() {
    create_shared_mem();

    // Child process
    if (fork() == 0) {
        char* message = "Hello, parent!";
        write_to_shared_mem(message);
        exit(EXIT_SUCCESS);
    }

    // Parent process
    char* message = read_from_shared_mem();
    if (message != NULL) {
        printf("Received message from child: %s\n", message);
    }

    return 0;
}