//LLAMA2-13B DATASET v1.0 Category: Compression algorithms ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1024
#define REPEAT_FACTOR 2

void compress(char *input, char *output);
void decompress(char *compressed, char *output);

int main() {
    char input[] = "The quick brown fox jumps over the lazy dog";
    char compressed[MAX_LEN];
    char output[MAX_LEN];

    compress(input, compressed);
    printf("Compressed string: %s\n", compressed);

    decompress(compressed, output);
    printf("Original string: %s\n", output);

    return 0;
}

void compress(char *input, char *output) {
    int i, j, repeat = 0;
    char last = '\0';

    for (i = 0; i < strlen(input); i++) {
        if (input[i] == last) {
            repeat++;
            if (repeat >= REPEAT_FACTOR) {
                output[j] = last;
                j++;
                repeat = 0;
            }
        } else {
            last = input[i];
            output[j] = last;
            j++;
        }
    }
    output[j] = '\0';
}

void decompress(char *compressed, char *output) {
    int i, j, repeat = 0;
    char last = '\0';

    for (i = 0; i < strlen(compressed); i++) {
        if (compressed[i] == last) {
            repeat++;
            if (repeat >= REPEAT_FACTOR) {
                output[j] = last;
                j++;
                repeat = 0;
            }
        } else {
            last = compressed[i];
            output[j] = last;
            j++;
        }
    }
    output[j] = '\0';
}