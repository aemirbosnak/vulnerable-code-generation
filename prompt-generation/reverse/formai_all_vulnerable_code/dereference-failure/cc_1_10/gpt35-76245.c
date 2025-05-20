//FormAI DATASET v1.0 Category: String manipulation ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define MAX_LEN 1024

int main() {
    // Open file for reading
    int fd = open("example.txt", O_RDONLY | O_CREAT, S_IRUSR | S_IWUSR);
    if (fd == -1) {
        perror("Error opening file");
        return errno;
    }

    // Read file contents into buffer
    char buffer[MAX_LEN];
    ssize_t num_read = read(fd, buffer, MAX_LEN);
    if (num_read == -1) {
        perror("Error reading file");
        return errno;
    }

    // Close file and convert buffer to C string
    close(fd);
    buffer[num_read] = '\0';

    // Asynchronously reverse the C string
    char *reverse_buf = calloc(num_read+1, sizeof(char));
    int i;
    pid_t pid = fork();
    if (pid == -1) {
        perror("Error forking process");
        return errno;
    }
    else if (pid == 0) {
        for (i = num_read-1; i >= 0; i--) {
            reverse_buf[num_read-1-i] = buffer[i];
        }
        printf("Reversing string...\n");
        sleep(2);
        _exit(0);
    }
    else {
        printf("Processing file...\n");
        sleep(1);
    }

    // Print original and reversed strings
    printf("Original string: %s\n", buffer);
    printf("Reversed string: %s\n", reverse_buf);

    return 0;
}