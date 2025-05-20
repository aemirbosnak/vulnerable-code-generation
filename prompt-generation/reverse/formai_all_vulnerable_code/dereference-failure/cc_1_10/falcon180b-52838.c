//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/stat.h>

#define MAX_SIZE 1024
#define FIFO_FILE "myfifo"

int main() {
    int fd;
    char buffer[MAX_SIZE];

    // Create the FIFO file
    if (mkfifo(FIFO_FILE, S_IRUSR | S_IWUSR) == -1) {
        printf("Error creating FIFO file: %s\n", strerror(errno));
        exit(1);
    }

    // Open the FIFO file for reading and writing
    fd = open(FIFO_FILE, O_RDWR);
    if (fd == -1) {
        printf("Error opening FIFO file: %s\n", strerror(errno));
        exit(1);
    }

    // Loop to read and write messages
    while (1) {
        // Read a message from the FIFO file
        memset(buffer, 0, MAX_SIZE);
        if (read(fd, buffer, MAX_SIZE) == -1) {
            printf("Error reading from FIFO file: %s\n", strerror(errno));
            exit(1);
        }
        printf("Received message: %s\n", buffer);

        // Write a message to the FIFO file
        strcpy(buffer, "Hello, World!");
        if (write(fd, buffer, strlen(buffer)) == -1) {
            printf("Error writing to FIFO file: %s\n", strerror(errno));
            exit(1);
        }
        printf("Sent message: %s\n", buffer);
    }

    // Close the FIFO file
    close(fd);

    return 0;
}