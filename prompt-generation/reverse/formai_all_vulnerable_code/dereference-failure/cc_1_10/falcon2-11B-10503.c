//Falcon2-11B DATASET v1.0 Category: System process viewer ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char *argv[]) {
    pid_t pid = 0;
    int status;
    int fd;
    char *buffer = NULL;
    size_t bytes_read;

    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <process_name>\n", argv[0]);
        exit(1);
    }

    pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        exit(1);
    } else if (pid == 0) {
        // Child process
        // Terminate parent process
        close(0);
        close(1);
        close(2);
        dup2(fd, 0);
        dup2(fd, 1);
        dup2(fd, 2);
        close(fd);
        exit(0);
    } else {
        // Parent process
        // Find process by name
        fd = open("/proc/<process_name>", O_RDONLY);
        if (fd == -1) {
            perror("Open failed");
            exit(1);
        }

        // Read process memory usage
        bytes_read = read(fd, buffer, sizeof(buffer));
        if (bytes_read == -1) {
            perror("Read failed");
            exit(1);
        }
        printf("Memory usage: %zu bytes\n", bytes_read);

        // Wait for child process to terminate
        waitpid(pid, &status, 0);
    }

    return 0;
}