//FormAI DATASET v1.0 Category: Text Summarizer ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to calculate the occurrence of each word in the input string
void word_counter(char *input_string, int *word_count) 
{
    char *word;
    word = strtok(input_string, " \n"); // tokenize each word using space and new line as delimiters 
  
    while (word != NULL) 
    {
        word_count++;
        word = strtok(NULL, " \n"); // continue tokenizing the remaining words
    }
}

// Function to summarize the text by extracting the most important sentences based on word count
void summarize_text(char *input_string, int sentence_count) 
{
    int word_count = 0, i = 0, j = 0;
    int sentence_length = strlen(input_string)/sentence_count;
    int *sentence_score = (int *)malloc(sizeof(int) * sentence_count); // allocate memory for sentence scores
    memset(sentence_score, 0, sentence_count * sizeof(int)); // initialize sentence scores to 0
    
    while (input_string[i] != '\0') 
    {
        if (input_string[i] == '.' || input_string[i] == '?' || input_string[i] == '!') 
        {
            sentence_score[j] += word_count; // add the word count for each sentence
            j++;
            word_count = 0;
        }
        else 
        {
            word_count++;
        }
        i++;
    }
    
    // sort the sentence scores in descending order to extract the highest scores
    for (i = 0; i < sentence_count; i++) 
    {
        for (j = i+1; j < sentence_count; j++) 
        {
            if (sentence_score[j] > sentence_score[i]) 
            {
                int temp = sentence_score[i];
                sentence_score[i] = sentence_score[j];
                sentence_score[j] = temp;
            }
        }
    }
    
    // extract the highest scoring sentences and print as a summary
    printf("SUMMARY:\n");
    for (i = 0; i < sentence_count; i++) 
    {
        for (j = 0; j < strlen(input_string); j++) 
        {
            if (input_string[j] == '.' || input_string[j] == '?' || input_string[j] == '!') 
            {
                sentence_score--;
                if (sentence_score[i] == 0) 
                {
                    printf("\n");
                    break;
                }
            }
            else 
            {
                printf("%c", input_string[j]);
            }
        }
    }
}

int main() 
{
    char input_string[1000];
    int sentence_count;
    int word_count = 0;

    printf("Enter the text to be summarized:\n");
    fgets(input_string, 1000, stdin); // accept input string from user
    
    printf("Enter the number of sentences to extract for summary:\n");
    scanf("%d", &sentence_count); // accept number of sentences to extract from user
    
    word_counter(input_string, word_count);
    summarize_text(input_string, sentence_count); // summarize the input text based on user input
    
    return 0;
}