//GPT-4o-mini DATASET v1.0 Category: Text to ASCII art generator ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1000
#define MAX_ASCII_HEIGHT 6
#define CHAR_SET_SIZE 128

// ASCII representation for each character
const char* ascii_art[CHAR_SET_SIZE][MAX_ASCII_HEIGHT] = {
    ['A'] = {"  ###  ", " #   # ", "#     #", "#######", "#     #", "#     #"},
    ['B'] = {"###### ", "#     #", "###### ", "#     #", "#     #", "###### "},
    ['C'] = {" ######", "#      ", "#      ", "#      ", "#      ", " ######"},
    ['D'] = {"###### ", "#     #", "#     #", "#     #", "#     #", "###### "},
    ['E'] = {"###### ", "#      ", "###### ", "#      ", "#      ", "###### "},
    ['F'] = {"###### ", "#      ", "###### ", "#      ", "#      ", "#      "},
    ['G'] = {" ######", "#      ", "#  ####", "#     #", "#     #", " ######"},
    ['H'] = {"#     #", "#     #", "#######", "#     #", "#     #", "#     #"},
    ['I'] = {" ######", "   ##  ", "   ##  ", "   ##  ", "   ##  ", " ######"},
    ['J'] = {" ######", "     ##", "     ##", "#    ##", "#    ##", " ######"},
    ['K'] = {"#    # ", "#  #   ", "###    ", "#  #   ", "#    # ", "#    # "},
    ['L'] = {"#      ", "#      ", "#      ", "#      ", "#      ", "###### "},
    ['M'] = {"#     #", "##   ##", "# # # #", "#     #", "#     #", "#     #"},
    ['N'] = {"#     #", "##    #", "# #   #", "#  #  #", "#   ##", "#    #"},
    ['O'] = {" ######", "#     #", "#     #", "#     #", "#     #", " ######"},
    ['P'] = {"###### ", "#     #", "###### ", "#      ", "#      ", "#      "},
    ['Q'] = {" ######", "#     #", "#     #", "#   ## ", "#    # ", " ######"},
    ['R'] = {"###### ", "#     #", "###### ", "# #    ", "#  ##  ", "#    # "},
    ['S'] = {" ######", "#      ", " ######", "      #", "#     #", " ######"},
    ['T'] = {"#######", "   ##  ", "   ##  ", "   ##  ", "   ##  ", "   ##  "},
    ['U'] = {"#     #", "#     #", "#     #", "#     #", "#     #", " ######"},
    ['V'] = {"#     #", "#     #", "#     #", " #   # ", "  # #  ", "   #   "},
    ['W'] = {"#     #", "#     #", "#  #  #", "# # # #", "##   ##", "#     #"},
    ['X'] = {"#     #", "#     #", " #   # ", "  # #  ", " #   # ", "#     #"},
    ['Y'] = {"#     #", "#     #", " #   # ", "  # #  ", "   #   ", "   #   "},
    ['Z'] = {"#######", "     # ", "    #  ", "   #   ", "  #    ", "#######"},
    [' '] = {"       ", "       ", "       ", "       ", "       ", "       "}
};

// Function to display the ASCII art
void display_ascii_art(const char* text) {
    char lines[MAX_ASCII_HEIGHT][MAX_LINE_LENGTH] = {0};

    for (int i = 0; i < strlen(text); ++i) {
        char c = text[i];

        if (c < 0 || c >= CHAR_SET_SIZE) {
            continue;
        }

        for (int j = 0; j < MAX_ASCII_HEIGHT; ++j) {
            strcat(lines[j], ascii_art[c][j]);
            strcat(lines[j], " "); // Add space between characters
        }
    }

    // Print lines of ASCII art
    for (int j = 0; j < MAX_ASCII_HEIGHT; ++j) {
        printf("%s\n", lines[j]);
    }
}

// Main function
int main() {
    char input[MAX_LINE_LENGTH];

    printf("Welcome to the C ASCII Art Generator!\n");
    printf("Enter text to convert to ASCII art (max %d characters):\n", MAX_LINE_LENGTH - 1);
    fgets(input, sizeof(input), stdin);

    // Remove new line character from input
    input[strcspn(input, "\n")] = 0;

    printf("\nHere is your ASCII art representation:\n\n");
    display_ascii_art(input);

    return EXIT_SUCCESS;
}