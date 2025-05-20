//GPT-4o-mini DATASET v1.0 Category: Text to ASCII art generator ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT 256
#define MAX_OUTPUT 1024

void generate_ascii_art(const char *input, char *output) {
    const char *ascii_map[] = {
        "  ##     ##    #######    ##     ##    ######     ######   ##     ##    #######   ######   ######    ######   ",
        "  ##     ##   ##     ##   ##     ##   ##    ##   ##    ##  ##     ##   ##     ##  ##    ##  ##    ##  ##    ##  ",
        "  ##     ##   ##     ##   ##     ##   ##         ##       ##     ##   ##     ##  ##        ##       ##         ",
        "  ##     ##   ##     ##   ##     ##   ##   ####   ######## ##     ##   ##     ##  ##   ####  ##       ##   ####  ",
        "  ##     ##   ##     ##   ##     ##   ##    ##    ##          ##     ##   ##     ##  ##    ##  ##       ##    ##  ",
        "  ##     ##   ##     ##   ##     ##   ##    ##   ##          ##     ##   ##     ##  ##    ##   ##       ##    ##  ",
        "   #######    #######     #######     ######     ##           #######     #######    ######    ######    ######    ",
        // Continue mapping for all characters and functions...
    };

    char mapped_char;
    size_t offset = 0;

    for (size_t i = 0; input[i] != '\0'; i++) {
        if (input[i] >= 'A' && input[i] <= 'Z') {
            mapped_char = 'A' + (input[i] - 'A'); // Map to ASCII art based on the uppercase letter
            strcat(output + offset, ascii_map[mapped_char - 'A']);
            offset += strlen(ascii_map[mapped_char - 'A']);
        } else if (input[i] >= 'a' && input[i] <= 'z') {
            mapped_char = 'A' + (input[i] - 'a'); // Map lowercase to uppercase
            strcat(output + offset, ascii_map[mapped_char - 'A']);
            offset += strlen(ascii_map[mapped_char - 'A']);
        } else if (input[i] == ' ') {
            strcat(output + offset, "         ");
            offset += 9; // Space length in ASCII art
        } else {
            strcat(output + offset, "#########"); // Handle special characters or other symbols
            offset += 9; // Represent non-mapped characters with hashed symbols
        }
    }
}

int main() {
    char input[MAX_INPUT];
    char output[MAX_OUTPUT] = {'\0'};

    printf("Enter the text to convert into ASCII art: ");
    fgets(input, MAX_INPUT, stdin);

    // Remove newline character from input
    input[strcspn(input, "\n")] = 0;

    generate_ascii_art(input, output);
    printf("\nASCII Art Representation:\n\n%s\n", output);

    return 0;
}