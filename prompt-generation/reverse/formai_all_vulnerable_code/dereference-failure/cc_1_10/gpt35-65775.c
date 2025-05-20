//FormAI DATASET v1.0 Category: Color Code Converter ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* hexToRGB(char* hex);
char* RGBToHex(char* rgb);

int main() {
    char hex[8];
    char rgb[12];

    printf("Enter hex code: ");
    scanf("%s", hex);
    printf("RGB code: %s\n", hexToRGB(hex));

    printf("Enter RGB code: ");
    scanf("%s", rgb);
    printf("Hex code: %s\n", RGBToHex(rgb));

    return 0;
}

char* hexToRGB(char* hex) {
    char* result = (char*)malloc(sizeof(char)*12);

    if(strlen(hex) == 6 && hex[0] == '#') {
        int r = (int)strtol(&hex[1], NULL, 16);
        int g = (int)strtol(&hex[3], NULL, 16);
        int b = (int)strtol(&hex[5], NULL, 16);

        sprintf(result, "%d, %d, %d", r, g, b);
    } else {
        strcpy(result, "Invalid Format");
    }

    return result;
}

char* RGBToHex(char* rgb) {
    char* result = (char*)malloc(sizeof(char)*8);

    int r, g, b;
    if(sscanf(rgb, "%d, %d, %d", &r, &g, &b) == 3) {
        if(r >= 0 && r <= 255 && g >= 0 && g <= 255 && b >= 0 && b <= 255) {
            sprintf(result, "#%02x%02x%02x", r, g, b);
        }
        else {
            strcpy(result, "Invalid Format");
        }
    }

    return result;
}