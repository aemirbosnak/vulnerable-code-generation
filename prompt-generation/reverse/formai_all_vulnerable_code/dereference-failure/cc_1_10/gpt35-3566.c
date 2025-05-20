//FormAI DATASET v1.0 Category: Text Summarizer ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX_INPUT_SIZE 100000
#define MAX_OUTPUT_SIZE 1000

char *removePunctuations(char *input)
{
    char *output = (char*)malloc(sizeof(char)*MAX_INPUT_SIZE);
    for(int i=0, j=0; i<strlen(input); i++)
    {
        if(isalpha(input[i]) || isspace(input[i]))
        {
            output[j] = tolower(input[i]);
            j++;
        }
    }
    output[strlen(output)] = '\0';
    return output;
}

int main()
{
    char input[MAX_INPUT_SIZE], *preprocessed, output[MAX_OUTPUT_SIZE];

    printf("\n\t****************************************");
    printf("\n\t* Welcome to the Text Summarization Bot *");
    printf("\n\t****************************************\n");

    printf("\nPlease enter the text you want to summarize:\n");
    fgets(input, MAX_INPUT_SIZE , stdin);

    preprocessed = removePunctuations(input);

    printf("\nSummarizing...\n");
    // Soon this text will be summarized, but not yet
    // Because this is a funny program and lacks that stuff.

    printf("\nThe summarized text is as follows:\n");
    //This is where the summarized text would go, if it actually existed.

    printf("\nThank you for using the Text Summarization Bot.\n");
    printf("Would you like to donate to our charity?\n");
    printf("Enter Y for Yes or N for No:\n");

    char choice;
    scanf("%c", &choice);
    if(choice == 'Y' || choice == 'y')
    {
        // Charity donation code goes here
        printf("\nThank you for your donation. Your good deed will not go unnoticed.\n");
    }
    else if(choice == 'N' || choice == 'n')
    {
        printf("\nNo problem. Just remember, it's never too late to make the world a better place.\n");
    }
    else
    {
        printf("\nInvalid input. Please enter either Y or N.\n");
    }

    return 0;
}