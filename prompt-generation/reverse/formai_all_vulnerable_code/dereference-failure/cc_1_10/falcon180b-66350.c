//Falcon-180B DATASET v1.0 Category: System administration ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

#define BUFFER_SIZE 1024

void execute_command(char **args) {
    pid_t pid = fork();

    if (pid == 0) { // Child process
        if (execvp(args[0], args) == -1) {
            perror("Error executing command");
            exit(1);
        }
    } else if (pid < 0) { // Error forking
        perror("Error forking");
        exit(1);
    } else { // Parent process
        int status;
        waitpid(pid, &status, 0);
    }
}

void read_file(char *filename, char **buffer) {
    int file_descriptor = open(filename, O_RDONLY);

    if (file_descriptor == -1) {
        perror("Error opening file");
        exit(1);
    }

    struct stat file_stat;
    if (fstat(file_descriptor, &file_stat) == -1) {
        perror("Error getting file status");
        exit(1);
    }

    size_t file_size = file_stat.st_size;
    *buffer = malloc(file_size + 1);

    ssize_t bytes_read = read(file_descriptor, *buffer, file_size);

    if (bytes_read!= file_size) {
        perror("Error reading file");
        exit(1);
    }

    (*buffer)[file_size] = '\0';
    close(file_descriptor);
}

int main(int argc, char **argv) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <command> <filename>\n", argv[0]);
        exit(1);
    }

    char *command = argv[1];
    char *filename = argv[2];

    char *buffer = NULL;
    read_file(filename, &buffer);

    char **args = malloc(3 * sizeof(char *));
    args[0] = "sh";
    args[1] = "-c";
    args[2] = buffer;

    execute_command(args);

    free(buffer);
    free(args);

    return 0;
}