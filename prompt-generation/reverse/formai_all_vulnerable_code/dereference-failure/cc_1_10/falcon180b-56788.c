//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

#define BUFFER_SIZE 1024

typedef struct {
    int fd;
    char* filename;
    off_t file_size;
    char* buffer;
} FileData;

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: %s <file_path>\n", argv[0]);
        return 1;
    }

    char* file_path = argv[1];
    int fd = open(file_path, O_RDWR);
    if (fd < 0) {
        printf("Error opening file: %s\n", file_path);
        return 1;
    }

    struct stat file_stat;
    if (fstat(fd, &file_stat) < 0) {
        printf("Error getting file status: %s\n", file_path);
        return 1;
    }

    FileData* file_data = malloc(sizeof(FileData));
    file_data->fd = fd;
    file_data->filename = strdup(file_path);
    file_data->file_size = file_stat.st_size;
    file_data->buffer = malloc(BUFFER_SIZE);

    int bytes_read = 0;
    while ((bytes_read = read(fd, file_data->buffer, BUFFER_SIZE)) > 0) {
        printf("%s", file_data->buffer);
    }

    close(fd);
    free(file_data->filename);
    free(file_data->buffer);
    free(file_data);

    return 0;
}