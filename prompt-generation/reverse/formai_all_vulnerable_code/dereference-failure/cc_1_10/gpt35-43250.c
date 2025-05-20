//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// function declarations
void poly_sub(const unsigned char *a, const unsigned char *b, unsigned char *out, size_t len);
size_t poly_mul(const unsigned char *a, const unsigned char *b, unsigned char *out, size_t len);

int main()
{
    // input parameters
    unsigned char a[16] = {0x21, 0x6d, 0x6f, 0x64, 0x72, 0x6f, 0x66, 0x66, 0x74, 0x69, 0x6f, 0x6e, 0x73, 0x65, 0x63, 0x72};
    unsigned char b[16] = {0x38, 0x4a, 0x4d, 0x4d, 0x56, 0x47, 0x33, 0x39, 0x5a, 0x4a, 0x6f, 0x5a, 0x78, 0x61, 0x49, 0x77};
    unsigned char c[16] = {0x00};

    // perform polynomial subtraction
    poly_sub(a, b, c, 16);

    // perform polynomial multiplication
    size_t len = poly_mul(a, b, c, 16);

    // print input and output values
    printf("Input a: ");
    for (int i = 0; i < 16; i++) {
        printf("%02x", a[i]);
    }
    printf("\n");

    printf("Input b: ");
    for (int i = 0; i < 16; i++) {
        printf("%02x", b[i]);
    }
    printf("\n");

    printf("Subtraction output c: ");
    for (int i = 0; i < 16; i++) {
        printf("%02x", c[i]);
    }
    printf("\n");

    printf("Multiplication output c: ");
    for (int i = 0; i < len; i++) {
        printf("%02x", c[i]);
    }
    printf("\n");

    return 0;
}

// function to subtract two polynomials
void poly_sub(const unsigned char *a, const unsigned char *b, unsigned char *out, size_t len)
{
    for (size_t i = 0; i < len; i++) {
        out[i] = a[i] ^ b[i];
    }
}

// function to multiply two polynomials
size_t poly_mul(const unsigned char *a, const unsigned char *b, unsigned char *out, size_t len)
{
    unsigned char temp[32] = {0};

    for (size_t i = 0; i < len; i++) {
        for (size_t j = 0; j < len; j++) {
            temp[i+j] ^= a[i] * b[j];
        }
    }

    size_t i;
    for (i = len*2-1; i > 0; i--) {
        if (temp[i]) {
            break;
        }
    }

    memcpy(out, temp, i+1);
    return i+1;
}