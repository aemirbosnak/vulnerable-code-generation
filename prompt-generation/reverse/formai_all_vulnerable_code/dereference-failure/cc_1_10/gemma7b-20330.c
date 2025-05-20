//Gemma-7B DATASET v1.0 Category: Spell checking ; Style: paranoid
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>

#define MAX_WORDS 1024
#define MAX_WORD_LENGTH 256

char **words = NULL;

void load_words(void)
{
    FILE *fp = fopen("words.txt", "r");
    if (fp == NULL)
    {
        perror("Error opening words.txt");
        exit(1);
    }

    words = malloc(MAX_WORDS * sizeof(char *));
    if (words == NULL)
    {
        perror("Error allocating memory");
        exit(1);
    }

    char line[MAX_WORD_LENGTH];
    int i = 0;
    while (fgets(line, MAX_WORD_LENGTH, fp) != NULL)
    {
        words[i++] = strdup(line);
    }

    fclose(fp);
}

int spell_check(char *word)
{
    load_words();

    for (int i = 0; i < MAX_WORDS; i++)
    {
        if (strcmp(words[i], word) == 0)
        {
            return 1;
        }
    }

    return 0;
}

int main()
{
    char word[MAX_WORD_LENGTH];

    printf("Enter a word: ");
    scanf("%s", word);

    if (spell_check(word))
    {
        printf("Word is spelled correctly.\n");
    }
    else
    {
        printf("Word is not spelled correctly.\n");
    }

    return 0;
}