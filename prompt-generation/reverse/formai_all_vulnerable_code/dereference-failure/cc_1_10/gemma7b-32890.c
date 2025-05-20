//Gemma-7B DATASET v1.0 Category: Alien Language Translator ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>

#define RAND_MAX 2147483647

void alien_speak(char **phrase)
{
    int i, j, k, l, num_words, alien_noise;
    char alien_phrase[1000], temp[100], vowel_sound[10], consonant_sound[10], tone[2];

    num_words = rand() % 5 + 1;
    alien_noise = rand() % RAND_MAX;

    for (i = 0; i < num_words; i++)
    {
        l = rand() % 10 + 1;
        alien_phrase[i] = 'a' + l;
    }

    alien_phrase[num_words] = '\0';

    for (i = 0; i < alien_noise; i++)
    {
        printf("Blorg! ");
    }

    printf("%s\n", alien_phrase);

    for (k = 0; k < num_words; k++)
    {
        switch (alien_phrase[k])
        {
            case 'a':
                vowel_sound[k] = 'oo';
                break;
            case 'e':
                vowel_sound[k] = 'ah';
                break;
            case 'i':
                vowel_sound[k] = 'ee';
                break;
            case 'o':
                vowel_sound[k] = 'ah';
                break;
            case 'u':
                vowel_sound[k] = 'oh';
                break;
            default:
                consonant_sound[k] = 'b';
                break;
        }
    }

    for (i = 0; i < num_words; i++)
    {
        printf("%c ", vowel_sound[i]);
    }

    printf("\n");

    for (i = 0; i < num_words; i++)
    {
        printf("%c ", consonant_sound[i]);
    }

    printf("\n");

    for (k = 0; k < num_words; k++)
    {
        switch (alien_phrase[k])
        {
            case 'a':
                tone[k] = 'high';
                break;
            case 'e':
                tone[k] = 'low';
                break;
            case 'i':
                tone[k] = 'sharp';
                break;
            case 'o':
                tone[k] = 'smooth';
                break;
            case 'u':
                tone[k] = 'vibrant';
                break;
            default:
                tone[k] = 'neutral';
                break;
        }
    }

    for (i = 0; i < num_words; i++)
    {
        printf("%s ", tone[i]);
    }

    printf("\n");

    free(*phrase);
}

int main()
{
    char *phrase = malloc(100);

    alien_speak(phrase);

    return 0;
}