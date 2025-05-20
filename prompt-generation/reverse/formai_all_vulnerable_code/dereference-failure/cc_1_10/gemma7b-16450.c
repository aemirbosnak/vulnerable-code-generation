//Gemma-7B DATASET v1.0 Category: Cat Language Translator ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

void translate_c_cat(char **translate)
{
    int i = 0;
    char *src = translate[0];
    char *dest = translate[1];

    for (; src[i] != '\0'; i++)
    {
        switch (src[i])
        {
            case 'a':
                dest[i] = 'A';
                break;
            case 'e':
                dest[i] = 'E';
                break;
            case 'i':
                dest[i] = 'I';
                break;
            case 'o':
                dest[i] = 'O';
                break;
            case 'u':
                dest[i] = 'U';
                break;
            default:
                dest[i] = src[i];
                break;
        }
    }

    dest[i] = '\0';
}

int main()
{
    char **translate = malloc(sizeof(char *) * 2);
    translate[0] = "Meow, human!";
    translate[1] = "";

    translate_c_cat(translate);

    printf("%s\n", translate[1]);

    free(translate);

    return 0;
}