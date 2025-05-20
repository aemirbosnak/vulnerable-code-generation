//GPT-4o-mini DATASET v1.0 Category: Text to ASCII art generator ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printUsage(char *programName) {
    printf("Usage: %s <text>\n", programName);
    printf("Converts the provided text into ASCII art representation.\n");
}

void generateASCIIArt(char *text) {
    const char *asciiTable[] = {
        "  #   # ", // A
        " # # # # ", // B
        "  # #   ", // C
        " # # #  ", // D
        "#####  ", // E
        "###   ", // F
        " ####  ", // G
        " # # #  ", // H
        "  ##### ", // I
        "      # ", // J
        " ##  ## ", // K
        " #     ", // L
        " #   # # ", // M
        " #    # ", // N
        "   ###   ", // O 
        " ####  # ", // P
        "  #   #  ", // Q
        " ######   ", // R
        "  ####   ", // S
        " ######## ", // T
        " #      # ", // U
        " #      # ", // V
        " #   # # ", // W
        " #   #  # ", // X
        "       # ", // Y
        " ######   "  // Z
    };
    
    for (int i = 0; i < 8; i++) {
        for (int j = 0; text[j] != '\0'; j++) {
            char ch = text[j];
            if (ch >= 'A' && ch <= 'Z') {
                printf("%s ", asciiTable[ch - 'A']);
            } else if (ch >= 'a' && ch <= 'z') {
                printf("%s ", asciiTable[ch - 'a']);
            } else if (ch == ' ') {
                printf("        "); // Space represented by empty space
            }
        }
        printf("\n");
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printUsage(argv[0]);
        return 1; // Indicate error in usage
    }

    char *inputText = argv[1];
    
    // Clean input text and convert to uppercase
    for (int i = 0; inputText[i]; i++) {
        inputText[i] = toupper(inputText[i]);
    }

    // Generating ASCII Art
    printf("Generating ASCII art for: \"%s\"\n", inputText);
    generateASCIIArt(inputText);

    return 0; // Success
}