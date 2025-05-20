//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Morse code table
const char *morse_table[] = { ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", 
                             "..", ".---", "-.-", ".-..", "--", "-.", "---", 
                             ".--.", "--.-", ".-.", "...", "-", "..-", 
                             "...-", ".--", "-..-", "-.--", "--.."
                           };

// Corresponding alphabet table
const char *alpha_table = "abcdefghijklmnopqrstuvwxyz";

// Morse code character separator
const char *char_separator = " ";

// Convert character to its Morse code form
char *morse_encode(char c) {
    int alpha_index = -1;
    
    for (int i = 0; i < strlen(alpha_table); i++) {
        if (tolower(c) == alpha_table[i]) {
            alpha_index = i;
            break;
        }
    }
    
    if (alpha_index < 0) {
        return "";
    }
    
    return morse_table[alpha_index];
}

// Convert string to its Morse code form
char *string_to_morse(char *input) {
    char *output = malloc(strlen(input) * 4);
    output[0] = '\0';
    
    for (int i = 0; i < strlen(input); i++) {
        char *morse_char = morse_encode(input[i]);
        
        if (strlen(morse_char) > 0) {
            strcat(output, morse_char);
            strcat(output, char_separator);
        }
    }
    
    return output;
}

int main() {
    char input[255];
    
    printf("Enter a string to convert to Morse code: ");
    fgets(input, 255, stdin);
    
    // Remove trailing newline character
    input[strcspn(input, "\n")] = 0;
    
    char *morse_code = string_to_morse(input);
    
    printf("Morse code representation: %s\n", morse_code);
    
    free(morse_code);
    
    return 0;
}