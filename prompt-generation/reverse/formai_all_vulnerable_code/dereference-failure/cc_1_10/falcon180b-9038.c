//Falcon-180B DATASET v1.0 Category: System boot optimizer ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/mman.h>

#define PAGE_SIZE 4096

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <executable>\n", argv[0]);
        return 1;
    }

    char *executable = argv[1];
    int fd = open(executable, O_RDONLY);
    if (fd == -1) {
        printf("Error: could not open file '%s'\n", executable);
        return 1;
    }

    struct stat st;
    if (fstat(fd, &st) == -1) {
        printf("Error: could not stat file '%s'\n", executable);
        close(fd);
        return 1;
    }

    void *addr = mmap(NULL, st.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
    if (addr == MAP_FAILED) {
        printf("Error: could not mmap file '%s'\n", executable);
        close(fd);
        return 1;
    }

    close(fd);

    char *ptr = addr;
    while (ptr < (char *)addr + st.st_size) {
        if (*ptr == '\n') {
            *ptr = '\0';
        }
        ptr++;
    }

    char *text = addr;
    size_t size = st.st_size;

    while (size > 0) {
        int count = 0;
        char *line = strtok(text, "\n");
        while (line!= NULL) {
            printf("%s", line);
            count++;
            if (count == 10) {
                break;
            }
            line = strtok(NULL, "\n");
        }
        text += strlen(line) + 1;
        size -= strlen(line) + 1;
    }

    munmap(addr, st.st_size);

    return 0;
}