//LLAMA2-13B DATASET v1.0 Category: Compression algorithms ; Style: brave
// Brave Compression Algorithm - BCA

#include <stdio.h>
#include <string.h>

#define BCA_MAX_LEN 1024

// Brave Compression Struct
typedef struct {
    char *text;
    int len;
} bca_struct;

// Brave Compression Functions

// Compress Function
void bca_compress(bca_struct *text) {
    int i, j, k, l;
    char c, d, e;
    int count = 0;

    // Step 1: Sliding Window of 3 Characters
    for (i = 0; i < text->len - 2; i++) {
        c = text->text[i];
        d = text->text[i + 1];
        e = text->text[i + 2];

        // Step 2: Find Most Frequent Character
        if (count < 3) {
            count++;
            continue;
        }

        // Step 3: Replace with Single Character
        if (c == d && d == e) {
            text->text[i] = c;
            text->len--;
            count = 0;
        }
    }

    // Step 4: Huffman Coding
    for (i = 0; i < text->len; i++) {
        if (count == 0) {
            count++;
            continue;
        }

        j = i - count + 1;
        k = i + count - 1;
        l = count - 1;

        // Huffman Code
        text->text[j] = '0' + (l * 2);
        text->text[k] = '1' + (l * 2);
    }
}

// Decompress Function
void bca_decompress(bca_struct *text) {
    int i, j, k, l;
    char c, d, e;
    int count = 0;

    // Step 1: Huffman Decoding
    for (i = 0; i < text->len; i++) {
        c = text->text[i];

        if (c >= '0' && c <= '9') {
            count = (c - '0') * 2;
        } else if (c >= 'a' && c <= 'z') {
            count = (c - 'a') * 2 + 10;
        } else {
            count = -1;
            break;
        }

        if (count < 0) {
            break;
        }

        j = i - count + 1;
        k = i + count - 1;
        l = count - 1;

        // Step 2: Replace with Original Character
        text->text[j] = text->text[k];
        text->text[k] = ' ';
        text->len--;
        count = 0;
    }
}

int main() {
    bca_struct text;
    text.text = "Hello World!";
    text.len = strlen(text.text);

    // Compress
    bca_compress(&text);

    // Decompress
    bca_decompress(&text);

    printf("Original: %s\n", text.text);
    printf("Compressed: %s\n", text.text);
    printf("Decompressed: %s\n", text.text);

    return 0;
}