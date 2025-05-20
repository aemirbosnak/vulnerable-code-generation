//Gemma-7B DATASET v1.0 Category: Data mining ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_SENTENCE_LENGTH 255

int main()
{
    char **words = NULL;
    char **sentences = NULL;
    int num_words = 0;
    int num_sentences = 0;

    // Read the text data from a file
    FILE *fp = fopen("text.txt", "r");
    if (fp == NULL)
    {
        return 1;
    }

    // Allocate memory for the words and sentences arrays
    words = (char**)malloc(MAX_WORDS * sizeof(char*));
    sentences = (char**)malloc(MAX_SENTENCE_LENGTH * sizeof(char*));

    // Tokenize the text into sentences
    char sentence[MAX_SENTENCE_LENGTH] = "";
    int sentence_length = 0;
    while (fgets(sentence, MAX_SENTENCE_LENGTH, fp) != NULL)
    {
        sentences[num_sentences++] = strdup(sentence);

        // Tokenize the sentence into words
        char word[MAX_WORDS] = "";
        int word_length = 0;
        for (int i = 0; sentence[i] != '\0'; i++)
        {
            if (sentence[i] == ' ' || sentence[i] == '\n')
            {
                words[num_words++] = strdup(word);

                word_length = 0;
            }
            else
            {
                word[word_length++] = sentence[i];
            }
        }
        words[num_words++] = strdup(word);
    }

    // Print the words and sentences
    for (int i = 0; i < num_words; i++)
    {
        printf("%s ", words[i]);
    }

    printf("\n");

    for (int i = 0; i < num_sentences; i++)
    {
        printf("%s\n", sentences[i]);
    }

    // Free the memory allocated for the words and sentences arrays
    free(words);
    free(sentences);

    fclose(fp);

    return 0;
}