//FormAI DATASET v1.0 Category: Color Code Converter ; Style: ephemeral
/*
* This program is a C Color Code Converter, written in an ephemeral style.
* It convert colors from Hexadecimal (HEX) code to RGB, and vice versa.
*/


#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void to_rgb(char hex[], int rgb[]);
void to_hex(int rgb[], char hex[]);
void print_rgb(int rgb[]);
void print_hex(char hex[]);

// Main function
int main()
{
    char hex[7] = "#FFFFFF";
    int rgb[3] = {255, 255, 255};

    printf("Welcome to the C Color Code Converter!\n\n");

    // Convert HEX to RGB
    printf("Converting HEX code %s to RGB...\n", hex);
    to_rgb(hex, rgb);
    printf("\nThe RGB equivalent is: ");
    print_rgb(rgb);

    // Convert RGB to HEX
    printf("\n\nConverting RGB code ");
    print_rgb(rgb);
    printf(" to HEX...\n");
    to_hex(rgb, hex);
    printf("\nThe HEX equivalent is: ");
    print_hex(hex);

    printf("\n\nThank you for using the C Color Code Converter.\n");

    return 0;
}

// HEX to RGB conversion function
void to_rgb(char hex[], int rgb[])
{
    char sub[3];
    sub[2] = '\0';
    for (int i = 1; i < 7; i += 2)
    {
        sub[0] = hex[i];
        sub[1] = hex[i+1];
        rgb[i/2-1] = (int) strtol(sub, NULL, 16);
    }
}

// RGB to HEX conversion function
void to_hex(int rgb[], char hex[])
{
    sprintf(hex, "#%02X%02X%02X", rgb[0], rgb[1], rgb[2]);
}

// Function to print RGB array values
void print_rgb(int rgb[])
{
    printf("(%d, %d, %d)", rgb[0], rgb[1], rgb[2]);
}

// Function to print HEX string
void print_hex(char hex[])
{
    printf("%s", hex);
}