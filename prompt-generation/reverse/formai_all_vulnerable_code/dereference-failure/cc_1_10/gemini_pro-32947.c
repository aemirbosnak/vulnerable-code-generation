//GEMINI-pro DATASET v1.0 Category: Data recovery tool ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <image file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Open the image file
    int fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        perror("open");
        return EXIT_FAILURE;
    }

    // Get the size of the image file
    struct stat st;
    if (fstat(fd, &st) == -1) {
        perror("fstat");
        return EXIT_FAILURE;
    }

    // Allocate a buffer to hold the image data
    uint8_t *buffer = malloc(st.st_size);
    if (buffer == NULL) {
        fprintf(stderr, "malloc failed\n");
        return EXIT_FAILURE;
    }

    // Read the image data into the buffer
    if (read(fd, buffer, st.st_size) != st.st_size) {
        perror("read");
        return EXIT_FAILURE;
    }

    // Close the image file
    close(fd);

    // Find the start of the partition table
    uint32_t partition_table_offset = 446;

    // Get the number of partitions in the partition table
    uint8_t num_partitions = buffer[partition_table_offset];

    // Iterate over the partitions and print their information
    for (int i = 0; i < num_partitions; i++) {
        // Get the partition's starting sector
        uint32_t starting_sector = *(uint32_t *)(buffer + partition_table_offset + 8 + (i * 16));

        // Get the partition's size in sectors
        uint32_t size_in_sectors = *(uint32_t *)(buffer + partition_table_offset + 12 + (i * 16));

        // Print the partition's information
        printf("Partition %d:\n", i);
        printf("  Starting sector: %u\n", starting_sector);
        printf("  Size in sectors: %u\n", size_in_sectors);
    }

    // Free the buffer
    free(buffer);

    return EXIT_SUCCESS;
}