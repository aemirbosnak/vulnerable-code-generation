//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: calm
#include <stdio.h>
#include <string.h>

// Morse code lookup table
const char* morse_table[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--",
    "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..",
    ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----.", "-----"
};

// Function to convert a single character to Morse code
void char_to_morse(char input, char* output) {
    if(input >= 'a' && input <= 'z') {
        strcpy(output, morse_table[input - 'a']);
    } else if(input >= 'A' && input <= 'Z') {
        strcpy(output, morse_table[input - 'A']);
    } else if(input >= '0' && input <= '9') {
        strcpy(output, morse_table[input - '0' + 26]);
    } else {
        output[0] = '\0';
    }
}

// Function to convert a string to Morse code
void text_to_morse(char* input, char* output) {
    int len = strlen(input);
    for(int i = 0; i < len; i++) {
        if(input[i] == ' ') {
            strcat(output, "/ ");
        } else {
            char morse[5];
            char_to_morse(input[i], morse);
            strcat(output, morse);
            strcat(output, " ");
        }
    }
}

// Main function
int main() {
    char text[100];
    printf("Enter text to convert to Morse code: ");
    fgets(text, 100, stdin);
    text[strcspn(text, "\n")] = '\0';  // Remove trailing newline from input
    
    char morse[500];
    morse[0] = '\0';
    text_to_morse(text, morse);
    printf("Morse code: %s\n", morse);
    
    return 0;
}