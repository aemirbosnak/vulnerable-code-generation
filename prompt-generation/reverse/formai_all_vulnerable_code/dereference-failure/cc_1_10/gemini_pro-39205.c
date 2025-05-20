//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: active
#include <stdio.h>
#include <string.h>

// Morse code character mapping
char *morse_code[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.",
    "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", "..--",
    "-....", "--...", "---..", "----.", ".-.-.-", "--..--", "---...", ".-.-.", "-.--.", "-.--.-",
    ".-...", "-.-.-. ", ".----.", "..---", ".----.", "-....-", "--...", "-..-.", ".-..-. ", ".--.-.",
    "..--.-", ".-...", "...-..-", ".-..--- ", ".-....-", ".--.-..", "-..-...", "-.-.--.", "--..-.",
    ".-...-", ".-....", "..-.-.-", "--..--.", "-....-", ".-..--.", ".-...-", "....---", "--...--",
    "....-.", "..--.-.", "-.-.--.", "..--..", "-...-", "-.--.", ".-....-", "-....", ".-.-.-.-",
    "--..--", "-....-", "-.--.-.-", ".---...", ".-..-. ", ".--.-. ", "-...-", "-....-", "...-..-",
    "--...--", ".-..---", "....---", ".-....-", "-....", ".-..--.", ".-...-", "-..--.", "....-- ",
    ".--...-", "-.-.--.", "-....-", ".-..-. ", "--..--", ".-..---", ".-.-.-. ", ".--.-.", "-.-.-.-",
    "-...-"
};

// Function to convert text to Morse code
char *text_to_morse(char *text) {
    // Allocate memory for the Morse code representation
    char *morse_code_representation = malloc(strlen(text) * 5);

    // Convert each character of the text to Morse code and concatenate it to the Morse code representation
    for (int i = 0; i < strlen(text); i++) {
        strcat(morse_code_representation, morse_code[text[i] - 'a']);
    }

    // Return the Morse code representation
    return morse_code_representation;
}

// Function to print the Morse code representation
void print_morse_code(char *morse_code_representation) {
    // Print the Morse code representation character by character
    for (int i = 0; i < strlen(morse_code_representation); i++) {
        printf("%c", morse_code_representation[i]);
    }
}

int main() {
    // Get the text to be converted to Morse code
    char text[100];
    printf("Enter the text to be converted to Morse code: ");
    scanf("%[^\n]%*c", text);

    // Convert the text to Morse code
    char *morse_code_representation = text_to_morse(text);

    // Print the Morse code representation
    printf("Morse code representation: ");
    print_morse_code(morse_code_representation);

    // Free the allocated memory
    free(morse_code_representation);

    return 0;
}