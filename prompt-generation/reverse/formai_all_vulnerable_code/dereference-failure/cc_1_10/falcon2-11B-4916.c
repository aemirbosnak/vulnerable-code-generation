//Falcon2-11B DATASET v1.0 Category: Compression algorithms ; Style: peaceful
#include <stdio.h>
#include <string.h>

char* compress(const char* str) {
    int len = strlen(str);
    char* compressed = (char*)malloc((len + 1) * sizeof(char));
    memset(compressed, 0, len + 1);
    int count = 1;
    int i = 0;
    while (i < len) {
        if (str[i] == str[i + 1]) {
            count++;
        } else {
            compressed[count - 1] = str[i];
            compressed[count] = '\0';
            count = 1;
        }
        i++;
    }
    compressed[count] = '\0';
    return compressed;
}

char* decompress(const char* compressed) {
    int len = strlen(compressed);
    char* decompressed = (char*)malloc((len + 1) * sizeof(char));
    memset(decompressed, 0, len + 1);
    int count = 0;
    int i = 0;
    while (i < len) {
        if (compressed[i] == '\0') {
            break;
        } else if (compressed[i] == '\n') {
            decompressed[count] = '\n';
            count++;
            i++;
        } else {
            decompressed[count] = compressed[i];
            decompressed[count + 1] = compressed[i + 1];
            count += 2;
        }
        i++;
    }
    decompressed[count] = '\0';
    return decompressed;
}

int main() {
    const char* str = "aabbccdd";
    const char* compressed = compress(str);
    printf("Compressed: %s\n", compressed);
    const char* decompressed = decompress(compressed);
    printf("Decompressed: %s\n", decompressed);
    free(compressed);
    free(decompressed);
    return 0;
}