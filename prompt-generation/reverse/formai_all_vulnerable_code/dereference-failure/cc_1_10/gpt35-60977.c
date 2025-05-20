//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: light-weight
#include <stdio.h>
#include <string.h>

// Morse code array
char *morse_code[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", 
                      ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", 
                      ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};

// Alphabet array
char *alphabet[] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J",
                    "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T",
                    "U", "V", "W", "X", "Y", "Z"};

// Convert text to Morse code
char* text_to_morse(char *text) {
    // Variable to store Morse code conversion
    char *morse = "";
    
    // Loop through each character in the text
    for (int i = 0; i < strlen(text); i++) {
        // Check if the character is a space
        if (text[i] == ' ') {
            // Add a space to the Morse code string
            morse = strcat(morse, " ");
        } else {
            // Loop through the alphabet to find the corresponding Morse code
            for (int j = 0; j < 26; j++) {
                // Check if the character matches an alphabet letter
                if (text[i] == alphabet[j][0]) {
                    // Add the Morse code to the Morse code string
                    morse = strcat(morse, morse_code[j]);
                    // Add a space to the Morse code string
                    morse = strcat(morse, " ");
                    break;
                }
            }
        }
    }
    
    // Return the Morse code string
    return morse;
}

// Main function
int main() {
    // Variable to store text input
    char text[100];
    
    // Prompt user to enter text
    printf("Enter text: ");
    fgets(text, 100, stdin);
    
    // Replace newline character with null character
    text[strcspn(text, "\n")] = '\0';
    
    // Convert text to Morse code
    char *morse = text_to_morse(text);
    
    // Print Morse code
    printf("Morse code: %s\n", morse);
    
    return 0;
}