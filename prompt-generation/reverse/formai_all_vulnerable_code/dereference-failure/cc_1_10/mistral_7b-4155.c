//MISTRAL-7B DATASET v1.0 Category: Color Code Converter ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SIZE 100

typedef struct {
    char r[3];
    char g[3];
    char b[3];
} RGB;

void convertRGBToHex(RGB rgb) {
    char hex[7][3] = {"00", "01", "02", "03", "04", "05", "06"};
    int i, j;

    printf("%s", "#");
    for (i = 0; i < 3; i++) {
        j = (rgb.r[i] & 0xF0) >> 4;
        printf("%s%s", hex[j], hex[rgb.r[i] & 0xF]);

        j = (rgb.g[i] & 0xF0) >> 4;
        printf("%s%s", hex[j], hex[rgb.g[i] & 0xF]);

        j = (rgb.b[i] & 0xF0) >> 4;
        printf("%s%s", hex[j], hex[rgb.b[i] & 0xF]);

        if (i < 2)
            printf(":");
    }
    printf("\n");
}

RGB stringToRGB(char *str) {
    RGB rgb;
    int i, len = strlen(str);

    if (str[0] != '#' || len != 7) {
        printf("Invalid color code!\n");
        exit(1);
    }

    for (i = 0; i < 3; i++) {
        rgb.r[i] = str[i * 2 + 1];
        rgb.g[i] = str[i * 2 + 3];
        rgb.b[i] = str[i * 2 + 5];
    }

    for (i = 0; i < 3; i++) {
        rgb.r[i] = (isdigit(rgb.r[i]) ? rgb.r[i] - '0' : toupper(rgb.r[i]) - 'A' + 10);
        rgb.g[i] = (isdigit(rgb.g[i]) ? rgb.g[i] - '0' : toupper(rgb.g[i]) - 'A' + 10);
        rgb.b[i] = (isdigit(rgb.b[i]) ? rgb.b[i] - '0' : toupper(rgb.b[i]) - 'A' + 10);
    }

    return rgb;
}

int main(int argc, char **argv) {
    char str[SIZE];
    RGB rgb;

    if (argc != 2) {
        printf("Usage: %s <color code>\n", argv[0]);
        return 1;
    }

    strcpy(str, argv[1]);
    rgb = stringToRGB(str);
    convertRGBToHex(rgb);

    return 0;
}