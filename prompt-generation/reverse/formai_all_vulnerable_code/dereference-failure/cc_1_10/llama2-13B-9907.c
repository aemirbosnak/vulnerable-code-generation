//LLAMA2-13B DATASET v1.0 Category: File handling ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>

#define MAX_FILE_SIZE 1024 * 1024 * 10
#define MAX_BUFFER_SIZE 1024 * 1024

int main(void) {
    // Create a random file name
    char filename[50];
    srand(time(NULL));
    for (int i = 0; i < 50; i++) {
        filename[i] = 'a' + (rand() % 26);
    }

    // Open the file in random access mode
    int fd = open(filename, O_RDWR | O_CREAT, 0666);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }

    // Set the file size to a random value between 1MB and 10MB
    long filesize = rand() % (MAX_FILE_SIZE / 1024) * 1024;
    if (lseek(fd, filesize, SEEK_SET) < 0) {
        perror("Error seeking to file size");
        close(fd);
        return 1;
    }

    // Read and write random data to the file
    char buffer[MAX_BUFFER_SIZE];
    for (int i = 0; i < 10; i++) {
        // Read a random number of bytes from the file
        ssize_t readbytes = read(fd, buffer, rand() % MAX_BUFFER_SIZE);
        if (readbytes < 0) {
            perror("Error reading from file");
            break;
        }

        // Write the data to the file
        write(fd, buffer, readbytes);
    }

    // Close the file
    close(fd);

    // Mmap the file and read it as a binary
    int fd2 = open(filename, O_RDONLY, 0);
    if (fd2 == -1) {
        perror("Error opening file for mmap");
        return 1;
    }
    void* addr = mmap(NULL, filesize, PROT_READ, MAP_FILE | MAP_PRIVATE, fd2, 0);
    if (addr == MAP_FAILED) {
        perror("Error mmapping file");
        close(fd2);
        return 1;
    }
    char* buffer2 = (char*)addr;
    for (int i = 0; i < filesize; i++) {
        printf("%c", buffer2[i]);
    }
    munmap(addr, filesize);
    close(fd2);

    return 0;
}