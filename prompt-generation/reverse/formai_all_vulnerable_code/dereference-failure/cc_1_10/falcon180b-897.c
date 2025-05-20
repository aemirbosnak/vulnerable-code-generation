//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: Cryptic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<errno.h>

#define BUF_SIZE 1024
#define MAX_FILE_SIZE (1024*1024*10) //10 MB

typedef struct {
    char *filename;
    int filesize;
    int fd;
    char *buffer;
} File;

int main(int argc, char **argv) {
    if(argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    char *filename = argv[1];
    int fd = open(filename, O_RDONLY);
    if(fd == -1) {
        printf("Error opening file: %s\n", strerror(errno));
        exit(1);
    }

    struct stat st;
    if(fstat(fd, &st) == -1) {
        printf("Error getting file size: %s\n", strerror(errno));
        exit(1);
    }

    if(st.st_size > MAX_FILE_SIZE) {
        printf("File is too large!\n");
        exit(1);
    }

    File *file = malloc(sizeof(File));
    file->filename = filename;
    file->filesize = st.st_size;
    file->fd = fd;
    file->buffer = malloc(BUF_SIZE);

    int bytes_read = 0;
    int bytes_written = 0;
    while((bytes_read = read(fd, file->buffer, BUF_SIZE)) > 0) {
        if(write(1, file->buffer, bytes_read)!= bytes_read) {
            printf("Error writing to stdout: %s\n", strerror(errno));
            exit(1);
        }
        bytes_written += bytes_read;
    }

    if(bytes_read == -1) {
        printf("Error reading from file: %s\n", strerror(errno));
        exit(1);
    }

    if(bytes_written!= st.st_size) {
        printf("Error: Data recovery failed!\n");
        exit(1);
    }

    printf("Data recovery successful!\n");

    free(file->buffer);
    free(file);
    close(fd);

    return 0;
}