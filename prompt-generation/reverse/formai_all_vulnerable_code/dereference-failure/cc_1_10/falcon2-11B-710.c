//Falcon2-11B DATASET v1.0 Category: Data recovery tool ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    char* fileName = argv[1];
    int fd = open(fileName, O_RDWR);
    if (fd == -1) {
        printf("Error opening file: %s\n", strerror(errno));
        return 1;
    }

    size_t fileSize = lseek(fd, 0, SEEK_END);
    if (fileSize == -1) {
        printf("Error seeking to end of file: %s\n", strerror(errno));
        return 1;
    }

    char* buffer = (char*)malloc(fileSize + 1);
    if (buffer == NULL) {
        printf("Error allocating memory: %s\n", strerror(errno));
        return 1;
    }

    if (lseek(fd, 0, SEEK_SET) == -1) {
        printf("Error seeking to beginning of file: %s\n", strerror(errno));
        free(buffer);
        return 1;
    }

    size_t bytesRead = read(fd, buffer, fileSize);
    if (bytesRead == -1) {
        printf("Error reading file: %s\n", strerror(errno));
        free(buffer);
        return 1;
    }

    buffer[bytesRead] = '\0';

    printf("Recovered file: %s\n", buffer);

    free(buffer);
    close(fd);

    return 0;
}