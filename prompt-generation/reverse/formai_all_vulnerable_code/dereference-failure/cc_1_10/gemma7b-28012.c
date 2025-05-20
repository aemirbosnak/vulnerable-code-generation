//Gemma-7B DATASET v1.0 Category: Spam Detection System ; Style: medieval
#include <stdio.h>
#include <string.h>

#define MAX_WORDS 100

void analyze_sentence(char *sentence);

int main()
{
    char sentence[MAX_WORDS];

    printf("Enter a sentence: ");
    fgets(sentence, MAX_WORDS, stdin);

    analyze_sentence(sentence);

    return 0;
}

void analyze_sentence(char *sentence)
{
    char words[MAX_WORDS][MAX_WORDS];
    int num_words = 0;
    int i = 0;
    char flag = 0;

    // Tokenize the sentence
    for (i = 0; sentence[i] != '\0'; i++)
    {
        if (sentence[i] == ' ' || sentence[i] == ',' || sentence[i] == '.')
        {
            words[num_words][0] = sentence[i - 1];
            words[num_words][1] = '\0';
            num_words++;
        }
    }

    // Check for spam words
    for (i = 0; i < num_words; i++)
    {
        if (strcmp(words[i], "spam") == 0)
        {
            flag = 1;
        }
    }

    // Print the result
    if (flag)
    {
        printf("Spam detected!");
    }
    else
    {
        printf("No spam detected.");
    }
}