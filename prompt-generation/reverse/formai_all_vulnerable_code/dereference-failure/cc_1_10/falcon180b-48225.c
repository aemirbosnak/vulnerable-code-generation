//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>

typedef struct {
    unsigned char magic[2];
    int version;
    int header_size;
    int file_size;
} Header;

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <file_name>\n", argv[0]);
        return -1;
    }

    char *filename = argv[1];
    int fd = open(filename, O_RDONLY);
    if (fd == -1) {
        printf("Error: %s\n", strerror(errno));
        return -1;
    }

    Header header;
    memset(&header, 0, sizeof(header));
    read(fd, &header, sizeof(header));

    if (header.magic[0]!= 0x7f || header.magic[1]!= 'E' || header.version!= 1) {
        printf("Error: Invalid file format\n");
        close(fd);
        return -1;
    }

    int file_size = header.file_size;
    char *buffer = malloc(file_size);
    if (buffer == NULL) {
        printf("Error: Out of memory\n");
        close(fd);
        return -1;
    }

    read(fd, buffer, file_size);
    close(fd);

    printf("File recovered successfully!\n");
    printf("File size: %d bytes\n", file_size);
    printf("File content:\n%s", buffer);

    free(buffer);
    return 0;
}