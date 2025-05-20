//FormAI DATASET v1.0 Category: Text Summarizer ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SENTENCES 30
#define MAX_SENTENCE_LENGTH 200
#define MAX_SUMMARY_LENGTH 1000

int main()
{
    char input_text[MAX_SENTENCES][MAX_SENTENCE_LENGTH];
    char summary[MAX_SUMMARY_LENGTH] = "";
    int sentence_scores[MAX_SENTENCES], sentence_lengths[MAX_SENTENCES];
    FILE *fp;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    int i, j;

    // Open input file, read text into input_text array
    fp = fopen("input.txt", "r");
    if (fp == NULL)
    {
        printf("Unable to open input file\n");
        exit(EXIT_FAILURE);
    }

    i = 0;
    while ((read = getline(&line, &len, fp)) != -1 && i < MAX_SENTENCES)
    {
        strcpy(input_text[i], line);
        sentence_lengths[i] = strlen(input_text[i]);
        i++;
    }

    fclose(fp);
    if (line)
    {
        free(line);
    }

    // Score sentences based on length and number of keywords
    for (i = 0; i < MAX_SENTENCES; i++)
    {
        sentence_scores[i] = 0;
        for (j = 0; j < sentence_lengths[i]; j++)
        {
            if (input_text[i][j] == ' ' || input_text[i][j] == '\n')
            {
                sentence_scores[i]++;
            }
        }
        sentence_scores[i] /= sentence_lengths[i];
    }

    // Select best sentences for summary, add to summary string
    int summary_length = 0, num_sentences = 0;
    for (i = 0; i < MAX_SENTENCES; i++)
    {
        if (sentence_scores[i] > 0)
        {
            strcat(summary, input_text[i]);
            summary_length += sentence_lengths[i];
            num_sentences++;
        }

        if (summary_length >= MAX_SUMMARY_LENGTH) break;
    }

    // Write summary to output file
    fp = fopen("output.txt", "w");
    if (fp == NULL)
    {
        printf("Unable to write output file\n");
        exit(EXIT_FAILURE);
    }

    fprintf(fp, "%s\n", summary);
    fclose(fp);

    return 0;
}