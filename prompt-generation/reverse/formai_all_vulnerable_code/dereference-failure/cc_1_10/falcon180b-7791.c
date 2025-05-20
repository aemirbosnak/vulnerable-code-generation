//Falcon-180B DATASET v1.0 Category: Error handling ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    char buffer[BUFFER_SIZE];
    FILE *file;
    int bytes_read;
    int i;

    if (argc < 3) {
        fprintf(stderr, "Usage: %s <filename> [<output_filename>]\n", argv[0]);
        return 1;
    }

    file = fopen(argv[1], "r");
    if (file == NULL) {
        fprintf(stderr, "Error: %s\n", strerror(errno));
        return 1;
    }

    if (argc > 2) {
        fprintf(stdout, "Copying %s to %s...\n", argv[1], argv[2]);
    } else {
        fprintf(stdout, "Reading %s...\n", argv[1]);
    }

    while ((bytes_read = fread(buffer, 1, BUFFER_SIZE, file)) > 0) {
        if (argc > 2) {
            if (fwrite(buffer, 1, bytes_read, stdout)!= bytes_read) {
                fprintf(stderr, "Error: failed to write to output file\n");
                fclose(file);
                return 1;
            }
        } else {
            for (i = 0; i < bytes_read; i++) {
                putchar(buffer[i]);
            }
        }
    }

    if (ferror(file)) {
        fprintf(stderr, "Error: %s\n", strerror(errno));
        fclose(file);
        return 1;
    }

    if (argc > 2) {
        fprintf(stdout, "Done.\n");
    } else {
        fprintf(stdout, "\n");
    }

    fclose(file);
    return 0;
}