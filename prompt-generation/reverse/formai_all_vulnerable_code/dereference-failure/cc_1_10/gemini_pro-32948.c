//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: Donald Knuth
#include <stdio.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

// Declare the Morse code map.
static const char *morse_code_map[] = {
    ".-",   "-...", "-.-.", "-..",  ".",
    "..-.", "--.",  "....", "..",   ".---",
    "-.-",  ".-..", "--",   "-.",   "...",
    "---",  ".--.", ".-..", "--..",  "-..-",
    "-.--", "-.--.", "--..--", ".-.",  "...-",
    ".--",  "-..-", "-.--",  "--..",  ".----",
    "..---", "---..", "----.", "-----", " "
};

// Convert a character to Morse code.
static void char_to_morse(char c, char *morse_code) {
    if (c >= 'a' && c <= 'z') {
        c -= 32;
    }
    if (c >= 'A' && c <= 'Z') {
        *morse_code = morse_code_map[c - 'A'][0];
        *(morse_code + 1) = morse_code_map[c - 'A'][1];
        *(morse_code + 2) = '\0';
    } else if (c >= '0' && c <= '9') {
        *morse_code = morse_code_map[c - '0'][0];
        *(morse_code + 1) = morse_code_map[c - '0'][1];
        *(morse_code + 2) = morse_code_map[c - '0'][2];
        *(morse_code + 3) = '\0';
    } else if (c == ' ') {
        *morse_code = ' ';
        *(morse_code + 1) = '\0';
    }
}

// Convert a string to Morse code.
static void string_to_morse(char *string, char *morse_code) {
    int i;
    for (i = 0; i < strlen(string); i++) {
        char_to_morse(string[i], morse_code);
        morse_code += strlen(morse_code);
    }
}

// Print the Morse code for a string.
static void print_morse_code(char *morse_code) {
    printf("%s\n", morse_code);
}

// Get a line of text from the user.
static void get_line_of_text(char *line) {
    printf("Enter a line of text: ");
    fgets(line, MAX_LINE_LENGTH, stdin);
}

// Main function.
int main(void) {
    char line[MAX_LINE_LENGTH];
    char morse_code[MAX_LINE_LENGTH * 4];

    get_line_of_text(line);
    string_to_morse(line, morse_code);
    print_morse_code(morse_code);

    return 0;
}