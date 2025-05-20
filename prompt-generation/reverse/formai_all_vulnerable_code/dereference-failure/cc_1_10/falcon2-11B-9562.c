//Falcon2-11B DATASET v1.0 Category: Text Summarizer ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 100

typedef struct {
    char word[MAX_WORDS];
    int count;
} WordCount;

WordCount word_counts[MAX_WORDS];
int num_words = 0;

void initialize_word_counts() {
    for (int i = 0; i < MAX_WORDS; i++) {
        word_counts[i].count = 0;
    }
}

int is_word_present(const char* word) {
    for (int i = 0; i < MAX_WORDS; i++) {
        if (strcmp(word, word_counts[i].word) == 0) {
            return 1;
        }
    }
    return 0;
}

void add_word_count(const char* word, int count) {
    if (num_words == MAX_WORDS) {
        printf("Too many words, please use a larger array.\n");
        exit(1);
    }
    if (is_word_present(word)) {
        word_counts[num_words].count += count;
    } else {
        strcpy(word_counts[num_words].word, word);
        word_counts[num_words].count = count;
        num_words++;
    }
}

void summarize_text(const char* text) {
    char* token = strtok(text, " ");
    while (token!= NULL) {
        add_word_count(token, 1);
        token = strtok(NULL, " ");
    }
}

void print_summarized_text(const char* text) {
    char* token = strtok(text, " ");
    int total_count = 0;
    while (token!= NULL) {
        printf("%s (%d)\n", token, word_counts[total_count].count);
        total_count++;
        token = strtok(NULL, " ");
    }
}

int main() {
    char* text = "This is a sample text for text summarization. It is a long and verbose paragraph that needs to be summarized for better readability.";
    summarize_text(text);
    print_summarized_text(text);
    return 0;
}