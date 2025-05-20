//FormAI DATASET v1.0 Category: Text Summarizer ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void summarize(char *text, int sentenceCount);

int main()
{
    int sentenceCount = 3; // number of sentences in the summary
    char text[10000];

    printf("Enter the text to be summarized:\n");
    fgets(text, 10000, stdin);

    summarize(text, sentenceCount);

    return 0;
}

void summarize(char *text, int sentenceCount)
{
    // replace special characters with spaces
    for(int i = 0; i < strlen(text); i++)
    {
        if(text[i] == '\n' || text[i] == '\r')
        {
            text[i] = ' ';
        }
        else if(!isalnum(text[i]))
        {
            text[i] = ' ';
        }
    }

    // split text into sentences
    char *sentence;
    sentence = strtok(text, ".?!");

    // count number of sentences
    int count = 0;
    while(sentence != NULL)
    {
        count++;
        sentence = strtok(NULL, ".?!");
    }

    // allocate memory for storing sentences
    char **sentences = (char**)malloc(count*sizeof(char*));
    for(int i = 0; i < count; i++)
    {
        sentences[i] = (char*)malloc(1000*sizeof(char));
    }

    // split text into sentences and store in array
    sentence = strtok(text, ".?!");
    int i = 0;
    while(sentence != NULL)
    {
        strcpy(sentences[i], sentence);
        i++;
        sentence = strtok(NULL, ".?!");
    }

    // initialize array to store sentence scores
    int *scores = (int*)calloc(count, sizeof(int));

    // calculate score for each sentence
    for(int i = 0; i < count; i++)
    {
        for(int j = 0; j < strlen(sentences[i]); j++)
        {
            if(isalpha(sentences[i][j]))
            {
                scores[i]++;
            }
        }
    }

    // sort array of sentence scores
    for(int i = 0; i < count-1; i++)
    {
        for(int j = i+1; j < count; j++)
        {
            if(scores[j] > scores[i])
            {
                // swap scores
                int tempScore = scores[i];
                scores[i] = scores[j];
                scores[j] = tempScore;

                // swap sentences
                char *tempSentence = (char*)malloc(1000*sizeof(char));
                strcpy(tempSentence, sentences[i]);
                strcpy(sentences[i], sentences[j]);
                strcpy(sentences[j], tempSentence);
            }
        }
    }

    // print summary
    printf("\nSummary:\n");
    for(int i = 0; i < sentenceCount; i++)
    {
        printf("%s. ", sentences[i]);
    }

    // free allocated memory
    free(scores);
    for(int i = 0; i < count; i++)
    {
        free(sentences[i]);
    }
    free(sentences);
}