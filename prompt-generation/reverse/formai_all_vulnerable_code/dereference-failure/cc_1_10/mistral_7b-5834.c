//MISTRAL-7B DATASET v1.0 Category: Performance-Critical Component ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

#define BUF_SIZE 1024
#define ALIGNMENT 64

typedef struct {
    unsigned int magic;
    size_t size;
    void* data;
} my_buffer_t;

void *my_mmap(size_t size, int prot, int flags, int fd, off_t offset) {
    struct stat st;
    fstat(fd, &st);
    size_t aligned_size = ((size + ALIGNMENT - 1) & ~(ALIGNMENT - 1));
    my_buffer_t* buf = mmap(NULL, aligned_size, prot, flags, fd, offset);
    if (buf == MAP_FAILED) {
        perror("mmap failed");
        exit(EXIT_FAILURE);
    }
    buf->magic = 0x12345678;
    buf->size = size;
    return buf;
}

void my_munmap(void* addr) {
    my_buffer_t* buf = (my_buffer_t*) addr;
    munmap(addr, buf->size + sizeof(my_buffer_t));
}

int main() {
    int fd = open("input.txt", O_RDONLY);
    if (fd < 0) {
        perror("open failed");
        exit(EXIT_FAILURE);
    }

    size_t file_size = lseek(fd, 0, SEEK_END);
    lseek(fd, 0, SEEK_SET);

    void* buf = my_mmap(file_size, PROT_READ, MAP_PRIVATE, fd, 0);
    close(fd);

    ssize_t bytes_read = read(fileno(stdin), buf, file_size);
    if (bytes_read < 0) {
        perror("read failed");
        my_munmap(buf);
        exit(EXIT_FAILURE);
    }

    char* str = (char*) buf + sizeof(my_buffer_t);
    printf("Content of input.txt:\n");
    puts(str);

    my_munmap(buf);
    return EXIT_SUCCESS;
}