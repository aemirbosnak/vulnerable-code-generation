//FormAI DATASET v1.0 Category: Text Summarizer ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 100000

void tokenize(char *str, char **tokens, int *num_tokens);
void remove_new_line(char *str);
void read_file(char *file_name, char *text);
void summarize(char *text, int summary_length);

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Usage: ./summarizer <file_name> <summary_length>\n");
        return 1;
    }

    char *file_name = argv[1];
    int summary_length = atoi(argv[2]);

    if (summary_length <= 0)
    {
        printf("Length of summary should be greater than zero\n");
        return 1;
    }

    char text[MAX_FILE_SIZE];
    read_file(file_name, text);

    summarize(text, summary_length);

    return 0;
}

void summarize(char *text, int summary_length)
{
    char *sentences[MAX_FILE_SIZE];
    int num_sentences = 0;
    tokenize(text, sentences, &num_sentences);

    if (summary_length > num_sentences)
    {
        printf("Summary length should be less than the number of sentences in the text.\n");
        return;
    }

    int sentence_scores[num_sentences];
    for (int i = 0; i < num_sentences; i++)
    {
        sentence_scores[i] = 0;
        char *words[MAX_FILE_SIZE];
        int num_words = 0;
        tokenize(sentences[i], words, &num_words);

        for (int j = 0; j < num_words; j++)
        {
            if (strstr(text, words[j]) != NULL)
            {
                sentence_scores[i]++;
            }
        }
    }

    int summary_indexes[summary_length];
    for (int i = 0; i < summary_length; i++)
    {
        int max_score_index = 0;
        int max_score = sentence_scores[0];

        for (int j = 1; j < num_sentences; j++)
        {
            if (sentence_scores[j] > max_score)
            {
                max_score = sentence_scores[j];
                max_score_index = j;
            }
        }

        summary_indexes[i] = max_score_index;
        sentence_scores[max_score_index] = -1;
    }

    printf("\nSummary:\n");

    for (int i = 0; i < summary_length; i++)
    {
        printf("%d. %s\n", i + 1, sentences[summary_indexes[i]]);
    }
}

void read_file(char *file_name, char *text)
{
    FILE *file = fopen(file_name, "r");
    if (file == NULL)
    {
        printf("Error opening file %s\n", file_name);
        exit(1);
    }

    int i = 0;
    char c = fgetc(file);
    while (c != EOF)
    {
        text[i++] = c;
        c = fgetc(file);
    }
    text[i] = '\0';

    fclose(file);
}

void tokenize(char *str, char **tokens, int *num_tokens)
{
    const char *delim = ".?!";
    char *token = strtok(str, delim);

    while (token != NULL)
    {
        remove_new_line(token);

        if (strlen(token) != 0)
        {
            tokens[*num_tokens] = token;
            (*num_tokens)++;
        }

        token = strtok(NULL, delim);
    }
}

void remove_new_line(char *str)
{
    int len = strlen(str);
    if (str[len - 1] == '\n')
    {
        str[len - 1] = '\0';
    }
}