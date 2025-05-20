//Gemma-7B DATASET v1.0 Category: Alien Language Translator ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void alien_translator(char **str)
{
    char **trans_str = NULL;
    int i = 0;
    int str_len = strlen(*str);

    trans_str = malloc(sizeof(char *) * (str_len + 1));

    for (i = 0; i < str_len; i++)
    {
        switch (*str[i])
        {
            case 'a':
                trans_str[i] = 'x';
                break;
            case 'e':
                trans_str[i] = 'z';
                break;
            case 'i':
                trans_str[i] = 'h';
                break;
            case 'o':
                trans_str[i] = 't';
                break;
            default:
                trans_str[i] = *str[i];
                break;
        }
    }

    trans_str[str_len] = '\0';

    *str = trans_str;
}

int main()
{
    char *str = "Hello, world!";

    alien_translator(&str);

    printf("%s\n", str);

    free(str);

    return 0;
}