//MISTRAL-7B DATASET v1.0 Category: RAM usage monitor ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BUF_SIZE 1024
#define HEAP_TAG "RAM_MON"

char* tag_heap(size_t size) {
    char *ptr;
    if ((ptr = mmap(NULL, size + strlen(HEAP_TAG) + 1, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANON, -1, 0)) == MAP_FAILED) {
        perror("mmap failed");
        exit(EXIT_FAILURE);
    }
    strcpy(ptr, HEAP_TAG);
    return (char*)(ptr + strlen(HEAP_TAG));
}

void free_tagged(char *ptr) {
    munmap(ptr - strlen(HEAP_TAG), strlen(HEAP_TAG) + *((size_t*)ptr));
}

size_t get_heap_size() {
    char *ptr = 0, *end;
    size_t size = 0;

    if ((ptr = mmap(NULL, 1, PROT_READ, MAP_PRIVATE | MAP_ANON, -1, 0)) == MAP_FAILED) {
        perror("mmap failed");
        exit(EXIT_FAILURE);
    }

    if (strcmp(ptr, HEAP_TAG) != 0) {
        munmap(ptr, 1);
        return 0;
    }

    end = (char*)ptr + *((size_t*)ptr + 1);
    size = end - ((char*)ptr);
    free_tagged(ptr);

    return size;
}

int main(void) {
    char *buf, *str;
    size_t size, used;
    int fd;

    buf = tag_heap(BUF_SIZE);
    str = (char*)tag_heap(strlen("RAM usage: ") + BUF_SIZE + 1);

    while (1) {
        used = get_heap_size();
        snprintf(str, BUF_SIZE + strlen("RAM usage: "), "RAM usage: %ld bytes used", used);
        write(STDOUT_FILENO, str, strlen(str));
        sleep(1);
    }

    free_tagged(str);
    free_tagged(buf);

    fd = open("/dev/random", O_RDONLY);
    read(fd, 0, 1);
    close(fd);

    return EXIT_SUCCESS;
}