//FormAI DATASET v1.0 Category: Color Code Converter ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LEN 10

char* convert_color(char*);
char* hex_to_rgb(char*);
char* rgb_to_hex(char*);

int main() {
    char input[MAX_INPUT_LEN];
    char* color_code;

    printf("Enter a color code (hex or rgb): ");
    fgets(input, MAX_INPUT_LEN, stdin);
    input[strcspn(input, "\n")] = 0; // remove newline character

    color_code = convert_color(input);

    printf("Converted color code: %s\n", color_code);

    free(color_code);
    return 0;
}

char* convert_color(char* color_code) {
    char* converted_code;

    if (strlen(color_code) == 7 && color_code[0] == '#') { // hex to rgb
        converted_code = hex_to_rgb(color_code);
    } else if (strlen(color_code) == 12 && color_code[3] == ',' && color_code[7] == ',') { // rgb to hex
        converted_code = rgb_to_hex(color_code);
    } else { // invalid color code
        converted_code = malloc(sizeof(char) * 14);
        strcpy(converted_code, "Invalid input");
    }

    return converted_code;
}

char* hex_to_rgb(char* hex_code) {
    char* rgb_code = malloc(sizeof(char) * 16);

    int r, g, b;
    sscanf(hex_code, "#%02x%02x%02x", &r, &g, &b);

    sprintf(rgb_code, "rgb(%d,%d,%d)", r, g, b);

    return rgb_code;
}

char* rgb_to_hex(char* rgb_code) {
    char* hex_code = malloc(sizeof(char) * 8);

    int r, g, b;
    sscanf(rgb_code, "rgb(%d,%d,%d)", &r, &g, &b);

    sprintf(hex_code, "#%02x%02x%02x", r, g, b);

    return hex_code;
}