//FormAI DATASET v1.0 Category: Text processing ; Style: beginner-friendly
// This program reads a text file, performs word count and character count, finds the longest word and outputs various statistics
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

// function declarations
void read_file(FILE *file);
void process_word(char *word, int length);
void output_stats();

char *longest_word;
int longest_word_length = 0;
int total_word_count = 0;
int total_char_count = 0;

int main()
{
    FILE *file;
    char filename[100];

    // prompt user for filename and open file
    printf("Enter filename: ");
    scanf("%s", filename);
    file = fopen(filename, "r");

    // check if file was successfully opened
    if (file == NULL)
    {
        printf("Unable to open file. Program will now exit.");
        exit(1);
    }

    // read file and process words
    read_file(file);

    // output statistics
    output_stats();

    // close file and free memory
    fclose(file);
    free(longest_word);

    return 0;
}

void read_file(FILE *file)
{
    char c;
    int word_length = 0;
    char *word = (char *) malloc(sizeof(char) * 50); // allocate memory for word

    while ((c = fgetc(file)) != EOF)
    {
        if (isalnum(c) || c == '-') // check if character is part of a word
        {
            word[word_length] = c;
            word_length++;
        }
        else // end of word reached
        {
            if (word_length > 0) // check if word has at least one character
            {
                word[word_length] = '\0'; // add null terminator to end of word
                process_word(word, word_length);
                total_word_count++;
                total_char_count += word_length;
                word_length = 0; // reset word length
                free(word); // free memory for word
                word = (char *) malloc(sizeof(char) * 50); // allocate memory for new word
            }
        }
    }
}

void process_word(char *word, int length)
{
    if (length > longest_word_length)
    {
        longest_word_length = length;
        longest_word = (char *) realloc(longest_word, sizeof(char) * longest_word_length); // allocate memory for longest word
        strcpy(longest_word, word); // copy word to longest_word
    }
}

void output_stats()
{
    printf("Total words: %d\n", total_word_count);
    printf("Total characters: %d\n", total_char_count);
    printf("Longest word: %s (%d characters)\n", longest_word, longest_word_length);
}