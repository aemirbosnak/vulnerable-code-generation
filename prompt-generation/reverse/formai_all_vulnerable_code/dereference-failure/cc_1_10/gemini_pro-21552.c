//GEMINI-pro DATASET v1.0 Category: Text processing ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to reverse a string
char *reverse_string(char *str)
{
    int len = strlen(str);
    char *new_str = (char *)malloc(len + 1);
    int i;

    for (i = len - 1; i >= 0; i--)
    {
        new_str[len - i - 1] = str[i];
    }
    new_str[len] = '\0';

    return new_str;
}

// Function to remove all spaces from a string
char *remove_spaces(char *str)
{
    int len = strlen(str);
    char *new_str = (char *)malloc(len + 1);
    int i, j;

    j = 0;
    for (i = 0; i < len; i++)
    {
        if (str[i] != ' ')
        {
            new_str[j] = str[i];
            j++;
        }
    }
    new_str[j] = '\0';

    return new_str;
}

// Function to count the number of words in a string
int count_words(char *str)
{
    int len = strlen(str);
    int count = 0;
    int i;

    for (i = 0; i < len; i++)
    {
        if (str[i] == ' ')
        {
            count++;
        }
    }

    return count + 1;
}

// Function to find the longest word in a string
char *find_longest_word(char *str)
{
    int len = strlen(str);
    int max_len = 0;
    char *longest_word = NULL;
    int i, j;

    for (i = 0; i < len; i++)
    {
        if (str[i] != ' ')
        {
            j = i;
            while (str[j] != ' ' && j < len)
            {
                j++;
            }
            if (j - i > max_len)
            {
                max_len = j - i;
                longest_word = &str[i];
            }
        }
    }

    return longest_word;
}

// Function to print a histogram of the word lengths in a string
void print_histogram(char *str)
{
    int len = strlen(str);
    int max_len = 0;
    int i, j;

    // Find the maximum word length
    for (i = 0; i < len; i++)
    {
        if (str[i] != ' ')
        {
            j = i;
            while (str[j] != ' ' && j < len)
            {
                j++;
            }
            if (j - i > max_len)
            {
                max_len = j - i;
            }
        }
    }

    // Create a histogram
    int *histogram = (int *)calloc(max_len + 1, sizeof(int));

    // Count the number of words of each length
    for (i = 0; i < len; i++)
    {
        if (str[i] != ' ')
        {
            j = i;
            while (str[j] != ' ' && j < len)
            {
                j++;
            }
            histogram[j - i]++;
        }
    }

    // Print the histogram
    for (i = 1; i <= max_len; i++)
    {
        printf("%d: %d\n", i, histogram[i]);
    }

    free(histogram);
}

int main()
{
    char str[] = "This is a sample text to process for different operations.";

    // Reverse the string
    char *reversed_str = reverse_string(str);
    printf("Reversed string: %s\n", reversed_str);

    // Remove all spaces from the string
    char *no_spaces_str = remove_spaces(str);
    printf("String with no spaces: %s\n", no_spaces_str);

    // Count the number of words in the string
    int word_count = count_words(str);
    printf("Number of words in the string: %d\n", word_count);

    // Find the longest word in the string
    char *longest_word = find_longest_word(str);
    printf("Longest word in the string: %s\n", longest_word);

    // Print a histogram of the word lengths in the string
    print_histogram(str);

    return 0;
}