//LLAMA2-13B DATASET v1.0 Category: Compression algorithms ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAX_LEN 1024
#define DEF_LEN 256
#define REPEAT_THRESH 4

typedef struct {
    char *data;
    int len;
} compress_data_t;

compress_data_t *compress(char *data, int len) {
    compress_data_t *cd;
    int i, j, repeat_count;
    char *ptr, *temp;

    if (len <= DEF_LEN) {
        return (compress_data_t *)calloc(1, sizeof(compress_data_t));
    }

    cd = (compress_data_t *)calloc(1, sizeof(compress_data_t));
    cd->data = (char *)malloc(MAX_LEN);
    cd->len = 0;

    ptr = data;
    repeat_count = 0;

    while (ptr < data + len) {
        if (*ptr == 'a' || *ptr == 'e' || *ptr == 'i' || *ptr == 'o' || *ptr == 'u') {
            repeat_count++;
            ptr++;
            continue;
        }

        if (repeat_count > REPEAT_THRESH) {
            for (i = 0; i < repeat_count; i++) {
                cd->data[cd->len++] = *ptr++;
            }
            repeat_count = 0;
        }
    }

    if (repeat_count > 0) {
        for (i = 0; i < repeat_count; i++) {
            cd->data[cd->len++] = *ptr++;
        }
    }

    temp = cd->data;
    for (i = 0; i < cd->len; i++) {
        if (temp[i] == 'a' || temp[i] == 'e' || temp[i] == 'i' || temp[i] == 'o' || temp[i] == 'u') {
            temp[i] = '4';
        }
    }

    return cd;
}

int main() {
    char data[] = "The quick brown fox jumps over the lazy dog";
    compress_data_t *cd;
    int len;

    cd = compress(data, strlen(data));
    len = strlen(cd->data);

    printf("Compressed data: %s\n", cd->data);
    free(cd->data);
    free(cd);

    return 0;
}