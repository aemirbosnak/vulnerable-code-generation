//Gemma-7B DATASET v1.0 Category: Sentiment analysis tool ; Style: Cyberpunk
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_WORDS 1024

typedef struct Word {
    char *word;
    int sentiment;
    struct Word *next;
} Word;

Word *word_list = NULL;

void add_word(char *word, int sentiment) {
    Word *new_word = malloc(sizeof(Word));
    new_word->word = strdup(word);
    new_word->sentiment = sentiment;
    new_word->next = NULL;

    if (word_list == NULL) {
        word_list = new_word;
    } else {
        Word *current = word_list;
        while (current->next) {
            current = current->next;
        }
        current->next = new_word;
    }
}

int sentiment_analysis(char *text) {
    char *words[MAX_WORDS];
    int num_words = 0;
    int sentiment = 0;

    // Split the text into words
    char *word = strtok(text, " ");
    while (word) {
        words[num_words++] = word;
        word = strtok(NULL, " ");
    }

    // Analyze each word
    for (int i = 0; i < num_words; i++) {
        Word *current = word_list;
        while (current) {
            if (strcmp(words[i], current->word) == 0) {
                sentiment += current->sentiment;
            }
            current = current->next;
        }
    }

    // Return the overall sentiment
    return sentiment;
}

int main() {
    add_word("joy", 3);
    add_word("sadness", -2);
    add_word("anger", -1);
    add_word("love", 4);

    char *text = "I am sad, but I am also happy.";

    int sentiment = sentiment_analysis(text);

    printf("The sentiment of the text is: %d\n", sentiment);

    return 0;
}