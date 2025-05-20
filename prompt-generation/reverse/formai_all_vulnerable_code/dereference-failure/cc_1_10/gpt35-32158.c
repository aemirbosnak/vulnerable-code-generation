//FormAI DATASET v1.0 Category: Compression algorithms ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void compress(char* src, char* dest)
{
    int len = strlen(src);
    int count = 1, index = 0;
    char c = src[0];
    int i;
    for(i = 1; i < len; i++) {
        if(src[i] == c) {
            count++;
        }
        else {
            dest[index++] = c;
            dest[index++] = count + '0';
            c = src[i];
            count = 1;
        }
    }
    dest[index++] = c;
    dest[index++] = count + '0';
    dest[index] = '\0';
}

void decompress(char* src, char* dest)
{
    int len = strlen(src);
    int index = 0, i;
    for(i = 0; i < len; i += 2) {
        char c = src[i];
        int count = src[i+1] - '0';
        int j;
        for(j = 0; j < count; j++, index++) {
            dest[index] = c;
        }
    }
    dest[index] = '\0';
}

int main()
{
    char* src = "aaabbbbbcccee";
    char* compressed = malloc(2*strlen(src) + 1);
    compress(src, compressed);
    printf("Compressed: %s\n", compressed);
    char* decompressed = malloc(strlen(src) + 1);
    decompress(compressed, decompressed);
    printf("Decompressed: %s\n", decompressed);

    free(compressed);
    free(decompressed);
    return 0;
}