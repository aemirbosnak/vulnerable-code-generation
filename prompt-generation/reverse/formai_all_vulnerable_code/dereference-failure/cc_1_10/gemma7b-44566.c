//Gemma-7B DATASET v1.0 Category: Spam Detection System ; Style: portable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORDS 100
#define MAX_SENTENCE_LENGTH 200

int main()
{
    char **words = (char **)malloc(MAX_WORDS * sizeof(char *));
    char **sentences = (char **)malloc(MAX_SENTENCE_LENGTH * sizeof(char *));

    // Get the text from the user
    printf("Enter the text: ");
    getline(stdin, sentences[0], MAX_SENTENCE_LENGTH);

    // Split the text into words
    words = split_text(sentences[0], words);

    // Analyze the words
    int spam_score = analyze_words(words);

    // Print the spam score
    printf("Spam score: %d\n", spam_score);

    free(words);
    free(sentences);

    return 0;
}

int split_text(char *text, char **words)
{
    char *word = strtok(text, " ");
    int i = 0;

    while (word)
    {
        words[i++] = word;
        word = strtok(NULL, " ");
    }

    return i;
}

int analyze_words(char **words)
{
    int i, spam_score = 0;

    for (i = 0; words[i] != NULL; i++)
    {
        if (is_spam_word(words[i]))
        {
            spam_score++;
        }
    }

    return spam_score;
}

int is_spam_word(char *word)
{
    // Check if the word is a known spam word
    return strcmp(word, "free") == 0 || strcmp(word, "lottery") == 0 || strcmp(word, "miracle") == 0;
}