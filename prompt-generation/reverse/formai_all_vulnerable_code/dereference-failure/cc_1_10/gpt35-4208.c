//FormAI DATASET v1.0 Category: Compression algorithms ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    printf("Welcome to the Mind-Bending Compression Algorithm Program.\n");
    printf("Please enter the file name that you would like to compress:\n");
    char filename[100];
    scanf("%s", filename);
    FILE* f = fopen(filename, "rb");
    if (!f) {
        printf("Error: File not found!\n");
        return 1;
    }

    // Get the file size
    fseek(f, 0, SEEK_END);
    size_t size = ftell(f);
    fseek(f, 0, SEEK_SET);

    // Read the file into memory
    unsigned char* data = (unsigned char*)malloc(size);
    fread(data, size, 1, f);
    fclose(f);

    // Compress the data using our insane algorithm
    unsigned char* compressed_data = (unsigned char*)malloc(size);
    int compressed_size = 0;
    for (int i = 0; i < size; i++) {
        unsigned char val = data[i];
        int count = 0;
        for (int j = i + 1; j < size; j++) {
            if (data[j] == val && count < 255) {
                count++;
            } else {
                break;
            }
        }
        if (count > 2) {
            compressed_data[compressed_size++] = val;
            compressed_data[compressed_size++] = (unsigned char)count;
            i += count;
        } else {
            compressed_data[compressed_size++] = val;
        }
    }

    // Write the compressed data to a new file
    char output_filename[100];
    strcpy(output_filename, filename);
    strcat(output_filename, ".compressed");
    f = fopen(output_filename, "wb");
    fwrite(compressed_data, compressed_size, 1, f);
    fclose(f);
    printf("File successfully compressed!\n");
    free(data);
    free(compressed_data);
    return 0;
}