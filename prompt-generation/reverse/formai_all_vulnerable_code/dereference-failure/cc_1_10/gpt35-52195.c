//FormAI DATASET v1.0 Category: Text Summarizer ; Style: Ada Lovelace
//As a pioneer of computer programming, Ada Lovelace was passionate about algorithms and logic.
//In honor of her contributions, this C Text Summarizer program utilizes her innovative spirit to efficiently condense lengthy paragraphs of text into a concise summary.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LENGTH 1000
#define MAX_SUMMARY_LENGTH 100

//function to calculate the frequency of each word
void wordFrequency(char *inputText, int *wordCount, int *uniqueWords)
{
    char *word = strtok(inputText, " .,");
    while(word != NULL)
    {
        wordCount[tolower(word[0]) - 'a']++;
        uniqueWords[tolower(word[0]) - 'a']++;
        word = strtok(NULL, " .,");
    }
}

//function to summarize the input text
void summarizeText(char *inputText, char *outputText, int *wordCount, int uniqueWords)
{
    //initialize maximum frequency and most frequent word
    int maxFrequency = 0;
    char mostFrequentWord;

    //find the most frequent starting letter and its frequency
    for(int i=0; i<26; i++)
    {
        if(wordCount[i]>maxFrequency)
        {
            maxFrequency = wordCount[i];
            mostFrequentWord = i + 'a';
        }
    }

    //create summary by selecting sentences that start with the most frequent word
    strcat(outputText, "The summary is as follows:\n");
    char *sentence = strtok(inputText, ".");
    while(sentence!= NULL)
    {
        if(tolower(sentence[0]) == mostFrequentWord)
        {
            strcat(outputText, sentence);
            strcat(outputText, ". ");
        }
        sentence = strtok(NULL, ".");
    }
}

int main()
{
    char inputText[MAX_INPUT_LENGTH];
    char outputText[MAX_SUMMARY_LENGTH];
    int wordCount[26] = {0};
    int uniqueWords[26] = {0};

    printf("Enter the text to summarize:\n");
    fgets(inputText, MAX_INPUT_LENGTH, stdin);

    wordFrequency(inputText, wordCount, uniqueWords);
    summarizeText(inputText, outputText, wordCount, uniqueWords);

    printf("%s\n", outputText);
    return 0;
}