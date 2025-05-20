//LLAMA2-13B DATASET v1.0 Category: Compression algorithms ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

// Structure to hold the compressed data
typedef struct {
    int length;
    char data[BUFFER_SIZE];
} compressed_data_t;

// Function to compress the data
compressed_data_t* compress(char* data) {
    // Step 1: Remove all whitespace characters
    char* p = strtok(data, " \t\n");
    while (p != NULL) {
        data[strcspn(p, " \t\n")] = '\0';
        p = strtok(NULL, " \t\n");
    }

    // Step 2: Replace all consecutive identical characters with a single character
    for (int i = 0; i < strlen(data); i++) {
        if (i < strlen(data) - 1 && data[i] == data[i + 1]) {
            data[i] = '~';
        }
    }

    // Step 3: Compress the data using Huffman coding
    int num_codes = 0;
    int* codes = calloc(strlen(data) + 1, sizeof(int));
    for (int i = 0; i < strlen(data); i++) {
        if (data[i] == '~') {
            num_codes++;
            codes[num_codes] = i;
        }
    }

    // Generate the Huffman code for each character
    for (int i = 0; i < strlen(data); i++) {
        if (data[i] == '~') {
            int j = 0;
            while (j < num_codes) {
                if (codes[j] == i) {
                    data[i] = j + '0';
                    break;
                }
                j++;
            }
        }
    }

    // Step 4: Pack the compressed data into a struct
    compressed_data_t* cd = calloc(1, sizeof(compressed_data_t));
    cd->length = strlen(data);
    memcpy(cd->data, data, cd->length);

    return cd;
}

// Function to decompress the data
char* decompress(compressed_data_t* cd) {
    char* data = calloc(cd->length, sizeof(char));
    int i = 0;
    for (int j = 0; j < cd->length; j++) {
        if (cd->data[j] >= '0' && cd->data[j] <= '9') {
            data[i] = (cd->data[j] - '0') << 1;
            i++;
        } else {
            data[i] = cd->data[j];
        }
    }

    // Step 5: Unpack the compressed data from the struct
    memcpy(cd->data, data, cd->length);

    return data;
}

int main() {
    char input[] = "Hello, World!";
    compressed_data_t* cd = compress(input);
    char* output = decompress(cd);
    printf("%s\n", output);

    return 0;
}