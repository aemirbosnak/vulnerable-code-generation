//Falcon-180B DATASET v1.0 Category: System boot optimizer ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <errno.h>

#define PAGE_SIZE (4096)
#define NUM_PAGES (10)

static void *mmap_pages(void) {
    int fd = open("/dev/zero", O_RDWR | O_CREAT, 0666);
    if (fd == -1) {
        perror("open");
        exit(1);
    }

    void *addr = mmap(NULL, PAGE_SIZE * NUM_PAGES, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (addr == MAP_FAILED) {
        perror("mmap");
        exit(1);
    }

    printf("Mapped %zu bytes at %p\n", PAGE_SIZE * NUM_PAGES, addr);
    return addr;
}

static void touch_pages(void *addr) {
    int i;
    for (i = 0; i < NUM_PAGES; ++i) {
        char *page = (char *)addr + i * PAGE_SIZE;
        memset(page, 0xAA, PAGE_SIZE);
    }
}

static void unmap_pages(void *addr) {
    if (munmap(addr, PAGE_SIZE * NUM_PAGES) == -1) {
        perror("munmap");
        exit(1);
    }
}

int main() {
    void *pages = mmap_pages();
    touch_pages(pages);
    unmap_pages(pages);

    return 0;
}