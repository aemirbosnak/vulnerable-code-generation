//GEMINI-pro DATASET v1.0 Category: RAM usage monitor ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/wait.h>

#define PAGE_SIZE 4096
#define MAP_SIZE 1024*1024*1024

int main() {
    int fd = open("/dev/zero", O_RDWR);
    if (fd == -1) {
        perror("open");
        exit(1);
    }

    void *map = mmap(NULL, MAP_SIZE, PROT_READ|PROT_WRITE, MAP_PRIVATE, fd, 0);
    if (map == MAP_FAILED) {
        perror("mmap");
        exit(1);
    }

    close(fd);

    int pid = fork();
    if (pid == -1) {
        perror("fork");
        exit(1);
    }

    if (pid == 0) {
        // Child process
        char *buf = malloc(PAGE_SIZE);
        if (buf == NULL) {
            perror("malloc");
            exit(1);
        }

        while (1) {
            memset(buf, 0, PAGE_SIZE);
            memcpy(map, buf, PAGE_SIZE);
        }
    } else {
        // Parent process
        while (1) {
            printf("RAM usage: %ld MB\n", MAP_SIZE/(1024*1024));
            sleep(1);
        }
    }

    return 0;
}