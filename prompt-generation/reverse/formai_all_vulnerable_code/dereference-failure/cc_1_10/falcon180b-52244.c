//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

#define BUFFER_SIZE 4096

typedef struct {
    char *filename;
    int size;
    int offset;
    int fd;
} FILE_INFO;

FILE_INFO *read_file_info(char *filename) {
    FILE_INFO *info = malloc(sizeof(FILE_INFO));
    int fd = open(filename, O_RDONLY);

    if (fd == -1) {
        printf("Error: Could not open file %s\n", filename);
        exit(1);
    }

    struct stat statbuf;
    if (fstat(fd, &statbuf) == -1) {
        printf("Error: Could not get file size for %s\n", filename);
        exit(1);
    }

    info->filename = strdup(filename);
    info->size = statbuf.st_size;
    info->offset = 0;
    info->fd = fd;

    return info;
}

int search_file(FILE_INFO *info, char *pattern) {
    int bytes_read;
    char buffer[BUFFER_SIZE];
    char *found_pattern = NULL;

    while ((bytes_read = read(info->fd, buffer, BUFFER_SIZE)) > 0) {
        char *start = buffer;
        while ((found_pattern = strstr(start, pattern))!= NULL) {
            printf("Found pattern '%s' at offset %d\n", pattern, info->offset + (found_pattern - buffer));
            info->offset += (found_pattern - buffer);
        }
        start += bytes_read - strlen(buffer);
        info->offset += bytes_read - strlen(buffer);
    }

    if (bytes_read == -1) {
        printf("Error: Could not read from file %s\n", info->filename);
        exit(1);
    }

    return 0;
}

int main(int argc, char **argv) {
    if (argc < 3) {
        printf("Usage: %s [filename] [pattern]\n", argv[0]);
        exit(1);
    }

    FILE_INFO *info = read_file_info(argv[1]);
    search_file(info, argv[2]);

    free(info->filename);
    close(info->fd);
    free(info);

    return 0;
}