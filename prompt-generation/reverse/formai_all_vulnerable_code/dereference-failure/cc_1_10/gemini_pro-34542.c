//GEMINI-pro DATASET v1.0 Category: Compression algorithms ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *data;
    int length;
} String;

String *compress(String *input) {
    String *output = malloc(sizeof(String));
    output->data = malloc(sizeof(char) * input->length);
    output->length = 0;

    int count = 1;
    for (int i = 0; i < input->length - 1; i++) {
        if (input->data[i] == input->data[i + 1]) {
            count++;
        } else {
            output->data[output->length++] = input->data[i];
            if (count > 1) {
                output->data[output->length++] = '0' + count;
                count = 1;
            }
        }
    }

    if (count > 1) {
        output->data[output->length++] = input->data[input->length - 1];
        output->data[output->length++] = '0' + count;
    }

    return output;
}

String *decompress(String *input) {
    String *output = malloc(sizeof(String));
    output->data = malloc(sizeof(char) * input->length * 2);
    output->length = 0;

    int count = 0;
    for (int i = 0; i < input->length; i++) {
        if (input->data[i] >= '0' && input->data[i] <= '9') {
            count = input->data[i] - '0';
        } else {
            for (int j = 0; j < count; j++) {
                output->data[output->length++] = input->data[i];
            }
            count = 0;
        }
    }

    return output;
}

int main() {
    String *input = malloc(sizeof(String));
    input->data = "AAAAABBBCCCDDEEEFFGGHHIIJJJKKKLLLLMMMMNNNOOOPPPQQQRRRRSSSSTTTUUUVVVWWWXXXYYYZZZ";
    input->length = strlen(input->data);

    printf("Input: %s\n", input->data);

    String *compressed = compress(input);
    printf("Compressed: %s\n", compressed->data);

    String *decompressed = decompress(compressed);
    printf("Decompressed: %s\n", decompressed->data);

    free(input->data);
    free(input);
    free(compressed->data);
    free(compressed);
    free(decompressed->data);
    free(decompressed);

    return 0;
}