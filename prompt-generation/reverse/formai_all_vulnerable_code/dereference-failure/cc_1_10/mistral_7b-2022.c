//MISTRAL-7B DATASET v1.0 Category: System administration ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_PATH 1024
#define MAX_FILE 256
#define MAX_CONTENT 1024

void die(char *message) {
    perror(message);
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {

    if (argc < 4) {
        fprintf(stderr, "Usage: %s <path_to_directory> <file_to_read> <content_to_write>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char path[MAX_PATH];
    char file[MAX_FILE];
    char content[MAX_CONTENT];

    strcpy(path, argv[1]);
    strcpy(file, argv[2]);

    if (chdir(path) == -1) {
        die("Failed to change directory!");
    }

    int fd_file = open(file, O_RDONLY);
    if (fd_file == -1) {
        die("Failed to open file for reading!");
    }

    ssize_t bytes_read = read(fd_file, content, MAX_CONTENT - 1);
    if (bytes_read < 0) {
        die("Failed to read file content!");
    }
    content[bytes_read] = '\0'; // null terminate the string
    close(fd_file);

    int fd_new_file = open(file, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
    if (fd_new_file == -1) {
        die("Failed to open file for writing!");
    }

    // Shocked style - Reverse the content and write it back to the file
    for (int i = strlen(content) - 1; i >= 0; i--) {
        if (write(fd_new_file, &content[i], 1) == -1) {
            die("Failed to write reversed content to file!");
        }
    }

    close(fd_new_file);

    printf("File %s in directory %s has been shocked with reversed content!\n", file, path);

    return EXIT_SUCCESS;
}