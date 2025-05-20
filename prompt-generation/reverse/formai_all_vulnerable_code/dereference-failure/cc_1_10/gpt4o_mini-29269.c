//GPT-4o-mini DATASET v1.0 Category: Data recovery tool ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>

#define BLOCK_SIZE 512
#define FILE_PATH "disk_image.img"
#define RECOVERED_FILE_PATH "recovered_data.bin"
#define MAGIC_HEADER "DATA_RECOVERY"

void *malloc_safe(size_t size) {
    void *ptr = malloc(size);
    if (!ptr) {
        perror("Failed to allocate memory");
        exit(EXIT_FAILURE);
    }
    return ptr;
}

void write_to_file(const char *filename, unsigned char *data, size_t size) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("Failed to open file for writing");
        exit(EXIT_FAILURE);
    }
    fwrite(data, sizeof(unsigned char), size, file);
    fclose(file);
}

void read_from_device(const char *device, unsigned char *buffer, size_t block_count) {
    int fd = open(device, O_RDONLY);
    if (fd < 0) {
        perror("Failed to open the device");
        exit(EXIT_FAILURE);
    }
    
    ssize_t read_bytes = read(fd, buffer, block_count * BLOCK_SIZE);
    if (read_bytes < 0) {
        perror("Failed to read from device");
        close(fd);
        exit(EXIT_FAILURE);
    }
    
    close(fd);
}

int search_for_magic_header(unsigned char *buffer, size_t block_count) {
    for (size_t i = 0; i < block_count * BLOCK_SIZE; i++) {
        if (strncmp((char *)&buffer[i], MAGIC_HEADER, strlen(MAGIC_HEADER)) == 0) {
            return i; // Found the magic header position
        }
    }
    return -1; // Not found
}

void recover_data_from_image(const char *device, const char *output_file) {
    size_t block_count = 1024; // Number of blocks to read from the device
    unsigned char *buffer = malloc_safe(BLOCK_SIZE * block_count);
    
    read_from_device(device, buffer, block_count);
    
    int header_position = search_for_magic_header(buffer, block_count);
    if (header_position != -1) {
        write_to_file(output_file, &buffer[header_position], BLOCK_SIZE * (block_count - header_position / BLOCK_SIZE));
        printf("Data recovery successful. Recovered data written to %s\n", output_file);
    } else {
        printf("No recoverable data found.\n");
    }
    
    free(buffer);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <device_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *device_file = argv[1];
    recover_data_from_image(device_file, RECOVERED_FILE_PATH);

    return EXIT_SUCCESS;
}