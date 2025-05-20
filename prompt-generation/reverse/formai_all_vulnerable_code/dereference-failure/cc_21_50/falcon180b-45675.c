//Falcon-180B DATASET v1.0 Category: Text to Morse code conversion ; Style: Sherlock Holmes
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAX_CODE_LENGTH 5
#define MAX_WORD_LENGTH 80

int main() {
    char input[MAX_WORD_LENGTH];
    char *output = malloc(MAX_CODE_LENGTH * sizeof(char));
    printf("Enter text to convert to Morse code: ");
    fgets(input, MAX_WORD_LENGTH, stdin);
    int length = strlen(input);
    int code_length = 0;
    for (int i = 0; i < length; i++) {
        if (isalpha(input[i])) {
            switch (tolower(input[i])) {
                case 'a':
                    strcat(output, ".-");
                    break;
                case 'b':
                    strcat(output, "-...");
                    break;
                case 'c':
                    strcat(output, "-.-.");
                    break;
                case 'd':
                    strcat(output, "-..");
                    break;
                case 'e':
                    strcat(output, ".");
                    break;
                case 'f':
                    strcat(output, "..-.");
                    break;
                case 'g':
                    strcat(output, "--.");
                    break;
                case 'h':
                    strcat(output, "....");
                    break;
                case 'i':
                    strcat(output, "..");
                    break;
                case 'j':
                    strcat(output, ".---");
                    break;
                case 'k':
                    strcat(output, "-.-");
                    break;
                case 'l':
                    strcat(output, ".-..");
                    break;
                case'm':
                    strcat(output, "--");
                    break;
                case 'n':
                    strcat(output, "-.");
                    break;
                case 'o':
                    strcat(output, "---");
                    break;
                case 'p':
                    strcat(output, ".--.");
                    break;
                case 'q':
                    strcat(output, "--.-");
                    break;
                case 'r':
                    strcat(output, ".-.");
                    break;
                case's':
                    strcat(output, "...");
                    break;
                case 't':
                    strcat(output, "-");
                    break;
                case 'u':
                    strcat(output, "..-");
                    break;
                case 'v':
                    strcat(output, "...-");
                    break;
                case 'w':
                    strcat(output, ".--");
                    break;
                case 'x':
                    strcat(output, "-..-");
                    break;
                case 'y':
                    strcat(output, "-.--");
                    break;
                case 'z':
                    strcat(output, "--..");
                    break;
                default:
                    strcat(output, " ");
                    break;
            }
            code_length++;
        }
    }
    printf("Morse code: %s\n", output);
    free(output);
    return 0;
}