//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_COLOR_CODE_LENGTH 7
#define MAX_COLOR_NAME_LENGTH 20

typedef struct {
    char *color_name;
    char *color_code;
} ColorCode;

ColorCode color_codes[] = {
    {"black", "\033[0;30m"},
    {"red", "\033[0;31m"},
    {"green", "\033[0;32m"},
    {"yellow", "\033[0;33m"},
    {"blue", "\033[0;34m"},
    {"purple", "\033[0;35m"},
    {"cyan", "\033[0;36m"},
    {"white", "\033[0;37m"},
    {"reset", "\033[0m"}
};

int num_color_codes = sizeof(color_codes) / sizeof(ColorCode);

int main(int argc, char **argv) {
    char *input_string;
    char *color_code;
    int input_length;
    int color_code_length;
    int i;

    printf("Enter a string: ");
    fgets(input_string, MAX_COLOR_CODE_LENGTH, stdin);
    input_length = strlen(input_string);

    if (input_string[input_length - 1] == '\n') {
        input_string[input_length - 1] = '\0';
    }

    for (i = 0; i < num_color_codes; i++) {
        color_code = color_codes[i].color_code;
        color_code_length = strlen(color_code);

        while ((input_length - color_code_length) >= 0) {
            if (strncmp(input_string, color_code, color_code_length) == 0) {
                printf("Color code found: %s\n", color_codes[i].color_name);
                break;
            }

            input_string += color_code_length;
            input_length -= color_code_length;
        }
    }

    return 0;
}