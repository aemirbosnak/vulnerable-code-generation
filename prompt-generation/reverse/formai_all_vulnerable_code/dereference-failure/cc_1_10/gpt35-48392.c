//FormAI DATASET v1.0 Category: Compression algorithms ; Style: statistical
#include <stdio.h>
#include <stdlib.h>

#define BITS 8

unsigned char buffer[BITS];

void write_bit(FILE *outfile, int bit) {
    static int pos = BITS - 1;
    buffer[pos--] = bit;
    if (pos < 0) {
        fwrite(buffer, sizeof(unsigned char), BITS, outfile);
        pos = BITS - 1;
    }
}

void flush_buffer(FILE *outfile) {
    if (buffer[0] != -1) {
        fwrite(buffer, sizeof(unsigned char), BITS, outfile);
    }
}

void compress(FILE *infile, FILE *outfile) {
    int c;
    while ((c = fgetc(infile)) != EOF) {
        int bit = 0;
        while (c > 0) {
            write_bit(outfile, c % 2);
            c /= 2;
            bit++;
        }
        write_bit(outfile, 2);
        while (--bit >= 0) {
            write_bit(outfile, buffer[bit]);
        }
    }
    write_bit(outfile, 3);
    flush_buffer(outfile);
}

void decompress(FILE *infile, FILE *outfile) {
    int c;
    int bit = 0;
    int decimal = 0;
    while ((c = fgetc(infile)) != EOF) {
        if (bit == BITS) {
            fwrite(&decimal, sizeof(unsigned char), 1, outfile);
            decimal = 0;
            bit = 0;
        }
        int val = (c >> bit) & 1;
        if (val == 2) {
            bit++;
            int i;
            for (i = 0; i < bit; i++) {
                val = (c >> i) & 1;
                decimal += val * (1 << i);
            }
            bit = decimal;
            decimal = 0;
        } else if (val == 3) {
            break;
        } else {
            decimal += val * (1 << bit);
            bit++;
        }
    }
}

int main(int argc, char **argv) {
    if (argc != 4) {
        printf("Usage: ./compress {c/d} <infile> <outfile>\n");
        return EXIT_FAILURE;
    }
    FILE *infile;
    if ((infile = fopen(argv[2], "r")) == NULL) {
        printf("Could not open %s for reading.\n", argv[2]);
        return EXIT_FAILURE;
    }
    FILE *outfile;
    if ((outfile = fopen(argv[3], "w")) == NULL) {
        printf("Could not open %s for writing.\n", argv[3]);
        return EXIT_FAILURE;
    }
    if (*argv[1] == 'c') {
        compress(infile, outfile);
    } else if (*argv[1] == 'd') {
        decompress(infile, outfile);
    } else {
        printf("Invalid option %c.\n", *argv[1]);
        return EXIT_FAILURE;
    }
    fclose(infile);
    fclose(outfile);
    return EXIT_SUCCESS;
}