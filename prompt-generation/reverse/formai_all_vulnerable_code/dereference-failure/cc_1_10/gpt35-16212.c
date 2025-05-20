//FormAI DATASET v1.0 Category: File Encyptor ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define BUFFSIZE 1024

int main(int argc, char *argv[])
{
    FILE *f_in, *f_out;
    char key[BUFFSIZE];
    char buffer[BUFFSIZE];
    size_t bytes_read;
    int i;

    if (argc != 4) {
        fprintf(stderr, "Usage: %s <input-file> <output-file> <key>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    f_in = fopen(argv[1], "r");
    if (!f_in) {
        fprintf(stderr, "Failed to open input file %s: %s\n", argv[1], strerror(errno));
        exit(EXIT_FAILURE);
    }

    f_out = fopen(argv[2], "w");
    if (!f_out) {
        fprintf(stderr, "Failed to open output file %s: %s\n", argv[2], strerror(errno));
        exit(EXIT_FAILURE);
    }

    strncpy(key, argv[3], BUFFSIZE);

    i = 0;
    while (key[i]) {
        key[i] = key[i] % 26;
        i++;
    }

    i = 0;
    while (1) {
        bytes_read = fread(buffer, sizeof(char), BUFFSIZE, f_in);
        if (bytes_read == 0) {
            break;
        }

        for (i = 0; i < bytes_read; i++) {
            buffer[i] = ((buffer[i] - 'a' + key[i % strlen(key)]) % 26) + 'a';
        }

        fwrite(buffer, sizeof(char), bytes_read, f_out);
    }

    fclose(f_in);
    fclose(f_out);

    printf("Encryption successful! Output written to file %s\n", argv[2]);

    return 0;
}