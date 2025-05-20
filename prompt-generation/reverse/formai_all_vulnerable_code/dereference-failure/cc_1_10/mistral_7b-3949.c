//MISTRAL-7B DATASET v1.0 Category: Binary Converter ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <errno.h>
#include <time.h>

#define BIN_FILE "binary.bin"
#define BUF_SIZE 1024

typedef struct bin_header {
    char magic[4];
    int version;
    int data_size;
} bin_header;

void die(const char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    srand(time(NULL));

    int num = rand() % 10 + 1;
    int i;
    bin_header *header;
    char *buf;
    int *data;
    int fd;

    fd = open(BIN_FILE, O_RDWR | O_CREAT | O_TRUNC, 0644);
    if (fd < 0) die("Cannot open file for writing.");

    header = mmap(NULL, sizeof(bin_header), PROT_READ | PROT_WRITE, MAP_PRIVATE, fd, 0);
    if (header == MAP_FAILED) die("Cannot map file header.");

    header->magic[0] = 'B';
    header->magic[1] = 'I';
    header->magic[2] = 'N';
    header->magic[3] = '\0';
    header->version = 1;
    header->data_size = num * sizeof(int);

    buf = mmap(NULL, BUF_SIZE, PROT_READ | PROT_WRITE, MAP_PRIVATE, fd, (off_t)sizeof(bin_header));
    if (buf == MAP_FAILED) die("Cannot map binary data buffer.");

    data = (int *)calloc(num, sizeof(int));
    if (data == NULL) die("Cannot allocate memory for data.");

    for (i = 0; i < num; i++) {
        data[i] = rand() % 128;
    }

    memcpy(buf, data, num * sizeof(int));

    msync(buf, num * sizeof(int), MS_SYNC);
    munmap(data, num * sizeof(int));

    munmap(buf, BUF_SIZE);
    munmap(header, sizeof(bin_header));

    close(fd);

    printf("Binary data written to %s, size: %d bytes.\n", BIN_FILE, header->data_size);

    fd = open(BIN_FILE, O_RDONLY);
    if (fd < 0) die("Cannot open file for reading.");

    buf = mmap(NULL, BUF_SIZE, PROT_READ, MAP_PRIVATE, fd, 0);
    if (buf == MAP_FAILED) die("Cannot map binary data buffer for reading.");

    for (i = 0; i < num; i++) {
        printf("Data %d: %d\n", i, *((int *)((char *)buf + (i * sizeof(int)))));
    }

    munmap(buf, BUF_SIZE);
    close(fd);

    return 0;
}