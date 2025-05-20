//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *morseCode[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.",
    "....", "..", ".---", "-.-", ".-..", "--", "-.",
    "---", ".--.", "--.-", ".-.", "...", "-", "..-",
    "...-", ".--", "-..-", "-.--", "--..", ".-.-",
    ".-..", "---.", "..-.", ".-..", "..--", ".-.",
    "---", ".--.", ".-..", "..--", "-...-", "-....",
    "--...", "---..", ".----", "..---", "...--", "....-",
    ".....", "-....-", "--...", "---..", "----.", "-----"
};

char *getMorseCode(char c) {
    if (c >= 'A' && c <= 'Z') {
        return morseCode[c - 'A'];
    } else if (c >= 'a' && c <= 'z') {
        return morseCode[c - 'a'];
    } else if (c >= '0' && c <= '9') {
        return morseCode[c - '0' + 26];
    } else {
        return "";
    }
}

char *convertTextToMorse(char *text) {
    int textLen = strlen(text);
    char *morseCodeText = malloc(textLen * 5);

    int i, j, k = 0;
    for (i = 0; i < textLen; i++) {
        char *code = getMorseCode(text[i]);
        int codeLen = strlen(code);

        for (j = 0; j < codeLen; j++) {
            morseCodeText[k++] = code[j];
            morseCodeText[k++] = ' ';
        }

        morseCodeText[k++] = ' ';
    }

    morseCodeText[k] = '\0';

    return morseCodeText;
}

int main() {
    char text[] = "Hello World!";
    char *morseCodeText = convertTextToMorse(text);

    printf("Original Text: %s\n", text);
    printf("Morse Code: %s\n", morseCodeText);

    free(morseCodeText);

    return 0;
}