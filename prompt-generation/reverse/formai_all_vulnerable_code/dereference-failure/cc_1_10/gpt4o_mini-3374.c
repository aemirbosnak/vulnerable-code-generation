//GPT-4o-mini DATASET v1.0 Category: Compression algorithms ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024
#define HASH_TABLE_SIZE 65536

typedef struct {
    unsigned short length;
    unsigned short offset;
} LZEntry;

typedef struct {
    LZEntry entries[BUFFER_SIZE];
    int count;
} LZBuffer;

void init_lz_buffer(LZBuffer *lz) {
    lz->count = 0;
}

void clear_lz_buffer(LZBuffer *lz) {
    lz->count = 0;
}

void insert_lz_entry(LZBuffer *lz, unsigned short length, unsigned short offset) {
    if (lz->count < BUFFER_SIZE) {
        lz->entries[lz->count].length = length;
        lz->entries[lz->count].offset = offset;
        lz->count++;
    }
}

unsigned int hash(const char *data, size_t length) {
    unsigned int hashval = 5381;
    for (size_t i = 0; i < length; i++) {
        hashval = ((hashval << 5) + hashval) + data[i]; // hash * 33 + c
    }
    return hashval % HASH_TABLE_SIZE;
}

void compress(const char *input, size_t inputLen, FILE *output) {
    LZBuffer lzBuffer;
    init_lz_buffer(&lzBuffer);
    char *buffer = (char *)malloc(BUFFER_SIZE);
    if (!buffer) {
        perror("Failed to allocate memory");
        exit(EXIT_FAILURE);
    }

    size_t i = 0;
    while (i < inputLen) {
        unsigned short offset = 0;
        unsigned short length = 0;
        
        // Look for the longest match in the buffer
        for (size_t j = i > BUFFER_SIZE ? i - BUFFER_SIZE : 0; j < i; j++) {
            size_t matchLen = 0;
            while (input[j + matchLen] == input[i + matchLen] && (i + matchLen) < inputLen) {
                matchLen++;
            }
            if (matchLen > length) {
                length = matchLen;
                offset = i - j;
            }
        }

        if (length > 0) {
            insert_lz_entry(&lzBuffer, length, offset);
            i += length;
        } else {
            // No match, add the next character as a literal
            if (lzBuffer.count < BUFFER_SIZE) {
                insert_lz_entry(&lzBuffer, 0, (unsigned short)input[i]);
                i++;
            }
        }

        // Write compressed data when the buffer is full
        if (lzBuffer.count == BUFFER_SIZE) {
            fwrite(lzBuffer.entries, sizeof(LZEntry), lzBuffer.count, output);
            clear_lz_buffer(&lzBuffer);
        }
    }

    // Write any remaining entries
    if (lzBuffer.count > 0) {
        fwrite(lzBuffer.entries, sizeof(LZEntry), lzBuffer.count, output);
    }

    free(buffer);
}

void decompress(FILE *input, FILE *output) {
    LZEntry entry;
    while (fread(&entry, sizeof(LZEntry), 1, input) == 1) {
        if (entry.length > 0) {
            // Copy from the output back to fill the offset location
            long pos = ftell(output);
            fseek(output, pos - entry.offset, SEEK_SET);
            for (unsigned short i = 0; i < entry.length; i++) {
                int ch = fgetc(output);
                fputc(ch, output);
            }
        } else {
            // Write literal value
            fputc(entry.offset, output);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        fprintf(stderr, "Usage: %s <compress|decompress> <input_filename> <output_filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if (strcmp(argv[1], "compress") == 0) {
        FILE *inputFile = fopen(argv[2], "rb");
        FILE *outputFile = fopen(argv[3], "wb");
        if (!inputFile || !outputFile) {
            perror("File open error");
            exit(EXIT_FAILURE);
        }

        fseek(inputFile, 0, SEEK_END);
        size_t inputLen = ftell(inputFile);
        fseek(inputFile, 0, SEEK_SET);

        char *buffer = (char *)malloc(inputLen);
        fread(buffer, 1, inputLen, inputFile);

        compress(buffer, inputLen, outputFile);

        free(buffer);
        fclose(inputFile);
        fclose(outputFile);
    } else if (strcmp(argv[1], "decompress") == 0) {
        FILE *inputFile = fopen(argv[2], "rb");
        FILE *outputFile = fopen(argv[3], "wb");
        if (!inputFile || !outputFile) {
            perror("File open error");
            exit(EXIT_FAILURE);
        }

        decompress(inputFile, outputFile);

        fclose(inputFile);
        fclose(outputFile);
    } else {
        fprintf(stderr, "Invalid mode: %s. Use 'compress' or 'decompress'.\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    return 0;
}