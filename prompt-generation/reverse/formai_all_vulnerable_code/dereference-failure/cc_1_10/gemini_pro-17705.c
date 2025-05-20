//GEMINI-pro DATASET v1.0 Category: Compression algorithms ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

// Our secret weapon: the Lempel-Ziv-Welch (LZW) compression algorithm
#define LZW_TABLE_SIZE 4096
#define LZW_MAX_CODE 65535

typedef struct {
    unsigned short code;
    char *string;
} LZWEntry;

// The LZW compression function
char *lzw_compress(char *input) {
    // Initialize the LZW table
    LZWEntry lzw_table[LZW_TABLE_SIZE];
    for (int i = 0; i < 256; i++) {
        lzw_table[i].code = i;
        lzw_table[i].string = malloc(2);
        lzw_table[i].string[0] = i;
        lzw_table[i].string[1] = '\0';
    }

    // Initialize the output buffer
    char *output = malloc(1);
    output[0] = '\0';

    // Initialize the current code
    unsigned short current_code = 256;

    // Iterate over the input string
    char *p = input;
    while (*p) {
        // Find the longest matching string in the LZW table
        int match_len = 0;
        LZWEntry *match_entry = NULL;
        for (int i = 0; i < current_code; i++) {
            int len = strlen(lzw_table[i].string);
            if (strncmp(lzw_table[i].string, p, len) == 0 && len > match_len) {
                match_len = len;
                match_entry = &lzw_table[i];
            }
        }

        // If a match was found, add its code to the output buffer
        if (match_entry) {
            char *new_output = realloc(output, strlen(output) + sizeof(short));
            if (!new_output) {
                free(output);
                return NULL;
            }
            output = new_output;
            *(unsigned short *)(output + strlen(output)) = match_entry->code;
            output[strlen(output) + sizeof(short)] = '\0';
            p += match_len;
        }

        // If no match was found, add the current character to the LZW table and the output buffer
        else {
            lzw_table[current_code].code = current_code;
            lzw_table[current_code].string = malloc(match_len + 2);
            if (!lzw_table[current_code].string) {
                free(output);
                return NULL;
            }
            strncpy(lzw_table[current_code].string, p, match_len);
            lzw_table[current_code].string[match_len] = *p;
            lzw_table[current_code].string[match_len + 1] = '\0';
            char *new_output = realloc(output, strlen(output) + sizeof(short) + 1);
            if (!new_output) {
                free(output);
                return NULL;
            }
            output = new_output;
            *(unsigned short *)(output + strlen(output)) = current_code++;
            output[strlen(output) + sizeof(short)] = '\0';
            p++;
        }
    }

    // Return the compressed output
    return output;
}

// The LZW decompression function
char *lzw_decompress(char *input) {
    // Initialize the LZW table
    LZWEntry lzw_table[LZW_TABLE_SIZE];
    for (int i = 0; i < 256; i++) {
        lzw_table[i].code = i;
        lzw_table[i].string = malloc(2);
        lzw_table[i].string[0] = i;
        lzw_table[i].string[1] = '\0';
    }

    // Initialize the output buffer
    char *output = malloc(1);
    output[0] = '\0';

    // Initialize the current code
    unsigned short current_code = 256;

    // Iterate over the input string
    unsigned short *p = (unsigned short *)input;
    while (*p) {
        // Find the string in the LZW table corresponding to the current code
        LZWEntry *entry = &lzw_table[*p];

        // Append the string to the output buffer
        char *new_output = realloc(output, strlen(output) + strlen(entry->string) + 1);
        if (!new_output) {
            free(output);
            return NULL;
        }
        output = new_output;
        strcat(output, entry->string);
        output[strlen(output)] = '\0';

        // If the current code is not the end of the string, add the first character of the string to the LZW table
        if (*p != LZW_MAX_CODE) {
            lzw_table[current_code].code = current_code;
            lzw_table[current_code].string = malloc(strlen(entry->string) + 2);
            if (!lzw_table[current_code].string) {
                free(output);
                return NULL;
            }
            strcpy(lzw_table[current_code].string, entry->string);
            lzw_table[current_code].string[strlen(entry->string)] = output[strlen(output) - 1];
            lzw_table[current_code].string[strlen(entry->string) + 1] = '\0';
            current_code++;
        }

        // Advance to the next code in the input string
        p++;
    }

    // Return the decompressed output
    return output;
}

// A simple test function
int main() {
    char *input = "TOBEORNOTTOBEORTOBEORNOT";

    // Compress the input string
    char *compressed = lzw_compress(input);
    if (!compressed) {
        printf("Error: compression failed.\n");
        return 1;
    }

    // Print the compressed output
    printf("Compressed output: %s\n", compressed);

    // Decompress the compressed output
    char *decompressed = lzw_decompress(compressed);
    free(compressed);
    if (!decompressed) {
        printf("Error: decompression failed.\n");
        return 1;
    }

    // Print the decompressed output
    printf("Decompressed output: %s\n", decompressed);
    free(decompressed);

    return 0;
}