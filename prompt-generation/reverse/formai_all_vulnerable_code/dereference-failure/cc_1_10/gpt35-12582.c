//FormAI DATASET v1.0 Category: Text Summarizer ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHARACTERS 1000
#define MAX_SUMMARY_LENGTH 100

// Function to remove punctuations from a given string
void removePunctuations(char *str) 
{
    int count = 0;
    for (int i = 0; str[i]; i++) 
    {
        if (str[i] != ',' && str[i] != '.' && str[i] != '!' && str[i] != '?') 
        {
            str[count++] = tolower(str[i]);
        }
    }
    str[count] = '\0'; 
}

// Function to create a frequency table of words in given string
void createFrequencyTable(char *str, int *freqTable) 
{
    char *token = strtok(str, " ");
    while (token != NULL) 
    {
        freqTable[token[0] - 'a']++;
        token = strtok(NULL, " ");
    }
}

// Function to find and print the summary of given string
void summarizeText(char *text) 
{
    char *tempText = (char *) malloc(MAX_CHARACTERS * sizeof(char));
    strcpy(tempText, text);
    
    // Remove all punctuations and convert characters to lower case
    removePunctuations(tempText);
    
    int freqTable[26] = {0};
    
    // Create a frequency table of words in given string
    createFrequencyTable(tempText, freqTable);
    
    char *token = strtok(tempText, " ");
    int wordsCount = 0;
    while (token != NULL) 
    {
        wordsCount++;
        token = strtok(NULL, " ");
    }
    
    float ratio = (float) MAX_SUMMARY_LENGTH / wordsCount;
    
    printf("Summary:\n");
    
    // Print the most frequent words in given string
    while (ratio > 0.0) 
    {
        int maxFreq = -1;
        int j = -1;
        for (int i = 0; i < 26; i++) 
        {
            if (freqTable[i] > maxFreq) 
            {
                maxFreq = freqTable[i];
                j = i;
            }
        }
        if (j >= 0) 
        {
            printf("%c ", j + 'a');
            freqTable[j] = 0;
            ratio--;
        }
    }
}

int main() 
{
    char text[MAX_CHARACTERS];
    printf("Enter text to summarize:\n");
    fgets(text, MAX_CHARACTERS, stdin);
    summarizeText(text);
    return 0;
}