//MISTRAL-7B DATASET v1.0 Category: System boot optimizer ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define KERNEL_ADDR 0x100000
#define KERNEL_SIZE 0x2000

void decompress_rle(unsigned char *src, unsigned char *dst, unsigned int len) {
    unsigned char prev = src[0];
    unsigned int count = 1;
    unsigned int i = 0;

    while (i < len) {
        if (src[i] == prev) {
            count++;
        } else {
            dst[i - count] = prev;
            prev = src[i];
            count = 1;
        }
        i++;
    }

    dst[i - count] = prev;
}

int main(void) {
    int fd;
    char *compressed_kernel;
    unsigned char *decompressed_kernel;

    fd = open("kernel.img", O_RDONLY);
    if (fd < 0) {
        perror("Error opening kernel image file");
        exit(1);
    }

    size_t file_size = lseek(fd, 0, SEEK_END);
    lseek(fd, 0, SEEK_SET);

    compressed_kernel = mmap(NULL, file_size, PROT_READ, MAP_PRIVATE, fd, 0);
    if (compressed_kernel == MAP_FAILED) {
        perror("Error mapping kernel image file");
        exit(1);
    }

    decompressed_kernel = mmap(NULL, KERNEL_SIZE, PROT_READ | PROT_WRITE, MAP_PRIVATE, -1, KERNEL_ADDR);
    if (decompressed_kernel == MAP_FAILED) {
        perror("Error mapping kernel memory");
        exit(1);
    }

    close(fd);

    decompress_rle((unsigned char *)compressed_kernel, decompressed_kernel, KERNEL_SIZE);

    munmap(compressed_kernel, file_size);
    munmap((caddr_t)KERNEL_ADDR, KERNEL_SIZE);

    // Jump to the decompressed kernel
    ((void (*)())decompressed_kernel)();

    return 0;
}