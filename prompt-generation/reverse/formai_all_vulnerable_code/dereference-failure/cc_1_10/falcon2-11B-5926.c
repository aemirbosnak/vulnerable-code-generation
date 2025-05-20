//Falcon2-11B DATASET v1.0 Category: System administration ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void print_usage() {
    printf("Usage:./process_manager <pid_file> <command>\n");
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        print_usage();
        exit(1);
    }

    char *pid_file = argv[1];
    char *command = argv[2];

    // Check if the pid file already exists
    if (access(pid_file, F_OK) == 0) {
        printf("PID file already exists. Please remove it first.\n");
        exit(1);
    }

    // Create the pid file
    FILE *pid_file_fp = fopen(pid_file, "w");
    if (pid_file_fp == NULL) {
        printf("Failed to create PID file.\n");
        exit(1);
    }

    // Fork to create a child process
    pid_t pid = fork();
    if (pid < 0) {
        printf("Fork failed.\n");
        exit(1);
    } else if (pid == 0) {
        // Child process
        execvp(command, &command);
        perror("execvp");
        exit(1);
    }

    // Wait for the child process to finish
    int status;
    waitpid(pid, &status, 0);

    // Close the pid file
    fclose(pid_file_fp);

    // Clean up
    unlink(pid_file);

    return 0;
}