//GEMINI-pro DATASET v1.0 Category: Spam Detection System ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct to represent a spam filter
typedef struct {
    char *word;
    int count;
} SpamFilter;

// Create a new spam filter
SpamFilter *newSpamFilter() {
    SpamFilter *filter = malloc(sizeof(SpamFilter));
    filter->word = NULL;
    filter->count = 0;
    return filter;
}

// Add a word to the spam filter
void addWordToSpamFilter(SpamFilter *filter, const char *word) {
    if (filter->word == NULL) {
        filter->word = strdup(word);
        filter->count = 1;
    } else if (strcmp(filter->word, word) == 0) {
        filter->count++;
    }
}

// Check if a string is spam
int isSpam(SpamFilter *filter, const char *string) {
    char *haystack = strdup(string);
    char *token = strtok(haystack, " ");
    while (token != NULL) {
        if (strcmp(token, filter->word) == 0) {
            free(haystack);
            return 1;
        }
        token = strtok(NULL, " ");
    }
    free(haystack);
    return 0;
}

// Free a spam filter
void freeSpamFilter(SpamFilter *filter) {
    free(filter->word);
    free(filter);
}

// Main function
int main() {
    // Create a new spam filter
    SpamFilter *filter = newSpamFilter();

    // Add some words to the spam filter
    addWordToSpamFilter(filter, "viagra");
    addWordToSpamFilter(filter, "free");
    addWordToSpamFilter(filter, "make");
    addWordToSpamFilter(filter, "money");

    // Check if a string is spam
    if (isSpam(filter, "I need some viagra")) {
        printf("This string is spam.\n");
    } else {
        printf("This string is not spam.\n");
    }

    // Free the spam filter
    freeSpamFilter(filter);

    return 0;
}