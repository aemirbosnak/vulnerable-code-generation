//MISTRAL-7B DATASET v1.0 Category: String manipulation ; Style: Claude Shannon
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define SWAP(a, b) do { char t = (a); (a) = (b); (b) = t; } while(0)

void reverse_string(char *str, int start, int end) {
    while (start < end) {
        SWAP(str[start], str[end]);
        start++;
        end--;
    }
}

void rotate_string_left(char *str, int num_rotations) {
    int len = strlen(str);
    char *start = str;
    char *end = str;

    if (num_rotations > len) {
        num_rotations %= len;
    }

    while (num_rotations--) {
        end += len;
        reverse_string(str, start, end - 1);
        start += len;
    }

    reverse_string(str, start, end);
}

void encode_hamming(char *str) {
    int i, parity = 0;

    for (i = 0; str[i] != '\0'; i++) {
        parity ^= (i & 0x1) ^ (str[i] & 0x1);
    }

    str[strlen(str)] = parity;
}

void decode_hamming(char *str) {
    int i, parity = str[strlen(str)];

    for (i = 0; str[i] != '\0'; i++) {
        if ((i & 0x1) && (str[i] != parity)) {
            printf("Error detected!\n");
            exit(1);
        }
        parity ^= str[i];
    }

    str[strlen(str)] = '\0';
}

int main(int argc, char **argv) {
    char str[128];
    int i, num_rotations;

    if (argc < 2) {
        printf("Usage: %s <string> [num_rotations]\n", argv[0]);
        return 1;
    }

    strcpy(str, argv[1]);

    if (argc > 2) {
        num_rotations = atoi(argv[2]);
        rotate_string_left(str, num_rotations);
    }

    encode_hamming(str);
    printf("Encoded string: %s\n", str);

    decode_hamming(str);
    printf("Decoded string: %s\n", str);

    return 0;
}