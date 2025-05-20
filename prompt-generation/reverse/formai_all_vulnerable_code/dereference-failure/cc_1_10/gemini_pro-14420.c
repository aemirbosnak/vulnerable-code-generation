//GEMINI-pro DATASET v1.0 Category: Antivirus scanner ; Style: future-proof
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>

#define PAGE_SIZE 4096
#define SCAN_BUFFER_SIZE (PAGE_SIZE * 16)

struct av_signature {
    uint32_t offset;
    uint32_t length;
    uint8_t signature[0];
};

struct av_scanner {
    size_t num_signatures;
    struct av_signature *signatures;
    uint8_t *scan_buffer;
    size_t scan_buffer_size;
};

int av_scanner_init(struct av_scanner *scanner, const char *signature_file)
{
    int fd;
    struct stat statbuf;
    void *data;

    fd = open(signature_file, O_RDONLY);
    if (fd < 0) {
        return -1;
    }

    if (fstat(fd, &statbuf) < 0) {
        close(fd);
        return -1;
    }

    data = mmap(NULL, statbuf.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
    if (data == MAP_FAILED) {
        close(fd);
        return -1;
    }

    scanner->num_signatures = *(uint32_t *)data;
    scanner->signatures = (struct av_signature *)(data + sizeof(uint32_t));
    scanner->scan_buffer = malloc(SCAN_BUFFER_SIZE);
    if (scanner->scan_buffer == NULL) {
        munmap(data, statbuf.st_size);
        close(fd);
        return -1;
    }

    scanner->scan_buffer_size = SCAN_BUFFER_SIZE;

    munmap(data, statbuf.st_size);
    close(fd);

    return 0;
}

void av_scanner_fini(struct av_scanner *scanner)
{
    free(scanner->scan_buffer);
    scanner->scan_buffer = NULL;
    scanner->scan_buffer_size = 0;
    scanner->signatures = NULL;
    scanner->num_signatures = 0;
}

int av_scanner_scan(struct av_scanner *scanner, const char *file)
{
    int fd;
    struct stat statbuf;
    uint8_t *data;
    size_t i, j, k;
    int found = 0;

    fd = open(file, O_RDONLY);
    if (fd < 0) {
        return -1;
    }

    if (fstat(fd, &statbuf) < 0) {
        close(fd);
        return -1;
    }

    data = mmap(NULL, statbuf.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
    if (data == MAP_FAILED) {
        close(fd);
        return -1;
    }

    for (i = 0; i < statbuf.st_size; i += scanner->scan_buffer_size) {
        size_t len = statbuf.st_size - i;
        if (len > scanner->scan_buffer_size) {
            len = scanner->scan_buffer_size;
        }

        memcpy(scanner->scan_buffer, data + i, len);

        for (j = 0; j < scanner->num_signatures; j++) {
            for (k = 0; k < len - scanner->signatures[j].length; k++) {
                if (memcmp(scanner->scan_buffer + k, scanner->signatures[j].signature, scanner->signatures[j].length) == 0) {
                    printf("Found virus at offset %zu: %s\n", i + k + scanner->signatures[j].offset, scanner->signatures[j].signature);
                    found = 1;
                }
            }
        }
    }

    munmap(data, statbuf.st_size);
    close(fd);

    return found;
}

int main(int argc, char **argv)
{
    struct av_scanner scanner;
    int i;

    if (argc < 3) {
        fprintf(stderr, "Usage: %s signature_file file ...\n", argv[0]);
        return 1;
    }

    if (av_scanner_init(&scanner, argv[1]) < 0) {
        fprintf(stderr, "Error initializing scanner\n");
        return 1;
    }

    for (i = 2; i < argc; i++) {
        if (av_scanner_scan(&scanner, argv[i]) < 0) {
            fprintf(stderr, "Error scanning file %s\n", argv[i]);
            continue;
        }
    }

    av_scanner_fini(&scanner);

    return 0;
}