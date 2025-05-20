//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: complete
#include <stdio.h>
#include <string.h>

// Function that converts text to Morse code
void text_to_morse(char* text) {
    // Array with Morse code representation of each letter and number
    char morse[36][6] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", "-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----."};
    
    int len = strlen(text);
    char *morse_code = "";
    
    // Loop through each letter in the text
    for (int i = 0; i < len; i++) {
        // Get the ASCII value of the letter
        int ascii = (int) text[i];
        
        // Check if the letter is uppercase
        if (ascii >= 65 && ascii <= 90) {
            // Convert the letter to lowercase
            ascii += 32;
        }
        
        // Check if the letter is a space
        if (ascii == 32) {
            morse_code = strcat(morse_code, "  ");
        } else {
            // Get the Morse code representation of the letter
            char *letter = morse[ascii - 97];
            // Add the Morse code to the output string
            morse_code = strcat(morse_code, letter);
            // Add a space between letters
            morse_code = strcat(morse_code, " ");
        }
    }
    
    // Print the Morse code representation of the text
    printf("Morse code: %s\n", morse_code);
}

int main() {
    // Prompt the user to enter a string
    char text[100];
    printf("Enter text to convert to Morse code: ");
    fgets(text, sizeof(text), stdin);
    // Remove the newline character from the input string
    text[strcspn(text, "\n")] = 0;
    
    // Convert the text to Morse code
    text_to_morse(text);
    
    return 0;
}