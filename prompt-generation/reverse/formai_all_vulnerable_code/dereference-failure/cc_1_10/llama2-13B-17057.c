//LLAMA2-13B DATASET v1.0 Category: Compression algorithms ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1024
#define MASK 0x55555555

void compress(char *str) {
    int i, j, k, len = strlen(str);
    char *dst = malloc(len / 2 * sizeof(char));
    char *src = str;

    for (i = 0; i < len; i++) {
        if (src[i] == 'a' || src[i] == 'e' || src[i] == 'i' || src[i] == 'o' || src[i] == 'u') {
            j = i + 1;
            while (j < len && src[j] == 'a' || src[j] == 'e' || src[j] == 'i' || src[j] == 'o' || src[j] == 'u') {
                j++;
            }
            k = j - i;
            if (k > 2) {
                dst[i / 2] = (src[i] - 'a' + 'a') << 1;
                for (int m = 1; m < k; m++) {
                    dst[i / 2 + m] = (src[i + m] - 'a' + 'a') << 1;
                }
            } else {
                dst[i / 2] = src[i];
            }
            i += k;
        } else {
            dst[i / 2] = src[i];
        }
    }
    *(str = dst) = '\0';
}

void decompress(char *str) {
    int i, j, k, len = strlen(str);
    char *dst = malloc(len * sizeof(char));
    char *src = str;

    for (i = 0; i < len; i++) {
        if (src[i] & MASK) {
            j = i + 1;
            while (j < len && src[j] & MASK) {
                j++;
            }
            k = j - i;
            for (int m = 1; m < k; m++) {
                dst[i + m] = (src[i + m] & MASK) + 'a';
            }
        } else {
            dst[i] = src[i];
        }
    }
    *(str = dst) = '\0';
}

int main() {
    char str[] = "The quick brown fox jumps over the lazy dog";
    compress(str);
    printf("%s\n", str);
    decompress(str);
    printf("%s\n", str);
    return 0;
}