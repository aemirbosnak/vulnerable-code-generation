//FormAI DATASET v1.0 Category: Compression algorithms ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Compression function
char* compress(char* str) {
    int i, j, count;
    char* compressed = (char*) malloc(strlen(str) * sizeof(char));
    int len = strlen(str);

    for (i = 0, j = 0; i < len; i++) {
        count = 1;
        while (i + 1 < len && str[i] == str[i + 1]) {
            count++;
            i++;
        }
        if (count == 1) {
            compressed[j++] = str[i];
        } else if (count > 1) {
            compressed[j++] = count + '0';
            compressed[j++] = str[i];
        }
    }
    compressed[j] = '\0';
    return compressed;
}

// Decompression function
char* decompress(char* str) {
    int i, j, k, num;
    char* decompressed = (char*) malloc(strlen(str) * sizeof(char));
    int len = strlen(str);

    for (i = 0, j = 0; i < len; i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            num = str[i] - '0';
            for (k = 0; k < num; k++) {
                decompressed[j++] = str[i + 1];
            }
            i++;
        } else {
            decompressed[j++] = str[i];
        }
    }
    decompressed[j] = '\0';
    return decompressed;
}

int main() {
    char str[100], *compressed, *decompressed;
    printf("Enter a string to compress: ");
    scanf("%[^\n]s", str);

    compressed = compress(str);
    printf("Compressed string: %s\n", compressed);

    decompressed = decompress(compressed);
    printf("Decompressed string: %s\n", decompressed);

    free(compressed);
    free(decompressed);
    return 0;
}