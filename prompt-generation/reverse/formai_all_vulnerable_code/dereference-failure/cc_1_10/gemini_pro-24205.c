//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

// Romeo's letter to Juliet
char *romeo = "But soft, what light through yonder window breaks? It is the east, and Juliet is the sun.";

// Juliet's response to Romeo
char *juliet = "O Romeo, Romeo, wherefore art thou Romeo? Deny thy father and refuse thy name.";

// Morse code table
char *morse_code[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.",
    "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..",
    ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----.", "-----"
};

// Convert a character to Morse code
char *char_to_morse(char c) {
    int i = c - 'a';
    if (i >= 0 && i < 26) {
        return morse_code[i];
    } else {
        return "";
    }
}

// Convert a string to Morse code
char *string_to_morse(char *str) {
    char *morse = "";
    for (int i = 0; str[i] != '\0'; i++) {
        char *c_morse = char_to_morse(str[i]);
        if (strlen(c_morse) > 0) {
            morse = strcat(morse, c_morse);
            morse = strcat(morse, " ");
        }
    }
    return morse;
}

// Print a string in Morse code
void print_morse(char *morse) {
    for (int i = 0; morse[i] != '\0'; i++) {
        if (morse[i] == '.') {
            printf("·");
        } else if (morse[i] == '-') {
            printf("—");
        } else {
            printf(" ");
        }
    }
    printf("\n");
}

int main() {
    // Convert Romeo's letter to Morse code
    char *romeo_morse = string_to_morse(romeo);
    
    // Convert Juliet's response to Morse code
    char *juliet_morse = string_to_morse(juliet);
    
    // Print Romeo's letter in Morse code
    printf("Romeo: %s\n", romeo_morse);
    
    // Print Juliet's response in Morse code
    printf("Juliet: %s\n", juliet_morse);
    
    return 0;
}