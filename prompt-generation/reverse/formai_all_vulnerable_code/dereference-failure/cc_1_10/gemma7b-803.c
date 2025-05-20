//Gemma-7B DATASET v1.0 Category: Cat Language Translator ; Style: energetic
#include <stdio.h>
#include <string.h>

#define MAX_WORD_LENGTH 20

void translate(char **word, int length)
{
    char *newWord = malloc(length * MAX_WORD_LENGTH);
    int i = 0;

    for (; i < length; i++)
    {
        switch (*word[i])
        {
            case 'a':
                newWord[i] = '4';
                break;
            case 'e':
                newWord[i] = '3';
                break;
            case 'i':
                newWord[i] = '2';
                break;
            case 'o':
                newWord[i] = '5';
                break;
            case 'u':
                newWord[i] = '8';
                break;
            default:
                newWord[i] = *word[i];
                break;
        }
    }

    free(word);
    word = newWord;
}

int main()
{
    char *word = "Meow";
    int length = strlen(word);

    translate(&word, length);

    printf("%s", word);

    return 0;
}