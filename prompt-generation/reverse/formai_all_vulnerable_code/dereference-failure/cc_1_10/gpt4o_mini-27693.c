//GPT-4o-mini DATASET v1.0 Category: Text to Morse code conversion ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define Morse code mapping for letters and digits
const char *morse_code[] = {
    "A", ".-", "B", "-...", "C", "-.-.", "D", "-..", 
    "E", ".", "F", "..-.", "G", "--.", "H", "....", 
    "I", "..", "J", ".---", "K", "-.-", "L", ".-..", 
    "M", "--", "N", "-.", "O", "---", "P", ".--.", 
    "Q", "--.-", "R", ".-.", "S", "...", "T", "-", 
    "U", "..-", "V", "...-", "W", ".--", "X", "-..-", 
    "Y", "-.--", "Z", "--..", 

    "0", "-----", "1", ".----", "2", "..---", 
    "3", "...--", "4", "....-", "5", ".....", 
    "6", "-....", "7", "--...", "8", "---..", 
    "9", "----.", "/","-..-."
};

// Function to convert a character to its Morse code representation
const char* char_to_morse(char c) {
    c = toupper(c);
    for (int i = 0; i < 36; i++) {
        if (morse_code[i * 2][0] == c) {
            return morse_code[i * 2 + 1];
        }
    }
    return " "; // Return a space for unsupported characters
}

// Function to encode a string to Morse code
void string_to_morse(const char *input, char *output) {
    output[0] = '\0'; // Initialize output string as empty
    for (size_t i = 0; i < strlen(input); i++) {
        const char* morse_char = char_to_morse(input[i]);
        strcat(output, morse_char);
        if (input[i] != ' ') {
            strcat(output, " "); // Add space between Morse characters
        }
    }
}

// Command-line program to demonstrate Morse code conversion
int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <string_to_convert>\n", argv[0]);
        return 1;
    }
    
    char morse_output[256]; // Assume input won't exceed 100 characters
    string_to_morse(argv[1], morse_output);
    
    printf("Original String: %s\n", argv[1]);
    printf("Morse Code: %s\n", morse_output);
    
    return 0;
}