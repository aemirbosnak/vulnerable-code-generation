//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ENCRYPT 1
#define DECRYPT 0

void usage(char *progname) {
    fprintf(stderr, "Usage: %s [-e|-d] key filename\n", progname);
    fprintf(stderr, "  -e: encrypt the file using the specified key\n");
    fprintf(stderr, "  -d: decrypt the file using the specified key\n");
    exit(1);
}

int main(int argc, char *argv[]) {
    int mode;
    char *key;
    char *filename;
    FILE *fp;
    unsigned char buffer[1024];

    if (argc < 4) {
        usage(argv[0]);
    }

    if (strcmp(argv[1], "-e") == 0) {
        mode = ENCRYPT;
    } else if (strcmp(argv[1], "-d") == 0) {
        mode = DECRYPT;
    } else {
        usage(argv[0]);
    }

    key = argv[2];
    filename = argv[3];

    fp = fopen(filename, "rb+");
    if (fp == NULL) {
        perror("fopen");
        exit(1);
    }

    while (fread(buffer, 1, sizeof(buffer), fp) > 0) {
        for (int i = 0; i < sizeof(buffer); i++) {
            if (mode == ENCRYPT) {
                buffer[i] ^= key[i % strlen(key)];
            } else {
                buffer[i] ^= key[i % strlen(key)];
            }
        }
        fwrite(buffer, 1, sizeof(buffer), fp);
    }

    fclose(fp);

    return 0;
}