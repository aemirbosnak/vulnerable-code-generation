//Falcon2-11B DATASET v1.0 Category: Compression algorithms ; Style: dynamic
#include <stdio.h>
#include <string.h>

#define MAX_STRING_LEN 100

void compress(char *string, int max_length, int *compressed_len) {
    int i, j, k, l;
    int count = 1;
    int prev_char = '\0';
    int current_char;

    for (i = 0; i < max_length; i++) {
        current_char = string[i];

        if (current_char == prev_char) {
            count++;
        } else {
            compressed_len[k++] = current_char;
            compressed_len[k++] = count;
            count = 1;
            prev_char = current_char;
        }
    }

    compressed_len[k++] = prev_char;
    compressed_len[k++] = count;
}

void decompress(char *compressed_string, int *decompressed_len) {
    int i, j, k;
    int count;
    int current_char;

    for (i = 0; i < 2; i++) {
        current_char = compressed_string[i];
        count = compressed_string[i + 1];

        for (j = 0; j < count; j++) {
            decompressed_len[k++] = current_char;
        }
    }
}

int main() {
    char string[MAX_STRING_LEN] = "abcdefghijklmnopqrstuvwxyz";
    int compressed_len[MAX_STRING_LEN];
    int decompressed_len[MAX_STRING_LEN];

    compress(string, strlen(string), compressed_len);
    decompress(compressed_len, decompressed_len);

    printf("Compressed String: %s\n", string);
    printf("Decompressed String: %s\n", decompressed_len);

    return 0;
}