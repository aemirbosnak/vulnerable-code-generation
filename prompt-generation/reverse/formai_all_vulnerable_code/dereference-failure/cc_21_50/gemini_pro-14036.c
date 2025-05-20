//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *text2morse(char *text) {
    char *morse = malloc(strlen(text) * 5 + 1);
    int i, j, k;
    for (i = 0, j = 0; text[i]; i++) {
        switch (text[i]) {
        case ' ':
            morse[j++] = ' ';
            break;
        case 'A':
        case 'a':
            morse[j++] = '.';
            morse[j++] = '-';
            break;
        case 'B':
        case 'b':
            morse[j++] = '-';
            morse[j++] = '...';
            break;
        case 'C':
        case 'c':
            morse[j++] = '-';
            morse[j++] = '.';
            morse[j++] = '-';
            morse[j++] = '.';
            break;
        case 'D':
        case 'd':
            morse[j++] = '-';
            morse[j++] = '.';
            morse[j++] = '..';
            break;
        case 'E':
        case 'e':
            morse[j++] = '.';
            break;
        case 'F':
        case 'f':
            morse[j++] = '..';
            morse[j++] = '.';
            morse[j++] = '-';
            break;
        case 'G':
        case 'g':
            morse[j++] = '--';
            morse[j++] = '.';
            break;
        case 'H':
        case 'h':
            morse[j++] = '....';
            break;
        case 'I':
        case 'i':
            morse[j++] = '..';
            break;
        case 'J':
        case 'j':
            morse[j++] = '.';
            morse[j++] = '---';
            morse[j++] = '-';
            break;
        case 'K':
        case 'k':
            morse[j++] = '-';
            morse[j++] = '.';
            morse[j++] = '-';
            break;
        case 'L':
        case 'l':
            morse[j++] = '.';
            morse[j++] = '..';
            morse[j++] = '-';
            break;
        case 'M':
        case 'm':
            morse[j++] = '--';
            break;
        case 'N':
        case 'n':
            morse[j++] = '-';
            morse[j++] = '.';
            break;
        case 'O':
        case 'o':
            morse[j++] = '---';
            break;
        case 'P':
        case 'p':
            morse[j++] = '.';
            morse[j++] = '--';
            morse[j++] = '.';
            break;
        case 'Q':
        case 'q':
            morse[j++] = '--';
            morse[j++] = '-';
            morse[j++] = '.';
            break;
        case 'R':
        case 'r':
            morse[j++] = '.';
            morse[j++] = '.';
            morse[j++] = '.';
            break;
        case 'S':
        case 's':
            morse[j++] = '...';
            break;
        case 'T':
        case 't':
            morse[j++] = '-';
            break;
        case 'U':
        case 'u':
            morse[j++] = '..-';
            morse[j++] = '-';
            break;
        case 'V':
        case 'v':
            morse[j++] = '...-';
            morse[j++] = '.';
            break;
        case 'W':
        case 'w':
            morse[j++] = '.';
            morse[j++] = '--';
            break;
        case 'X':
        case 'x':
            morse[j++] = '-..-';
            break;
        case 'Y':
        case 'y':
            morse[j++] = '-.--';
            morse[j++] = '--';
            break;
        case 'Z':
        case 'z':
            morse[j++] = '--..';
            break;
        case '0':
            morse[j++] = '-----';
            break;
        case '1':
            morse[j++] = '.----';
            break;
        case '2':
            morse[j++] = '..---';
            break;
        case '3':
            morse[j++] = '...--';
            break;
        case '4':
            morse[j++] = '....-';
            break;
        case '5':
            morse[j++] = '.....';
            break;
        case '6':
            morse[j++] = '-....';
            break;
        case '7':
            morse[j++] = '--...';
            break;
        case '8':
            morse[j++] = '---..';
            break;
        case '9':
            morse[j++] = '----.';
            break;
        case '.':
            morse[j++] = '.-.-.-';
            break;
        case ',':
            morse[j++] = '--..--';
            break;
        case '?':
            morse[j++] = '..--..';
            break;
        case '!':
            morse[j++] = '-.-.--';
            break;
        case '/':
            morse[j++] = '-..-.';
            break;
        case '(':
            morse[j++] = '-.--.';
            break;
        case ')':
            morse[j++] = '-.--.-';
            break;
        case '&':
            morse[j++] = '.-...';
            break;
        case ':':
            morse[j++] = '---...';
            break;
        case ';':
            morse[j++] = '-.-.-.';
            break;
        case '=':
            morse[j++] = '-...-';
            break;
        case '+':
            morse[j++] = '.-.-.';
            break;
        case '-':
            morse[j++] = '-....-';
            break;
        case '_':
            morse[j++] = '..--.-';
            break;
        case '"':
            morse[j++] = '.-..-.';
            break;
        case '$':
            morse[j++] = '...-..-';
            break;
        case '@':
            morse[j++] = '.--.-.';
            break;
        }
    }
    morse[j] = '\0';
    return morse;
}

int main() {
    char *text = "Hello world! 123";
    char *morse = text2morse(text);
    printf("%s\n", morse);
    free(morse);
    return 0;
}