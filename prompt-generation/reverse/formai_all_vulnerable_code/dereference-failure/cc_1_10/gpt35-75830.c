//FormAI DATASET v1.0 Category: Compression algorithms ; Style: portable
#include <stdio.h>
#include <stdlib.h>

#define CHUNK_SIZE 128

unsigned char *compress(unsigned char *input, size_t input_size, size_t *output_size) {
    unsigned char *output = (unsigned char*) malloc(input_size * sizeof(unsigned char));
    size_t output_position = 0;
    unsigned char current_byte = input[0];
    unsigned char count = 1;
    
    for(size_t i = 1; i < input_size; i++) {
        if(input[i] == current_byte) {
            count++;
        } else {
            output[output_position++] = current_byte;
            output[output_position++] = count;
            
            current_byte = input[i];
            count = 1;
        }
    }
    
    output[output_position++] = current_byte;
    output[output_position++] = count;
    
    *output_size = output_position;
    return output;
}

unsigned char *decompress(unsigned char *input, size_t input_size, size_t *output_size) {
    unsigned char *output = (unsigned char*) malloc(input_size * sizeof(unsigned char));
    size_t output_position = 0;
    
    for(size_t i = 0; i < input_size; i += 2) {
        unsigned char current_byte = input[i];
        unsigned char count = input[i+1];
        
        for(unsigned char j = 0; j < count; j++) {
            output[output_position++] = current_byte;
        }
    }
    
    *output_size = output_position;
    return output;
}

int main() {
    unsigned char input[] = {0x41, 0x41, 0x41, 0x41, 0x42, 0x42, 0x43, 0x43, 0x43, 0x43, 0x43};
    size_t input_size = sizeof(input) / sizeof(unsigned char);
    
    size_t compressed_size;
    unsigned char *compressed = compress(input, input_size, &compressed_size);
    
    printf("Original size: %d\nCompressed size: %d\n\n", (int) input_size, (int) compressed_size);
    
    for(size_t i = 0; i < compressed_size; i++) {
        printf("%02x ", compressed[i]);
    }
    printf("\n\n");
    
    size_t decompressed_size;
    unsigned char *decompressed = decompress(compressed, compressed_size, &decompressed_size);
    
    for(size_t i = 0; i < decompressed_size; i++) {
        printf("%02x ", decompressed[i]);
    }
    printf("\n\n");
    
    free(compressed);
    free(decompressed);
    
    return 0;
}