//GEMINI-pro DATASET v1.0 Category: Antivirus scanner ; Style: Donald Knuth
#define _POSIX_C_SOURCE 200809L

#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <limits.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/stat.h>

#define PAGE_SIZE 4096

typedef unsigned long uword;

uword inline rol32(uword n, unsigned k) {
    return (n << k) | (n >> (32 - k));
}

uword inline xor64(uword x, uword y) {
    return x ^ y;
}

uword inline add64(uword x, uword y) {
    return x + y;
}

uword inline sub64(uword x, uword y) {
    return x - y;
}

struct virus_signature {
    char *name;
    uword size;
    uword *pattern;
};

struct virus_database {
    struct virus_signature *signatures;
    unsigned num_signatures;
};

int load_virus_database(struct virus_database *db, const char *filename) {
    int fd;
    struct stat st;
    int err;

    fd = open(filename, O_RDONLY);
    if (fd == -1) {
        return -errno;
    }

    err = fstat(fd, &st);
    if (err) {
        close(fd);
        return -errno;
    }

    db->signatures = malloc(st.st_size);
    if (!db->signatures) {
        close(fd);
        return -ENOMEM;
    }

    err = read(fd, db->signatures, st.st_size);
    if (err == -1) {
        close(fd);
        free(db->signatures);
        return -errno;
    }

    close(fd);

    db->num_signatures = st.st_size / sizeof(struct virus_signature);

    return 0;
}

void free_virus_database(struct virus_database *db) {
    free(db->signatures);
}

int scan_file(const char *filename, struct virus_database *db) {
    int fd;
    struct stat st;
    int err;
    void *buf;
    unsigned i;
    unsigned j;
    uword *pattern;
    uword *p;
    uword *q;

    fd = open(filename, O_RDONLY);
    if (fd == -1) {
        return -errno;
    }

    err = fstat(fd, &st);
    if (err) {
        close(fd);
        return -errno;
    }

    buf = mmap(NULL, st.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
    if (buf == MAP_FAILED) {
        close(fd);
        return -errno;
    }

    for (i = 0; i < db->num_signatures; i++) {
        pattern = db->signatures[i].pattern;
        for (j = 0; j < st.st_size - db->signatures[i].size; j++) {
            p = (uword *) &buf[j];
            q = pattern;
            while (*p == *q) {
                p++;
                q++;
                if (*q == 0) {
                    munmap(buf, st.st_size);
                    close(fd);
                    return -1;
                }
            }
        }
    }

    munmap(buf, st.st_size);
    close(fd);

    return 0;
}

int main(int argc, char **argv) {
    struct virus_database db;
    int err;

    if (argc < 3) {
        printf("Usage: %s <database file> <file to scan>\n", argv[0]);
        return -1;
    }

    err = load_virus_database(&db, argv[1]);
    if (err) {
        fprintf(stderr, "Error loading virus database: %s\n", strerror(-err));
        return err;
    }

    err = scan_file(argv[2], &db);
    if (err) {
        fprintf(stderr, "Error scanning file: %s\n", strerror(-err));
        return err;
    }

    printf("No viruses found in %s\n", argv[2]);

    free_virus_database(&db);

    return 0;
}