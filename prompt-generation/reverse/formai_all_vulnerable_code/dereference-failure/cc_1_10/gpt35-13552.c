//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: optimized
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LEN 50 // maximum length of a word

int compare_count_desc(const void *a, const void *b); // function to compare word counts in descending order
void print_frequencies(char **words, int *counts, int num_words); // function to print word frequencies

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Error: Please provide only one argument (file name).\n");
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        printf("Error: Unable to open file.\n");
        return 1;
    }

    char word[MAX_WORD_LEN + 1]; // buffer to store each word
    char c;
    int num_words = 0;
    int capacity = 10; // initial capacity of the words array
    char **words = malloc(capacity * sizeof(char *));
    int *counts = malloc(capacity * sizeof(int));

    while ((c = getc(file)) != EOF)
    {
        if (isalpha(c)) // if the character is alphabetic
        {
            if (strlen(word) < MAX_WORD_LEN) // if the word length is less than the maximum allowed length
            {
                word[strlen(word)] = tolower(c); // convert the character to lowercase and add to the word
            }
        }
        else if (strlen(word) > 0) // if the current character is not alphabetic and there is a word in the buffer
        {
            int found = 0;
            for (int i = 0; i < num_words; i++)
            {
                if (strcmp(words[i], word) == 0) // if the word is already in the array
                {
                    counts[i]++;
                    found = 1;
                    break;
                }
            }
            if (!found) // if the word is not in the array
            {
                if (num_words == capacity) // if the array is full, double its capacity
                {
                    capacity *= 2;
                    words = realloc(words, capacity * sizeof(char *));
                    counts = realloc(counts, capacity * sizeof(int));
                }
                words[num_words] = malloc(strlen(word) + 1);
                strcpy(words[num_words], word);
                counts[num_words] = 1;
                num_words++;
            }
            memset(word, 0, sizeof(word)); // reset the word buffer
        }
    }
    fclose(file);

    qsort(counts, num_words, sizeof(int), compare_count_desc); // sort the word counts in descending order
    print_frequencies(words, counts, num_words); // print the word frequencies

    for (int i = 0; i < num_words; i++) // free the memory used by the words array
    {
        free(words[i]);
    }
    free(words);
    free(counts);

    return 0;
}

int compare_count_desc(const void *a, const void *b)
{
    return *(int *)b - *(int *)a;
}

void print_frequencies(char **words, int *counts, int num_words)
{
    printf("Word Frequencies (Descending Order):\n");
    printf("--------------------------------------\n");
    for (int i = 0; i < num_words; i++)
    {
        printf("%-20s %d\n", words[i], counts[i]);
    }
}