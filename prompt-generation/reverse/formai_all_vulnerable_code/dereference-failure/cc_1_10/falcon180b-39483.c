//Falcon-180B DATASET v1.0 Category: System boot optimizer ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>

#define PAGE_SIZE 4096

void *mmap_file(const char *filename, size_t length) {
    int fd = open(filename, O_RDWR);
    if (fd == -1) {
        perror("mmap_file: open");
        return NULL;
    }

    struct stat st;
    if (fstat(fd, &st) == -1) {
        perror("mmap_file: fstat");
        close(fd);
        return NULL;
    }

    if (st.st_size < length) {
        if (ftruncate(fd, length) == -1) {
            perror("mmap_file: ftruncate");
            close(fd);
            return NULL;
        }
    }

    void *ptr = mmap(NULL, length, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (ptr == MAP_FAILED) {
        perror("mmap_file: mmap");
        close(fd);
        return NULL;
    }

    return ptr;
}

void munmap_file(void *ptr, size_t length) {
    if (munmap(ptr, length) == -1) {
        perror("munmap_file: munmap");
    }
}

int main() {
    const char *filename = "example.txt";
    size_t length = 1024 * 1024 * 10; // 10 MB

    void *ptr = mmap_file(filename, length);
    if (ptr == NULL) {
        return 1;
    }

    char *data = (char *)ptr;
    memset(data, 'a', length);

    munmap_file(ptr, length);

    return 0;
}