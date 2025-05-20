//Falcon2-11B DATASET v1.0 Category: File Synchronizer ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>

#define MAX_PATH_LENGTH 256

void syncFile(const char *sourcePath, const char *destinationPath) {
    int sourceFD = open(sourcePath, O_RDONLY);
    if (sourceFD < 0) {
        printf("Error opening source file: %s\n", sourcePath);
        return;
    }

    int destinationFD = open(destinationPath, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
    if (destinationFD < 0) {
        printf("Error creating destination file: %s\n", destinationPath);
        close(sourceFD);
        return;
    }

    struct stat sourceStat;
    fstat(sourceFD, &sourceStat);
    off_t sourceSize = sourceStat.st_size;

    char *buffer = malloc(sourceSize + 1);
    if (!buffer) {
        printf("Error allocating memory\n");
        close(sourceFD);
        close(destinationFD);
        return;
    }

    int bytesRead = read(sourceFD, buffer, sourceSize);
    if (bytesRead < 0) {
        printf("Error reading from source file\n");
        free(buffer);
        close(sourceFD);
        close(destinationFD);
        return;
    }
    buffer[bytesRead] = '\0';

    int bytesWritten = write(destinationFD, buffer, bytesRead);
    if (bytesWritten < 0) {
        printf("Error writing to destination file\n");
        free(buffer);
        close(sourceFD);
        close(destinationFD);
        return;
    }
    free(buffer);

    close(sourceFD);
    close(destinationFD);
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s source_path destination_path\n", argv[0]);
        return 1;
    }

    syncFile(argv[1], argv[2]);

    return 0;
}