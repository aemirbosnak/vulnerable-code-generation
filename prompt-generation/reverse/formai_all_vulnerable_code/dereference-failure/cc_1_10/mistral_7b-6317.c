//MISTRAL-7B DATASET v1.0 Category: Ebook reader ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>

#define BUFFER_SIZE 0x10000

typedef struct {
    char magic[4];
    int version;
    int length;
    char content[1];
} ebook_header;

typedef struct {
    int offset;
    int length;
    char name[32];
} ebook_file;

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <ebook_file>\n", argv[0]);
        return 1;
    }

    int fd = open(argv[1], O_RDONLY);
    if (fd < 0) {
        perror("Error opening file");
        return 1;
    }

    off_t file_size = lseek(fd, 0, SEEK_END);
    lseek(fd, 0, SEEK_SET);

    ebook_header header;
    read(fd, &header, sizeof(ebook_header));

    if (strncmp(header.magic, "EPUB", 4) != 0) {
        fprintf(stderr, "Invalid eBook file\n");
        close(fd);
        return 1;
    }

    int num_files = header.length / sizeof(ebook_file);

    ebook_file *files = mmap(NULL, file_size, PROT_READ, MAP_PRIVATE, fd, 0);

    close(fd);

    if (files == MAP_FAILED) {
        perror("Error mapping file to memory");
        return 1;
    }

    printf("\nContents of eBook:\n--------------------\n");

    for (int i = 0; i < num_files; i++) {
        ebook_file file = files[i];
        char *buffer = mmap(NULL, file.length, PROT_READ, MAP_PRIVATE, fd, file.offset);

        if (buffer == MAP_FAILED) {
            perror("Error mapping file content to memory");
            munmap(files, file_size);
            return 1;
        }

        printf("\n%s (%d bytes)\n", file.name, file.length);
        write(STDOUT_FILENO, buffer, file.length);

        munmap(buffer, file.length);
    }

    munmap(files, file_size);

    return 0;
}