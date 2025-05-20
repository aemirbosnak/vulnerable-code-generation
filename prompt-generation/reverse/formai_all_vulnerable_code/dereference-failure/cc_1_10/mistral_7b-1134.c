//MISTRAL-7B DATASET v1.0 Category: Color Code Converter ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_COLOR 256

typedef struct {
    unsigned char r, g, b;
} rgb_t;

int hex_to_decimal(char c)
{
    if (isdigit(c))
        return c - '0';

    if (isalpha(c))
        return c - 'A' + 10;

    return -1;
}

int parse_color(char *str, rgb_t *color)
{
    char *end;
    int r, g, b;

    r = hex_to_decimal(*str++) << 4;
    r |= hex_to_decimal(*str++);

    g = hex_to_decimal(*str++) << 4;
    g |= hex_to_decimal(*str++);

    b = hex_to_decimal(*str++) << 4;
    b |= hex_to_decimal(*str++);

    if (*str != '\0') {
        fprintf(stderr, "Invalid color code: %s\n", str);
        return -1;
    }

    color->r = (unsigned char)r;
    color->g = (unsigned char)g;
    color->b = (unsigned char)b;

    return 0;
}

int main(int argc, char *argv[])
{
    rgb_t color;
    int i;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <color hex code>\n", argv[0]);
        return 1;
    }

    if (parse_color(argv[1], &color)) {
        fprintf(stderr, "Error: Invalid color code\n");
        return 1;
    }

    printf("RGB value for color code %s:\n", argv[1]);
    printf("R: %d, G: %d, B: %d\n", (int)color.r, (int)color.g, (int)color.b);

    for (i = 0; i < MAX_COLOR; i++) {
        rgb_t tmp;
        char str[8];

        sprintf(str, "%02X%02X%02X", (unsigned char)i >> 4, (unsigned char)i & 0x0F, (unsigned char)(i & 0xF0) >> 4);

        if (parse_color(str, &tmp)) {
            fprintf(stderr, "Error: Color code %06X is invalid\n", i);
            break;
        }

        if (color.r == tmp.r && color.g == tmp.g && color.b == tmp.b) {
            printf("Color code %06X is identical to %s\n", i, argv[1]);
            return 0;
        }
    }

    printf("Color code %s does not match any standard RGB value\n", argv[1]);

    return 1;
}