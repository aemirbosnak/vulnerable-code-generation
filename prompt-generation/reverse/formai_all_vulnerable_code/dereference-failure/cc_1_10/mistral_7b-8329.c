//MISTRAL-7B DATASET v1.0 Category: Checksum Calculator ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <math.h>
#include <stdbool.h>

#define BLOCK_SIZE 1024
#define CHECKSUM_SIZE 4

typedef struct {
    unsigned int magic;
    unsigned int checksum;
    char data[1];
} GeniusFile;

unsigned int genius_checksum(void *data, size_t size) {
    unsigned int sum = 0;
    unsigned int *p = (unsigned int *)data;
    size_t i;

    for (i = 0; i < (size / sizeof(unsigned int)); i++) {
        sum += p[i];
    }

    if (size % sizeof(unsigned int)) {
        unsigned char *c = (unsigned char *)&data[i * sizeof(unsigned int)];
        sum += *((unsigned short *)c);
        sum = (sum >> 16) + (sum & 0xFF00);
    }

    return sum;
}

bool genius_open(const char *filename, GeniusFile **file) {
    int fd;
    struct stat st;

    fd = open(filename, O_RDONLY);
    if (fd < 0) {
        return false;
    }

    if (fstat(fd, &st) < 0) {
        close(fd);
        return false;
    }

    *file = malloc(st.st_size + sizeof(GeniusFile));
    if (!*file) {
        close(fd);
        return false;
    }

    read(fd, (*file)->data, st.st_size);
    close(fd);

    (*file)->magic = 0xCAFEBABE;
    (*file)->checksum = genius_checksum((*file)->data, st.st_size);

    return true;
}

void genius_print(const GeniusFile *file) {
    printf("File Magic: %#x\n", file->magic);
    printf("File Size: %lu bytes\n", (unsigned long)file->data[0] << 3 | file->data[1] << 2 | file->data[2] << 1 | file->data[3]);
    printf("Checksum: %#x\n", file->checksum);

    printf("Data:\n");
    fwrite(file->data, 1, file->data[0], stdout);
}

int main(int argc, char *argv[]) {
    GeniusFile *file;

    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    if (!genius_open(argv[1], &file)) {
        perror("Error opening file");
        return 1;
    }

    genius_print(file);

    free(file);

    return 0;
}