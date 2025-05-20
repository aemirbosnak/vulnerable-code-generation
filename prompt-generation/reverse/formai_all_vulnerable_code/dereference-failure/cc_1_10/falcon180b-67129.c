//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1000
#define MAX_CODE_LENGTH 7
#define ERROR_MSG "Error: Invalid input. Please try again.\n"
#define SUCCESS_MSG "Success: %s\n"

void print_help(void) {
    printf("Usage:./program [OPTION] [COLOR_CODE]\n");
    printf("Options:\n");
    printf("  -h, --help\t\tDisplay this help message\n");
    printf("  -v, --version\t\tDisplay version information\n");
    printf("  -c, --convert\t\tConvert a color code\n");
}

void print_version(void) {
    printf("Color Code Converter v1.0\n");
}

int is_valid_color_code(char* code) {
    int i;
    for (i = 0; i < strlen(code); i++) {
        if (!isdigit(code[i]) && code[i]!= '#') {
            return 0;
        }
    }
    return 1;
}

void convert_color_code(char* code) {
    int red, green, blue;
    if (strlen(code)!= MAX_CODE_LENGTH) {
        printf(ERROR_MSG);
        return;
    }
    if (code[0]!= '#') {
        printf(ERROR_MSG);
        return;
    }
    sscanf(code, "#%02x%02x%02x", &red, &green, &blue);
    printf(SUCCESS_MSG, code);
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        print_help();
        return 1;
    }
    if (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0) {
        print_help();
        return 0;
    } else if (strcmp(argv[1], "-v") == 0 || strcmp(argv[1], "--version") == 0) {
        print_version();
        return 0;
    } else if (strcmp(argv[1], "-c") == 0 || strcmp(argv[1], "--convert") == 0) {
        if (argc!= 3) {
            printf(ERROR_MSG);
            return 1;
        }
        convert_color_code(argv[2]);
        return 0;
    } else {
        printf(ERROR_MSG);
        return 1;
    }
}