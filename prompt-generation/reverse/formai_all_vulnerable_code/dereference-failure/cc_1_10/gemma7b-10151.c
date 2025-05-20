//Gemma-7B DATASET v1.0 Category: Word Count Tool ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

int count_words(char **arr, int index, int total_words)
{
    char *word = NULL;
    int i = 0;

    if (total_words >= 1000)
    {
        return total_words;
    }

    if (arr[index] == NULL)
    {
        return total_words;
    }

    word = strchr(arr[index], ' ');
    if (word != NULL)
    {
        total_words++;
    }

    count_words(arr, index + 1, total_words);
}

int main()
{
    char **arr = NULL;
    int total_words = 0;

    arr = (char **)malloc(10 * sizeof(char *));
    for (int i = 0; i < 10; i++)
    {
        arr[i] = (char *)malloc(100 * sizeof(char));
    }

    arr[0] = "This is a sample text with several words.";
    arr[1] = "It also contains a few sentences.";
    arr[2] = "The text is divided into multiple paragraphs.";
    arr[3] = "Each paragraph has its own set of words.";
    arr[4] = "The text is a good example of how to use the word count tool.";

    total_words = count_words(arr, 0, total_words);

    printf("Total words: %d", total_words);

    return 0;
}