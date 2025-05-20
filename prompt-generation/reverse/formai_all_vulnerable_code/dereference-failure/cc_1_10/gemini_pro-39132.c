//GEMINI-pro DATASET v1.0 Category: Spam Detection System ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct to represent a word
typedef struct Word {
    char *word;
    int count;
} Word;

// Define a struct to represent a spam filter
typedef struct SpamFilter {
    Word **words;
    int num_words;
} SpamFilter;

// Create a new spam filter
SpamFilter *new_spam_filter() {
    SpamFilter *filter = malloc(sizeof(SpamFilter));
    filter->words = NULL;
    filter->num_words = 0;
    return filter;
}

// Add a word to a spam filter
void add_word_to_filter(SpamFilter *filter, char *word) {
    // Check if the word is already in the filter
    for (int i = 0; i < filter->num_words; i++) {
        if (strcmp(filter->words[i]->word, word) == 0) {
            filter->words[i]->count++;
            return;
        }
    }

    // If the word is not in the filter, add it
    Word *new_word = malloc(sizeof(Word));
    new_word->word = strdup(word);
    new_word->count = 1;
    filter->words = realloc(filter->words, (filter->num_words + 1) * sizeof(Word *));
    filter->words[filter->num_words++] = new_word;
}

// Check if a message is spam
int is_spam(SpamFilter *filter, char *message) {
    // Tokenize the message
    char *token = strtok(message, " ");
    while (token != NULL) {
        // Check if the token is in the spam filter
        for (int i = 0; i < filter->num_words; i++) {
            if (strcmp(filter->words[i]->word, token) == 0) {
                return 1;
            }
        }

        // Get the next token
        token = strtok(NULL, " ");
    }

    // If no spam words were found, the message is not spam
    return 0;
}

// Free a spam filter
void free_spam_filter(SpamFilter *filter) {
    for (int i = 0; i < filter->num_words; i++) {
        free(filter->words[i]->word);
        free(filter->words[i]);
    }
    free(filter->words);
    free(filter);
}

int main() {
    // Create a new spam filter
    SpamFilter *filter = new_spam_filter();

    // Add some spam words to the filter
    add_word_to_filter(filter, "free");
    add_word_to_filter(filter, "money");
    add_word_to_filter(filter, "viagra");
    add_word_to_filter(filter, "rolex");

    // Check if a message is spam
    char *message = "I have a free gift for you! Click here to claim your free money.";
    if (is_spam(filter, message)) {
        printf("The message is spam.\n");
    } else {
        printf("The message is not spam.\n");
    }

    // Free the spam filter
    free_spam_filter(filter);

    return 0;
}