//LLAMA2-13B DATASET v1.0 Category: Compression algorithms ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN 1024

typedef struct {
    char *str;
    int len;
} string_t;

string_t *compress(string_t *input) {
    int i, j, k;
    char *output;
    int len = 0;

    // Step 1: Remove duplicate characters
    for (i = 0; i < input->len; i++) {
        char c = input->str[i];
        for (j = i + 1; j < input->len; j++) {
            if (c == input->str[j]) {
                input->str[len] = c;
                len++;
                break;
            }
        }
    }

    // Step 2: Remove leading and trailing whitespace
    for (i = 0; i < input->len; i++) {
        if (isspace(input->str[i])) {
            input->str[len] = input->str[i];
            len++;
        }
    }

    // Step 3: Compress runs of identical characters
    for (i = 0; i < input->len; i++) {
        char c = input->str[i];
        j = i + 1;
        while (j < input->len && c == input->str[j]) {
            j++;
        }
        input->str[len] = c;
        len += j - i;
    }

    // Step 4: Compress consecutive runs of identical characters
    for (i = 0; i < input->len; i++) {
        char c = input->str[i];
        j = i + 1;
        while (j < input->len && c == input->str[j]) {
            j++;
        }
        if (j > 1) {
            input->str[len] = c;
            len += j - 1;
        }
    }

    // Step 5: Compress the compressed data
    for (i = 0; i < len; i++) {
        char c = input->str[i];
        if (c == ' ' || c == '\t') {
            input->str[len] = c;
            len++;
        } else {
            input->str[len] = c;
            len++;
        }
    }

    output = calloc(1, len + 1);
    strcpy(output, input->str);
    free(input);
    return output;
}

int main() {
    string_t *input = malloc(sizeof(string_t));
    input->str = "The quick brown fox jumps over the lazy dog";
    input->len = strlen(input->str);

    string_t *compressed = compress(input);
    printf("Original string: %s\n", input->str);
    printf("Compressed string: %s\n", compressed->str);

    free(compressed);
    return 0;
}