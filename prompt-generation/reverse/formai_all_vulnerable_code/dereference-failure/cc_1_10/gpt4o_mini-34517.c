//GPT-4o-mini DATASET v1.0 Category: Text to ASCII art generator ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT 256
#define MAX_FONT_NAME 100

void display_help() {
    printf("Text to ASCII Art Generator\n");
    printf("Usage: text2ascii [options] <text>\n");
    printf("Options:\n");
    printf("  -f <font>      Specify the font name (default is standard).\n");
    printf("  -h             Display this help message.\n");
}

void generate_ascii_art(const char *text, const char *font) {
    char command[MAX_INPUT + MAX_FONT_NAME + 50];

    // Prepare the command to call figlet
    if (font[0] != '\0') {
        snprintf(command, sizeof(command), "figlet -f %s \"%s\"", font, text);
    } else {
        snprintf(command, sizeof(command), "figlet \"%s\"", text);
    }
    
    // Execute the command
    system(command);
}

int main(int argc, char *argv[]) {
    char text[MAX_INPUT];
    char font[MAX_FONT_NAME] = "";

    // Command line argument parsing
    if (argc < 2) {
        display_help();
        return 1;
    }

    // Loop through arguments
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-f") == 0) {
            if (i + 1 < argc) {
                strncpy(font, argv[i + 1], MAX_FONT_NAME - 1);
                font[MAX_FONT_NAME - 1] = '\0';  // Ensure null-terminated
                i++;  // Skip the font argument
            } else {
                printf("Error: Missing font name after '-f' option.\n");
                return 1;
            }
        } else if (strcmp(argv[i], "-h") == 0) {
            display_help();
            return 0;
        } else {
            // Collect the text input
            if (strlen(text) + strlen(argv[i]) + 1 < MAX_INPUT) {
                strcat(text, argv[i]);
                strcat(text, " ");  // Add space between words
            } else {
                printf("Error: Input text is too long.\n");
                return 1;
            }
        }
    }

    // Trim the trailing space
    if (strlen(text) > 0) {
        text[strlen(text) - 1] = '\0';  // Remove the last space
    } else {
        printf("Error: No text input provided.\n");
        return 1;
    }

    // Generate and display ASCII art
    generate_ascii_art(text, font);
    return 0;
}