//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

#define BLOCK_SIZE 1024

typedef struct {
    char* filename;
    int blocks;
    int block_size;
} File;

void read_file(File* file) {
    int fd = open(file->filename, O_RDONLY);
    if (fd == -1) {
        printf("Error opening file: %s\n", file->filename);
        exit(1);
    }

    struct stat stat;
    fstat(fd, &stat);

    file->blocks = stat.st_size / file->block_size;

    char* buffer = malloc(file->block_size);

    int i = 0;
    while (i < file->blocks) {
        int bytes_read = read(fd, buffer, file->block_size);
        if (bytes_read == -1) {
            printf("Error reading file: %s\n", file->filename);
            exit(1);
        }

        printf("%s\n", buffer);
        i++;
    }

    close(fd);
}

void write_file(File* file) {
    int fd = open(file->filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1) {
        printf("Error opening file: %s\n", file->filename);
        exit(1);
    }

    char* buffer = malloc(file->block_size);

    int i = 0;
    while (i < file->blocks) {
        printf("Enter block %d:\n", i+1);
        fgets(buffer, file->block_size, stdin);

        int bytes_written = write(fd, buffer, strlen(buffer));
        if (bytes_written == -1) {
            printf("Error writing file: %s\n", file->filename);
            exit(1);
        }

        i++;
    }

    close(fd);
}

int main() {
    File file;

    printf("Enter filename:\n");
    scanf("%s", file.filename);

    printf("Enter block size (in bytes):\n");
    scanf("%d", &file.block_size);

    printf("Enter number of blocks:\n");
    scanf("%d", &file.blocks);

    int choice;
    printf("Choose an option:\n1. Read file\n2. Write file\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            read_file(&file);
            break;
        case 2:
            write_file(&file);
            break;
        default:
            printf("Invalid option\n");
    }

    return 0;
}