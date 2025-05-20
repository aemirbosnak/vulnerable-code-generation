//GPT-4o-mini DATASET v1.0 Category: Compression algorithms ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1024

typedef struct {
    char *data;
    int length;
} CompressedData;

CompressedData futuristic_compress(const char *input) {
    int length = strlen(input);
    CompressedData result;
    result.data = (char *) malloc(length + 1); // Allocate memory for compressed data
    if (result.data == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    
    int count = 1, j = 0;
    for (int i = 1; i <= length; i++) {
        if (input[i] == input[i - 1]) {
            count++;
        } else {
            // Store char and its count
            j += sprintf(result.data + j, "%c%d", input[i - 1], count);
            count = 1; // Reset count
        }
    }
    
    result.length = j;
    result.data[result.length] = '\0'; // Terminate the string
    return result;
}

char *futuristic_decompress(const CompressedData *compressed) {
    char *result = (char *)malloc(MAX_SIZE);
    if (result == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }

    int j = 0, i = 0;
    while (compressed->data[i]) {
        char ch = compressed->data[i++];
        int count = 0;

        // Extract the number
        while (isdigit(compressed->data[i])) {
            count = count * 10 + (compressed->data[i] - '0');
            i++;
        }
        
        // Expand the character count into the result
        for (int k = 0; k < count; k++) {
            result[j++] = ch;
        }
    }
    
    result[j] = '\0'; // Null-terminate the decompressed string
    return result;
}

void futuristic_file_compression(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Could not open file %s for reading.\n", filename);
        return;
    }

    char buffer[MAX_SIZE];
    fread(buffer, sizeof(char), MAX_SIZE, file);
    fclose(file);

    CompressedData compressed = futuristic_compress(buffer);
    printf("Compressed data: %s\n", compressed.data);

    // Save the compressed data to a file
    FILE *comp_file = fopen("compressed_data.txt", "w");
    if (comp_file != NULL) {
        fwrite(compressed.data, sizeof(char), compressed.length, comp_file);
        fclose(comp_file);
    }

    // Decompression demonstration
    char *decompressed = futuristic_decompress(&compressed);
    printf("Decompressed data: %s\n", decompressed);

    // Clean up
    free(compressed.data);
    free(decompressed);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    futuristic_file_compression(argv[1]);
    return EXIT_SUCCESS;
}