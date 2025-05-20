//GEMINI-pro DATASET v1.0 Category: System administration ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

int main() {
    // Create a temporary file
    FILE *fp = tmpfile();
    if (fp == NULL) {
        perror("tmpfile");
        return EXIT_FAILURE;
    }

    // Write some data to the file
    const char *data = "Hello, world!\n";
    fwrite(data, strlen(data), 1, fp);
    fflush(fp);

    // Get the file descriptor for the temporary file
    int fd = fileno(fp);

    // Fork a child process
    pid_t child_pid = fork();
    if (child_pid == -1) {
        perror("fork");
        return EXIT_FAILURE;
    }

    // In the child process, read the data from the file and print it
    if (child_pid == 0) {
        char buffer[1024];
        memset(buffer, 0, sizeof(buffer));
        read(fd, buffer, sizeof(buffer));
        printf("%s", buffer);
        exit(EXIT_SUCCESS);
    }

    // In the parent process, wait for the child process to finish
    int status;
    waitpid(child_pid, &status, 0);

    // Close the temporary file
    fclose(fp);

    // If the child process exited with an error, return an error code
    if (WEXITSTATUS(status) != EXIT_SUCCESS) {
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}