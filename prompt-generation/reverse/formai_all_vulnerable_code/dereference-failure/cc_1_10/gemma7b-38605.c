//Gemma-7B DATASET v1.0 Category: Spell checking ; Style: brave
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORD_LENGTH 20

void spellcheck(char **wordList, int wordListSize)
{
    int i;
    char word[MAX_WORD_LENGTH];

    printf("Enter a word: ");
    scanf("%s", word);

    for (i = 0; i < wordListSize; i++)
    {
        if (strcmp(word, wordList[i]) == 0)
        {
            printf("Word found: %s\n", wordList[i]);
            break;
        }
    }

    if (i == wordListSize)
    {
        printf("Word not found.\n");
    }
}

int main()
{
    char **wordList = NULL;
    int wordListSize = 0;

    wordList = malloc(sizeof(char *) * 10);
    wordListSize = 10;

    wordList[0] = "apple";
    wordList[1] = "banana";
    wordList[2] = "orange";
    wordList[3] = "grape";
    wordList[4] = "mango";
    wordList[5] = "apricot";
    wordList[6] = "peach";
    wordList[7] = "watermelon";
    wordList[8] = "strawberry";
    wordList[9] = "pineapple";

    spellcheck(wordList, wordListSize);

    free(wordList);

    return 0;
}