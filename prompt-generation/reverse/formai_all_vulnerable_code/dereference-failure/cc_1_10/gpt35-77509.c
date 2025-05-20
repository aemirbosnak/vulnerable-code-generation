//FormAI DATASET v1.0 Category: Text Summarizer ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LEN 1000
#define MAX_SENTENCES 100

int wordCount(char *str);
void printSummary(char *summary[], int size);

int main()
{
    char inputStr[MAX_STR_LEN];
    char *sentences[MAX_SENTENCES];
    char *summary[MAX_SENTENCES];
    int i, j, k, l, wordCountSum, summaryCount, sentenceCount;
    int topSentences[MAX_SENTENCES];

    /* Getting input string from user */
    printf("Enter the text to be summarized:\n");
    fgets(inputStr, MAX_STR_LEN, stdin);

    wordCountSum = 0;
    j = 0;
    sentenceCount = 1;

    /* Splitting the input text into separate sentences */
    for(i=0; i<strlen(inputStr); i++)
    {
        if(inputStr[i] == '.' || inputStr[i] == '!' || inputStr[i] == '?')
        {
            sentences[j] = (char*)malloc(sizeof(char)*(i+2));
            strncpy(sentences[j], inputStr+(i-sentenceCount+1), sentenceCount+1);
            sentences[j][sentenceCount] = '\0';
            sentenceCount = 1;
            j++;
        }
        else
        {
            sentenceCount++;
        }
    }

    /* Calculating the score for each sentence */
    int sentenceScore[j];
    for(i=0; i<j; i++)
    {
        sentenceScore[i] = 0;
        k = 0;
        while(sentences[i][k] != '\0')
        {
            if(sentences[i][k] == ' ')
            {
                sentenceScore[i] += wordCount(sentences[i]+k);
            }
            k++;
        }
        wordCountSum += sentenceScore[i];
    }

    summaryCount = 0;

    /* Selecting top sentences to include in the summary */
    for(i=0; i<j; i++)
    {
        if(i < 3)
        {
            topSentences[i] = i;
            summaryCount++;
        }
        else if(wordCountSum == 0)
        {
            break;
        }
        else
        {
            if(sentenceScore[i] > (float)(wordCountSum/summaryCount))
            {
                for(k=0; k<summaryCount; k++)
                {
                    if(sentenceScore[topSentences[k]] < sentenceScore[i])
                    {
                        for(l=summaryCount-1; l>k; l--)
                        {
                            topSentences[l] = topSentences[l-1];
                        }
                        topSentences[k] = i;
                        wordCountSum -= sentenceScore[topSentences[summaryCount-1]];
                        wordCountSum += sentenceScore[i];
                        break;
                    }
                }
            }
            else if(summaryCount < 10)
            {
                topSentences[summaryCount] = i;
                summaryCount++;
                wordCountSum += sentenceScore[i];
            }
        }
    }

    /* Storing top sentences into summary array */
    for(i=0; i<summaryCount; i++)
    {
        summary[i] = sentences[topSentences[i]];
    }

    /* Printing the summary */
    printf("\n---SUMMARY---\n");
    printSummary(summary, summaryCount);

    /* Freeing memory */
    for(i=0; i<j; i++)
    {
        free(sentences[i]);
    }

    return 0;
}

/* Function to count the number of words in a string */
int wordCount(char *str)
{
    int i, count;
    count = 0;
    for(i=0; i<strlen(str); i++)
    {
        if(str[i] == ' ')
        {
            count++;
        }
    }
    return count+1;
}

/* Function to print the summary */
void printSummary(char *summary[], int size)
{
    int i;
    for(i=0; i<size; i++)
    {
        printf("%s ", summary[i]);
    }
    printf("\n");
}