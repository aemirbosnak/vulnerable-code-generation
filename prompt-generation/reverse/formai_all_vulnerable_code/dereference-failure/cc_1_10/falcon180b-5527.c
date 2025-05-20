//Falcon-180B DATASET v1.0 Category: File Synchronizer ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <source_file> <destination_file>\n", argv[0]);
        return 1;
    }

    FILE *source_file = fopen(argv[1], "rb");
    if (source_file == NULL) {
        printf("Error opening source file: %s\n", strerror(errno));
        return 1;
    }

    FILE *destination_file = fopen(argv[2], "wb");
    if (destination_file == NULL) {
        printf("Error opening destination file: %s\n", strerror(errno));
        fclose(source_file);
        return 1;
    }

    struct stat source_stat;
    if (fstat(fileno(source_file), &source_stat) == -1) {
        printf("Error getting source file status: %s\n", strerror(errno));
        fclose(source_file);
        fclose(destination_file);
        return 1;
    }

    off_t source_size = source_stat.st_size;
    off_t destination_size = 0;

    char buffer[BUFFER_SIZE];
    while ((source_size > 0) && (destination_size < source_size)) {
        ssize_t bytes_read = fread(buffer, 1, BUFFER_SIZE, source_file);
        if (bytes_read == -1) {
            printf("Error reading from source file: %s\n", strerror(errno));
            fclose(source_file);
            fclose(destination_file);
            return 1;
        }

        ssize_t bytes_written = fwrite(buffer, 1, bytes_read, destination_file);
        if (bytes_written == -1) {
            printf("Error writing to destination file: %s\n", strerror(errno));
            fclose(source_file);
            fclose(destination_file);
            return 1;
        }

        destination_size += bytes_written;
    }

    if (source_size!= destination_size) {
        printf("Error: Source and destination files have different sizes.\n");
        fclose(source_file);
        fclose(destination_file);
        return 1;
    }

    fclose(source_file);
    fclose(destination_file);

    printf("Files synchronized successfully.\n");
    return 0;
}