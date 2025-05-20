//MISTRAL-7B DATASET v1.0 Category: Automated Fortune Teller ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>

#define BUFFER_SIZE 1024
#define FILENAME "/dev/urandom"

typedef struct {
    int magic;
    char fortune[128];
} fortune_t;

int main() {
    int fd, i;
    char *ptr;
    fortune_t *ft;

    srand(time(NULL));

    fd = open(FILENAME, O_RDONLY);
    if (fd == -1) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    ptr = mmap(NULL, BUFFER_SIZE, PROT_READ, MAP_PRIVATE, fd, 0);
    if (ptr == MAP_FAILED) {
        perror("Error mapping file");
        exit(EXIT_FAILURE);
    }

    close(fd);

    ft = malloc(sizeof(fortune_t));
    if (ft == NULL) {
        perror("Error allocating memory");
        munmap(ptr, BUFFER_SIZE);
        exit(EXIT_FAILURE);
    }

    ft->magic = 0xdeadbeef;

    for (i = 0; i < 127; i++) {
        ft->fortune[i] = ptr[rand() % BUFFER_SIZE];
    }

    ft->fortune[127] = '\0';

    printf("Your fortune: %s\n", ft->fortune);

    munmap(ptr, BUFFER_SIZE);
    free(ft);

    return EXIT_SUCCESS;
}