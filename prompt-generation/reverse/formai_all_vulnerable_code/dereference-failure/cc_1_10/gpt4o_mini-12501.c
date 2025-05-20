//GPT-4o-mini DATASET v1.0 Category: Compression algorithms ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1000
#define DICTIONARY_SIZE 256

typedef struct {
    unsigned char byte;
    unsigned int frequency;
} Frequency;

void countFrequency(const char *data, Frequency frequencies[DICTIONARY_SIZE]) {
    while (*data) {
        frequencies[(unsigned char)*data].byte = (unsigned char)*data;
        frequencies[(unsigned char)*data].frequency++;
        data++;
    }
}

int compareFrequency(const void *a, const void *b) {
    return ((Frequency *)b)->frequency - ((Frequency *)a)->frequency; // Sort descending
}

void printFrequencies(Frequency frequencies[DICTIONARY_SIZE]) {
    printf("Byte Frequencies:\n");
    for (int i = 0; i < DICTIONARY_SIZE; i++) {
        if (frequencies[i].frequency > 0) {
            printf("Byte: %c (ASCII: %d) - Frequency: %u\n", frequencies[i].byte, (unsigned char)frequencies[i].byte, frequencies[i].frequency);
        }
    }
}

void compressData(const char *data, char *compressedData, int *compressedSize) {
    Frequency frequencies[DICTIONARY_SIZE] = {{0, 0}};
    
    countFrequency(data, frequencies);
    qsort(frequencies, DICTIONARY_SIZE, sizeof(Frequency), compareFrequency);

    *compressedSize = 0;
    for (int i = 0; i < DICTIONARY_SIZE; i++) {
        if (frequencies[i].frequency > 0) {
            // Store the byte and its frequency in the compressed data
            compressedData[(*compressedSize)++] = frequencies[i].byte;
            compressedData[(*compressedSize)++] = frequencies[i].frequency;
        }
    }
}

void decompressData(const char *compressedData, char *decompressedData, int compressedSize) {
    int index = 0;
    while (index < compressedSize) {
        unsigned char byte = compressedData[index++];
        unsigned int frequency = compressedData[index++];
        for (unsigned int i = 0; i < frequency; i++) {
            *decompressedData++ = byte;
        }
    }
    *decompressedData = '\0'; // Null terminate the decompressed string
}

void configureCompression(const char *data) {
    char compressedData[MAX_LEN] = {0};
    char decompressedData[MAX_LEN] = {0};
    int compressedSize = 0;

    compressData(data, compressedData, &compressedSize);
    printf("Compressed Data Size: %d bytes\n", compressedSize);
    
    decompressData(compressedData, decompressedData, compressedSize);
    printf("Decompressed Data: %s\n", decompressedData);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <string to compress>\n", argv[0]);
        return 1;
    }
    
    configureCompression(argv[1]);
    return 0;
}