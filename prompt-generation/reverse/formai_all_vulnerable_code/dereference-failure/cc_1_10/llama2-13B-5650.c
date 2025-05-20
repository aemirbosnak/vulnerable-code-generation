//LLAMA2-13B DATASET v1.0 Category: File handling ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>

#define MAX_PATH 1024
#define BUFFER_SIZE 4096

int main() {
    char *filename = "invasive_example.txt";
    char *buffer = malloc(BUFFER_SIZE);
    int fd;
    off_t file_size;
    struct stat stat_info;

    // Open the file in read-write mode
    fd = open(filename, O_RDWR | O_CREAT, 0644);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }

    // Get the file size
    if (fstat(fd, &stat_info) == -1) {
        perror("Error getting file size");
        close(fd);
        return 1;
    }
    file_size = stat_info.st_size;

    // Map the file into memory
    void *map_addr = mmap(NULL, file_size, PROT_READ | PROT_WRITE, MAP_FILE | MAP_PRIVATE, fd, 0);
    if (map_addr == MAP_FAILED) {
        perror("Error mapping file");
        close(fd);
        return 1;
    }

    // Overwrite the file with a new contents
    char *new_contents = "Invasive example\n";
    memcpy(buffer, new_contents, strlen(new_contents));
    buffer[strlen(new_contents)] = '\0';
    write(fd, buffer, strlen(buffer));

    // Unmap the file from memory
    munmap(map_addr, file_size);

    // Close the file
    close(fd);

    // Print a success message
    printf("File %s updated successfully\n", filename);

    return 0;
}