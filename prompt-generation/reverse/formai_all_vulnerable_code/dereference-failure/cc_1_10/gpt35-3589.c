//FormAI DATASET v1.0 Category: Spell checking ; Style: inquisitive
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Function to check if a character is an alphabet
int isAlphabet(char c)
{
    if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        return 1;
    return 0;
}

// Function to check if a word is spelled correctly
int checkSpelling(char *word)
{
    // List of correct words
    char *dictionary[] = {"apple", "ball", "cat", "dog", "elephant", "frog", "goat", "honey", "icecream", "jacket"};
    int n = sizeof(dictionary) / sizeof(dictionary[0]);

    // Create a copy of the word with all lowercase letters
    char *copy = (char*)malloc(strlen(word)+1);
    strcpy(copy, word);
    for(int i=0; i<strlen(copy); i++)
    {
        if(copy[i] >= 'A' && copy[i] <= 'Z')
            copy[i] = copy[i] + 32;
    }

    // Check if the word is in the dictionary
    for(int i=0; i<n; i++)
    {
        if(strcmp(copy, dictionary[i]) == 0)
        {
            free(copy);
            return 1;
        }
    }

    free(copy);
    return 0;
}

int main()
{
    char sentence[1000], word[100];
    int len, start, end, i, j, correct;
    
    printf("Enter a sentence: ");
    fgets(sentence, 1000, stdin);
    
    len = strlen(sentence);

    // Loop through each character in the sentence
    for(i=0; i<len; i++)
    {
        if(isAlphabet(sentence[i]))
        {
            // Create a word by concatenating all alphabets
            start = i;
            while(i<len && isAlphabet(sentence[i]))
                i++;
            end = i - 1;
            int k = 0;
            for(j=start; j<=end; j++)
                word[k++] = sentence[j];
            word[k] = '\0';

            // Check if the word is spelled correctly
            correct = checkSpelling(word);

            if(!correct)
                printf("%s is spelled incorrectly.\n", word);
        }
    }
    return 0;
}