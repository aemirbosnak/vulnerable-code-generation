//GEMINI-pro DATASET v1.0 Category: Color Code Converter ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*
 * Convert a hex color string to RGB values.
 *
 * @param hex The hex color string to convert.
 * @param r The pointer to the red value.
 * @param g The pointer to the green value.
 * @param b The pointer to the blue value.
 */
void hex_to_rgb(char *hex, unsigned char *r, unsigned char *g, unsigned char *b) {
    char *p;
    int i;

    p = hex;
    for (i = 0; i < 3; i++) {
        *p = tolower(*p);
        if (*p >= '0' && *p <= '9') {
            *p -= '0';
        } else if (*p >= 'a' && *p <= 'f') {
            *p -= 'a' - 10;
        }
        p++;
    }

    *r = (*p << 4) + *p;
    *g = (*p << 4) + *p;
    *b = (*p << 4) + *p;
}

/*
 * Convert a RGB color values to a hex color string.
 *
 * @param r The red value.
 * @param g The green value.
 * @param b The blue value.
 * @return The hex color string.
 */
char *rgb_to_hex(unsigned char r, unsigned char g, unsigned char b) {
    char *hex;

    hex = malloc(7);
    sprintf(hex, "#%02x%02x%02x", r, g, b);

    return hex;
}

/*
 * Print the RGB and hex color codes.
 *
 * @param r The red value.
 * @param g The green value.
 * @param b The blue value.
 */
void print_color_codes(unsigned char r, unsigned char g, unsigned char b) {
    char *hex;

    hex = rgb_to_hex(r, g, b);
    printf("RGB: (%d, %d, %d)\n", r, g, b);
    printf("Hex: %s\n", hex);

    free(hex);
}

int main(int argc, char **argv) {
    unsigned char r, g, b;
    char *hex;

    if (argc == 2) {
        hex = argv[1];
        hex_to_rgb(hex, &r, &g, &b);
        print_color_codes(r, g, b);
    } else if (argc == 4) {
        r = atoi(argv[1]);
        g = atoi(argv[2]);
        b = atoi(argv[3]);
        print_color_codes(r, g, b);
    } else {
        printf("Usage: %s [hex color code] or %s [red] [green] [blue]\n", argv[0], argv[0]);
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}