//FormAI DATASET v1.0 Category: Spell checking ; Style: configurable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// function to read dictionary words from file and store in array
int read_dictionary(char dictionary[100000][50], char *filename)
{
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening dictionary file");
        return -1;
    }

    int i = 0;
    while (fgets(dictionary[i], 50, file) != NULL)
    {
        int len = strlen(dictionary[i]);
        if (dictionary[i][len-1] == '\n') { // remove newline character
            dictionary[i][len-1] = '\0';
        }
        i++;
    }

    fclose(file);
    return i;
}

// function to check if a word is spelled correctly
int check_spelling(char *word, char dictionary[100000][50], int dictionary_size)
{
    for (int i = 0; i < dictionary_size; i++)
    {
        if (strcmp(word, dictionary[i]) == 0)
        {
            return 1; // word is spelled correctly
        }
    }
    return 0; // word is misspelled
}

int main()
{
    char dictionary[100000][50];
    int dictionary_size = read_dictionary(dictionary, "dictionary.txt");
    if (dictionary_size == -1) {
        return 1;
    }

    // loop to prompt user for input and check spelling of each word
    char line[1000];
    printf("Enter text to spell check (press ENTER to exit):\n");
    while (fgets(line, 1000, stdin) != NULL)
    {
        char *word = strtok(line, " \n");
        while (word != NULL)
        {
            if (!check_spelling(word, dictionary, dictionary_size))
            {
                printf("%s is misspelled.\n", word);
            }
            word = strtok(NULL, " \n");
        }
    }

    return 0;
}