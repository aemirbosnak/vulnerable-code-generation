//FormAI DATASET v1.0 Category: Color Code Converter ; Style: real-life
#include <stdio.h>
#include <string.h>

// function prototypes
void hexToRGB(char*, int*, int*, int*);
void RGBToHex(int, int, int, char*);

int main() {
    char input[8];      // user input string
    char output[8];     // converted output string
    int r, g, b;        // red, green, blue values

    printf("C Color Code Converter\n");
    printf("Enter a hex code or 3 RGB values (separated by spaces):\n");
    fgets(input, 8, stdin);

    if (input[0] == '#') {
        // convert hex to RGB
        hexToRGB(input, &r, &g, &b);
        printf("RGB values: %d, %d, %d\n", r, g, b);

        // convert RGB to hex
        RGBToHex(r, g, b, output);
        printf("Hex code: %s\n", output);
    } else {
        // separate RGB values from input string
        char* p = strtok(input, " ");
        r = atoi(p);
        p = strtok(NULL, " ");
        g = atoi(p);
        p = strtok(NULL, " ");
        b = atoi(p);

        // convert RGB to hex
        RGBToHex(r, g, b, output);
        printf("Hex code: %s\n", output);

        // convert hex to RGB
        hexToRGB(output, &r, &g, &b);
        printf("RGB values: %d, %d, %d\n", r, g, b);
    }

    return 0;
}

// function to convert a hex code to RGB values
void hexToRGB(char* hex, int* r, int* g, int* b) {
    *r = (int)strtol(&hex[1], NULL, 16);
    *g = (int)strtol(&hex[3], NULL, 16);
    *b = (int)strtol(&hex[5], NULL, 16);
}

// function to convert RGB values to a hex code
void RGBToHex(int r, int g, int b, char* hex) {
    sprintf(hex, "#%02X%02X%02X", r, g, b);
}