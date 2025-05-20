//GEMINI-pro DATASET v1.0 Category: System boot optimizer ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/mman.h>

#define PAGE_SIZE 4096

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <boot_image>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Open the boot image file
    int fd = open(argv[1], O_RDWR);
    if (fd == -1) {
        perror("open");
        return EXIT_FAILURE;
    }

    // Get the size of the boot image file
    struct stat st;
    if (fstat(fd, &st) == -1) {
        perror("fstat");
        close(fd);
        return EXIT_FAILURE;
    }

    // Memory map the boot image file
    void *file_map = mmap(NULL, st.st_size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (file_map == MAP_FAILED) {
        perror("mmap");
        close(fd);
        return EXIT_FAILURE;
    }

    // Find the kernel image and its entry point
    uint32_t *kernel_addr = (uint32_t *)file_map + 1;
    uint32_t kernel_entry = *kernel_addr;

    // Find the initrd image and its size
    uint32_t *initrd_addr = (uint32_t *)file_map + 2;
    uint32_t initrd_size = *initrd_addr;

    // Find the command line passed to the kernel
    char *cmdline = (char *)file_map + PAGE_SIZE;

    // Print information about the boot image
    printf("Kernel image: %08x\n", kernel_entry);
    printf("Initrd image: %08x (%d bytes)\n", initrd_addr, initrd_size);
    printf("Command line: %s\n", cmdline);

    // Create a new boot image file
    int fd_new = open("boot_image.new", O_RDWR | O_CREAT | O_TRUNC, 0666);
    if (fd_new == -1) {
        perror("open");
        munmap(file_map, st.st_size);
        close(fd);
        return EXIT_FAILURE;
    }

    // Write the kernel image to the new boot image file
    if (write(fd_new, &kernel_entry, sizeof(kernel_entry)) != sizeof(kernel_entry)) {
        perror("write");
        munmap(file_map, st.st_size);
        close(fd);
        close(fd_new);
        return EXIT_FAILURE;
    }

    // Write the initrd image to the new boot image file
    if (write(fd_new, &initrd_addr, sizeof(initrd_addr)) != sizeof(initrd_addr)) {
        perror("write");
        munmap(file_map, st.st_size);
        close(fd);
        close(fd_new);
        return EXIT_FAILURE;
    }

    // Write the command line to the new boot image file
    if (write(fd_new, cmdline, strlen(cmdline) + 1) != strlen(cmdline) + 1) {
        perror("write");
        munmap(file_map, st.st_size);
        close(fd);
        close(fd_new);
        return EXIT_FAILURE;
    }

    // Close the boot image files
    munmap(file_map, st.st_size);
    close(fd);
    close(fd_new);

    return EXIT_SUCCESS;
}