//LLAMA2-13B DATASET v1.0 Category: Data recovery tool ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 4096

struct file_info {
    char *name;
    size_t size;
    off_t offset;
};

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <file_path>\n", argv[0]);
        return 1;
    }

    char *file_path = argv[1];
    struct stat stat_buf;
    if (stat(file_path, &stat_buf) != 0) {
        perror("Stat failed");
        return 2;
    }

    off_t file_size = stat_buf.st_size;
    off_t buffer_size = BUFFER_SIZE;
    char *buffer = malloc(buffer_size);
    off_t current_offset = 0;

    while (current_offset < file_size) {
        ssize_t read_size = read(fileno(stdin), buffer, buffer_size);
        if (read_size < 0) {
            perror("Read failed");
            break;
        }

        for (ssize_t i = 0; i < read_size; i++) {
            if (buffer[i] == 0x0A) { // 0x0A is the newline character
                struct file_info *file_info = malloc(sizeof(struct file_info));
                file_info->name = buffer + i + 1; // Skip the newline character
                file_info->size = current_offset - current_offset;
                file_info->offset = current_offset;
                printf("%s %zu %zu\n", file_info->name, file_info->size, file_info->offset);
                current_offset += file_info->size;
                break;
            }
        }
    }

    free(buffer);
    return 0;
}