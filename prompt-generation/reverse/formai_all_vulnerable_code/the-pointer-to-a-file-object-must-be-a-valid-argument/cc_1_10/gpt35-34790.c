//FormAI DATASET v1.0 Category: Spell checking ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to remove leading and trailing whitespaces from a string
char* trim(char* str)
{
    int i, j;
    for (i = 0; isspace(str[i]); i++);
    for (j = strlen(str) - 1; isspace(str[j]); j--);
    str[j + 1] = '\0';
    return &str[i];
}

int main()
{
    char text[1000]; // Input text buffer
    char dictionary[1000]; // Dictionary buffer
    char* words[1000]; // Array to store individual words from input text
    int i, j, k, num_words = 0, num_found = 0;

    // Read dictionary from file
    FILE* dict_file = fopen("dictionary.txt", "r");
    fgets(dictionary, 1000, dict_file);
    fclose(dict_file);

    // Convert all letters in dictionary to lowercase for case-insensitive search
    for (i = 0; dictionary[i] != '\0'; i++)
    {
        dictionary[i] = tolower(dictionary[i]);
    }

    // Read input text from user
    printf("Enter the text to spell check:\n");
    fgets(text, 1000, stdin);

    // Tokenize input text into individual words
    char* token = strtok(text, " .,!?\n");
    while (token != NULL)
    {
        words[num_words++] = trim(token);
        token = strtok(NULL, " .,!?\n");
    }

    // Check each word in input text against the dictionary
    printf("Misspelled words found:\n");
    for (i = 0; i < num_words; i++)
    {
        int len = strlen(words[i]);

        // Convert word to lowercase for case-insensitive search
        for (j = 0; words[i][j] != '\0'; j++)
        {
            words[i][j] = tolower(words[i][j]);
        }

        // Check if word is in dictionary
        for (j = 0; dictionary[j] != '\0'; j++)
        {
            if (dictionary[j] == words[i][0])
            {
                k = 1;
                while (dictionary[j+k] == words[i][k] && words[i][k] != '\0')
                {
                    k++;
                }
                if (dictionary[j+k] == ' ' || dictionary[j+k] == '\0')
                {
                    num_found++;
                    break;
                }
            }
        }

        // Print misspelled word if not found in dictionary
        if (num_found == 0)
        {
            printf("- %s\n", words[i]);
        }
        num_found = 0; // Reset counter for next word
    }

    return 0;
}