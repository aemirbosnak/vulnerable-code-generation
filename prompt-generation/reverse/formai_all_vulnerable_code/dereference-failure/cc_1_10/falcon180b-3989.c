//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_LINE_LENGTH 1000
#define MAX_NUM_LENGTH 64
#define MAX_NUM_DIGITS 1000

typedef struct {
    char *value;
    int base;
} number_t;

number_t *parse_number(const char *str, int base) {
    number_t *num = malloc(sizeof(number_t));
    num->value = strdup(str);
    num->base = base;
    return num;
}

char *itoa(int value, char *buffer, int base) {
    char *ptr = buffer + strlen(buffer);
    do {
        *--ptr = "0123456789ABCDEF"[value % base];
        value /= base;
    } while (value > 0);
    return buffer;
}

char *ltoa(long value, char *buffer, int base) {
    char *ptr = buffer + strlen(buffer);
    do {
        *--ptr = "0123456789ABCDEF"[value % base];
        value /= base;
    } while (value > 0);
    return buffer;
}

void print_number(const number_t *num, int base) {
    printf("Base %d: %s\n", num->base, num->value);
}

int main() {
    char line[MAX_LINE_LENGTH];
    char *buffer;
    char *token;
    number_t *num;
    int base;

    printf("Enter a binary number: ");
    fgets(line, MAX_LINE_LENGTH, stdin);
    buffer = strtok_r(line, " \t\r\n", &token);

    if (buffer[0] == '0' && buffer[1] == 'b') {
        base = 2;
        buffer += 2;
    } else if (buffer[0] == '0' && buffer[1] == 'x') {
        base = 16;
        buffer += 2;
    } else {
        base = 10;
    }

    num = parse_number(buffer, base);
    print_number(num, base);

    free(num->value);
    free(num);

    return 0;
}