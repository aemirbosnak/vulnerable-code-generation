//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: Claude Shannon
/* 
 * This is a program that extracts metadata from files in C. Inspired by the work of Claude Shannon, 
 * this program uses information theory to extract relevant data from files and output it to the console.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1024 // Maximum file size allowed

/* 
 * This function calculates the entropy of a given byte frequency distribution.
 */
double entropy(unsigned long freq[]) {
    double sum = 0.0, p;

    for(int i = 0; i < 256; i++) {
        if(freq[i] > 0) {
            p = (double)freq[i] / MAX_FILE_SIZE;
            sum -= p * log2(p);
        }
    }

    return sum;
}

int main(int argc, char *argv[]) {
    if(argc < 2) {
        fprintf(stderr, "Usage: %s filename\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    FILE *file = fopen(argv[1], "rb");
    if(!file) {
        fprintf(stderr, "Error opening file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    /* 
     * Allocate memory for frequency table
     */
    unsigned long *freq = calloc(256, sizeof(unsigned long));
    if(!freq) {
        fprintf(stderr, "Error allocating memory\n");
        exit(EXIT_FAILURE);
    }

    /* 
     * Read file and construct frequency table
     */
    unsigned char buffer[MAX_FILE_SIZE];
    size_t bytes_read;

    while((bytes_read = fread(buffer, sizeof(unsigned char), MAX_FILE_SIZE, file)) > 0) {
        for(int i = 0; i < bytes_read; i++) {
            freq[buffer[i]]++;
        }
    }

    fclose(file);

    double file_entropy = entropy(freq);

    /* 
     * Cleanup and output results
     */
    free(freq);

    printf("Filename: %s\n", argv[1]);
    printf("File size: %zu bytes\n", bytes_read);
    printf("Entropy: %f\n", file_entropy);

    return EXIT_SUCCESS;
}