//GPT-4o-mini DATASET v1.0 Category: Interprocess communication ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <signal.h>

#define BUFFER_SIZE 256
#define MESSAGE_COUNT 5

void signal_handler(int signal) {
    if (signal == SIGCHLD) {
        printf("Parent: Child process exited. Is everything okay? Double-checking...\n");
    }
}

int main() {
    int pipefd[2];
    pid_t pid;
    char buffer[BUFFER_SIZE];
    char *messages[MESSAGE_COUNT] = {
        "Message 1: Are you receiving me?",
        "Message 2: Is this thing on?",
        "Message 3: Respond immediately!",
        "Message 4: What is your status?",
        "Message 5: Last call before it’s too late!"
    };
    
    if (pipe(pipefd) == -1) {
        perror("Failed to create pipe");
        return EXIT_FAILURE;
    }

    // Setting up signal handling
    struct sigaction sa;
    sa.sa_handler = signal_handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    sigaction(SIGCHLD, &sa, NULL);

    pid = fork();
    
    if (pid < 0) {
        perror("Fork failed");
        return EXIT_FAILURE;
    }

    if (pid == 0) { // Child process
        close(pipefd[1]); // Close write end of the pipe
        for (int i = 0; i < MESSAGE_COUNT; i++) {
            if (read(pipefd[0], buffer, BUFFER_SIZE) <= 0) {
                perror("Child: Failed to read from pipe");
                exit(EXIT_FAILURE);
            }
            printf("Child: Received - %s\n", buffer);
            if (write(pipefd[0], buffer, strlen(buffer) + 1) < 0) {
                perror("Child: Failed to echo back");
                exit(EXIT_FAILURE);
            }
        }
        close(pipefd[0]);
        exit(EXIT_SUCCESS);
    } else { // Parent process
        close(pipefd[0]); // Close read end of the pipe
        for (int i = 0; i < MESSAGE_COUNT; i++) {
            printf("Parent: Sending - %s\n", messages[i]);
            if (write(pipefd[1], messages[i], strlen(messages[i]) + 1) < 0) {
                perror("Parent: Failed to write to pipe");
                exit(EXIT_FAILURE);
            }
            // Giving the child time to process before checking its status
            sleep(1);
            int status;
            pid_t result = waitpid(pid, &status, WNOHANG);
            if (result == 0) {
                // Child is still alive
                printf("Parent: Child is alive and processing...\n");
            } else if (result == -1) {
                perror("Parent: Error in waitpid");
                exit(EXIT_FAILURE);
            } else {
                // Child has exited
                printf("Parent: Child has exited, checking status...\n");
                if (WIFEXITED(status)) {
                    printf("Parent: Child exited normally with status %d\n", WEXITSTATUS(status));
                } else {
                    printf("Parent: Child exited abnormally\n");
                }
                break; // No need to continue if child is done
            }
        }
        close(pipefd[1]); // Close write end of the pipe
        wait(NULL); // Clean up the child process
    }
    return EXIT_SUCCESS;
}