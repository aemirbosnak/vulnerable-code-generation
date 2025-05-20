//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: synchronous
#include <stdio.h>
#include <string.h>

#define MAX_LEN 100 // Maximum length of input string

// Morse code alphabet
char *morse_alphabet[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};

// Corresponding letters of Morse code
char letters[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

/**
 * Function to convert a character to its Morse code equivalent
 */
char *char_to_morse(char c) {
    int pos = -1;
    char upper_c = toupper(c);
    char *morse_char = NULL;
    
    // Find the position of character in letters string
    for(int i=0; i<26; i++) {
        if(letters[i] == upper_c) {
            pos = i;
            break;
        }
    }
    
    if(pos != -1) { // If character is found in letters
        
        // Copy the Morse code of the character
        morse_char = malloc(strlen(morse_alphabet[pos]));
        strcpy(morse_char, morse_alphabet[pos]);
    }
    
    return morse_char;
}

/**
 * Function to convert text to Morse code
 */
void text_to_morse(char *text, char *morse) {
    int text_len = strlen(text);
    
    for(int i=0; i<text_len; i++) {
        char *morse_char = char_to_morse(text[i]);
        
        if(morse_char != NULL) { // If character is one of the 26 letters
            
            // Append Morse code of character to morse string
            strcat(morse, morse_char);
            strcat(morse, " "); // Add space between Morse code of characters
        }
        
        free(morse_char);
    }
}

int main() {
    char text[MAX_LEN], morse[MAX_LEN*5] = {0}; // Morse code can be up to 5 times longer than original text
    
    printf("Enter text to convert to Morse code:\n");
    fgets(text, MAX_LEN, stdin);
    
    text_to_morse(text, morse);
    
    printf("Morse code:\n%s\n", morse);
    
    return 0;
}