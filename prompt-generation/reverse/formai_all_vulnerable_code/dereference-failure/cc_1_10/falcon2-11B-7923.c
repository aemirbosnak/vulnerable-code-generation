//Falcon2-11B DATASET v1.0 Category: Text to Morse code conversion ; Style: excited
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to convert a character to Morse code
char toMorse(char c) {
    switch (c) {
        case 'a': return ".-";
        case 'b': return "-...";
        case 'c': return "-.-.";
        case 'd': return "-..";
        case 'e': return ".";
        case 'f': return "..-.";
        case 'g': return "--.";
        case 'h': return "....";
        case 'i': return "..";
        case 'j': return ".---";
        case 'k': return "-.-";
        case 'l': return ".-..";
        case'm': return "--";
        case 'n': return "-.";
        case 'o': return "---";
        case 'p': return ".--.";
        case 'q': return "--.-";
        case 'r': return ".-.";
        case's': return "...";
        case 't': return "-";
        case 'u': return "..-";
        case 'v': return "...-";
        case 'w': return ".--";
        case 'x': return "-..-";
        case 'y': return "-.--";
        case 'z': return "--..";
        default: return " ";
    }
}

// Function to convert a string to Morse code
void toMorseCode(char *text) {
    int i, n;
    char *morse = (char *)malloc(strlen(text) + 1);
    strcpy(morse, text);
    for (i = 0, n = strlen(morse); i < n; i++) {
        morse[i] = toMorse(morse[i]);
    }
    printf("%s\n", morse);
}

int main() {
    char text[] = "Hello, World!";
    toMorseCode(text);
    return 0;
}