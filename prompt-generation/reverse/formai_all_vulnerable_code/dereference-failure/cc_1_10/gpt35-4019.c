//FormAI DATASET v1.0 Category: Text Summarizer ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//function to remove punctuations from a string
void removePunctuations(char *text)
{
    char *temp = text;
    while(*temp)
    {
        if(ispunct(*temp))
        {
            memmove(temp, temp + 1, strlen(temp + 1) + 1);
        }
        else
        {
            ++temp;
        }
    }
}

//function to convert a string to lowercase
void toLowercase(char *text)
{
    int i = 0;
    while(text[i])
    {
        text[i] = tolower(text[i]);
        ++i;
    }
}

//function to split a string into words
void splitWords(char *text, char **words, int *count)
{
    char *token;
    token = strtok(text, " ");
    while(token != NULL)
    {
        words[*count] = token;
        ++*count;
        token = strtok(NULL, " ");
    }
}

//function to count the occurrence of each word in a string
void countWords(char **words, int wordCount, char **uniqueWords, int *wordFreq, int *uniqueWordCount)
{
    for(int i = 0; i < wordCount; ++i)
    {
        int found = 0;
        for(int j = 0; j < *uniqueWordCount; ++j)
        {
            if(strcmp(uniqueWords[j], words[i]) == 0)
            {
                ++wordFreq[j];
                found = 1;
                break;
            }
        }
        if(found == 0)
        {
            uniqueWords[*uniqueWordCount] = words[i];
            wordFreq[*uniqueWordCount] = 1;
            ++*uniqueWordCount;
        }
    }
}

//function to find the most frequent word
char *mostFrequentWord(char **uniqueWords, int *wordFreq, int uniqueWordCount)
{
    int max = 0;
    int index;
    for(int i = 0; i < uniqueWordCount; ++i)
    {
        if(wordFreq[i] > max)
        {
            max = wordFreq[i];
            index = i;
        }
    }
    return uniqueWords[index];
}

int main()
{
    char text[1000];
    printf("Enter the text: ");
    fgets(text, 1000, stdin);

    //remove punctuations
    removePunctuations(text);

    //convert to lowercase
    toLowercase(text);

    //split into words
    char *words[100];
    int wordCount = 0;
    splitWords(text, words, &wordCount);

    //count occurrence of each word
    char *uniqueWords[100];
    int wordFreq[100] = {0};
    int uniqueWordCount = 0;
    countWords(words, wordCount, uniqueWords, wordFreq, &uniqueWordCount);

    //find most frequent word
    char *mostFrequent = mostFrequentWord(uniqueWords, wordFreq, uniqueWordCount);

    printf("The most frequent word is \"%s\"\n", mostFrequent);

    return 0;
}