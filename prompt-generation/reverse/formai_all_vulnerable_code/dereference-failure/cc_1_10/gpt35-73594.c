//FormAI DATASET v1.0 Category: Text Summarizer ; Style: excited
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_STRING_LEN 1000
#define MAX_SUMMARY_LEN 100

char* findFirstSentence(char* text);
char* summarize(char* text, int max_length);

int main()
{
    printf("Welcome to the text summarizer!\n");
    printf("Please input the text you would like to summarize:\n");

    char input_text[MAX_STRING_LEN];
    fgets(input_text, MAX_STRING_LEN, stdin);

    char* first_sentence = findFirstSentence(input_text);
    char* summary = summarize(input_text, MAX_SUMMARY_LEN);

    printf("The first sentence of the input text is: %s\n", first_sentence);
    printf("The summarized text is: %s\n", summary);

    free(first_sentence);
    free(summary);

    return 0;
}

char* findFirstSentence(char* text)
{
    char* first_sentence = calloc(MAX_STRING_LEN, sizeof(char)); // allocate memory for the first sentence

    int i = 0;
    while(text[i] != '.' && text[i] != '?' && text[i] != '!' && text[i] != '\0')
    {
        first_sentence[i] = text[i];
        i++;
    }

    return first_sentence;
}

char* summarize(char* text, int max_length)
{
    char* summary = calloc(max_length, sizeof(char)); // allocate memory for the summary text
    int summary_length = 0; // keep track of the length of the summary so far

    char* token = strtok(text, " ");
    while(token != NULL && summary_length < max_length)
    {
        if(token[strlen(token)-1] == '.' || token[strlen(token)-1] == '?' || token[strlen(token)-1] == '!')
        {
            strcat(summary, token); // add the sentence to the summary
            summary_length += strlen(token);
            break; // stop summarizing once the first sentence is complete
        }
        else
        {
            strcat(summary, token);
            strcat(summary, " ");
            summary_length += strlen(token) + 1;
        }

        token = strtok(NULL, " ");
    }

    return summary;
}