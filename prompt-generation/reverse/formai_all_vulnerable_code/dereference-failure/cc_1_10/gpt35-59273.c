//FormAI DATASET v1.0 Category: Spell checking ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_WORD_LENGTH 20
#define WORDS_COUNT 5

int dict[WORDS_COUNT] = {0}; // dictionary array 

char words[WORDS_COUNT][MAX_WORD_LENGTH] = {"apple", "banana", "cherry", "orange", "grape"}; // words to be checked

void readDict()
{
    FILE *fp;
    char line[MAX_WORD_LENGTH];
    fp = fopen("dictionary.txt", "r");
    while (fgets(line, MAX_WORD_LENGTH, fp) != NULL)
    {
        char *word = strtok(line, "\n"); // removes newline character 
        for (int i = 0; i < WORDS_COUNT; i++)
        {
            if (strcmp(word, words[i]) == 0) // if words match 
            {
                dict[i] = 1; // set as valid word 
                break;
            }
        }
    }
    fclose(fp);
}

int checkSpelling(char *word)
{
    for (int i = 0; i < WORDS_COUNT; i++)
    {
        if (strcmp(word, words[i]) == 0) // if word found in list 
        {
            if (dict[i] == 1) // if word is valid 
            {
                printf("'%s' is spelled correctly!\n", word);
                return 1;
            }
            else // if word is not valid 
            {
                printf("'%s' is spelled incorrectly!\n", word);
                printf("Did you mean: %s?\n", words[i]); // suggest correct spelling 
                return 0;
            }
        }
    }
    printf("'%s' is not in the dictionary!\n", word); // if word not found in list 
    return 0;
}

int main()
{
    readDict(); // read dictionary file 
    printf("Welcome! Please enter a word: ");
    char input[MAX_WORD_LENGTH];
    fgets(input, MAX_WORD_LENGTH, stdin); // take user input 
    char *word = strtok(input, "\n"); // remove newline character from input 

    int result = checkSpelling(word); // check spelling 

    return result;
}