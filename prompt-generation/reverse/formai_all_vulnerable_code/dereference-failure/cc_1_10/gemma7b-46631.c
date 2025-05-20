//Gemma-7B DATASET v1.0 Category: Alien Language Translator ; Style: happy
#include <stdio.h>
#include <string.h>

int alien_translator(char *alien_word)
{
    int i, alien_word_length, english_word_length;
    char *english_word;

    alien_word_length = strlen(alien_word);
    english_word_length = alien_word_length * 2;
    english_word = malloc(english_word_length);

    for (i = 0; i < alien_word_length; i++)
    {
        switch (alien_word[i])
        {
            case 'a':
                english_word[i] = 'A';
                break;
            case 'b':
                english_word[i] = 'B';
                break;
            case 'c':
                english_word[i] = 'C';
                break;
            case 'd':
                english_word[i] = 'D';
                break;
            case 'e':
                english_word[i] = 'E';
                break;
            default:
                english_word[i] = alien_word[i];
                break;
        }
    }

    english_word[english_word_length - 1] = '\0';

    return english_word_length;
}

int main()
{
    char alien_word[] = "extraterrestrial";
    int english_word_length = alien_translator(alien_word);
    char *english_word = malloc(english_word_length);

    alien_translator(alien_word);

    printf("The translated word is: %s\n", english_word);

    free(english_word);

    return 0;
}