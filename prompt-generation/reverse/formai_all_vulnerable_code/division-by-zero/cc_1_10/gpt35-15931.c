//FormAI DATASET v1.0 Category: Text Summarizer ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SENTENCES 50
#define MAX_WORDS 500

char *read_file(char *filename)
{
    FILE *fp;
    char *text;
    long int size;

    fp = fopen(filename, "r");

    if (fp == NULL)
    {
        printf("Error opening file\n");
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    text = (char *)malloc(size * sizeof(char));
    if (text == NULL)
    {
        printf("Error allocating memory for file\n");
        exit(1);
    }

    fread(text, sizeof(char), size, fp);

    fclose(fp);

    return text;
}

int count_sentences(char *text, int size)
{
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            count++;
        }
    }
    return count;
}

int count_words(char *sentence)
{
    int count = 0;
    char *word;

    word = strtok(sentence, " ");
    while (word != NULL)
    {
        count++;
        word = strtok(NULL, " ");
    }

    return count;
}

void summarize(char *text)
{
    char *sentences[MAX_SENTENCES];
    int size, n_sentences, n_words, sentence_lengths[MAX_SENTENCES], total_words, avg_length;
    float ratio;
    char *p;

    size = strlen(text);

    n_sentences = count_sentences(text, size);

    p = strtok(text, ".?!");

    for (int i = 0; i < n_sentences && p != NULL; i++)
    {
        sentences[i] = p;
        sentence_lengths[i] = strlen(p);
        p = strtok(NULL, ".?!");
    }

    total_words = 0;
    for (int i = 0; i < n_sentences; i++)
    {
        n_words = count_words(sentences[i]);
        total_words += n_words;
    }

    avg_length = total_words / n_sentences;

    ratio = 0.5;

    printf("\nSummary:\n");

    for (int i = 0; i < n_sentences; i++)
    {
        if (sentence_lengths[i] > avg_length * ratio)
        {
            printf("%s.", sentences[i]);
        }
    }
}

int main()
{
    char *filename = "sample.txt";
    char *text;

    text = read_file(filename);

    summarize(text);

    free(text);
}