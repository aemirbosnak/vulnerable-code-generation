//FormAI DATASET v1.0 Category: Spell checking ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50
#define DICTIONARY_SIZE 300000

// Structure for holding dictionary words
typedef struct Word
{
    char word[MAX_WORD_LENGTH+1];
} Word;

// Declare the dictionary and the size
Word dictionary[DICTIONARY_SIZE];
int dictionary_size = 0;

// Function to read the dictionary from file
void read_dictionary()
{
    FILE* file = fopen("dictionary.txt", "r");
    while (fgets(dictionary[dictionary_size].word, MAX_WORD_LENGTH+1, file) != NULL)
    {
        // Remove newline character from the end of the word
        dictionary[dictionary_size].word[strcspn(dictionary[dictionary_size].word, "\n")] = '\0';
        dictionary_size++;
    }
    fclose(file);
}

// Function to check if a word is in the dictionary
int in_dictionary(char* word)
{
    // Convert word to lowercase
    for (int i = 0; i < strlen(word); i++)
    {
        word[i] = tolower(word[i]);
    }
    
    // Perform binary search over dictionary words
    int left = 0;
    int right = dictionary_size - 1;
    while (left <= right)
    {
        int middle = (left + right) / 2;
        int cmp = strcmp(word, dictionary[middle].word);
        if (cmp < 0)
        {
            right = middle - 1;
        }
        else if (cmp > 0)
        {
            left = middle + 1;
        }
        else
        {
            return 1;
        }
    }
    return 0;
}

// Function to print a word with an underline at the position of the error
void print_underline(char* word, int error_position)
{
    printf("%s\n", word);
    for (int i = 0; i < error_position; i++)
    {
        printf(" ");
    }
    printf("^\n");
}

int main()
{
    // Read the dictionary
    read_dictionary();
    
    // Get input from user
    char input[1000];
    printf("Enter a sentence: ");
    fgets(input, 1000, stdin);

    // Parse the sentence into words
    char* word;
    char* saveptr;
    int error = 0;
    word = strtok_r(input, " \n", &saveptr);
    while (word != NULL)
    {
        // Check if the word is in the dictionary
        if (!in_dictionary(word))
        {
            printf("Error: \"%s\" is not a valid word.\n", word);
            print_underline(word, strlen(word)/2); // Underline the middle of the word
            error = 1;
        }
        
        word = strtok_r(NULL, " \n", &saveptr);
    }
    
    if (!error)
    {
        printf("No errors found.\n");
    }
    
    return 0;
}