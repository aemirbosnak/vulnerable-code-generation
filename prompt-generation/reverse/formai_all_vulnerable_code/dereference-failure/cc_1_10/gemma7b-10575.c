//Gemma-7B DATASET v1.0 Category: Cat Language Translator ; Style: calm
#include <stdio.h>
#include <string.h>

void translate(char *source, char *target)
{
    int i, j, k, l, source_length, target_length;

    source_length = strlen(source);
    target_length = source_length * 2;
    target = malloc(target_length);

    for (i = 0; i < source_length; i++)
    {
        switch (source[i])
        {
            case 'a':
                target[k] = 'a';
                break;
            case 'e':
                target[k] = 'e';
                break;
            case 'i':
                target[k] = 'i';
                break;
            case 'o':
                target[k] = 'o';
                break;
            case 'u':
                target[k] = 'u';
                break;
            default:
                target[k] = source[i];
                break;
        }

        k++;
    }

    target[k] = '\0';

    printf("%s", target);
}

int main()
{
    char *source = "Hello, world!";
    char *target = NULL;

    translate(source, target);

    printf("\nThe translated text is: %s", target);

    free(target);

    return 0;
}