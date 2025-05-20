//MISTRAL-7B DATASET v1.0 Category: Color Code Converter ; Style: single-threaded
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_COLOR_CODE_LENGTH 7

typedef struct {
    char r;
    char g;
    char b;
} ColorCode;

void decodeColorCode(char* colorCode) {
    ColorCode result;
    if (sscanf(colorCode, "%c%c%c", &result.r, &result.g, &result.b) != 3) {
        printf("Invalid color code: %s\n", colorCode);
        return;
    }

    result.r = (isdigit(result.r) ? result.r - '0' : toupper(result.r) - 'A' + 10);
    result.g = (isdigit(result.g) ? result.g - '0' : toupper(result.g) - 'A' + 10);
    result.b = (isdigit(result.b) ? result.b - '0' : toupper(result.b) - 'A' + 10);

    printf("Decoded color code: RGB(%d, %d, %d)\n", result.r, result.g, result.b);
}

int main(int argc, char** argv) {
    int i;

    if (argc < 2) {
        printf("Usage: %s <color code>\n", argv[0]);
        return 1;
    }

    char* colorCode = argv[1];

    if (strlen(colorCode) > MAX_COLOR_CODE_LENGTH) {
        printf("Error: Color code too long\n");
        return 1;
    }

    decodeColorCode(colorCode);

    for (i = 2; i < argc; i++) {
        printf("Ignoring additional arguments: %s\n", argv[i]);
    }

    return 0;
}