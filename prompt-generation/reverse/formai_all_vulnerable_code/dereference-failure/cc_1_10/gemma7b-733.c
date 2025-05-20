//Gemma-7B DATASET v1.0 Category: Spam Detection System ; Style: inquisitive
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_WORDS 100

char **word_list;

void load_words(char *text)
{
    char **words = NULL;
    int num_words = 0;
    char *word = NULL;

    words = malloc(MAX_WORDS * sizeof(char *));
    word_list = words;

    word = strtok(text, " \t\n");
    while (word)
    {
        words[num_words++] = strdup(word);
        word = strtok(NULL, " \t\n");
    }

    words[num_words] = NULL;
}

int is_spam(char *text)
{
    load_words(text);

    for (int i = 0; word_list[i] != NULL; i++)
    {
        if (strcmp(word_list[i], "free") == 0 ||
            strcmp(word_list[i], "lottery") == 0 ||
            strcmp(word_list[i], "miracle") == 0)
        {
            return 1;
        }
    }

    return 0;
}

int main()
{
    char *text = "You have won $10,000!";

    if (is_spam(text))
    {
        printf("Spam detected!");
    }
    else
    {
        printf("Not spam.");
    }

    return 0;
}