//FormAI DATASET v1.0 Category: Color Code Converter ; Style: decentralized
/* 
  C Color Code Converter Program
  Written in decentralized style
  by [Your Name] 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Function to convert hex code to RGB
 * @param hex char*
 * @return int*
 */
int* hexToRGB(char* hex) {
    int* rgb = malloc(3 * sizeof(int));
    sscanf(hex, "#%02x%02x%02x", &rgb[0], &rgb[1], &rgb[2]);
    return rgb;
}

/**
 * Function to convert RGB to hex code
 * @param rgb int*
 * @return char*
 */
char* RGBToHex(int* rgb) {
    char* hex = malloc(7 * sizeof(char));
    sprintf(hex, "#%02x%02x%02x", rgb[0], rgb[1], rgb[2]);
    return hex;
}

/**
 * Main function to take input and output converted color code
 * @return int
 */
int main() {
    char input[8], colorType;
    printf("Enter color code: ");
    scanf("%s", input);
    printf("Hexadecimal (h) or RGB (r)?: ");
    scanf(" %c", &colorType);

    if (colorType == 'h') {
        int* rgb = hexToRGB(input);
        printf("RGB code: (%d, %d, %d)\n", rgb[0], rgb[1], rgb[2]);
        free(rgb);
    } else if (colorType == 'r') {
        char* hex = RGBToHex(input);
        printf("Hexadecimal code: %s\n", hex);
        free(hex);
    } else {
        printf("Invalid option entered.\n");
        return 1;
    }

    return 0;
}