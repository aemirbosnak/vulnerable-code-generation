//Gemma-7B DATASET v1.0 Category: Spam Detection System ; Style: Romeo and Juliet
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORDS 100
#define MAX_SENTENCE_LENGTH 200

char **words;
char **sentences;

void analyze_sentence(char *sentence);

int main()
{
    words = (char **)malloc(MAX_WORDS * sizeof(char *));
    sentences = (char **)malloc(MAX_SENTENCE_LENGTH * sizeof(char *));

    char sentence[MAX_SENTENCE_LENGTH];

    printf("Enter a sentence: ");
    fgets(sentence, MAX_SENTENCE_LENGTH, stdin);

    analyze_sentence(sentence);

    return 0;
}

void analyze_sentence(char *sentence)
{
    char *word;
    int i = 0, j = 0, word_count = 0;

    // Tokenize the sentence into words
    word = strtok(sentence, " ");
    while (word)
    {
        words[word_count] = word;
        word_count++;
        word = strtok(NULL, " ");
    }

    // Analyze the word count
    if (word_count > MAX_WORDS)
    {
        sentences[j] = "Excessive number of words";
        j++;
    }

    // Analyze the sentence length
    if (strlen(sentence) > MAX_SENTENCE_LENGTH)
    {
        sentences[j] = "Sentence length exceeds limit";
        j++;
    }

    // Print the results
    for (i = 0; i < j; i++)
    {
        printf("%s\n", sentences[i]);
    }
}