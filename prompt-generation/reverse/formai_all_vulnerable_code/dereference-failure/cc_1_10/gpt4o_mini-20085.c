//GPT-4o-mini DATASET v1.0 Category: Text to Morse code conversion ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 1000

// Morse code representation for each alphabet and number.
const char *morseCode[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..",
    ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.",
    "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..",
    "-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----."
};

const char alphabets[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

// Function Prototypes
void textToMorse(const char *text, char *morseOutput);
void convertCharToMorse(char ch, char *output);
void trimWhitespace(char *str);
void toUpperCase(char *str);
void printUsage();

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printUsage();
        return EXIT_FAILURE;
    }

    char morseOutput[MAX_LEN] = "";
    char *inputText = argv[1];

    toUpperCase(inputText);
    trimWhitespace(inputText);
    textToMorse(inputText, morseOutput);

    printf("Original Text: %s\n", inputText);
    printf("Morse Code: %s\n", morseOutput);
    return EXIT_SUCCESS;
}

void printUsage() {
    printf("Usage: ./morse_converter <text_to_convert>\n");
    printf("Converts the provided text into Morse code.\n");
}

void toUpperCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = toupper(str[i]);
    }
}

void trimWhitespace(char *str) {
    char *end;

    // Trim leading space
    while(isspace((unsigned char)*str)) str++;

    // Trim trailing space
    end = str + strlen(str) - 1;
    while(end > str && isspace((unsigned char)*end)) end--;

    *(end + 1) = '\0';
}

void convertCharToMorse(char ch, char *output) {
    for (size_t i = 0; i < sizeof(alphabets); i++) {
        if (ch == alphabets[i]) {
            strcat(output, morseCode[i]);
            strcat(output, " "); // add space between letters
            return;
        }
    }
}

void textToMorse(const char *text, char *morseOutput) {
    for (size_t i = 0; i < strlen(text); i++) {
        if (text[i] != ' ') {
            convertCharToMorse(text[i], morseOutput);
        } else {
            strcat(morseOutput, "/ "); // Use '/' to represent space between words
        }
    }
}