//Gemma-7B DATASET v1.0 Category: Alien Language Translator ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

#define MAX_WORDS 10
#define MAX_WORD_LENGTH 20

void alien_translator(char **words, int index, char *translated_word)
{
    int i;
    char alien_word[MAX_WORD_LENGTH];

    if (index >= MAX_WORDS)
    {
        return;
    }

    printf("Enter an alien word: ");
    scanf("%s", alien_word);

    // Translate the alien word
    for (i = 0; alien_word[i] != '\0'; i++)
    {
        switch (alien_word[i])
        {
            case 'a':
                translated_word[i] = 'a';
                break;
            case 'b':
                translated_word[i] = 'b';
                break;
            case 'c':
                translated_word[i] = 'c';
                break;
            case 'd':
                translated_word[i] = 'd';
                break;
            case 'e':
                translated_word[i] = 'e';
                break;
            default:
                translated_word[i] = ' ';
                break;
        }
    }

    // Add the translated word to the array
    words[index] = translated_word;

    // Translate the remaining words
    alien_translator(words, index + 1, translated_word);
}

int main()
{
    char **words = (char **)malloc(MAX_WORDS * sizeof(char *));
    char translated_word[MAX_WORD_LENGTH];

    alien_translator(words, 0, translated_word);

    // Print the translated words
    for (int i = 0; words[i] != NULL; i++)
    {
        printf("%s\n", words[i]);
    }

    return 0;
}