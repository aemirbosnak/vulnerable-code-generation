//Falcon2-11B DATASET v1.0 Category: Color Code Converter ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <color code>\n", argv[0]);
        exit(1);
    }
    
    char *color_code = argv[1];
    int length = strlen(color_code);
    
    if (length!= 6) {
        printf("Invalid color code length.\n");
        exit(1);
    }
    
    char hex_digits[6];
    for (int i = 0; i < 6; i++) {
        hex_digits[i] = color_code[i];
        if (isdigit(hex_digits[i])) {
            continue;
        } else if (isupper(hex_digits[i])) {
            hex_digits[i] -= 'A' - '0';
        } else {
            printf("Invalid color code.\n");
            exit(1);
        }
    }
    
    printf("Color code: %s\n", color_code);
    printf("Hexadecimal digits: %s\n", hex_digits);
    
    char *red, *green, *blue;
    red = malloc(3 * sizeof(char));
    green = malloc(3 * sizeof(char));
    blue = malloc(3 * sizeof(char));
    if (red == NULL || green == NULL || blue == NULL) {
        printf("Failed to allocate memory.\n");
        exit(1);
    }
    
    int red_value = 0, green_value = 0, blue_value = 0;
    for (int i = 0; i < 3; i++) {
        red_value += hex_digits[i * 2] * 16 + hex_digits[i * 2 + 1];
        green_value += hex_digits[(i + 1) * 2] * 16 + hex_digits[(i + 1) * 2 + 1];
        blue_value += hex_digits[(i + 2) * 2] * 16 + hex_digits[(i + 2) * 2 + 1];
    }
    
    red[2] = '\0';
    sprintf(red, "%3d", red_value);
    green[2] = '\0';
    sprintf(green, "%3d", green_value);
    blue[2] = '\0';
    sprintf(blue, "%3d", blue_value);
    
    printf("Red: %s\n", red);
    printf("Green: %s\n", green);
    printf("Blue: %s\n", blue);
    
    free(red);
    free(green);
    free(blue);
    
    return 0;
}