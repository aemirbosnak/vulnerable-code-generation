//Gemma-7B DATASET v1.0 Category: Spam Detection System ; Style: expert-level
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000

char word_list[MAX_WORDS][20];
int word_count = 0;

void add_word(char *word)
{
    if (word_count >= MAX_WORDS)
    {
        return;
    }

    strcpy(word_list[word_count++], word);
}

int main()
{
    char email_text[1000];

    // Get email text from the user
    printf("Enter email text: ");
    fgets(email_text, 1000, stdin);

    // Remove punctuation and convert to lowercase
    char *text = email_text;
    char *word = NULL;

    while ((word = strsep(text, " .,!?:")) != NULL)
    {
        // Remove stop words and common spam words
        if (strlen(word) > 1 && !ispunct(word[0]) && !isupper(word[0]) && word[0] != ' ')
        {
            add_word(word);
        }
    }

    // Analyze word frequency
    int word_freq[MAX_WORDS];
    for (int i = 0; i < word_count; i++)
    {
        word_freq[i] = 0;
        for (int j = 0; j < word_count; j++)
        {
            if (strcmp(word_list[i], word_list[j]) == 0)
            {
                word_freq[i]++;
            }
        }
    }

    // Identify words with high frequency
    int threshold = 5;
    for (int i = 0; i < word_count; i++)
    {
        if (word_freq[i] > threshold)
        {
            printf("%s appears %d times.\n", word_list[i], word_freq[i]);
        }
    }

    return 0;
}