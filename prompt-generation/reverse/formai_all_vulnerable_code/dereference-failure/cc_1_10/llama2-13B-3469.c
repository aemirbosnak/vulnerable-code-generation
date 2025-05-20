//LLAMA2-13B DATASET v1.0 Category: File handling ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define MAX_FILE_SIZE 1024*1024*100
#define MAP_SIZE 1024*1024

int main() {
    // Create a file with a random size
    int fd = open("random_file.txt", O_RDWR | O_CREAT, 0644);
    char *buf = malloc(rand() % MAX_FILE_SIZE);
    write(fd, buf, rand() % MAX_FILE_SIZE);
    close(fd);

    // Mmap the file
    int fd2 = open("random_file.txt", O_RDWR, 0);
    void *addr = mmap(NULL, MAP_SIZE, PROT_READ | PROT_WRITE, MAP_FILE | MAP_PRIVATE, fd2, 0);
    if (addr == MAP_FAILED) {
        perror("mmap failed");
        return 1;
    }

    // Randomly modify the file contents
    for (int i = 0; i < 100; i++) {
        size_t len = rand() % 100;
        char *p = addr + rand() % MAP_SIZE;
        memset(p, 'a' + (rand() % 26), len);
    }

    // Check if the file contents have changed
    char buffer[1024];
    read(fd2, buffer, 1024);
    for (int i = 0; i < 100; i++) {
        if (buffer[i] != 'a' + (rand() % 26)) {
            printf("File contents have changed!\n");
            break;
        }
    }

    // Unmap the file
    munmap(addr, MAP_SIZE);

    // Rename the file
    char new_name[] = "new_random_file.txt";
    rename("random_file.txt", new_name);

    // Check if the file has been renamed
    if (access(new_name, F_OK) == 0) {
        printf("File renamed successfully\n");
    } else {
        printf("File renaming failed\n");
    }

    return 0;
}