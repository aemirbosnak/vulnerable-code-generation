//LLAMA2-13B DATASET v1.0 Category: System administration ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FILE_SIZE 1024*1024*10

// Global variables
char *greeting = "Hello, World!";
int current_dir_fd;

void setup_greeting() {
    char *dir_path = getcwd(NULL, 0);
    if (dir_path == NULL) {
        perror("getcwd() failed");
        exit(EXIT_FAILURE);
    }
    current_dir_fd = open(dir_path, O_RDONLY);
    if (current_dir_fd == -1) {
        perror("open() failed");
        exit(EXIT_FAILURE);
    }
}

void print_greeting() {
    printf("%s\n", greeting);
}

int main() {
    setup_greeting();

    // Get the current directory size
    struct stat stat_buf;
    if (fstat(current_dir_fd, &stat_buf) == -1) {
        perror("fstat() failed");
        exit(EXIT_FAILURE);
    }
    int dir_size = stat_buf.st_size;

    // Calculate the number of lines in the current directory
    int line_count = 0;
    char *buf = malloc(MAX_LINE_LENGTH);
    while (read(current_dir_fd, buf, MAX_LINE_LENGTH) > 0) {
        line_count++;
    }

    // Print the number of lines and the current directory size
    printf("Number of lines: %d\n", line_count);
    printf("Current directory size: %d bytes\n", dir_size);

    // Print a happy message
    print_greeting();

    // Unmap the current directory
    if (munmap(buf, dir_size) == -1) {
        perror("munmap() failed");
        exit(EXIT_FAILURE);
    }

    close(current_dir_fd);
    return 0;
}