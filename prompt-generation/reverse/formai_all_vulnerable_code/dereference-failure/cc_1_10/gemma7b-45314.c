//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: automated
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1024

void compress(char **buf, int *size) {
    int i, j, k, count = 0, runLength = 1;
    char previousChar = '\0';

    for (i = 0; i < *size; i++) {
        if (previousChar == buf[i]) {
            runLength++;
        } else {
            if (runLength > 1) {
                buf[k++] = (runLength - 1) + 'a';
            }
            previousChar = buf[i];
            runLength = 1;
        }
    }

    *size = k + 1;
    return;
}

int main() {
    char *buf = malloc(MAX_SIZE);
    int size = MAX_SIZE;

    // Sample data
    buf[0] = 'a';
    buf[1] = 'a';
    buf[2] = 'b';
    buf[3] = 'b';
    buf[4] = 'c';
    buf[5] = 'c';
    buf[6] = 'c';
    buf[7] = 'd';

    compress(&buf, &size);

    printf("Compressed size: %d\n", size);

    // Print compressed data
    for (int i = 0; i < size; i++) {
        printf("%c ", buf[i]);
    }

    free(buf);

    return 0;
}