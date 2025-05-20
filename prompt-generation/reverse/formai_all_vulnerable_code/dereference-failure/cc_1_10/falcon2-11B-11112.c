//Falcon2-11B DATASET v1.0 Category: Text to Morse code conversion ; Style: peaceful
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

// Convert a character to its corresponding Morse code
char toMorse(char c) {
    switch (c) {
        case 'A': return ".-";
        case 'B': return "-...";
        case 'C': return "-.-.";
        case 'D': return "-..";
        case 'E': return ".";
        case 'F': return "..-.";
        case 'G': return "--.";
        case 'H': return "....";
        case 'I': return "..";
        case 'J': return ".---";
        case 'K': return "-.-";
        case 'L': return ".-..";
        case 'M': return "--";
        case 'N': return "-.";
        case 'O': return "---";
        case 'P': return ".--.";
        case 'Q': return "--.-";
        case 'R': return ".-.";
        case 'S': return "...";
        case 'T': return "-";
        case 'U': return "..-";
        case 'V': return "...-";
        case 'W': return ".--";
        case 'X': return "-..-";
        case 'Y': return "-.--";
        case 'Z': return "--..";
        default: return "";
    }
}

// Convert a string to Morse code
char *toMorseCode(char *str) {
    char *result = (char *)malloc(strlen(str) + 1);
    int i = 0;
    for (; *str!= '\0'; str++) {
        result[i++] = toMorse(*str);
    }
    result[i] = '\0';
    return result;
}

int main() {
    char *str = "hello world";
    char *morseCode = toMorseCode(str);
    printf("Morse Code: %s\n", morseCode);
    free(morseCode);
    return 0;
}