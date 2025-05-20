//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert character to morse code string
char* charToMorse(char c){

    // Array of morse code strings for each character
    char* morseCodes[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....",
                          "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.",
                          "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-",
                          "-.--", "--.."};

    // Converting character to its respective ASCII index and subtracting by 65 to get array index
    // If the character is a space, return an empty string
    if(c == ' '){
        return "";
    } else {
        int index = (int)c - 65;
        return morseCodes[index];
    }
}

// Function to convert text string to morse code string
char* textToMorse(char* text){

    // Allocating memory for morse code string with twice the length of the original text string
    int textLen = strlen(text);
    char* morseCode = (char*)malloc(textLen*2*sizeof(char));
    morseCode[0] = '\0';

    // Loop through each character in the text string and add its morse code to the morse code string
    for(int i=0; i<textLen; i++){
        char* charMorse = charToMorse(text[i]);
        strcat(morseCode, charMorse);
        strcat(morseCode, " ");
    }

    return morseCode;
}

int main(){

    printf("Enter a text string to convert to Morse code:\n");

    // Get input from user
    char text[200];
    fgets(text, sizeof(text), stdin);

    // Convert text to Morse code and print result
    char* morseCode = textToMorse(text);
    printf("Morse code: %s\n", morseCode);

    free(morseCode);
    return 0;
}