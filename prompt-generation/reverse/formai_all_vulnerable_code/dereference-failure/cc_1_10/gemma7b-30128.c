//Gemma-7B DATASET v1.0 Category: Spell checking ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 10

char **words[MAX_WORDS];

void scan_for_errors(char *word)
{
    int i;
    for (i = 0; i < strlen(word); i++)
    {
        if (!isalnum(word[i]))
        {
            printf("Error: Non-alphanumeric character detected in word '%s'.\n", word);
            exit(1);
        }
    }

    if (strlen(word) < 3)
    {
        printf("Error: Word '%s' is too short. Minimum 3 characters are required.\n", word);
        exit(1);
    }

    if (word[0] == 'a' || word[0] == 'A')
    {
        printf("Error: Word '%s' begins with a vowel, which is not allowed.\n", word);
        exit(1);
    }
}

int main()
{
    int i = 0;

    words[i] = malloc(20);
    sprintf(words[i], "Hello, world!");

    words[i+1] = malloc(20);
    sprintf(words[i+1], "This is a sentence.");

    words[i+2] = malloc(20);
    sprintf(words[i+2], "The quick brown fox jumps over the lazy dog.");

    for (i = 0; i < MAX_WORDS; i++)
    {
        scan_for_errors(words[i]);
    }

    return 0;
}