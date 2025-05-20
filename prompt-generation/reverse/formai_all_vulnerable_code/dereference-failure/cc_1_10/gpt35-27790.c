//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 256

char *morse_table[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---",
    "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-",
    "..-", "...-", ".--", "-..-", "-.--", "--..", "-----", ".----", "..---",
    "...--", "....-", ".....", "-....", "--...", "---..", "----."
};

char *alpha_table[] = {
    "A", "B", "C", "D", "E", "F", "G", "H", "I", "J",
    "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T",
    "U", "V", "W", "X", "Y", "Z", "0", "1", "2", "3",
    "4", "5", "6", "7", "8", "9"
};

char *to_morse_code(char *text) {
    char *morse = malloc(MAX_LEN); // allocate memory to store morse code
    int morse_index = 0;
    int i, j;

    for (i = 0; i < strlen(text); i++) {
        char c = toupper(text[i]);

        if (c == ' ') { // if space, add 3 spaces to morse code
            morse[morse_index++] = ' ';
            morse[morse_index++] = ' ';
            morse[morse_index++] = ' ';
        } else {
            for (j = 0; j < 36; j++) {
                if (c == alpha_table[j][0]) { // if character found, add corresponding morse code to morse array
                    char *morse_code = morse_table[j];
                    int k = 0;
                    while (morse_code[k]) {
                        morse[morse_index++] = morse_code[k];
                        k++;
                    }
                    morse[morse_index++] = ' '; // add space after each morse code
                    break;
                }
            }
        }
    }

    morse[morse_index - 1] = '\0'; // add null terminator at the end
    return morse;
}

int main() {
    char text[MAX_LEN];
    printf("Enter text to convert to Morse code: ");
    fgets(text, MAX_LEN, stdin);
    text[strcspn(text, "\n")] = '\0'; // remove newline character

    char *morse = to_morse_code(text);
    printf("Morse code: %s\n", morse);

    free(morse); // deallocate memory
    return 0;
}