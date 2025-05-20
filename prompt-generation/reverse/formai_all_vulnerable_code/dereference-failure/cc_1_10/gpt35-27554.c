//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printMorse(char* input);
char letterToMorse(char letter);
void playMorse(char* morse);

int main() {

    printf("Welcome to the Text to Morse code converter!\n");
    printf("Please enter your text: \n");

    char input[100];
    fgets(input, sizeof(input), stdin); // Get input from user

    printf("Your input is: %s", input);
    printMorse(input); // Convert text to Morse code and print it
    return 0;
}

void printMorse(char* input) {

    int length = strlen(input); // Get length of input string

    for(int i = 0; i < length; i++) {
        char morse = letterToMorse(input[i]); // Convert letter to morse
        if(morse == '\0') continue; // Skip if the character is not a letter
        printf("%c", morse); // Print Morse code
        playMorse(&morse); // Play Morse code sound
    }
}

char letterToMorse(char letter) {

    char morse = '\0'; // Initialize Morse code as null

    switch(tolower(letter)) {
        case 'a': morse = '.'; break;
        case 'b': morse = '-'; break;
        case 'c': morse = '-.-.'; break;
        case 'd': morse = '-..'; break;
        case 'e': morse = '.'; break;
        case 'f': morse = '..-.'; break;
        case 'g': morse = '--.'; break;
        case 'h': morse = '....'; break;
        case 'i': morse = '..'; break;
        case 'j': morse = '.---'; break;
        case 'k': morse = '-.-'; break;
        case 'l': morse = '.-..'; break;
        case 'm': morse = '--'; break;
        case 'n': morse = '-.'; break;
        case 'o': morse = '---'; break;
        case 'p': morse = '.--.'; break;
        case 'q': morse = '--.-'; break;
        case 'r': morse = '.-.'; break;
        case 's': morse = '...'; break;
        case 't': morse = '-'; break;
        case 'u': morse = '..-'; break;
        case 'v': morse = '...-'; break;
        case 'w': morse = '.--'; break;
        case 'x': morse = '-..-'; break;
        case 'y': morse = '-.--'; break;
        case 'z': morse = '--..'; break;
        case ' ': morse = ' '; break;
        default: break;
    }

    return morse;
}

void playMorse(char* morse) {
    int length = strlen(morse); // Get length of morse string

    for(int i = 0; i < length; i++) {
        if(morse[i] == '.') {
            printf("%c", '.'); // Print dot
            printf("\a"); // Play sound
        }
        else {
            printf("%c", '-'); // Print dash
            printf("\a\a"); // Play sound
        }
    }

    printf(" "); // Add space after letter is played
}