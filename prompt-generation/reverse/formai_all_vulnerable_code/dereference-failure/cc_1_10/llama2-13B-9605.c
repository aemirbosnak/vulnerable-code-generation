//LLAMA2-13B DATASET v1.0 Category: Game ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_LENGTH 1024
#define SEEK_TO_END 1

int main(void) {
    char *filename = "ken_thompson.txt";
    char *file_contents;
    size_t file_size;
    int fd;

    // Open the file in append mode
    fd = open(filename, O_RDWR | O_CREAT, 0644);
    if (fd == -1) {
        perror("open");
        return 1;
    }

    // Get the file size
    file_size = lseek(fd, SEEK_TO_END, 0);
    if (file_size == -1) {
        perror("lseek");
        close(fd);
        return 1;
    }

    // Allocate memory for the file contents
    file_contents = malloc(file_size);
    if (file_contents == NULL) {
        perror("malloc");
        close(fd);
        return 1;
    }

    // Read the file contents into memory
    read(fd, file_contents, file_size);

    // Mmap the file contents
    int fd_mmap = open(filename, O_RDONLY, 0);
    if (fd_mmap == -1) {
        perror("open");
        free(file_contents);
        close(fd);
        return 1;
    }

    // Mmap the file contents
    void *mmap_addr = mmap(NULL, file_size, PROT_READ, MAP_FILE | MAP_PRIVATE, fd_mmap, 0);
    if (mmap_addr == MAP_FAILED) {
        perror("mmap");
        free(file_contents);
        close(fd);
        close(fd_mmap);
        return 1;
    }

    // Set the file contents in the mmap region
    file_contents = (char *)mmap_addr;

    // Unmap the file contents
    munmap(mmap_addr, file_size);

    // Close the mmap file descriptor
    close(fd_mmap);

    // Print the file contents
    printf("%s", file_contents);

    // Free the memory
    free(file_contents);

    // Close the file descriptor
    close(fd);

    return 0;
}