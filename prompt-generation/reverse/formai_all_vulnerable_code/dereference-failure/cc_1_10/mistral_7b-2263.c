//MISTRAL-7B DATASET v1.0 Category: Color Code Converter ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define COLOR_RED "\033[1;31m"
#define COLOR_GREEN "\033[1;32m"
#define COLOR_YELLOW "\033[1;33m"
#define COLOR_BLUE "\033[1;34m"
#define COLOR_MAGENTA "\033[1;35m"
#define COLOR_CYAN "\033[1;36m"
#define COLOR_WHITE "\033[1;37m"
#define COLOR_RESET "\033[0m"

typedef struct {
    unsigned char r;
    unsigned char g;
    unsigned char b;
} RGB;

char* rgb_to_hex(RGB color) {
    char hex[3][3] = {"00", "0F", "1E", "2F", "3E", "4F", "5E", "6F", "7E", "8F", "9F", "AF", "BF", "CF"};
    char* hex_color = (char*) malloc(7 * sizeof(char));

    hex_color[0] = hex[color.r / 16][color.r % 16];
    hex_color[1] = hex[color.g / 16][color.g % 16];
    hex_color[2] = hex[color.b / 16][color.b % 16];
    hex_color[3] = hex[color.r / 16][color.r % 16];
    hex_color[4] = hex[color.g / 16][color.g % 16];
    hex_color[5] = hex[color.b / 16][color.b % 16];
    hex_color[6] = '\0';

    return hex_color;
}

void print_cyberpunk(RGB color) {
    printf(COLOR_CYAN);
    printf("R: %d, G: %d, B: %d\n", color.r, color.g, color.b);
    printf(COLOR_MAGENTA);
    printf("Hex: %s\n", rgb_to_hex(color));
    printf(COLOR_RESET);
}

int main(int argc, char* argv[]) {
    if (argc != 4) {
        printf("Usage: %s R G B\n", argv[0]);
        return 1;
    }

    RGB color;
    color.r = atoi(argv[1]);
    color.g = atoi(argv[2]);
    color.b = atoi(argv[3]);

    print_cyberpunk(color);

    return 0;
}