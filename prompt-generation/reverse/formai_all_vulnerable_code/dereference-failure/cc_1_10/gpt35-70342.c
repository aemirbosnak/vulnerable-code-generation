//FormAI DATASET v1.0 Category: Color Code Converter ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void hex_to_rgb(char hex[], int *r, int *g, int *b) {
    char r_hex[3], g_hex[3], b_hex[3];

    r_hex[0] = hex[0];
    r_hex[1] = hex[1];
    r_hex[2] = '\0';
    g_hex[0] = hex[2];
    g_hex[1] = hex[3];
    g_hex[2] = '\0';
    b_hex[0] = hex[4];
    b_hex[1] = hex[5];
    b_hex[2] = '\0';

    *r = strtol(r_hex, NULL, 16);
    *g = strtol(g_hex, NULL, 16);
    *b = strtol(b_hex, NULL, 16);
}

void rgb_to_hex(int r, int g, int b, char hex[]) {
    sprintf(hex, "%02X%02X%02X", r, g, b);
}

void print_help() {
    printf("Usage: color-converter [hex|rgb] <value>\n");
    printf("\n");
    printf("Converts between hexadecimal and RGB color codes.\n");
    printf("\n");
    printf("Options:\n");
    printf("  hex <value>: Converts hexadecimal color code in the format RRGGBB to RGB color code values.\n");
    printf("  rgb <value>: Converts RGB color code values to hexadecimal color code in the format RRGGBB.\n");
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        print_help();
        return EXIT_FAILURE;
    }

    if (strcmp(argv[1], "hex") == 0) {
        char *hex = argv[2];
        int r, g, b;
        hex_to_rgb(hex, &r, &g, &b);
        printf("RGB: %d, %d, %d\n", r, g, b);
    } else if (strcmp(argv[1], "rgb") == 0) {
        int r, g, b;
        char hex[7];
        r = atoi(argv[2]);
        g = atoi(argv[3]);
        b = atoi(argv[4]);
        rgb_to_hex(r, g, b, hex);
        printf("HEX: %s\n", hex);
    } else {
        print_help();
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}