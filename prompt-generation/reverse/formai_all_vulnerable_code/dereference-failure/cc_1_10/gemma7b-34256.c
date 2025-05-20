//Gemma-7B DATASET v1.0 Category: Alien Language Translator ; Style: curious
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void alien_translator(char *str)
{
    int i, l, trans_str_len = 0, alien_str_len = 0;
    char *trans_str = NULL, *alien_str = NULL;

    l = strlen(str);
    alien_str_len = l * 2 + 1;
    alien_str = malloc(alien_str_len);
    trans_str_len = l + 1;
    trans_str = malloc(trans_str_len);

    for (i = 0; i < l; i++)
    {
        switch (str[i])
        {
            case 'a':
                alien_str[trans_str_len++] = 'z';
                break;
            case 'e':
                alien_str[trans_str_len++] = 'x';
                break;
            case 'i':
                alien_str[trans_str_len++] = 'c';
                break;
            case 'o':
                alien_str[trans_str_len++] = 'a';
                break;
            case 'u':
                alien_str[trans_str_len++] = 'r';
                break;
            default:
                alien_str[trans_str_len++] = str[i];
                break;
        }

        alien_str[trans_str_len++] = ' ';
    }

    alien_str[trans_str_len - 1] = '\0';

    printf("%s\n", alien_str);

    free(alien_str);
    free(trans_str);
}

int main()
{
    char str[] = "Hello, world!";

    alien_translator(str);

    return 0;
}