//Falcon2-11B DATASET v1.0 Category: Text Summarizer ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void summarize(char* text, int max_chars, int max_sentences)
{
    char* sentence_start = (char*)malloc(max_chars * sizeof(char));
    char* sentence_end = (char*)malloc(max_chars * sizeof(char));

    int sentence_count = 0;
    int sentence_length = 0;
    int sentence_start_index = 0;
    int sentence_end_index = 0;

    int i = 0;
    while (text[i]!= '\0')
    {
        if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            sentence_start[sentence_start_index] = text[i];
            sentence_start_index++;
            sentence_end_index = i;

            while (text[sentence_end_index]!= '.' && text[sentence_end_index]!= '?' && text[sentence_end_index]!= '!')
                sentence_end_index++;

            sentence_end[sentence_end_index] = '\0';
            sentence_length = sentence_end_index - sentence_start_index;

            if (sentence_length < max_chars)
            {
                if (sentence_count < max_sentences)
                {
                    printf("%s\n", sentence_start);
                    sentence_start = sentence_end;
                    sentence_start_index = 0;
                    sentence_end_index = 0;
                    sentence_count++;
                }
                else
                    break;
            }
            else
                break;
        }
        else
            sentence_start[sentence_start_index] = text[i];
        i++;
    }

    free(sentence_start);
    free(sentence_end);
}

int main()
{
    char text[] = "This is a sample text for testing the C text summarizer program.";
    int max_chars = 100;
    int max_sentences = 5;

    summarize(text, max_chars, max_sentences);

    return 0;
}