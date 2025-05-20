//LLAMA2-13B DATASET v1.0 Category: File handling ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>

#define MAX_FILE_SIZE 1024 * 1024 * 10

// Structure to store file information
typedef struct {
    char *name;
    size_t size;
    off_t offset;
} FileInfo;

// Function to read a file into memory
FileInfo *read_file(const char *filename) {
    // Open the file in read mode
    int fd = open(filename, O_RDONLY, 0644);
    if (fd == -1) {
        perror("Error opening file");
        return NULL;
    }

    // Get the file size
    struct stat stat_info;
    fstat(fd, &stat_info);
    size_t size = stat_info.st_size;

    // Map the file into memory
    void *ptr = mmap(NULL, size, PROT_READ, MAP_FILE | MAP_PRIVATE, fd, 0);
    if (ptr == MAP_FAILED) {
        perror("Error mapping file");
        close(fd);
        return NULL;
    }

    // Store the file information
    FileInfo *file_info = malloc(sizeof(FileInfo));
    file_info->name = filename;
    file_info->size = size;
    file_info->offset = 0;

    // Return the file information
    return file_info;
}

// Function to write a file from memory
void write_file(const char *filename, const void *data, size_t size) {
    // Open the file in write mode
    int fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1) {
        perror("Error opening file");
        return;
    }

    // Write the data to the file
    ssize_t written = write(fd, data, size);
    if (written == -1) {
        perror("Error writing to file");
        close(fd);
        return;
    }

    // Update the file size
    struct stat stat_info;
    fstat(fd, &stat_info);
    size_t new_size = stat_info.st_size;
    if (new_size != size) {
        perror("Error updating file size");
        close(fd);
        return;
    }

    // Unmap the file from memory
    munmap(data, size);

    // Close the file
    close(fd);
}

int main() {
    // Open a file for reading
    FileInfo *file_info = read_file("example.txt");
    if (file_info == NULL) {
        perror("Error reading file");
        return 1;
    }

    // Print the file information
    printf("File name: %s\n", file_info->name);
    printf("File size: %zu\n", file_info->size);
    printf("File offset: %zu\n", file_info->offset);

    // Write some data to the file
    char data[] = "Hello, world!";
    write_file(file_info->name, data, sizeof(data));

    // Update the file size
    struct stat stat_info;
    fstat(open(file_info->name, O_RDONLY), &stat_info);
    size_t new_size = stat_info.st_size;
    printf("New file size: %zu\n", new_size);

    // Close the file
    close(open(file_info->name, O_RDONLY));

    // Free the file information
    free(file_info);

    return 0;
}