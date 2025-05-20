//Gemma-7B DATASET v1.0 Category: Text processing ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char str1[] = "This is a string.";
    char str2[] = "It is a long string, with many words.";
    char str3[] = "And it has a lot of punctuation marks!";

    printf("Original string: %s", str1);
    printf("\n");

    // Reverse the order of words in str2
    char *ptr = str2;
    char **words = NULL;
    int wordCount = 0;
    while (ptr)
    {
        char *word = strtok(ptr, " ");
        if (word)
        {
            words = realloc(words, (wordCount + 1) * sizeof(char *));
            words[wordCount++] = word;
        }
        ptr = strchr(ptr, ' ') + 1;
    }

    printf("Reversed words: ");
    for (int i = 0; i < wordCount; i++)
    {
        printf("%s ", words[i]);
    }
    printf("\n");

    // Replace all punctuation marks in str3 with asterisks
    char *punc = str3;
    char *newStr = strdup(str3);
    while (punc)
    {
        char puncChar = *punc;
        if (puncChar >= 'a' && puncChar <= 'z')
        {
            *punc = '*';
        }
        punc++;
    }

    printf("Original string with punctuation marks replaced by asterisks: %s", newStr);
    printf("\n");

    free(words);
    free(newStr);

    return 0;
}