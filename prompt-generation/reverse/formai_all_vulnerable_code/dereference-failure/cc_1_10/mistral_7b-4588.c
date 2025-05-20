//MISTRAL-7B DATASET v1.0 Category: Checksum Calculator ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define BLOCK_SIZE 4096

unsigned long adler32(unsigned char *buf, unsigned long len);
void print_hex(unsigned char *data, unsigned int len);

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    struct stat file_stat;
    int fd = open(argv[1], O_RDONLY);

    if (fstat(fd, &file_stat) < 0) {
        perror("Error opening file");
        close(fd);
        return 1;
    }

    unsigned char *buffer = (unsigned char *)malloc(BLOCK_SIZE);
    unsigned long checksum = adler32(NULL, 0);

    ssize_t bytes_read;
    while ((bytes_read = read(fd, buffer, BLOCK_SIZE)) > 0) {
        checksum = adler32(buffer, bytes_read);
    }

    close(fd);
    free(buffer);

    printf("File %s checksum (hex):\n", argv[1]);
    print_hex((unsigned char *)&checksum, sizeof(checksum));
    printf("\n");

    return 0;
}

unsigned long adler32(unsigned char *buf, unsigned long len) {
    unsigned long s1 = 1, s2 = 0xFFFFFFFL;

    while (len--) {
        s1 = (s1 + *buf++) % 65521;
        s2 = s2 + s1;
    }

    s1 = (s1 + len) % 65521;
    s2 = (s2 + s1) % 65521;

    return (s2 << 16) | s1;
}

void print_hex(unsigned char *data, unsigned int len) {
    int i;

    for (i = 0; i < len; ++i) {
        printf("%.2X", data[i]);
    }

    printf("\n");
}