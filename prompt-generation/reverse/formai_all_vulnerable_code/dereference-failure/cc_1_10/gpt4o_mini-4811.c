//GPT-4o-mini DATASET v1.0 Category: Text to ASCII art generator ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHARS 100
#define MAX_LINES 100

void print_usage() {
    printf("Usage: ./ascii_art_generator <text>\n");
    printf("Generates ASCII art from the provided text.\n");
}

void create_ascii_art(const char *input) {
    char ascii_art[MAX_LINES][MAX_CHARS];
    int line_count = 0;

    for(int i = 0; i < strlen(input); i++) {
        char c = input[i];
        int j = 0;

        if (c == ' ') {
            // Assign empty space for space character
            sprintf(ascii_art[line_count], "   ");
            line_count++;
            continue;
        }

        sprintf(ascii_art[line_count], "%c", c);

        // Create simple ASCII art representation
        for (j = 0; j < 5; j++) {
            if (line_count < MAX_LINES) {
                switch (c) {
                    case 'A': 
                        strcat(ascii_art[line_count], "   /\\   ");
                        break;
                    case 'B':
                        strcat(ascii_art[line_count], "   | |  ");
                        break;
                    case 'C':
                        strcat(ascii_art[line_count], "   /    ");
                        break;
                    case 'D':
                        strcat(ascii_art[line_count], "   |\\   ");
                        break;
                    case 'E':
                        strcat(ascii_art[line_count], "   |____ ");
                        break;
                    case 'F':
                        strcat(ascii_art[line_count], "   |____ ");
                        break;
                    // You can add more characters here
                    default:
                        strcat(ascii_art[line_count], "   ? ");
                }
                line_count++;
            }
        }
    }

    // Output the generated ASCII Art
    for (int i = 0; i < line_count; i++) {
        printf("%s\n", ascii_art[i]);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        print_usage();
        return 1;
    }

    const char *input_text = argv[1];
    if (strlen(input_text) > MAX_CHARS) {
        printf("Error: Input text is too long. Please limit to %d characters.\n", MAX_CHARS);
        return 1;
    }

    create_ascii_art(input_text);
    return 0;
}