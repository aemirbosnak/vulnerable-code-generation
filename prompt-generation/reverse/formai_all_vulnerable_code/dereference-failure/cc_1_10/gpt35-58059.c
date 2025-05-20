//FormAI DATASET v1.0 Category: Compression algorithms ; Style: Linus Torvalds
/* Welcome to my compression algorithm! */

#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024
#define MAX_CODE 255

/* Our compression function */
void compress(char *input_filename, char *output_filename) {
    FILE *input_file = fopen(input_filename, "rb");
    if (!input_file) {
        perror("Could not open input file");
        exit(1);
    }

    FILE *output_file = fopen(output_filename, "wb");
    if (!output_file) {
        perror("Could not open output file");
        exit(1);
    }

    int freq[MAX_CODE+1] = {0}; // reset frequencies
    int c;
    while ((c = fgetc(input_file)) != EOF) {
        freq[c]++;
    }
    rewind(input_file); // start reading the file from the beginning

    int code = 256; // start codes from 256 and stop at MAX_CODE
    int max_freq = 0;
    for (int i = 0; i <= MAX_CODE; i++) {
        if (freq[i] > max_freq) {
            max_freq = freq[i];
            code = i;
        }
    }

    int next_code = code+1;
    int *prefix = malloc(BUFFER_SIZE * sizeof(int));
    int *suffix = malloc(BUFFER_SIZE * sizeof(int));
    int index = 0;

    prefix[index] = code;
    index++;

    while ((c = fgetc(input_file)) != EOF) {
        suffix[index-1] = c;

        int j;
        for (j = 0; j < index; j++) {
            if (prefix[j] != code || suffix[j] != c) {
                continue;
            }

            break;
        }

        if (j < index) { // found a matching string
            code = j == 0 ? prefix[0] : next_code++;
        } else { // no match, add new string to dictionary
            fwrite(&prefix[0], sizeof(int), index, output_file);
            code = c;
            prefix[0] = code;
            index = 1;
        }

        if (next_code > MAX_CODE) { // code table full, reset
            fwrite(&prefix[0], sizeof(int), index, output_file);
            code = 256;
            next_code = code+1;
            index = 1;
            prefix[0] = code;
            for (int i = 0; i < MAX_CODE; i++) {
                freq[i] = 0;
            }
            max_freq = 0;
            continue;
        }

        prefix[index] = code;
        index++;
    }

    fwrite(&prefix[0], sizeof(int), index, output_file);

    free(prefix);
    free(suffix);

    fclose(input_file);
    fclose(output_file);
}

/* Our decompression function */
void decompress(char *input_filename, char *output_filename) {
    FILE *input_file = fopen(input_filename, "rb");
    if (!input_file) {
        perror("Could not open input file");
        exit(1);
    }

    FILE *output_file = fopen(output_filename, "wb");
    if (!output_file) {
        perror("Could not open output file");
        exit(1);
    }

    int code = 256;
    int next_code = code+1;
    int size = BUFFER_SIZE;
    int index = 0;
    int *prefix = malloc(BUFFER_SIZE * sizeof(int));
    int *suffix = malloc(BUFFER_SIZE * sizeof(int));
    int *stack = malloc(BUFFER_SIZE * sizeof(int));
    int top = -1;

    fread(&prefix[0], sizeof(int), size, input_file);
    index = size;

    while (index == size) {
        int count = fread(&prefix[size], sizeof(int), size, input_file);
        index += count;
    }

    int c = prefix[0];
    fputc(c, output_file);

    for (int i = 1; i < index; i++) {
        int k = prefix[i];
        if (k >= next_code) {
            top++;
            stack[top] = c;
            k = c;
        }

        while (k >= code) {
            top++;
            stack[top] = suffix[k];
            k = prefix[k];
        }

        c = suffix[k];
        fputc(c, output_file);

        while (top >= 0) {
            fputc(stack[top], output_file);
            top--;
        }

        if (next_code <= MAX_CODE) {
            prefix[i] = code;
            suffix[code] = c;
            code = next_code++;
        }
    }

    free(prefix);
    free(suffix);
    free(stack);

    fclose(input_file);
    fclose(output_file);
}

/* Our main function */
int main(int argc, char *argv[]) {
    if (argc < 4) {
        printf("Usage: %s [-c | -d] [input file] [output file]\n", argv[0]);
        exit(1);
    }

    if (argv[1][0] == '-' && argv[1][1] == 'c') {
        compress(argv[2], argv[3]);
    } else if (argv[1][0] == '-' && argv[1][1] == 'd') {
        decompress(argv[2], argv[3]);
    } else {
        printf("Invalid option\n");
        exit(1);
    }

    return 0;
}