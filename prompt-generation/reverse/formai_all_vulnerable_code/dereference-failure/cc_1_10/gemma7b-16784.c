//Gemma-7B DATASET v1.0 Category: Alien Language Translator ; Style: complete
#include <stdio.h>
#include <string.h>

#define ALIENS_LANG_SIZE 20

typedef struct AlienLanguage
{
    char phrases[ALIENS_LANG_SIZE];
    int current_phrase_index;
} AlienLanguage;

AlienLanguage alien_language;

void alien_language_init()
{
    alien_language.current_phrase_index = 0;
    for (int i = 0; i < ALIENS_LANG_SIZE; i++)
    {
        alien_language.phrases[i] = '\0';
    }
}

void alien_language_add_phrase(char *phrase)
{
    strcpy(alien_language.phrases[alien_language.current_phrase_index], phrase);
    alien_language.current_phrase_index++;
}

char *alien_language_get_phrase(int index)
{
    return alien_language.phrases[index];
}

int alien_language_get_phrase_count()
{
    return alien_language.current_phrase_index;
}

int main()
{
    alien_language_init();

    alien_language_add_phrase("Greetings, traveler.");
    alien_language_add_phrase("May the force be with you.");
    alien_language_add_phrase("We come in peace.");

    for (int i = 0; i < alien_language_get_phrase_count(); i++)
    {
        printf("%s\n", alien_language_get_phrase(i));
    }

    return 0;
}