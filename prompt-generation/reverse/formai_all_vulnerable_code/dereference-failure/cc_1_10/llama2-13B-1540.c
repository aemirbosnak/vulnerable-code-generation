//LLAMA2-13B DATASET v1.0 Category: Compression algorithms ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1024

// Compression algorithm: reversible hash table with offset encoding

typedef struct {
    char *data; // original data
    int len; // original data length
    char *hash; // reversible hash table
    int hlen; // reversible hash table length
    int off; // offset encoding
} compression_data_t;

void compression_init(compression_data_t *cd) {
    cd->hash = (char *)calloc(1, MAX_LEN * 2);
    cd->hlen = 0;
    cd->off = 0;
}

void compression_free(compression_data_t *cd) {
    free(cd->hash);
}

int compression_encode(compression_data_t *cd, const char *data, int len) {
    int i, j, k;
    for (i = 0; i < len; i++) {
        // calculate hash value for current character
        int h = data[i] + (cd->off << 1);
        // store hash value in hash table
        for (j = 0; j < cd->hlen; j++) {
            if (cd->hash[j] == h) {
                // found match, use offset encoding
                k = j * 2 + cd->off;
                break;
            }
        }
        // not found, add new entry to hash table
        if (j == cd->hlen) {
            cd->hlen++;
            cd->hash = realloc(cd->hash, cd->hlen * 2);
            cd->hash[j] = h;
            k = j * 2 + cd->off;
        }
        // encode character using offset encoding
        cd->data[i] = (char)k;
    }
    return len;
}

int compression_decode(compression_data_t *cd, char *data, int len) {
    int i, j, k;
    for (i = 0; i < len; i++) {
        // decode character using offset encoding
        k = cd->data[i] & 1;
        if (k) {
            // use previous character's hash value as offset
            j = (cd->data[i - 1] >> 1) + cd->off;
        } else {
            // use current character's hash value as offset
            j = cd->hash[cd->data[i] >> 1] + cd->off;
        }
        // calculate actual position in original data
        k = j * 2 + cd->off;
        data[i] = (char)k;
    }
    return len;
}

int main() {
    compression_data_t cd;
    char original[] = "Hello World!";
    char compressed[MAX_LEN];
    int len;

    compression_init(&cd);
    len = compression_encode(&cd, original, strlen(original));
    compression_free(&cd);

    compression_init(&cd);
    len = compression_decode(&cd, compressed, len);
    compression_free(&cd);

    printf("Original: %s\n", original);
    printf("Compressed: %s\n", compressed);

    return 0;
}