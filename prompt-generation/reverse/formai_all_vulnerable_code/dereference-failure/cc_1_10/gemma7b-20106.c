//Gemma-7B DATASET v1.0 Category: Text to ASCII art generator ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void itoa(int num, char *str)
{
    int i = 0;
    char nstr[11];

    if (num == 0)
    {
        str[0] = '0';
        str[1] = '\0';
    }
    else
    {
        while (num)
        {
            int digit = num % 10;
            num /= 10;
            nstr[i++] = digit + '0';
        }
        nstr[i] = '\0';
        strcpy(str, nstr);
    }
}

int main()
{
    char text[] = "HELLO WORLD!";
    int text_len = strlen(text);

    int max_width = 50;
    char **ascii_art = malloc(max_width * text_len * sizeof(char *));

    for (int i = 0; i < text_len; i++)
    {
        ascii_art[i] = malloc(max_width * sizeof(char));
    }

    int row_height = 2;
    int current_row = 0;

    for (int i = 0; i < text_len; i++)
    {
        int char_width = 0;
        int max_char_width = 0;

        for (int j = 0; j < max_width; j++)
        {
            ascii_art[i][j] = ' ';
        }

        char letter = text[i];

        switch (letter)
        {
            case 'H':
                char_width = 6;
                max_char_width = 6;
                ascii_art[i][0] = '+';
                ascii_art[i][1] = '+';
                ascii_art[i][2] = '+';
                ascii_art[i][3] = ' ';
                ascii_art[i][4] = '+';
                ascii_art[i][5] = '+';
                break;
            case 'E':
                char_width = 3;
                max_char_width = 3;
                ascii_art[i][0] = '+';
                ascii_art[i][1] = ' ';
                ascii_art[i][2] = '+';
                break;
            case 'L':
                char_width = 3;
                max_char_width = 3;
                ascii_art[i][0] = '+';
                ascii_art[i][1] = ' ';
                ascii_art[i][2] = '+';
                break;
            case 'O':
                char_width = 3;
                max_char_width = 3;
                ascii_art[i][0] = '+';
                ascii_art[i][1] = ' ';
                ascii_art[i][2] = '+';
                break;
            case 'R':
                char_width = 3;
                max_char_width = 3;
                ascii_art[i][0] = '+';
                ascii_art[i][1] = ' ';
                ascii_art[i][2] = '+';
                break;
            case 'W':
                char_width = 6;
                max_char_width = 6;
                ascii_art[i][0] = '+';
                ascii_art[i][1] = ' ';
                ascii_art[i][2] = '+';
                ascii_art[i][3] = ' ';
                ascii_art[i][4] = '+';
                ascii_art[i][5] = '+';
                break;
            default:
                char_width = 1;
                max_char_width = 1;
                ascii_art[i][0] = letter;
        }

        int space_needed = max_char_width - char_width;

        for (int j = 0; j < space_needed; j++)
        {
            ascii_art[i][char_width++] = ' ';
        }

        ascii_art[i][char_width] = '\0';

        if (current_row == row_height - 1)
        {
            current_row = 0;
            printf("\n");
        }

        printf("%s", ascii_art[i]);

        current_row++;
    }

    for (int i = 0; i < text_len; i++)
    {
        free(ascii_art[i]);
    }

    free(ascii_art);

    return 0;
}