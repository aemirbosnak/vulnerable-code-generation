//MISTRAL-7B DATASET v1.0 Category: File handling ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FILE_NAME_LENGTH 256

int main(int argc, char *argv[]) {
    int ch, fd;
    char fileName[MAX_FILE_NAME_LENGTH], buffer[MAX_LINE_LENGTH];
    struct stat fileStat;

    if (argc != 2) {
        printf("Usage : %s <filename>\n", argv[0]);
        return 1;
    }

    strcpy(fileName, argv[1]);

    fd = open(fileName, O_RDONLY);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }

    if (fstat(fd, &fileStat) == -1) {
        perror("Error getting file status");
        close(fd);
        return 1;
    }

    printf("File Size : %lld bytes\n", (long long)fileStat.st_size);

    while ((ch = read(fd, buffer, MAX_LINE_LENGTH)) > 0) {
        buffer[ch] = '\0';
        printf("%s\n", buffer);
    }

    close(fd);

    if (ch == -1) {
        perror("Error reading file");
        return 1;
    }

    return 0;
}