//FormAI DATASET v1.0 Category: Compression algorithms ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// C Compression Algorithm - Introspective Style

// This C implementation of a compression algorithm utilizes a combination
// of frequency analysis and bit manipulation to efficiently reduce the size
// of binary data.

typedef struct {
    char c;         // Character value
    int freq;       // Frequency count
    char code[256]; // Huffman code
} CharEntry;

int compareEntries(const void *entry1, const void *entry2) {
    // Helper function for sorting CharEntries by frequency count
    return ((CharEntry *)entry1)->freq - ((CharEntry *)entry2)->freq;
}

void generateCode(CharEntry *table, int start, int end, char *prefix, int prefixLen) {
    // Recursive function to generate Huffman code for each character in the table
    if (end - start == 1) {
        // Special case for tables with only one character
        memcpy(table[start].code, prefix, prefixLen);
        table[start].code[prefixLen] = '\0';
    } else if (end - start > 1) {
        // Divide table in half and recurse on left and right halves
        int mid = (start + end) / 2;
        char newPrefix[prefixLen + 2];
        memcpy(newPrefix, prefix, prefixLen);
        newPrefix[prefixLen] = '0';
        newPrefix[prefixLen+1] = '\0';
        generateCode(table, start, mid, newPrefix, prefixLen+1);
        memcpy(newPrefix, prefix, prefixLen);
        newPrefix[prefixLen] = '1';
        newPrefix[prefixLen+1] = '\0';
        generateCode(table, mid, end, newPrefix, prefixLen+1);
    }
}

void compress(FILE *infile, FILE *outfile) {
    // Compresses an input file to an output file using the C compression algorithm
    // First pass: Count the frequency of each character in the input
    int counts[256] = {0};
    int totalChars = 0;
    int c;
    while ((c = fgetc(infile)) != EOF) {
        counts[c]++;
        totalChars++;
    }

    // Second pass: Generate Huffman codes for each character in the input
    CharEntry table[256];
    int numEntries = 0;
    for (int i = 0; i < 256; i++) {
        if (counts[i] > 0) {
            table[numEntries].c = (char)i;
            table[numEntries].freq = counts[i];
            numEntries++;
        }
    }
    qsort(table, numEntries, sizeof(CharEntry), compareEntries);
    generateCode(table, 0, numEntries, "", 0);

    // Write table to output file
    fwrite(&totalChars, sizeof(int), 1, outfile);
    fwrite(&numEntries, sizeof(int), 1, outfile);
    for (int i = 0; i < numEntries; i++) {
        fwrite(&table[i].c, sizeof(char), 1, outfile);
        fwrite(&table[i].freq, sizeof(int), 1, outfile);
    }

    // Third pass: Write compressed binary data to output file
    unsigned char buffer = 0;
    int bitCount = 0;
    fseek(infile, 0, SEEK_SET);
    while ((c = fgetc(infile)) != EOF) {
        CharEntry *entry = NULL;
        for (int i = 0; i < numEntries; i++) {
            if (table[i].c == c) {
                entry = &table[i];
                break;
            }
        }
        for (int i = 0; i < strlen(entry->code); i++) {
            if (entry->code[i] == '1') {
                buffer |= (1 << bitCount);
            }
            bitCount++;
            if (bitCount == 8) {
                fwrite(&buffer, sizeof(unsigned char), 1, outfile);
                buffer = 0;
                bitCount = 0;
            }
        }
    }
    if (bitCount > 0) {
        fwrite(&buffer, sizeof(unsigned char), 1, outfile);
    }
}

void decompress(FILE *infile, FILE *outfile) {
    // Decompresses an input file to an output file using the C compression algorithm
    // Read table from input file
    int totalChars;
    int numEntries;
    fread(&totalChars, sizeof(int), 1, infile);
    fread(&numEntries, sizeof(int), 1, infile);
    CharEntry table[numEntries];
    for (int i = 0; i < numEntries; i++) {
        fread(&table[i].c, sizeof(char), 1, infile);
        fread(&table[i].freq, sizeof(int), 1, infile);
        table[i].code[0] = '\0';
    }

    // Generate Huffman codes for each character in table
    qsort(table, numEntries, sizeof(CharEntry), compareEntries);
    generateCode(table, 0, numEntries, "", 0);

    // Decode input file using Huffman codes in table
    unsigned char buffer = 0;
    int bitCount = 0;
    int charsRead = 0;
    while (charsRead < totalChars) {
        while (strlen(table[buffer].code) == 0) {
            int bit = fgetc(infile) & (1 << bitCount);
            if (bit) {
                buffer = (buffer << 1) | 1;
            } else {
                buffer = buffer << 1;
            }
            bitCount++;
            if (bitCount == 8) {
                bitCount = 0;
            }
        }
        fputc(table[buffer].c, outfile);
        buffer = 0;
        bitCount = 0;
        charsRead++;
    }
}

int main(int argc, char **argv) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s (c|d) infile outfile\n", argv[0]);
        exit(1);
    }
    char mode = *argv[1];
    char *infile_name = argv[2];
    char *outfile_name = argv[3];
    FILE *infile = fopen(infile_name, "rb");
    FILE *outfile = fopen(outfile_name, "wb");
    if (mode == 'c') {
        compress(infile, outfile);
    } else if (mode == 'd') {
        decompress(infile, outfile);
    } else {
        fprintf(stderr, "Invalid mode: %c\n", mode);
        exit(1);
    }
    fclose(infile);
    fclose(outfile);
    return 0;
}