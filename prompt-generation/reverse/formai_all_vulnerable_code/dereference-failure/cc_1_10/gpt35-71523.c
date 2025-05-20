//FormAI DATASET v1.0 Category: Compression algorithms ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 4096   // LZW dictionary size
#define BUFFER_SIZE 4096  // Input buffer size

// LZW dictionary structure
typedef struct dictionary {
    char *string;
    int code;
    int length;
    struct dictionary *next;
} dictionary;

// Function to initialize the LZW dictionary
dictionary *initDictionary() {
    dictionary *dict = (dictionary*) malloc(TABLE_SIZE * sizeof(dictionary));
    for(int i = 0; i < 256; i++) {
        dict[i].string = (char*) malloc(sizeof(char));
        dict[i].string[0] = (char) i;
        dict[i].code = i;
        dict[i].length = 1;
        dict[i].next = NULL;
    }
    return dict;
}

// Function to add a new entry to the LZW dictionary
dictionary *addEntry(dictionary *dict, char *string, int length, int code) {
    dict[code].string = (char*) malloc(length * sizeof(char));
    strncpy(dict[code].string, string, length);
    dict[code].code = code;
    dict[code].length = length;
    dict[code].next = NULL;
    return dict;
}

// LZW compression function
void compress(FILE *in, FILE *out) {
    dictionary *dict = initDictionary();
    char buffer[BUFFER_SIZE];
    int nextCode = 256;
    int bytesRead = 0;
    char *p = buffer;
    int code = 0;
    int length = 0;
    while((bytesRead = fread(buffer, sizeof(char), BUFFER_SIZE, in)) > 0) {
        p = buffer;
        while(bytesRead--) {
            code = (*p++) << 16;
            code += (*p++) << 8;
            code += (*p++);
            if((length + 3) > TABLE_SIZE) {
                fwrite(&length, sizeof(int), 1, out);
                fwrite(dict, sizeof(dictionary), TABLE_SIZE, out);
                dict = initDictionary();
                nextCode = 256;
                length = 0;
            }
            else {
                dictionary *entry = dict + code;
                if(entry->length) {
                    length += entry->length;
                }
                else {
                    length += 3;
                    addEntry(dict, p-3, 3, nextCode++);
                }
            }
        }
    }
    if(length) {
        fwrite(&length, sizeof(int), 1, out);
        fwrite(dict, sizeof(dictionary), TABLE_SIZE, out);
    }
    else {
        length = -1;
        fwrite(&length, sizeof(int), 1, out);
    }
}

int main(int argc, char *argv[]) {
    if(argc < 2) {
        printf("Usage: %s <input_file>\n", argv[0]);
        exit(1);
    }
    FILE *in = fopen(argv[1], "rb");
    if(!in) {
        printf("Failed to open input file: %s\n", argv[1]);
        exit(1);
    }
    char outName[strlen(argv[1]) + 5];
    sprintf(outName, "%s.lzw", argv[1]);
    FILE *out = fopen(outName, "wb");
    if(!out) {
        printf("Failed to create output file: %s\n", outName);
        exit(1);
    }
    compress(in, out);
    fclose(in);
    fclose(out);
    printf("Compression complete. Output written to %s\n", outName);
    return 0;
}