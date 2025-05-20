//Falcon2-11B DATASET v1.0 Category: File Encyptor ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    FILE *infile = fopen(argv[1], "r");
    if (infile == NULL) {
        fprintf(stderr, "Could not open file: %s\n", argv[1]);
        exit(1);
    }

    FILE *outfile = fopen(argv[1], "w");
    if (outfile == NULL) {
        fprintf(stderr, "Could not create file: %s\n", argv[1]);
        exit(1);
    }

    int i;
    char c;
    while ((c = fgetc(infile))!= EOF) {
        if (c == 'a') {
            fputc('b', outfile);
        } else if (c == 'b') {
            fputc('a', outfile);
        } else if (c == 'c') {
            fputc('d', outfile);
        } else if (c == 'd') {
            fputc('c', outfile);
        } else if (c == 'e') {
            fputc('f', outfile);
        } else if (c == 'f') {
            fputc('e', outfile);
        } else if (c == 'g') {
            fputc('h', outfile);
        } else if (c == 'h') {
            fputc('g', outfile);
        } else if (c == 'i') {
            fputc('j', outfile);
        } else if (c == 'j') {
            fputc('i', outfile);
        } else if (c == 'k') {
            fputc('l', outfile);
        } else if (c == 'l') {
            fputc('k', outfile);
        } else if (c =='m') {
            fputc('n', outfile);
        } else if (c == 'n') {
            fputc('m', outfile);
        } else if (c == 'o') {
            fputc('p', outfile);
        } else if (c == 'p') {
            fputc('o', outfile);
        } else if (c == 'q') {
            fputc('r', outfile);
        } else if (c == 'r') {
            fputc('q', outfile);
        } else if (c =='s') {
            fputc('t', outfile);
        } else if (c == 't') {
            fputc('s', outfile);
        } else if (c == 'u') {
            fputc('v', outfile);
        } else if (c == 'v') {
            fputc('u', outfile);
        } else if (c == 'w') {
            fputc('x', outfile);
        } else if (c == 'x') {
            fputc('w', outfile);
        } else if (c == 'y') {
            fputc('z', outfile);
        } else if (c == 'z') {
            fputc('y', outfile);
        } else {
            fputc(c, outfile);
        }
    }

    fclose(infile);
    fclose(outfile);

    return 0;
}