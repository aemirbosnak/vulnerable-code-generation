//Code Llama-13B DATASET v1.0 Category: Text to Morse code conversion ; Style: Linus Torvalds
/*
 * A text to Morse code conversion program in the style of Linus Torvalds
 *
 * Usage: ./text_to_morse <text>
 *
 * Converts a text to Morse code and prints it to the console.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    // Check if the input text is valid
    if (argc != 2) {
        fprintf(stderr, "Usage: ./text_to_morse <text>\n");
        return 1;
    }

    // Get the input text
    char *text = argv[1];

    // Convert the text to Morse code
    char morse[strlen(text) * 3]; // buffer for the Morse code
    char *ptr = morse;
    for (int i = 0; text[i] != '\0'; i++) {
        switch (text[i]) {
            case 'A': ptr += sprintf(ptr, ".-"); break;
            case 'B': ptr += sprintf(ptr, "-..."); break;
            case 'C': ptr += sprintf(ptr, "-.-."); break;
            case 'D': ptr += sprintf(ptr, "-.."); break;
            case 'E': ptr += sprintf(ptr, "."); break;
            case 'F': ptr += sprintf(ptr, "..-."); break;
            case 'G': ptr += sprintf(ptr, "--."); break;
            case 'H': ptr += sprintf(ptr, "...."); break;
            case 'I': ptr += sprintf(ptr, ".."); break;
            case 'J': ptr += sprintf(ptr, ".---"); break;
            case 'K': ptr += sprintf(ptr, "-.-"); break;
            case 'L': ptr += sprintf(ptr, ".-.."); break;
            case 'M': ptr += sprintf(ptr, "--"); break;
            case 'N': ptr += sprintf(ptr, "-."); break;
            case 'O': ptr += sprintf(ptr, "---"); break;
            case 'P': ptr += sprintf(ptr, ".--."); break;
            case 'Q': ptr += sprintf(ptr, "--.-"); break;
            case 'R': ptr += sprintf(ptr, ".-."); break;
            case 'S': ptr += sprintf(ptr, "..."); break;
            case 'T': ptr += sprintf(ptr, "-"); break;
            case 'U': ptr += sprintf(ptr, "..-"); break;
            case 'V': ptr += sprintf(ptr, "...-"); break;
            case 'W': ptr += sprintf(ptr, ".--"); break;
            case 'X': ptr += sprintf(ptr, "-..-"); break;
            case 'Y': ptr += sprintf(ptr, "-.--"); break;
            case 'Z': ptr += sprintf(ptr, "--.."); break;
            case '1': ptr += sprintf(ptr, ".----"); break;
            case '2': ptr += sprintf(ptr, "..---"); break;
            case '3': ptr += sprintf(ptr, "...--"); break;
            case '4': ptr += sprintf(ptr, "....-"); break;
            case '5': ptr += sprintf(ptr, "....."); break;
            case '6': ptr += sprintf(ptr, "-...."); break;
            case '7': ptr += sprintf(ptr, "--..."); break;
            case '8': ptr += sprintf(ptr, "---.."); break;
            case '9': ptr += sprintf(ptr, "----."); break;
            case '0': ptr += sprintf(ptr, "-----"); break;
            case ' ': ptr += sprintf(ptr, "   "); break;
            default: ptr += sprintf(ptr, "?"); break;
        }
    }

    // Print the Morse code
    printf("%s\n", morse);

    return 0;
}