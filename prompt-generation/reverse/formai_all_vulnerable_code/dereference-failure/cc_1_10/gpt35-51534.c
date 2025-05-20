//FormAI DATASET v1.0 Category: String manipulation ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char sentence[100];
    int wordCount = 0;

    printf("Enter a sentence: ");
    fgets(sentence, 100, stdin);

    //counting the number of words in the sentence
    for (int i = 0; i < strlen(sentence); i++)
    {
        if (sentence[i] == ' ' || sentence[i] == '\n')
            wordCount++;
    }

    char** words = (char**)malloc(wordCount * sizeof(char*));

    int j = 0;
    //splitting the sentence into words and storing them in a dynamic array of strings(words[])
    char* token = strtok(sentence, " \n"); //splitting the sentence with space and newline as delimiters
    while (token != NULL)
    {
        words[j] = (char*)malloc(strlen(token) * sizeof(char));
        strcpy(words[j], token);
        j++;
        token = strtok(NULL, " \n");
    }

    for (int i = 0; i < wordCount; i++)
    {
        printf("%s ", words[i]); //printing the words in the sentence
    }
    printf("\n");

    //reversing the order of words in the sentence
    for (int i = 0; i < wordCount / 2; i++)
    {
        char* temp = words[i];
        words[i] = words[wordCount - i - 1];
        words[wordCount - i - 1] = temp;
    }

    for (int i = 0; i < wordCount; i++)
    {
        printf("%s ", words[i]);//printing the words in the reversed order
        free(words[i]);
    }

    free(words);
    return 0;
}