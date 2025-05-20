//Gemma-7B DATASET v1.0 Category: Cat Language Translator ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void translate(char *source, char **target)
{
    int i = 0;
    int j = 0;
    char *t = malloc(1024);

    while (source[i] != '\0')
    {
        switch (source[i])
        {
            case 'a':
                t[j] = 'a';
                break;
            case 'e':
                t[j] = 'e';
                break;
            case 'i':
                t[j] = 'i';
                break;
            case 'o':
                t[j] = 'o';
                break;
            case 'u':
                t[j] = 'u';
                break;
            default:
                t[j] = source[i];
                break;
        }

        i++;
        j++;
    }

    t[j] = '\0';
    *target = t;
}

int main()
{
    char *source = "Meow, human!";
    char *target = NULL;

    translate(source, &target);

    printf("Translated: %s\n", target);

    free(target);

    return 0;
}