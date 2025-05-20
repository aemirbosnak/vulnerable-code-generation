//Gemma-7B DATASET v1.0 Category: Spam Detection System ; Style: Claude Shannon
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char *message = "This is a spamy message, full of exclamation marks!!!";
    int spamy_score = spam_detector(message);
    if (spamy_score > 5)
    {
        printf("This message is highly spamy.\n");
    }
    else
    {
        printf("This message is not spamy.\n");
    }

    return 0;
}

int spam_detector(char *message)
{
    int spamy_words = count_words(message, "spam");
    int exclamation_marks = count_symbols(message, "!") + count_symbols(message, "?");
    int length = strlen(message);

    return spamy_words + exclamation_marks * length;
}

int count_words(char *message, char *word)
{
    int count = 0;
    char *token = strtok(message, " ");
    while (token)
    {
        if (strcmp(token, word) == 0)
        {
            count++;
        }
        token = strtok(NULL, " ");
    }

    return count;
}

int count_symbols(char *message, char *symbol)
{
    int count = 0;
    for (int i = 0; i < strlen(message); i++)
    {
        if (message[i] == symbol[0] || message[i] == symbol[1])
        {
            count++;
        }
    }

    return count;
}