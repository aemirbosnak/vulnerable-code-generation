//MISTRAL-7B DATASET v1.0 Category: File handling ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define FILE_MAGIC_NUMBER 0xDEADBEEF

typedef struct {
    char name[256];
    int size;
    time_t creation_time;
    time_t modification_time;
    int magic_number;
} FileInfo;

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <file_path>\n", argv[0]);
        return 1;
    }

    int file_fd = open(argv[1], O_RDONLY);
    if (file_fd < 0) {
        perror("Error opening file");
        return 1;
    }

    struct stat file_stat;
    if (fstat(file_fd, &file_stat) < 0) {
        perror("Error getting file status");
        close(file_fd);
        return 1;
    }

    char *file_buffer = malloc(file_stat.st_size);
    if (file_buffer == NULL) {
        perror("Error allocating memory");
        close(file_fd);
        return 1;
    }

    ssize_t bytes_read = read(file_fd, file_buffer, file_stat.st_size);
    if (bytes_read < 0) {
        perror("Error reading file");
        free(file_buffer);
        close(file_fd);
        return 1;
    }

    FileInfo file_info;
    strncpy(file_info.name, argv[1], sizeof(file_info.name));
    file_info.size = file_stat.st_size;
    file_info.creation_time = file_stat.st_ctime;
    file_info.modification_time = file_stat.st_mtime;
    file_info.magic_number = FILE_MAGIC_NUMBER;

    printf("File info for '%s':\n", file_info.name);
    printf("Size: %d bytes\n", file_info.size);
    printf("Creation time: %s\n", ctime(&file_info.creation_time));
    printf("Modification time: %s\n", ctime(&file_info.modification_time));
    printf("Magic number: 0x%x\n", file_info.magic_number);

    printf("\nFile contents:\n");
    for (int i = 0; i < file_stat.st_size; i += 16) {
        printf("%02x %02x %02x %02x %02x %02x %02x %02x ",
            file_buffer[i], file_buffer[i + 1],
            file_buffer[i + 2], file_buffer[i + 3],
            file_buffer[i + 4], file_buffer[i + 5],
            file_buffer[i + 6], file_buffer[i + 7]);
        if ((i + 8) % 16 == 0) {
            printf("\n");
        }
    }

    free(file_buffer);
    close(file_fd);

    return 0;
}