//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: multivariable
#include <stdio.h>
#include <string.h>

typedef struct {
    char letter;
    char code[6];
} morse_code;

morse_code morse_map[] = {
    {'a', ".-"},
    {'b', "-..."},
    {'c', "-.-."},
    {'d', "-.."},
    {'e', "."},
    {'f', "..-."},
    {'g', "--."},
    {'h', "...."},
    {'i', ".."},
    {'j', ".---"},
    {'k', "-.-"},
    {'l', ".-.."},
    {'m', "--"},
    {'n', "-."},
    {'o', "---"},
    {'p', ".--."},
    {'q', "--.-"},
    {'r', ".-."},
    {'s', "..."},
    {'t', "-"},
    {'u', "..-"},
    {'v', "...-"},
    {'w', ".--"},
    {'x', "-..-"},
    {'y', "-.--"},
    {'z', "--.."},
    {'1', ".----"},
    {'2', "..---"},
    {'3', "...--"},
    {'4', "....-"},
    {'5', "....."},
    {'6', "-...."},
    {'7', "--..."},
    {'8', "---.."},
    {'9', "----."},
    {'0', "-----"},
    {' ', " "}
};

char* to_morse(char* str) {
    int len = strlen(str);
    char *morse_str = malloc((len * 6) + 1);

    for (int i = 0; i < len; i++) {
        for (int j = 0; j < 37; j++) {
            if (morse_map[j].letter == tolower(str[i])) {
                strcat(morse_str, morse_map[j].code);
                strcat(morse_str, " ");
            }
        }
    }

    return morse_str;
}

int main() {
    char input[100];
    printf("Enter a string to convert to Morse code: ");
    fgets(input, 100, stdin);

    char *output = to_morse(input);
    printf("Morse Code: %s\n", output);
    free(output);

    return 0;
}