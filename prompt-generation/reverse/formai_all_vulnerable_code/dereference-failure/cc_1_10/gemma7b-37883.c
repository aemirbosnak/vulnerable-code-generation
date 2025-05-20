//Gemma-7B DATASET v1.0 Category: Text to Morse code conversion ; Style: all-encompassing
#include <stdio.h>
#include <string.h>

char morse_code[4] = {'.---', '-..---', '.---.', '--..---'};

void translate_text_to_morse(char text[])
{
    int i = 0;
    char word[20] = "";

    while (text[i] != '\0')
    {
        switch (text[i])
        {
            case 'a':
            case 'A':
                strcpy(word, morse_code[0]);
                break;
            case 'b':
            case 'B':
                strcpy(word, morse_code[1]);
                break;
            case 'c':
            case 'C':
                strcpy(word, morse_code[2]);
                break;
            case 'd':
            case 'D':
                strcpy(word, morse_code[3]);
                break;
            default:
                word[0] = '\0';
                break;
        }

        if (word[0] != '\0')
        {
            printf("%s ", word);
        }

        i++;
    }

    printf("\n");
}

int main()
{
    translate_text_to_morse("Hello, world!");

    return 0;
}