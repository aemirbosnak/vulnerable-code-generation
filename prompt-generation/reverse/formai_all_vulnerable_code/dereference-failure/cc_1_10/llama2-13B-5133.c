//LLAMA2-13B DATASET v1.0 Category: File handling ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>

#define MAX_FILE_SIZE 1024 * 1024 * 10

int main(void) {
    char *file_name = "/home/user/invasive_file.txt";
    int fd;
    char *buf = NULL;
    size_t len = 0;

    // Open the file in read-write mode
    fd = open(file_name, O_RDWR | O_CREAT, 0644);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }

    // Get the file size
    struct stat stat_info;
    fstat(fd, &stat_info);
    len = stat_info.st_size;

    // Map the file into memory
    buf = mmap(NULL, len, PROT_READ | PROT_WRITE, MAP_FILE | MAP_PRIVATE, fd, 0);
    if (buf == MAP_FAILED) {
        perror("Error mapping file");
        close(fd);
        return 1;
    }

    // Invade the file and modify its contents
    for (size_t i = 0; i < len; i++) {
        if (buf[i] == 'a') {
            buf[i] = 'b';
        }
    }

    // Unmap the file from memory
    munmap(buf, len);

    // Close the file
    close(fd);

    // Write the modified file back to disk
    if (write(fd, buf, len) != len) {
        perror("Error writing to file");
        return 1;
    }

    return 0;
}