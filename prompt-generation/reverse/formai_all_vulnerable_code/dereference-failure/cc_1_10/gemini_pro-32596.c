//GEMINI-pro DATASET v1.0 Category: Data recovery tool ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>

// Structure for a deleted file
struct deleted_file {
    char *name;
    uint64_t size;
    time_t mtime;
    uint64_t offset;
};

// Function to read a sector from a disk
int read_sector(int fd, uint64_t sector, void *buf) {
    if (lseek(fd, sector * 512, SEEK_SET) == -1) {
        perror("lseek");
        return -1;
    }
    if (read(fd, buf, 512) != 512) {
        perror("read");
        return -1;
    }
    return 0;
}

// Function to write a sector to a disk
int write_sector(int fd, uint64_t sector, const void *buf) {
    if (lseek(fd, sector * 512, SEEK_SET) == -1) {
        perror("lseek");
        return -1;
    }
    if (write(fd, buf, 512) != 512) {
        perror("write");
        return -1;
    }
    return 0;
}

// Function to find a deleted file
struct deleted_file *find_deleted_file(int fd, const char *name) {
    // Read the boot sector
    struct deleted_file *file = malloc(sizeof(struct deleted_file));
    if (!file) {
        perror("malloc");
        return NULL;
    }
    if (read_sector(fd, 0, file) == -1) {
        free(file);
        return NULL;
    }

    // Loop through the FAT table
    uint64_t sector = file->offset;
    while (sector != 0xFFFFFFFF) {
        // Read the FAT entry
        uint32_t entry;
        if (read_sector(fd, sector, &entry) == -1) {
            free(file);
            return NULL;
        }

        // Check if the entry is a deleted file
        if ((entry & 0x0FFFFFFF) == 0x00000000) {
            // Get the file name
            if (strcmp(file->name, name) == 0) {
                return file;
            }
        }

        // Get the next sector
        sector = entry & 0x0FFFFFFF;
    }

    // File not found
    free(file);
    return NULL;
}

// Function to recover a deleted file
int recover_deleted_file(int fd, const struct deleted_file *file) {
    // Create a new file
    int fd_new = open(file->name, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd_new == -1) {
        perror("open");
        return -1;
    }

    // Loop through the file sectors
    uint64_t sector = file->offset;
    while (sector != 0xFFFFFFFF) {
        // Read the file sector
        uint8_t buf[512];
        if (read_sector(fd, sector, buf) == -1) {
            close(fd_new);
            return -1;
        }

        // Write the file sector
        if (write(fd_new, buf, 512) != 512) {
            close(fd_new);
            return -1;
        }

        // Get the next sector
        sector = buf[0] | (buf[1] << 8) | (buf[2] << 16) | (buf[3] << 24);
    }

    // Close the new file
    close(fd_new);

    return 0;
}

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <disk image> <file name>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Open the disk image
    int fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        perror("open");
        return EXIT_FAILURE;
    }

    // Find the deleted file
    struct deleted_file *file = find_deleted_file(fd, argv[2]);
    if (!file) {
        fprintf(stderr, "File not found\n");
        close(fd);
        return EXIT_FAILURE;
    }

    // Recover the deleted file
    if (recover_deleted_file(fd, file) == -1) {
        fprintf(stderr, "Error recovering file\n");
        close(fd);
        free(file);
        return EXIT_FAILURE;
    }

    // Free the deleted file structure
    free(file);

    // Close the disk image
    close(fd);

    return EXIT_SUCCESS;
}