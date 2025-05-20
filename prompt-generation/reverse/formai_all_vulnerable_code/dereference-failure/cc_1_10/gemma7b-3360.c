//Gemma-7B DATASET v1.0 Category: Text to Morse code conversion ; Style: Ken Thompson
#include <stdio.h>
#include <string.h>

#define MORSE_DICT ".-.. --- .-. .-.. --- |.. --- ..-. .-.."

static int morse_dict_size = 30;

char **morse_dict_arr = NULL;

void morse_code_init()
{
    morse_dict_arr = malloc(morse_dict_size * sizeof(char *));

    for (int i = 0; i < morse_dict_size; i++)
    {
        morse_dict_arr[i] = malloc(10 * sizeof(char));
    }

    strcpy(morse_dict_arr[0], MORSE_DICT);
}

char **morse_dict_get(char letter)
{
    for (int i = 0; i < morse_dict_size; i++)
    {
        if (letter == morse_dict_arr[i][0])
        {
            return morse_dict_arr[i];
        }
    }

    return NULL;
}

int main()
{
    morse_code_init();

    char *message = "HELLO WORLD!";

    for (int i = 0; i < strlen(message); i++)
    {
        char letter = message[i];

        char *morse_code = morse_dict_get(letter);

        if (morse_code)
        {
            printf("%s ", morse_code);
        }
    }

    printf("\n");

    return 0;
}