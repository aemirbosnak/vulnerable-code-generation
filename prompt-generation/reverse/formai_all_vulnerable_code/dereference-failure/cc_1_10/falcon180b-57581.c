//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 1000000

int main(int argc, char** argv) {
    if(argc!= 2) {
        printf("Usage: %s <binary_file>\n", argv[0]);
        return 1;
    }

    FILE* input_file = fopen(argv[1], "rb");
    if(!input_file) {
        printf("Error: could not open file %s\n", argv[1]);
        return 1;
    }

    char* buffer = (char*) malloc(MAX_LENGTH);
    if(!buffer) {
        printf("Error: could not allocate memory\n");
        fclose(input_file);
        return 1;
    }

    int buffer_length = 0;
    int buffer_index = 0;

    while((buffer_length = fread(buffer + buffer_index, 1, MAX_LENGTH - buffer_index, input_file)) > 0) {
        buffer_index += buffer_length;
        if(buffer_index == MAX_LENGTH) {
            printf("Error: buffer overflow\n");
            fclose(input_file);
            free(buffer);
            return 1;
        }
    }

    fclose(input_file);

    char* output_buffer = (char*) malloc(buffer_index + 1);
    if(!output_buffer) {
        printf("Error: could not allocate memory\n");
        free(buffer);
        return 1;
    }

    int output_index = 0;

    for(int i = 0; i < buffer_index; i++) {
        int binary_value = buffer[i] - '0';
        output_buffer[output_index++] = (binary_value % 2) + '0';
        binary_value /= 2;
        if(binary_value > 0) {
            output_buffer[output_index++] = (binary_value % 2) + '0';
            binary_value /= 2;
        }
    }

    output_buffer[output_index] = '\0';

    printf("Binary to Decimal Conversion:\n");
    printf("%s\n", output_buffer);

    free(buffer);
    free(output_buffer);

    return 0;
}