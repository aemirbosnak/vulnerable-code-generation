//FormAI DATASET v1.0 Category: Compression algorithms ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BIT_SIZE 16
#define MAX_DICT_SIZE (1 << MAX_BIT_SIZE)
#define END_OF_STREAM_MARKER 256

/* data structure to store the dictionary */
struct dict {
    int c;
    int p;
};

/* function to initialize the dictionary */
void initializeDict(struct dict *D) {
    for (int i = 0; i < MAX_DICT_SIZE; i++) {
        D[i].c = END_OF_STREAM_MARKER;
        D[i].p = -1;
    }
}

/* function to append the character to the end of the dictionary */
void appendDict(char *s, int c) {
    strcat(s, (const char *)&c);
}

/* function to compress the data */
void compress(char *inputFile, char *outputFile) {
    FILE *fp_in = fopen(inputFile, "rb");
    FILE *fp_out = fopen(outputFile, "wb");

    if (fp_in == NULL || fp_out == NULL) {
        fprintf(stderr, "Error: Unable to open file.\n");
        exit(1);
    }

    struct dict D[MAX_DICT_SIZE];
    initializeDict(D);

    int i = 0, k = 0, code = END_OF_STREAM_MARKER, s = 0, b = 0;
    char *suff = malloc(sizeof(char) * MAX_DICT_SIZE);
    char *buffer = malloc(sizeof(char) * MAX_DICT_SIZE);

    while (1) {
        if (feof(fp_in)) {
            break;
        }

        char c = fgetc(fp_in);

        if (c == EOF) {
            break;
        }

        appendDict(suff, (int)c);

        if (D[code + (int)c].c != -1) {
            code = code + (int)c;
        } else {
            k++;
            D[code + (int)c].c = k;
            D[code + (int)c].p = code;
            fputc(code >> s, fp_out);

            if (s + writeBitSize(k - 1) >= MAX_BIT_SIZE) {
                rewind(fp_out);
                int temp;
                while ((temp = fgetc(fp_out)) != EOF) {
                    buffer[b++] = (char)temp;
                }
                fwrite(buffer, sizeof(char), b, fp_out);
                s = 0;
                b = 0;
            }

            code = (int)c;
            if (k >= (1 << MAX_BIT_SIZE)) {
                initializeDict(D);
                code = END_OF_STREAM_MARKER;
                k = 0;
                s = 0;
            }
        }

        while (s + writeBitSize(k) < MAX_BIT_SIZE && D[code].p != -1) {
            code = D[code].p;
            appendDict(suff, (char)(code & 0xFF));
        }

        s = s + writeBitSize(k);
        k++;
        if (k >= (1 << MAX_BIT_SIZE)) {
            initializeDict(D);
            k = 0;
            s = 0;
        }

    }

    fputc(code >> s, fp_out);

    if (s + writeBitSize(k - 1) >= MAX_BIT_SIZE) {
        rewind(fp_out);
        int temp;
        while ((temp = fgetc(fp_out)) != EOF) {
            buffer[b++] = (char)temp;
        }
        fwrite(buffer, sizeof(char), b, fp_out);
    }

    fputc(END_OF_STREAM_MARKER >> s, fp_out);

    fclose(fp_in);
    fclose(fp_out);
}

/* function to calculate the bit size of the code */
int writeBitSize(int k) {
    int size = 0;
    while (k > 0) {
        size++;
        k = k >> 1;
    }
    return size;
}

/* test the compress function */
int main() {
    char inputFile[] = "test.txt";
    char outputFile[] = "compressed.bin";
    compress(inputFile, outputFile);

    return 0;
}