//LLAMA2-13B DATASET v1.0 Category: Compression algorithms ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define N 1024

typedef struct {
    int freq[N];
    int len[N];
} fft_huffman_t;

fft_huffman_t* fft_huffman_init(void) {
    fft_huffman_t* h = malloc(sizeof(fft_huffman_t));
    for (int i = 0; i < N; i++) {
        h->freq[i] = 0;
        h->len[i] = 0;
    }
    return h;
}

void fft_huffman_free(fft_huffman_t* h) {
    free(h);
}

void fft_huffman_encode(fft_huffman_t* h, const char* str) {
    int i, j, k, len = strlen(str);
    for (i = 0; i < len; i++) {
        h->freq[str[i] - 'a']++;
    }
    for (i = 0; i < N; i++) {
        h->len[i] = 0;
    }
    for (j = 0; j < len; j++) {
        for (k = 0; k < N; k++) {
            if (h->freq[k] > 0) {
                h->len[k]++;
                break;
            }
        }
    }
}

void fft_huffman_decode(fft_huffman_t* h, char* str) {
    int i, j, k, len = strlen(str);
    for (i = 0; i < len; i++) {
        int c = str[i] - 'a';
        if (h->len[c] > 0) {
            h->len[c]--;
            str[i] = 'a' + c;
        }
    }
}

int main(void) {
    fft_huffman_t* h = fft_huffman_init();
    char str[] = "Hello World!";
    fft_huffman_encode(h, str);
    char* str_dec = malloc(sizeof(char) * strlen(str));
    fft_huffman_decode(h, str_dec);
    printf("Original: %s\n", str);
    printf("Encoded: %s\n", str_dec);
    free(str_dec);
    fft_huffman_free(h);
    return 0;
}