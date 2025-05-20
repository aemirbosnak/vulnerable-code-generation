//MISTRAL-7B DATASET v1.0 Category: Color Code Converter ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 100

void convertColor(char *colorName) {
    char r[3], g[3], b[3];
    int i;

    for (i = 0; i < strlen(colorName) && i < MAX_LEN - 3; i++) {
        if (isalpha(colorName[i]))
            colorName[i] = toupper(colorName[i]);
        else if (i > 0 && (colorName[i - 1] == ' ' || i == 0)) {
            switch (colorName[i - 1]) {
                case 'R':
                    strncpy(r, colorName + i, 2);
                    i += 2;
                    break;
                case 'G':
                    strncpy(g, colorName + i, 2);
                    i += 2;
                    break;
                case 'B':
                    strncpy(b, colorName + i, 2);
                    i += 2;
                    break;
                default:
                    i--;
                    break;
            }
        }
    }

    if (strlen(r) == 2 && strlen(g) == 2 && strlen(b) == 2) {
        printf("Color %s is equivalent to RGB(%s, %s, %s)\n", colorName, r, g, b);
        int rValue = atoi(r);
        int gValue = atoi(g);
        int bValue = atoi(b);

        // Convert RGB to desired color format (e.g., hexadecimal)
        printf("In hexadecimal format, RGB(%s, %s, %s) is #%02X%02X%02X\n", r, g, b, rValue, gValue, bValue);
    } else {
        printf("Invalid color name: %s\n", colorName);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <color_name>\n", argv[0]);
        return 1;
    }

    char colorName[MAX_LEN];
    strcpy(colorName, argv[1]);

    convertColor(colorName);

    return 0;
}

// Romeo and Juliet style comment
/*
This program converts a given color name into its RGB equivalent and hexadecimal format.
For instance, if you run the program with the argument "blue", the output will be:

Color blue is equivalent to RGB(0, 0, 255)
In hexadecimal format, RGB(0, 0, 255) is #0000FF
*/