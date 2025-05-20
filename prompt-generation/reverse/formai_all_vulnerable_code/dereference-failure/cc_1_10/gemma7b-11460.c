//Gemma-7B DATASET v1.0 Category: Cat Language Translator ; Style: automated
#include <stdio.h>
#include <string.h>

#define MAX_WORD_LENGTH 20

void translate(char *word)
{
    char *translatedWord = malloc(MAX_WORD_LENGTH);
    translatedWord[0] = '\0';

    // Replace vowels with their corresponding phonetic equivalents
    for (int i = 0; word[i] != '\0'; i++)
    {
        switch (word[i])
        {
            case 'a':
                translatedWord[i] = 'ah';
                break;
            case 'e':
                translatedWord[i] = 'eh';
                break;
            case 'i':
                translatedWord[i] = 'ih';
                break;
            case 'o':
                translatedWord[i] = 'oh';
                break;
            case 'u':
                translatedWord[i] = 'ooh';
                break;
        }
    }

    // Concatenate the translated word with the remaining characters
    strcat(translatedWord, word);

    // Print the translated word
    printf("%s\n", translatedWord);

    // Free the memory allocated for the translated word
    free(translatedWord);
}

int main()
{
    char word[MAX_WORD_LENGTH];

    printf("Enter a word: ");
    scanf("%s", word);

    translate(word);

    return 0;
}