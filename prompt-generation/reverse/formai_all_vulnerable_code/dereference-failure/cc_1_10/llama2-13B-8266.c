//LLAMA2-13B DATASET v1.0 Category: File handling ; Style: realistic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>

#define MAX_FILE_SIZE (1024 * 1024 * 10) // 10 MB

int main(void) {
    // Open a file in read-write mode
    int fd = open("example.txt", O_RDWR | O_CREAT, 0644);
    if (fd == -1) {
        perror("open");
        return 1;
    }

    // Write some data to the file
    char *data = "Hello, world!";
    write(fd, data, strlen(data));

    // Set the file's buffer size to 1024 bytes
    struct stat sb;
    fstat(fd, &sb);
    sb.st_blksize = 1024;
    ftruncate(fd, sb.st_size);

    // Mmap the file to memory
    void *addr = mmap(NULL, sb.st_size, PROT_READ | PROT_WRITE, MAP_FILE | MAP_PRIVATE, fd, 0);
    if (addr == MAP_FAILED) {
        perror("mmap");
        close(fd);
        return 1;
    }

    // Set the file's position to the beginning
    lseek(fd, 0, SEEK_SET);

    // Read the file's contents
    char *buf = malloc(sb.st_size);
    read(fd, buf, sb.st_size);

    // Check if the file's contents match our expectations
    if (strcmp(buf, data) != 0) {
        fprintf(stderr, "File contents do not match expectations: %s\n", buf);
        free(buf);
        munmap(addr, sb.st_size);
        close(fd);
        return 1;
    }

    // Unmap the file from memory
    munmap(addr, sb.st_size);

    // Close the file
    close(fd);

    return 0;
}