//FormAI DATASET v1.0 Category: File handling ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <signal.h>

#define MAX_BUF_SIZE 256

int main(int argc, char *argv[]) {
    if(argc != 2) {
        printf("Usage: ./a.out <filename>\n");
        exit(1);
    }

    char *filename = argv[1];
    int fd = open(filename, O_CREAT | O_RDWR, S_IRUSR | S_IWUSR);

    if(fd == -1) {
        fprintf(stderr, "Error opening file: %s\n", strerror(errno));
        exit(1);
    }

    char buffer[MAX_BUF_SIZE];
    int bytesRead = 0;

    printf("Type something and press enter. Press 'q' and enter to quit\n");

    while(1) {
        // read user input from stdin asynchronously
        fgets(buffer, MAX_BUF_SIZE, stdin);

        if(buffer[0] == 'q') {
            break;
        }

        // write to file asynchronously
        int bytesWritten = write(fd, buffer, strlen(buffer));

        if(bytesWritten == -1) {
            fprintf(stderr, "Error writing to file: %s\n", strerror(errno));
            exit(1);
        }
    }

    close(fd);
    return 0;
}