//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_CODE_LENGTH 7
#define HEX_DIGITS "0123456789ABCDEF"

enum {
    COLOR_RED = 31,
    COLOR_GREEN = 32,
    COLOR_YELLOW = 33,
    COLOR_BLUE = 34,
    COLOR_MAGENTA = 35,
    COLOR_CYAN = 36,
    COLOR_WHITE = 37
};

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <color_code>\n", argv[0]);
        exit(1);
    }

    char *color_code = argv[1];
    int code_length = strlen(color_code);

    if (code_length!= MAX_CODE_LENGTH) {
        printf("Invalid color code\n");
        exit(1);
    }

    int color = 0;

    for (int i = 0; i < code_length; i++) {
        char c = toupper(color_code[i]);

        if (c >= '0' && c <= '9') {
            color = (color * 10) + (c - '0');
        } else if (c >= 'A' && c <= 'F') {
            color = (color * 16) + (c - 'A');
        } else {
            printf("Invalid color code\n");
            exit(1);
        }
    }

    printf("Color code %s is equivalent to ANSI escape sequence %c[1;%dm\n", argv[1], COLOR_WHITE, color);

    return 0;
}