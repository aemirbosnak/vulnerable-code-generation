//Falcon2-11B DATASET v1.0 Category: RAM usage monitor ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t child_pid;
    int status;

    printf("Parent PID: %d\n", getpid());

    child_pid = fork();

    if (child_pid == -1) {
        perror("fork");
        exit(1);
    }

    if (child_pid == 0) {
        printf("Child PID: %d\n", getpid());

        // Allocate memory
        char* buffer = (char*)malloc(1024);

        // Modify the memory
        for (int i = 0; i < 1024; i++) {
            buffer[i] = i;
        }

        // Print the memory
        for (int i = 0; i < 1024; i++) {
            printf("%d ", buffer[i]);
        }
        printf("\n");

        exit(0);
    } else {
        // Wait for the child process to finish
        wait(&status);

        printf("Parent PID: %d\n", getpid());

        printf("Child PID: %d\n", child_pid);

        if (WIFEXITED(status)) {
            printf("Child exited normally with status %d\n", WEXITSTATUS(status));
        } else if (WIFSIGNALED(status)) {
            printf("Child terminated by signal %d\n", WTERMSIG(status));
        } else {
            printf("Child terminated by unknown signal\n");
        }

        exit(0);
    }
}