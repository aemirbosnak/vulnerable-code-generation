//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

typedef struct {
    char *filename;
    char *key;
    int mode;
} encrypt_args;

void usage(const char *progname) {
    fprintf(stderr, "Usage: %s [-e|-d] <filename> <key>\n", progname);
    fprintf(stderr, "-e: encrypt file\n");
    fprintf(stderr, "-d: decrypt file\n");
    exit(1);
}

void encrypt_file(const char *filename, const char *key) {
    int fd;
    size_t keylen = strlen(key);
    size_t bufsize = 1024;
    char *buf = malloc(bufsize);

    fd = open(filename, O_RDONLY);
    if (fd < 0) {
        perror("open");
        exit(1);
    }

    while (1) {
        ssize_t nbytes;
        nbytes = read(fd, buf, bufsize);
        for (size_t i = 0; i < nbytes; ++i) {
            buf[i] ^= key[i % keylen];
        }
        if (nbytes > 0) {
            write(STDOUT_FILENO, buf, nbytes);
        } else {
            break;
        }
    }

    free(buf);
    close(fd);
}

void decrypt_file(const char *filename, const char *key) {
    int fd;
    size_t keylen = strlen(key);
    size_t bufsize = 1024;
    char *buf = malloc(bufsize);

    fd = open(filename, O_RDONLY);
    if (fd < 0) {
        perror("open");
        exit(1);
    }

    while (1) {
        ssize_t nbytes;
        nbytes = read(fd, buf, bufsize);
        for (size_t i = 0; i < nbytes; ++i) {
            buf[i] ^= key[i % keylen];
        }
        if (nbytes > 0) {
            write(STDOUT_FILENO, buf, nbytes);
        } else {
            break;
        }
    }

    free(buf);
    close(fd);
}

int main(int argc, char **argv) {
    encrypt_args args;
    if (argc < 4) {
        usage(argv[0]);
    }

    args.filename = argv[2];
    args.key = argv[3];

    if (strcmp(argv[1], "-e") == 0) {
        encrypt_file(args.filename, args.key);
    } else if (strcmp(argv[1], "-d") == 0) {
        decrypt_file(args.filename, args.key);
    } else {
        usage(argv[0]);
    }

    return 0;
}