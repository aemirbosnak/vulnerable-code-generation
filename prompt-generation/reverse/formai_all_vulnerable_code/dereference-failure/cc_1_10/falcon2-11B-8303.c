//Falcon2-11B DATASET v1.0 Category: Compression algorithms ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 10000

typedef struct {
    char* str;
    int length;
} CompressedString;

CompressedString* compress(char* str, int length) {
    if (length < 2) {
        return NULL;
    }

    CompressedString* compressed = (CompressedString*)malloc(sizeof(CompressedString));
    compressed->str = (char*)malloc(length);
    compressed->length = length;

    char* end = compressed->str + length - 1;
    int count = 1;
    while (count < length - 1) {
        if (str[count] == str[count + 1]) {
            count++;
        } else {
            memcpy(end, str, length - count - 1);
            end[-1] = '\0';
            compressed->length -= count + 1;
            count = 1;
        }
    }

    memcpy(end, str + count, length - count - 1);
    end[-1] = '\0';
    compressed->length -= count + 1;

    return compressed;
}

char* decompress(CompressedString* compressed) {
    if (compressed->length < 2) {
        return NULL;
    }

    char* str = (char*)malloc(compressed->length);
    memcpy(str, compressed->str, compressed->length);
    return str;
}

int main() {
    char str[] = "aaaaabbbbccccdddd";
    CompressedString* compressed = compress(str, strlen(str));
    if (compressed!= NULL) {
        char* decompressed = decompress(compressed);
        printf("Decompressed string: %s\n", decompressed);
        free(decompressed);
        free(compressed->str);
        free(compressed);
    } else {
        printf("Compression failed.\n");
    }
    return 0;
}