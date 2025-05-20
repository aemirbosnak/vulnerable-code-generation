//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *morseCode[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", "/", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----.", "-----"};

char *asciiLetters[] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z", " ", "1", "2", "3", "4", "5", "6", "7", "8", "9", "0"};

char* convertToMorseCode(char* str);
char* getInput();

int main() {
    printf("Welcome to the Morse Code Converter!\n");
    while(1) { // keep running until user wants to exit
        printf("\nWhat would you like to convert to Morse code? (type 'exit' to quit)\n");
        char* input = getInput();
        if(strcmp(input, "exit") == 0) { // user wants to exit
            printf("\nThanks for using the Morse Code Converter!\n");
            free(input);
            break;
        }
        char* morseCode = convertToMorseCode(input);
        printf("\nMorse code: %s\n", morseCode);
        free(input);
        free(morseCode);
    }
    return 0;
}

char* getInput() {
    int size = 1;
    char* input = (char*) malloc(size * sizeof(char));
    while(1) { // keep getting user input until user presses enter
        char c = getchar();
        if(c == '\n') {
            input[size - 1] = '\0';
            break;
        }
        size += 1;
        input = (char*) realloc(input, size * sizeof(char));
        input[size - 2] = c;
    }
    return input;
}

char* convertToMorseCode(char* str) {
    int size = 1;
    char* morseCode = (char*) malloc(size * sizeof(char));
    for(int i = 0; i < strlen(str); i++) { // loop through each character in input string
        int index = -1;
        for(int j = 0; j < sizeof(asciiLetters) / sizeof(asciiLetters[0]); j++) { // find corresponding index in asciiLetters
            if(str[i] == asciiLetters[j][0]) {
                index = j;
                break;
            }
        }
        if(index == -1) { // character not found in asciiLetters
            printf("\nCould not find morse code for character: %c\n", str[i]);
            continue;
        }
        int morseSize = strlen(morseCode);
        morseSize += strlen(morseCode[index]);
        morseCode = (char*) realloc(morseCode, morseSize * sizeof(char));
        strcat(morseCode, morseCode[index]);
        strcat(morseCode, " ");
    }
    return morseCode;
}