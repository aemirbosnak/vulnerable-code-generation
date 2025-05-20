//Gemma-7B DATASET v1.0 Category: Sentiment analysis tool ; Style: accurate
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE 1024

char *read_file(char *filename)
{
    FILE *fp;
    char *buffer = NULL;
    size_t size = 0;

    fp = fopen(filename, "r");
    if (fp == NULL)
    {
        return NULL;
    }

    buffer = malloc(MAX_SIZE);
    if (buffer == NULL)
    {
        fclose(fp);
        return NULL;
    }

    size = fread(buffer, MAX_SIZE, 1, fp);
    fclose(fp);

    return buffer;
}

int sentiment_analysis(char *text)
{
    int positive = 0;
    int negative = 0;
    char *words[] = {"good", "excellent", "great", "wonderful", "positive", "happy", "joy", "pleasant", "fine", "acceptable"};
    char *negatives[] = {"bad", "terrible", "awful", "poor", "negative", "sad", "angry", "frustrated", "gloomy", "depressing"};

    for (int i = 0; i < 10; i++)
    {
        if (strstr(text, words[i]) != NULL)
        {
            positive++;
        }
    }

    for (int i = 0; i < 10; i++)
    {
        if (strstr(text, negatives[i]) != NULL)
        {
            negative++;
        }
    }

    if (positive > negative)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    char *text = read_file("sample.txt");
    int sentiment = sentiment_analysis(text);

    if (sentiment == 1)
    {
        printf("The text is positive.\n");
    }
    else
    {
        printf("The text is negative.\n");
    }

    return 0;
}