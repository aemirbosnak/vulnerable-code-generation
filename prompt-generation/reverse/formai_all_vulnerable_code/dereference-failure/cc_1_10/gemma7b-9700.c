//Gemma-7B DATASET v1.0 Category: Alien Language Translator ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

#define ALIENS "extraterrestrial"
#define LANG "C-Alien"

void translate(char *alien_phrase)
{
    char *translated_phrase = malloc(1024);
    translated_phrase[0] = '\0';

    for (int i = 0; alien_phrase[i] != '\0'; i++)
    {
        switch (alien_phrase[i])
        {
            case 'z':
                translated_phrase[i] = 'a';
                break;
            case 'Z':
                translated_phrase[i] = 'A';
                break;
            case 'q':
                translated_phrase[i] = 'w';
                break;
            case 'Q':
                translated_phrase[i] = 'W';
                break;
            case 'o':
                translated_phrase[i] = 'e';
                break;
            case 'O':
                translated_phrase[i] = 'E';
                break;
            default:
                translated_phrase[i] = alien_phrase[i];
                break;
        }
    }

    printf("%s translated into %s: %s\n", ALIENS, LANG, translated_phrase);
    free(translated_phrase);
}

int main()
{
    char alien_phrase[1024] = "Skreech'blzzzt, qu'blarz qu'blzzzt!";
    translate(alien_phrase);

    return 0;
}