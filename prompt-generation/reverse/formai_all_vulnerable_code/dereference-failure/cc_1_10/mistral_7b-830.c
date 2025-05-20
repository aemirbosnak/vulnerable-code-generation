//MISTRAL-7B DATASET v1.0 Category: Binary Converter ; Style: Donald Knuth
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    uintmax_t binary;
    size_t len;
} Binary;

void reverse(char *str, size_t len) {
    size_t i = 0, j = len - 1;
    char tmp;

    for (; i < len / 2; ++i, --j) {
        tmp = str[i];
        str[i] = str[j];
        str[j] = tmp;
    }
}

void itob(uintmax_t i, char *buf, size_t len) {
    size_t pos = len;

    while (i > 0) {
        --pos;
        buf[pos] = i % 2 + '0';
        i /= 2;
    }

    reverse(buf, len);
}

Binary fromDec(char *dec, size_t len) {
    uintmax_t num = 0;
    size_t i = 0;

    for (; i < len && isdigit(dec[i]); ++i) {
        num = num * 10 + (dec[i] - '0');
    }

    Binary ret = { num, i };
    return ret;
}

void printBinary(Binary b) {
    char buf[64];

    itob(b.binary, buf, b.len);
    printf("%s\n", buf);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <decimal number>\n", argv[0]);
        return 1;
    }

    Binary num = fromDec(argv[1], strlen(argv[1]) + 1);
    printBinary(num);

    return 0;
}