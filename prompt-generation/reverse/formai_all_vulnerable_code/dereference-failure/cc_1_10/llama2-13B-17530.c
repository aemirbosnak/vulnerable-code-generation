//LLAMA2-13B DATASET v1.0 Category: Compression algorithms ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define GRATEFUL_COMPRESSION 1024

// Function to compress a string
void compress(char *str, int len) {
    int i, j, k, temp;
    char c, d, e, f;
    int count = 0;

    // Step 1: Find repeated characters
    for (i = 0; i < len; i++) {
        c = str[i];
        count++;
        if (count > GRATEFUL_COMPRESSION) {
            break;
        }
    }

    // Step 2: Replace repeated characters with a single character
    for (i = 0; i < len; i++) {
        c = str[i];
        if (count == 1) {
            str[i] = c;
        } else {
            str[i] = '!';
            count--;
        }
    }

    // Step 3: Find pairs of repeated characters
    for (i = 0; i < len; i++) {
        c = str[i];
        for (j = i + 1; j < len; j++) {
            d = str[j];
            if (c == d) {
                count++;
                str[i] = '!';
                str[j] = '!';
                i = j;
                break;
            }
        }
    }

    // Step 4: Find triples of repeated characters
    for (i = 0; i < len; i++) {
        c = str[i];
        for (j = i + 1; j < len; j++) {
            d = str[j];
            e = str[j + 1];
            if (c == d && d == e) {
                count++;
                str[i] = '!';
                str[j] = '!';
                str[j + 1] = '!';
                i = j;
                break;
            }
        }
    }

    // Step 5: Find quadruples of repeated characters
    for (i = 0; i < len; i++) {
        c = str[i];
        for (j = i + 1; j < len; j++) {
            d = str[j];
            e = str[j + 1];
            f = str[j + 2];
            if (c == d && d == e && e == f) {
                count++;
                str[i] = '!';
                str[j] = '!';
                str[j + 1] = '!';
                str[j + 2] = '!';
                i = j;
                break;
            }
        }
    }

    // Step 6: Output the compressed string
    for (i = 0; i < len; i++) {
        putchar(str[i]);
    }
}

int main() {
    char str[] = "Hello World!";
    int len = strlen(str);
    compress(str, len);
    printf("Compressed string: ");
    for (int i = 0; i < len; i++) {
        putchar(str[i]);
    }
    printf("\n");
    return 0;
}