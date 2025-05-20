//MISTRAL-7B DATASET v1.0 Category: Color Code Converter ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

void rgb_to_hsv(float r, float g, float b, float *h, float *s, float *v) {
    float min, max, delta;

    min = (r < g) ? (r) : (g);
    min = (min < b) ? (min) : (b);

    max = (r > g) ? (r) : (g);
    max = (max > b) ? (max) : (b);

    *v = max;

    if (max == 0) {
        *h = 0;
        *s = 0;
        return;
    }

    delta = max - min;

    if (r == max) {
        *h = (g - b) / delta;
    } else if (g == max) {
        *h = 2.0 + (b - r) / delta;
    } else if (b == max) {
        *h = 4.0 + (r - g) / delta;
    }

    *h *= 60.0;

    if (*h < 0.0) {
        *h += 360.0;
    }

    if (r == g && g == b) {
        *s = 0.0;
    } else {
        *s = (delta / max) * 100.0;
    }
}

void hex_to_rgb(char hex[3], float *r, float *g, float *b) {
    hex[3] = '\0';

    if (strlen(hex) != 2) {
        printf("Invalid hex value.\n");
        exit(EXIT_FAILURE);
    }

    *r = strtoul(strchr(hex, '#') + 1, NULL, 16);
    *g = strtoul(strchr(hex, ':') + 1, NULL, 16);
    *b = strtoul(strchr(hex, ':') + 3, NULL, 16);
}

int main(int argc, char **argv) {
    char hex[MAX_LENGTH] = {0};
    float h, s, v, r, g, b;

    if (argc != 2) {
        printf("Usage: %s <HEX color code>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    strcpy(hex, argv[1]);

    hex_to_rgb(hex, &r, &g, &b);
    rgb_to_hsv(r, g, b, &h, &s, &v);

    printf("HSV representation of the color %s:\n", argv[1]);
    printf("Hue: %f\n", h);
    printf("Saturation: %f\n", s);
    printf("Value: %f\n", v);

    return EXIT_SUCCESS;
}