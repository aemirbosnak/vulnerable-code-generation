//GPT-4o-mini DATASET v1.0 Category: Data recovery tool ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>

#define BLOCK_SIZE 512
#define MAGIC_NUMBER 0xDEADBEEF
#define FILE_RECOVERY_LIMIT 10

typedef struct {
    unsigned int magic;
    int file_size;
    char filename[32];
} FileHeader;

void recover_file(int fd, int offset, const char *filename) {
    FileHeader header;
    lseek(fd, offset, SEEK_SET);
    read(fd, &header, sizeof(FileHeader));

    if (header.magic != MAGIC_NUMBER) {
        fprintf(stderr, "Invalid file header at offset %d\n", offset);
        return;
    }

    char *buffer = malloc(header.file_size);
    if (!buffer) {
        fprintf(stderr, "Memory allocation failed\n");
        return;
    }

    read(fd, buffer, header.file_size);
    FILE *out = fopen(filename, "wb");
    if (!out) {
        fprintf(stderr, "Error creating file %s: %s\n", filename, strerror(errno));
        free(buffer);
        return;
    }

    fwrite(buffer, 1, header.file_size, out);
    fclose(out);
    free(buffer);
    printf("Recovered file: %s (size: %d bytes)\n", filename, header.file_size);
}

void scan_for_files(const char *disk_image) {
    int fd = open(disk_image, O_RDONLY);
    if (fd < 0) {
        fprintf(stderr, "Error opening disk image %s: %s\n", disk_image, strerror(errno));
        return;
    }

    printf("Scanning %s for files...\n", disk_image);
    int block_offset = 0;
    int files_recovered = 0;

    while (files_recovered < FILE_RECOVERY_LIMIT) {
        FileHeader header;

        if (lseek(fd, block_offset, SEEK_SET) < 0) {
            fprintf(stderr, "Error seeking in disk image: %s\n", strerror(errno));
            break;
        }

        ssize_t read_bytes = read(fd, &header, sizeof(FileHeader));

        if (read_bytes < 0) {
            fprintf(stderr, "Error reading from disk image: %s\n", strerror(errno));
            break;
        }

        if (read_bytes == 0) {
            break; // End of file
        }

        if (header.magic == MAGIC_NUMBER) {
            char filename[36]; // Filename + NULL terminator
            snprintf(filename, sizeof(filename), "%s", header.filename);
            recover_file(fd, block_offset + sizeof(FileHeader), filename);
            files_recovered++;
        }

        block_offset += BLOCK_SIZE; // Move to the next block
    }

    close(fd);
    printf("Recovery process completed. Total files recovered: %d\n", files_recovered);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <disk_image>\n", argv[0]);
        return EXIT_FAILURE;
    }

    scan_for_files(argv[1]);
    return EXIT_SUCCESS;
}