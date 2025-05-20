//MISTRAL-7B DATASET v1.0 Category: File handling ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define REVERSE 0
#define FORWARD 1

typedef struct {
    FILE *fp;
    int mode;
} ioHandle;

void reverseFile(ioHandle *io) {
    char c;
    if (io->mode == REVERSE) {
        while (!feof(io->fp)) {
            c = fgetc(io->fp);
            fputc(c, stdout);
        }
        fseek(io->fp, 0, SEEK_SET);
    } else {
        while (!feof(io->fp)) {
            c = fgetc(io->fp);
            fputc(c, io->fp);
        }
        fseek(io->fp, 0, SEEK_END);
    }
}

int main() {
    ioHandle input, output;
    input.fp = fopen("input.txt", "r");
    output.fp = fopen("output.txt", "w");

    if (input.fp == NULL || output.fp == NULL) {
        fprintf(stderr, "Error opening files.\n");
        exit(1);
    }

    input.mode = FORWARD;
    output.mode = REVERSE;

    while (input.mode != output.mode) {
        reverseFile(&input);
        reverseFile(&output);
    }

    fclose(input.fp);
    fclose(output.fp);

    printf("Files processed.\n");

    return 0;
}