//FormAI DATASET v1.0 Category: Text Summarizer ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SENTENCES 100
#define MAX_SENTENCE_LENGTH 1000

char *input_text[MAX_SENTENCES];
char *output_summary[MAX_SENTENCES];

int input_text_count = 0;
int output_summary_count = 0;

void summarize_text(char *text)
{
    /*
     * Algorithm:
     * 1. Split the text into individual sentences
     * 2. Score each sentence based on relevance (number of important words)
     * 3. Pick the top sentences until the desired summary length is reached
     */

    // Step 1: Split the text into individual sentences
    char *sentence, *save_ptr1, *save_ptr2;
    sentence = strtok_r(text, ".!?", &save_ptr1);
    while (sentence != NULL && input_text_count < MAX_SENTENCES)
    {
        input_text[input_text_count++] = sentence;
        sentence = strtok_r(NULL, ".!?", &save_ptr1);
    }

    // Step 2: Score each sentence based on relevance (number of important words)
    int score[MAX_SENTENCES] = {0};
    char *important_words[] = {"important", "relevant", "crucial", "significant", "vital"};
    for (int i = 0; i < input_text_count; i++)
    {
        char *word = strtok_r(input_text[i], " \n\t", &save_ptr2);
        while (word != NULL)
        {
            for (int j = 0; j < 5; j++)
            {
                if (strcmp(word, important_words[j]) == 0)
                {
                    score[i]++;
                    break;
                }
            }
            word = strtok_r(NULL, " \n\t", &save_ptr2);
        }
    }

    // Step 3: Pick the top sentences until the desired summary length is reached
    int summary_length = 0;
    while (output_summary_count < MAX_SENTENCES && summary_length < 5)
    {
        int max_score = -1, max_index = -1;
        for (int i = 0; i < input_text_count; i++)
        {
            if (score[i] > max_score)
            {
                max_score = score[i];
                max_index = i;
            }
        }
        output_summary[output_summary_count++] = input_text[max_index];
        summary_length += strlen(input_text[max_index]);
        score[max_index] = -1; // Mark as already selected
    }

    // Print the summary
    for (int i = 0; i < output_summary_count; i++)
    {
        printf("%s", output_summary[i]);
        if (i < output_summary_count - 1)
        {
            printf(". ");
        }
    }
}

int main()
{
    char text[MAX_SENTENCE_LENGTH * MAX_SENTENCES];
    fgets(text, MAX_SENTENCE_LENGTH * MAX_SENTENCES, stdin);
    summarize_text(text);
    return 0;
}