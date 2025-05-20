//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <filename> <output>\n", argv[0]);
        return -1;
    }

    FILE *input = fopen(argv[1], "rb");
    if (input == NULL) {
        printf("Error opening input file: %s\n", strerror(errno));
        return -1;
    }

    FILE *output = fopen(argv[2], "wb");
    if (output == NULL) {
        printf("Error opening output file: %s\n", strerror(errno));
        fclose(input);
        return -1;
    }

    int fd = fileno(input);
    struct stat stat;
    if (fstat(fd, &stat) == -1) {
        printf("Error getting input file size: %s\n", strerror(errno));
        fclose(input);
        fclose(output);
        return -1;
    }

    int file_size = stat.st_size;
    char *buffer = malloc(BUF_SIZE);

    int bytes_read = 0;
    while ((bytes_read = fread(buffer, 1, BUF_SIZE, input)) > 0) {
        fwrite(buffer, 1, bytes_read, output);
    }

    free(buffer);
    fclose(input);
    fclose(output);

    return 0;
}