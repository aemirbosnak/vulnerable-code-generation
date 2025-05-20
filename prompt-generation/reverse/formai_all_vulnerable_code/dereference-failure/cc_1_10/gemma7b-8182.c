//Gemma-7B DATASET v1.0 Category: Spam Detection System ; Style: accurate
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 20

int main()
{
    char text[1000];
    printf("Enter text: ");
    fgets(text, 1000, stdin);

    char words[MAX_WORD_LENGTH][MAX_WORD_LENGTH];
    int numWords = tokenize(text, words);

    int spamScore = calculateSpamScore(words);

    if (spamScore > 50)
    {
        printf("Your text is considered spam.\n");
    }
    else
    {
        printf("Your text is not considered spam.\n");
    }

    return 0;
}

int tokenize(char *text, char **words)
{
    int i = 0;
    char *word = strtok(text, " ");

    while (word)
    {
        strcpy(words[i], word);
        i++;
        word = strtok(NULL, " ");
    }

    return i;
}

int calculateSpamScore(char **words)
{
    int score = 0;
    for (int i = 0; words[i]; i++)
    {
        if (isSpamWord(words[i]))
        {
            score++;
        }
    }

    return score;
}

int isSpamWord(char *word)
{
    char *spamWords[] = {"buy", "free", "lottery", "miracle", "prize"};

    for (int i = 0; spamWords[i]; i++)
    {
        if (strcmp(word, spamWords[i]) == 0)
        {
            return 1;
        }
    }

    return 0;
}