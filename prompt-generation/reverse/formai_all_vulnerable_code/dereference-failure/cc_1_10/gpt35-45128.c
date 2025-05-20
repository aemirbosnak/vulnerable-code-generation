//FormAI DATASET v1.0 Category: Compression algorithms ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* compress(char* input) {
    int length = strlen(input);
    char* output = (char*) malloc(sizeof(char) * (length + 1));
    int i = 0, j = 0, count;

    while (i < length) {
        count = 1;
        while ((i + count) < length && input[i] == input[i + count])
            count++;
        if (count > 1) {
            output[j++] = count + '0';
            output[j++] = input[i];
            i += count;
        } else {
            output[j++] = input[i++];
        }
    }
    output[j] = '\0';

    return output;
}

char* decompress(char* input) {
    int length = strlen(input);
    char* output = (char*) malloc(sizeof(char) * (length + 1));
    int i = 0, j = 0, count;

    while (i < length) {
        if (input[i] >= '2' && input[i] <= '9') {
            count = input[i] - '0';
            while (count--)
                output[j++] = input[i + 1];
            i += 2;
        } else {
            output[j++] = input[i++];
        }
    }
    output[j] = '\0';

    return output;
}

int main() {
    char* input = "aabcccccaaa";
    char* compressed = compress(input);
    printf("Compressed: %s\n", compressed);
    char* decompressed = decompress(compressed);
    printf("Decompressed: %s\n", decompressed);
    free(compressed);
    free(decompressed);

    return 0;
}