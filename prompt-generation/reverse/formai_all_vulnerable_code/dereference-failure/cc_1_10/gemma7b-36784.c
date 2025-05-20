//Gemma-7B DATASET v1.0 Category: Cat Language Translator ; Style: peaceful
#include <stdio.h>
#include <string.h>

void translate_c(char *sentence)
{
    char *translated_sentence = malloc(strlen(sentence) * 2);
    int i = 0;
    int j = 0;

    for (i = 0; sentence[i] != '\0'; i++)
    {
        switch (sentence[i])
        {
            case 'a':
                translated_sentence[j] = 'A';
                break;
            case 'e':
                translated_sentence[j] = 'E';
                break;
            case 'i':
                translated_sentence[j] = 'I';
                break;
            case 'o':
                translated_sentence[j] = 'O';
                break;
            case 'u':
                translated_sentence[j] = 'U';
                break;
            default:
                translated_sentence[j] = sentence[i];
                break;
        }

        j++;
    }

    translated_sentence[j] = '\0';

    printf("%s", translated_sentence);
    free(translated_sentence);
}

int main()
{
    char sentence[100] = "Hello, world!";

    translate_c(sentence);

    return 0;
}