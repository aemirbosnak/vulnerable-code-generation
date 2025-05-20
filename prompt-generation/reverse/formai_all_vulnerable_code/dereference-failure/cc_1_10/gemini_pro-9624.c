//GEMINI-pro DATASET v1.0 Category: System administration ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>

#define PAGE_SIZE 4096

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    int fd = open(argv[1], O_RDWR);
    if (fd == -1)
    {
        perror("open");
        exit(1);
    }

    struct stat st;
    if (fstat(fd, &st) == -1)
    {
        perror("fstat");
        exit(1);
    }

    if (!S_ISREG(st.st_mode))
    {
        fprintf(stderr, "%s is not a regular file\n", argv[1]);
        exit(1);
    }

    void *addr = mmap(NULL, st.st_size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (addr == MAP_FAILED)
    {
        perror("mmap");
        exit(1);
    }

    close(fd);

    // Do something with the mapped file
    for (int i = 0; i < st.st_size; i++)
    {
        ((char *)addr)[i] = 'a';
    }

    // Unmap the file
    if (munmap(addr, st.st_size) == -1)
    {
        perror("munmap");
        exit(1);
    }

    return 0;
}