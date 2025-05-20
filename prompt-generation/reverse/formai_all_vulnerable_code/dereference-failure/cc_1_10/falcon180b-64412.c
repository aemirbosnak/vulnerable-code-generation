//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/mman.h>

#define SIZE 100

int main() {
    int fd[2];
    int pid;
    int status;
    char *shared_memory;
    char *child_message = "Hello from child!";
    char *parent_message = "Hello from parent!";

    if (pipe(fd) == -1) {
        perror("Pipe failed");
        exit(1);
    }

    shared_memory = (char *)mmap(NULL, SIZE, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
    if (shared_memory == MAP_FAILED) {
        perror("mmap failed");
        exit(1);
    }

    pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        exit(1);
    } else if (pid == 0) {
        close(fd[0]);
        strcpy(shared_memory, child_message);
        write(fd[1], shared_memory, strlen(child_message));
        exit(0);
    } else {
        close(fd[1]);
        read(fd[0], shared_memory, SIZE);
        printf("Received message: %s\n", shared_memory);
        waitpid(pid, &status, 0);
    }

    munmap(shared_memory, SIZE);
    close(fd[0]);
    close(fd[1]);
    return 0;
}