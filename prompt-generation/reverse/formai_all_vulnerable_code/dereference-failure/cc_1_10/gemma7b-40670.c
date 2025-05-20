//Gemma-7B DATASET v1.0 Category: Alien Language Translator ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define alien_greeting "Skreeeeetch!"
#define alien_language_alphabet "Zork's ABC"
#define alien_language_punctuation "Blork's Symbols!"

int alien_language_translate(char *phrase)
{
    char *translated_phrase = malloc(strlen(phrase) * 2);
    int i = 0;

    for (i = 0; phrase[i] != '\0'; i++)
    {
        switch (phrase[i])
        {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                translated_phrase[i] = alien_language_alphabet[0];
                break;
            case 'A':
            case 'E':
            case 'I':
            case 'O':
            case 'U':
                translated_phrase[i] = alien_language_alphabet[1];
                break;
            case ' ':
                translated_phrase[i] = alien_language_punctuation[0];
                break;
            default:
                translated_phrase[i] = phrase[i];
                break;
        }
    }

    translated_phrase[strlen(phrase)] = '\0';

    return translated_phrase;
}

int main()
{
    char *phrase = "The quick brown fox jumps over the lazy dog.";
    char *translated_phrase = alien_language_translate(phrase);

    printf("%s\n", translated_phrase);

    free(translated_phrase);

    return 0;
}