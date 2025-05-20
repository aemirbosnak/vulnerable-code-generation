//MISTRAL-7B DATASET v1.0 Category: Text to Morse code conversion ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DOT 0
#define DASH 1
#define SPACE 2
#define LENGTH 3

char morseCode[26][LENGTH] = {
    {'.', '.', '....', '..', '.--.', '--.', '---.', '.--', '.-..', '--', '-.--.', '--..', '-----', '.----', '..---', '...--', '....-', '.....', '-....', '--...', '---..', '----.'},
    {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'}
};

void printMorse(char morseSymbol[]) {
    int i;

    for(i = 0; morseSymbol[i] != '\0'; i++) {
        switch(morseSymbol[i]) {
            case '.':
                printf("%c", DOT);
                break;
            case '-':
                printf("%c", DASH);
                break;
            case ' ':
                printf("%c", SPACE);
                break;
        }
        if(i < strlen(morseSymbol) - 1)
            printf(" ");
    }
    printf("\n");
}

void convertTextToMorse(char text[]) {
    int i, j;
    char symbol[LENGTH];

    for(i = 0; text[i] != '\0'; i++) {
        if(text[i] >= 'A' && text[i] <= 'Z') {
            strcpy(symbol, morseCode[text[i] - 'A']);
            printMorse(symbol);
        }
        else if(text[i] == ' ') {
            printMorse(morseCode[' ']);
        }
        else {
            printf("Invalid character: %c\n", text[i]);
        }
    }
}

int main() {
    char inputText[100];

    printf("Enter text: ");
    scanf("%s", inputText);

    convertTextToMorse(inputText);

    return 0;
}