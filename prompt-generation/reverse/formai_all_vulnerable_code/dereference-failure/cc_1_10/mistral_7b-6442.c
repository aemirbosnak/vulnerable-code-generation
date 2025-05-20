//MISTRAL-7B DATASET v1.0 Category: Data recovery tool ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HEADER_SIZE 10
#define BLOCK_SIZE 512

typedef struct {
    char magic[8];
    int version;
    int size;
} Header;

void die(const char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char **argv) {
    FILE *in, *out;
    Header header;
    char buffer[BLOCK_SIZE];
    int bytes_read, bytes_written;

    if (argc != 3) {
        fprintf(stderr, "Usage: %s input output\n", argv[0]);
        exit(1);
    }

    in = fopen(argv[1], "rb");
    if (!in) die("Cannot open input file.");

    out = fopen(argv[2], "wb");
    if (!out) die("Cannot open output file.");

    if (fread(&header, sizeof(Header), 1, in) != 1) {
        fprintf(stderr, "Error reading header.\n");
        fclose(in);
        fclose(out);
        exit(1);
    }

    if (strncmp(header.magic, "MYDATA", 5) != 0) {
        fprintf(stderr, "Invalid header.\n");
        fclose(in);
        fclose(out);
        exit(1);
    }

    printf("Valid header. Recovering data...\n");

    while ((bytes_read = fread(buffer, sizeof(char), BLOCK_SIZE, in)) > 0) {
        if (fwrite(buffer, sizeof(char), bytes_read, out) != bytes_read) {
            fprintf(stderr, "Error writing to output file.\n");
            fclose(in);
            fclose(out);
            exit(1);
        }
    }

    if (feof(in)) {
        printf("Data recovery completed.\n");
    } else {
        fprintf(stderr, "Error reading input file.\n");
        fclose(in);
        fclose(out);
        exit(1);
    }

    fclose(in);
    fclose(out);

    return 0;
}