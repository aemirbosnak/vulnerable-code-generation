//Gemma-7B DATASET v1.0 Category: Alien Language Translator ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define GALACTIC_SOUND "blorg zork quux"

void alien_translator(char **buffer)
{
    int i = 0;
    char alien_sound = 'a';

    while (*buffer[i] != '\0')
    {
        switch (*buffer[i])
        {
            case 'a':
                *buffer[i] = alien_sound;
                break;
            case 'e':
                *buffer[i] = alien_sound + 2;
                break;
            case 'i':
                *buffer[i] = alien_sound + 4;
                break;
            case 'o':
                *buffer[i] = alien_sound + 6;
                break;
            case 'u':
                *buffer[i] = alien_sound + 8;
                break;
            default:
                *buffer[i] = alien_sound + 1;
                break;
        }

        i++;
    }

    printf("%s", GALACTIC_SOUND);
}

int main()
{
    char *buffer = malloc(100);
    strcpy(buffer, "Hello, human. I am an alien.");

    alien_translator(&buffer);

    free(buffer);

    return 0;
}