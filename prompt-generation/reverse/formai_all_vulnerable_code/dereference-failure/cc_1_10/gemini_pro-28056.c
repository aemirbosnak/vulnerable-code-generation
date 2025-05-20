//GEMINI-pro DATASET v1.0 Category: Word Count Tool ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to count the number of words in a string
int count_words(char *str)
{
    int word_count = 0;
    int in_word = 0;

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == ' ' || str[i] == '\n' || str[i] == '\t')
        {
            in_word = 0;
        }
        else if (!in_word)
        {
            word_count++;
            in_word = 1;
        }
    }

    return word_count;
}

// Function to count the number of characters in a string
int count_chars(char *str)
{
    int char_count = 0;

    for (int i = 0; str[i] != '\0'; i++)
    {
        char_count++;
    }

    return char_count;
}

// Function to count the number of lines in a string
int count_lines(char *str)
{
    int line_count = 0;

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == '\n')
        {
            line_count++;
        }
    }

    return line_count;
}

// Function to print the results of the word count
void print_results(int word_count, int char_count, int line_count)
{
    printf("Word count: %d\n", word_count);
    printf("Character count: %d\n", char_count);
    printf("Line count: %d\n", line_count);
}

// Main function
int main(int argc, char **argv)
{
    // Check if a file was provided as an argument
    if (argc < 2)
    {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    // Open the file
    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        printf("Error: Unable to open file %s\n", argv[1]);
        return 1;
    }

    // Read the file into a string
    char *str = NULL;
    size_t len = 0;
    getline(&str, &len, file);

    // Close the file
    fclose(file);

    // Count the words, characters, and lines in the string
    int word_count = count_words(str);
    int char_count = count_chars(str);
    int line_count = count_lines(str);

    // Print the results
    print_results(word_count, char_count, line_count);

    // Free the string
    free(str);

    return 0;
}