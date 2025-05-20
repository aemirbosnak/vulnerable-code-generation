//FormAI DATASET v1.0 Category: Word Count Tool ; Style: Dennis Ritchie
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_WORD_SIZE 30 // maximum size of a word in the input string
#define MAX_WORDS 10000 // maximum number of words in the input string
#define DELIM " \t\n"

int main()
{
    char *input_string = NULL; // pointer to hold input string
    char *word = NULL; // pointer to hold each word
    int word_count[MAX_WORDS] = {0}; // array to hold the count of each word
    int num_words = 0; // counter for number of words
    int i = 0, j = 0, flag = 0;
    input_string = (char *) malloc(sizeof(char) * MAX_WORD_SIZE * MAX_WORDS); // allocate memory to input_string
    
    // get input string from user
    printf("Enter the input string: ");
    fgets(input_string, MAX_WORD_SIZE * MAX_WORDS, stdin);

    // tokenize the input string to get the individual words
    word = strtok(input_string, DELIM);
    while (word != NULL)
    {
        num_words++;
        for (i = 0; i < num_words; i++)
        {
            if (strcmp(word, input_string + i * MAX_WORD_SIZE) == 0) // check if word already exists
            {
                word_count[i]++; // increment count of existing word
                flag = 1; 
                break;
            }
        }
        if (!flag) // if word does not exist, add word to array and set count to 1
        {
            strcpy(input_string + num_words * MAX_WORD_SIZE, word);
            word_count[num_words - 1]++;
        }
        flag = 0;
        word = strtok(NULL, DELIM); // get next word
    }
    
    // print the count of each word
    printf("\nWord Count:\n");
    for (i = 0; i < num_words; i++)
    {
        printf("%s: %d\n", input_string + i * MAX_WORD_SIZE, word_count[i]);
    }

    free(input_string); // free memory allocated to input_string
    return 0;
}