//Falcon-180B DATASET v1.0 Category: Text Summarizer ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SENTENCE_LENGTH 1000
#define MAX_SENTENCES 1000

// Function to split a sentence into words
void split_sentence(char* sentence, char* words[]) {
    int word_count = 0;
    char* word = strtok(sentence, ",.!?;:");
    while (word!= NULL) {
        words[word_count++] = word;
        word = strtok(NULL, ",.!?;:");
    }
}

// Function to calculate the frequency of each word
void calculate_word_frequency(char* words[], int word_count, int* word_frequency) {
    memset(word_frequency, 0, sizeof(int) * MAX_SENTENCES);
    for (int i = 0; i < word_count; i++) {
        word_frequency[hash(words[i])]++;
    }
}

// Function to hash a string
int hash(char* str) {
    int hash = 0;
    int length = strlen(str);
    for (int i = 0; i < length; i++) {
        hash = (hash * 31 + str[i]) % MAX_SENTENCES;
    }
    return hash;
}

// Function to print the top N words
void print_top_words(int* word_frequency, int top_n) {
    for (int i = 0; i < MAX_SENTENCES; i++) {
        if (word_frequency[i] > 0) {
            printf("%d: %s (%d)\n", i, "", word_frequency[i]);
        }
    }
}

int main() {
    char input_text[MAX_SENTENCE_LENGTH];
    printf("Enter a text to summarize: ");
    fgets(input_text, MAX_SENTENCE_LENGTH, stdin);

    char* words[MAX_SENTENCES];
    int word_count = 0;
    split_sentence(input_text, words);
    word_count = strlen(input_text);

    int* word_frequency = (int*) malloc(sizeof(int) * MAX_SENTENCES);
    calculate_word_frequency(words, word_count, word_frequency);

    int top_n = 10;
    printf("Top %d words:\n", top_n);
    print_top_words(word_frequency, top_n);

    return 0;
}