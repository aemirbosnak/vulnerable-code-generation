//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1024

typedef struct {
    char alpha;
    char morse[6];
} morse_code;

morse_code morse_table[] = {
    {'A', ".-"}, {'B', "-..."}, {'C', "-.-."}, {'D', "-.."}, {'E', "."}, {'F', "..-."},
    {'G', "--."}, {'H', "...."}, {'I', ".."}, {'J', ".---"}, {'K', "-.-"}, {'L', ".-.."},
    {'M', "--"}, {'N', "-."}, {'O', "---"}, {'P', ".--."}, {'Q', "--.-"}, {'R', ".-."},
    {'S', "..."}, {'T', "-"}, {'U', "..-"}, {'V', "...-"}, {'W', ".--"}, {'X', "-..-"},
    {'Y', "-.--"}, {'Z', "--.."}, {'0', "-----"}, {'1', ".----"}, {'2', "..---"},
    {'3', "...--"}, {'4', "....-"}, {'5', "....."}, {'6', "-...."}, {'7', "--..."},
    {'8', "---.."}, {'9', "----."}, {' ', " "}
};

char *translate_to_morse(char *text) {
    char *morse_code = malloc(MAX_LEN);
    int len = strlen(text);
    int i, j;

    for (i = 0; i < len; i++) {
        for (j = 0; j < 44; j++) {
            if (text[i] == morse_table[j].alpha) {
                strcat(morse_code, morse_table[j].morse);
                strcat(morse_code, " ");
                break;
            }
        }
    }

    return morse_code;
}

int main() {
    char text[MAX_LEN];

    printf("Enter a text: ");
    scanf("%s", text);

    char *morse_code = translate_to_morse(text);

    printf("Morse code: %s\n", morse_code);

    return 0;
}