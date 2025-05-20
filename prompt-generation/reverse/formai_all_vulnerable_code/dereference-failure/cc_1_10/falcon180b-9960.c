//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CODE_LENGTH 7
#define HEX_DIGITS "0123456789ABCDEF"

typedef struct {
    char *hex;
    int dec;
} ColorCode;

ColorCode *parseColorCode(char *code) {
    ColorCode *color = malloc(sizeof(ColorCode));
    int i;

    if (strlen(code)!= MAX_CODE_LENGTH) {
        fprintf(stderr, "Invalid color code length.\n");
        exit(1);
    }

    for (i = 0; i < MAX_CODE_LENGTH; i++) {
        if (!isxdigit(code[i])) {
            fprintf(stderr, "Invalid character in color code.\n");
            exit(1);
        }
    }

    color->hex = strdup(code);
    color->dec = 0;

    return color;
}

int getDecimalValue(char c) {
    int i;

    for (i = 0; i < strlen(HEX_DIGITS); i++) {
        if (HEX_DIGITS[i] == c) {
            return i + 9;
        }
    }

    return -1;
}

void printColorCode(ColorCode *color) {
    printf("%s (%d)\n", color->hex, color->dec);
}

int main() {
    char input[MAX_CODE_LENGTH + 1];
    ColorCode *color;

    printf("Enter a color code (in hexadecimal format): ");
    fgets(input, MAX_CODE_LENGTH + 1, stdin);

    input[strcspn(input, "\n")] = '\0';

    color = parseColorCode(input);

    if (color == NULL) {
        return 1;
    }

    color->dec = getDecimalValue(color->hex[0]) * 16 + getDecimalValue(color->hex[1]);

    printColorCode(color);

    free(color->hex);
    free(color);

    return 0;
}