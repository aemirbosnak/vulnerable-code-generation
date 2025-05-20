//GEMINI-pro DATASET v1.0 Category: Binary Converter ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct {
    int base;
    int num_bits;
    char *digits;
} bcd_t;

bcd_t *bcd_create(int base, int num_bits, char *digits) {
    bcd_t *bcd = (bcd_t *)malloc(sizeof(bcd_t));
    if (!bcd) return NULL;
    bcd->base = base;
    bcd->num_bits = num_bits;
    bcd->digits = strdup(digits);
    return bcd;
}

void bcd_destroy(bcd_t *bcd) {
    if (!bcd) return;
    free(bcd->digits);
    free(bcd);
}

int bcd_to_int(bcd_t *bcd, char *str) {
    int value = 0;
    int len = strlen(str);
    for (int i = len - 1; i >= 0; i--) {
        int digit = str[i] - '0';
        if (digit < 0 || digit >= bcd->base) return -1;
        value += digit * pow(bcd->base, len - i - 1);
    }
    return value;
}

char *int_to_bcd(bcd_t *bcd, int value) {
    int len = (int)(log(value) / log(bcd->base)) + 1;
    char *str = (char *)malloc(len + 1);
    if (!str) return NULL;
    for (int i = len - 1; i >= 0; i--) {
        str[i] = bcd->digits[value % bcd->base];
        value /= bcd->base;
    }
    str[len] = '\0';
    return str;
}

int main(int argc, char **argv) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <base> <num_bits> <digits>\n", argv[0]);
        return EXIT_FAILURE;
    }
    int base = atoi(argv[1]);
    int num_bits = atoi(argv[2]);
    char *digits = argv[3];
    bcd_t *bcd = bcd_create(base, num_bits, digits);
    if (!bcd) {
        fprintf(stderr, "Error: could not create bcd\n");
        return EXIT_FAILURE;
    }
    char *str = "123";
    int value = bcd_to_int(bcd, str);
    if (value < 0) {
        fprintf(stderr, "Error: could not convert %s to an integer\n", str);
        bcd_destroy(bcd);
        return EXIT_FAILURE;
    }
    char *bcd_str = int_to_bcd(bcd, value);
    if (!bcd_str) {
        fprintf(stderr, "Error: could not convert %d to a bcd string\n", value);
        bcd_destroy(bcd);
        return EXIT_FAILURE;
    }
    printf("%s\n", bcd_str);
    free(bcd_str);
    bcd_destroy(bcd);
    return EXIT_SUCCESS;
}