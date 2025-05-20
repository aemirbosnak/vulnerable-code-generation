//FormAI DATASET v1.0 Category: Compression algorithms ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct for each token in the compressed file
typedef struct {
    char code[9];   // 8-bit code
    char ch;        // Original character
} Token;

// Configuration options
int BITS_PER_CODE = 8;  // Default number of bits per code
int MAX_TABLE_SIZE = 256;   // Maximum table size - change for different compression ratios

// Function to read from input file and return the file size
int getFileSize(FILE *file) {
    int size;
    fseek(file, 0L, SEEK_END);  // Move file pointer to end of file
    size = ftell(file);         // Get current position of file pointer (equals file size)
    fseek(file, 0L, SEEK_SET);  // Move file pointer back to beginning of file
    return size;
}

// Function to write bits to the output file buffer
void writeBits(char *buf, int *pos, unsigned int bits, int numBits) {
    while (numBits > 0) {
        // Add least significant bit to buffer
        buf[(*pos) / 8] |= ((bits & 1) << (*pos % 8));
        bits >>= 1;
        (*pos)++;
        numBits--;
    }
}

// Function to compress input file into output file
void compress(char *inFile, char *outFile) {
    FILE *in = fopen(inFile, "rb");
    FILE *out = fopen(outFile, "wb");
    int inSize = getFileSize(in);
    
    // Setup token table
    Token *table = malloc(MAX_TABLE_SIZE * sizeof(Token));
    int tableSize = 0;
    for (int i = 0; i < 256; i++) {
        table[i].code[0] = i;
        table[i].code[1] = 0;
        table[i].ch = i;
        tableSize++;
    }
    
    // Read input file into buffer
    unsigned char *inBuf = malloc(inSize + 1);
    fread(inBuf, 1, inSize, in);
    inBuf[inSize] = '\0';
    
    // Initialize output file buffer and positions
    char *outBuf = malloc(inSize * sizeof(Token) * BITS_PER_CODE);
    int outPos = 0;
    int outLen = 0;
    
    // Loop through input buffer and compress using LZW algorithm
    int i = 0;
    while (i < inSize) {
        // Get longest matching prefix in token table
        int len = 1;
        while (i + len <= inSize) {
            char *prefix = calloc(len + 1, sizeof(char));
            strncpy(prefix, (char *)inBuf + i, len);
            
            int matchIndex = -1;
            for (int j = 0; j < tableSize; j++) {
                if (strcmp(prefix, table[j].code) == 0) {
                    matchIndex = j;
                    break;
                }
            }
            
            if (matchIndex == -1) {
                // Add new token to table
                Token newToken;
                strncpy(newToken.code, prefix, len);
                newToken.ch = len > 1 ? *(prefix + len - 1) : *prefix;
                table[tableSize++] = newToken;
                
                // Write code for prefix to output buffer
                for (int j = 0; j < BITS_PER_CODE; j++) {
                    writeBits(outBuf, &outPos, matchIndex, BITS_PER_CODE);
                    outLen++;
                }
                break;
            }
            
            len++;
        }
        
        // Move input buffer position
        i += len - 1;
    }
    
    // Write output buffer to output file
    fwrite(outBuf, 1, (outLen + 7) / 8, out);
    
    // Free memory
    fclose(in);
    fclose(out);
    free(table);
    free(inBuf);
    free(outBuf);
}

// Function to decompress input file into output file
void decompress(char *inFile, char *outFile) {
    FILE *in = fopen(inFile, "rb");
    FILE *out = fopen(outFile, "wb");
    
    // Setup token table
    Token *table = malloc(MAX_TABLE_SIZE * sizeof(Token));
    int tableSize = 0;
    for (int i = 0; i < 256; i++) {
        table[i].code[0] = i;
        table[i].code[1] = 0;
        table[i].ch = i;
        tableSize++;
    }
    
    // Read input file into buffer
    int inSize = getFileSize(in);
    unsigned char *inBuf = malloc(inSize);
    fread(inBuf, 1, inSize, in);
    
    // Initialize output file buffer and position
    char *outBuf = malloc(inSize * sizeof(Token));
    int outPos = 0;
    
    // Loop through input buffer and decompress using LZW algorithm
    int i = 0;
    int codeBits = 0;
    unsigned int code = 0;
    int nextCode = 256;
    while (i < inSize * 8) {
        // Get code from input buffer
        code |= ((inBuf[i / 8] >> (i % 8)) & 1) << codeBits;
        i++;
        codeBits++;
        if (codeBits == BITS_PER_CODE) {
            // Look up code in token table
            Token token = table[code];
            
            // Write token to output buffer
            outBuf[outPos++] = token.ch;
            
            if (tableSize < MAX_TABLE_SIZE) {
                // Add new token to table
                Token newToken;
                strncpy(newToken.code, table[code].code, strlen(table[code].code));
                newToken.code[strlen(table[code].code)] = token.ch;
                newToken.code[strlen(table[code].code) + 1] = 0;
                newToken.ch = token.ch;
                table[tableSize++] = newToken;
            }
            
            code = 0;
            codeBits = 0;
        }
    }
    
    // Write output buffer to output file
    fwrite(outBuf, 1, outPos, out);
    
    // Free memory
    fclose(in);
    fclose(out);
    free(table);
    free(inBuf);
    free(outBuf);
}

int main(int argc, char **argv) {
    if (argc < 4) {
        printf("Usage: %s [compress|decompress] [input file] [output file] [options]\n", argv[0]);
        printf("Options:\n");
        printf("  -b [bits]     Number of bits per code (default is 8)\n");
        printf("  -s [size]     Maximum table size (default is 256)\n");
        exit(1);
    }
    
    // Process options
    for (int i = 4; i < argc; i++) {
        if (strcmp(argv[i], "-b") == 0) {
            i++;
            BITS_PER_CODE = atoi(argv[i]);
        } else if (strcmp(argv[i], "-s") == 0) {
            i++;
            MAX_TABLE_SIZE = atoi(argv[i]);
        } else {
            printf("Invalid option: %s\n", argv[i]);
            exit(1);
        }
    }
    
    if (strcmp(argv[1], "compress") == 0) {
        compress(argv[2], argv[3]);
    } else if (strcmp(argv[1], "decompress") == 0) {
        decompress(argv[2], argv[3]);
    } else {
        printf("Invalid command: %s\n", argv[1]);
        exit(1);
    }
    
    printf("Done!\n");
    
    return 0;
}