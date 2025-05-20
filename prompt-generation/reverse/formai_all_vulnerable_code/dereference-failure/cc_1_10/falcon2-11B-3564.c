//Falcon2-11B DATASET v1.0 Category: Hexadecimal Converter ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* text;
    int length;
} string_t;

void convert_to_hex(string_t* input, string_t* output) {
    int length = input->length;
    char* output_buffer = (char*)malloc((length * 2 + 1) * sizeof(char));
    int i, j, k;
    char* hex_buffer = (char*)malloc((length * 2 + 1) * sizeof(char));
    int hex_buffer_length = 0;

    for (i = 0; i < length; i++) {
        char byte = input->text[i];
        sprintf(hex_buffer, "%02X", byte);
        hex_buffer_length += strlen(hex_buffer);
        if (hex_buffer_length % 2 == 1) {
            sprintf(hex_buffer + strlen(hex_buffer), " ");
            hex_buffer_length += strlen(hex_buffer);
        }
    }

    for (i = 0, j = 0; i < length; i++) {
        char byte = input->text[i];
        sprintf(output_buffer + j, "%s", hex_buffer);
        j += strlen(hex_buffer);
        if (j % 2 == 0) {
            sprintf(output_buffer + j, " ");
            j += strlen(output_buffer + j);
        }
    }

    output->text = output_buffer;
    output->length = hex_buffer_length;
}

int main() {
    string_t input;
    string_t output;

    input.text = (char*)malloc(100 * sizeof(char));
    strcpy(input.text, "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");
    input.length = strlen(input.text);

    output.text = (char*)malloc(200 * sizeof(char));
    output.length = 0;

    convert_to_hex(&input, &output);

    printf("Input: %s\n", input.text);
    printf("Output: %s\n", output.text);

    free(input.text);
    free(output.text);

    return 0;
}