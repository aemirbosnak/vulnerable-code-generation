//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    printf("Welcome to the Text to Morse Code converter!\n");

    // Define morse code for each letter and number
    const char *morse_code[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", 
                                ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", 
                                "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", "-----", 
                                ".----", "..---", "...--", "....-", ".....", "-....", "--...", 
                                "---..", "----.", "/", " "};

    // Define letters and numbers
    const char *text[] = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", 
                          "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z",
                          "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", " ", ""};

    // Prompt user to enter text
    char input[100];
    printf("Please enter the text you wish to convert to Morse Code:\n");
    fgets(input, 100, stdin);

    // Remove newline character from input
    input[strcspn(input, "\n")] = 0;

    // Convert input to lowercase
    for (int i = 0; input[i]; i++) {
        input[i] = tolower(input[i]);
    }

    // Initialize variables for converting input to Morse Code
    char *output = malloc(1000);
    output[0] = '\0';

    // Loop through input and add corresponding morse code to output
    for (int i = 0; i < strlen(input); i++) {
        // Find index of input letter in text array
        int index = -1;
        for (int j = 0; j < 37; j++) {
            if (strcmp(text[j], &input[i]) == 0) {
                index = j;
                break;
            }
        }
        // If letter is found, concatenate corresponding morse code to output
        if (index != -1) {
            strcat(output, morse_code[index]);
            strcat(output, " ");
        }
    }

    // Display output
    printf("Your text in Morse Code is:\n%s\n", output);

    free(output);

    return 0;
}