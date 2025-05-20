//GPT-4o-mini DATASET v1.0 Category: Text to ASCII art generator ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ASCII art styles
#define STYLE_BLOCK  1
#define STYLE_THIN   2
#define STYLE_SLOPE  3

// Function Prototypes
void generateAsciiArt(char *input, int style);
void printBlock(char c);
void printThin(char c);
void printSlope(char c);

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <text> <style>\n", argv[0]);
        printf("Styles:\n");
        printf("1 - Block Style\n");
        printf("2 - Thin Style\n");
        printf("3 - Slope Style\n");
        return EXIT_FAILURE;
    }

    char *inputText = argv[1];
    int style = atoi(argv[2]);

    generateAsciiArt(inputText, style);

    return EXIT_SUCCESS;
}

void generateAsciiArt(char *input, int style) {
    printf("\nGenerating ASCII Art for: \"%s\" in style %d\n", input, style);
    for (int i = 0; i < strlen(input); i++) {
        char c = input[i];
        if (c == ' ') {
            printf("   "); // space for clarity
            continue;
        }
        switch (style) {
            case STYLE_BLOCK:
                printBlock(c);
                break;
            case STYLE_THIN:
                printThin(c);
                break;
            case STYLE_SLOPE:
                printSlope(c);
                break;
            default:
                printf("Unknown style! Use 1, 2 or 3.\n");
                return;
        }
    }
    printf("\n");
}

void printBlock(char c) {
    // Printing in block style
    char line1[7], line2[7], line3[7];
    
    snprintf(line1, sizeof(line1), "%c%c%c%c%c%c%c", c, c, c, c, c, c, c);
    snprintf(line2, sizeof(line2), "%c     %c", c, c);
    snprintf(line3, sizeof(line3), "%c%c%c%c%c%c%c", c, c, c, c, c, c, c);

    printf("%s\n%s\n%s\n", line1, line2, line3);
}

void printThin(char c) {
    // Printing in thin style
    printf(" %c ", c);
}

void printSlope(char c) {
    // Printing in slope style
    printf("%s\n", "  \\");
    printf("%c%c\n", c, c);
}