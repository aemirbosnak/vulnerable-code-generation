//GPT-4o-mini DATASET v1.0 Category: Text Summarizer ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TEXT_LENGTH 10000
#define MAX_SENTENCES 500
#define MAX_WORDS 1000

typedef struct {
    char **sentences;
    int sentence_count;
} Text;

typedef struct {
    char *word;
    int frequency;
} WordFrequency;

void to_lower_case(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower((unsigned char)(str[i]));
    }
}

int is_end_of_sentence(char c) {
    return c == '.' || c == '!' || c == '?';
}

Text split_into_sentences(const char *text) {
    Text result;
    result.sentence_count = 0;
    result.sentences = (char **)malloc(MAX_SENTENCES * sizeof(char *));
    
    const char *start = text;
    const char *end;
    
    while ((end = strchr(start, '.')) != NULL || 
           (end = strchr(start, '!')) != NULL ||
           (end = strchr(start, '?')) != NULL) {
        
        int length = end - start + 1; // Include delimiter
        result.sentences[result.sentence_count] = (char *)malloc((length + 1) * sizeof(char));
        strncpy(result.sentences[result.sentence_count], start, length);
        result.sentences[result.sentence_count][length] = '\0'; // Null-terminate
        result.sentence_count++;
        
        start = end + 1; // Move past the sentence delimiter
    }
    return result;
}

WordFrequency* get_word_frequencies(const char *text, int *unique_count) {
    WordFrequency *word_freq = (WordFrequency *)malloc(MAX_WORDS * sizeof(WordFrequency));
    int word_count = 0;
    char *token;
    char *str_copy = strdup(text);
    char *delimiters = " ,.\n\t!?\r";

    to_lower_case(str_copy); // Convert text to lower case
    token = strtok(str_copy, delimiters);
    
    while (token) {
        int found = 0;
        for (int i = 0; i < word_count; i++) {
            if (strcmp(word_freq[i].word, token) == 0) {
                word_freq[i].frequency++;
                found = 1;
                break;
            }
        }
        if (!found && word_count < MAX_WORDS) {
            word_freq[word_count].word = strdup(token);
            word_freq[word_count].frequency = 1;
            word_count++;
        }
        token = strtok(NULL, delimiters);
    }
    
    free(str_copy);
    *unique_count = word_count;
    return word_freq;
}

void free_resources(Text *text, WordFrequency *word_freq, int unique_count) {
    for (int i = 0; i < text->sentence_count; i++) {
        free(text->sentences[i]);
    }
    free(text->sentences);

    for (int i = 0; i < unique_count; i++) {
        free(word_freq[i].word);
    }
    free(word_freq);
}

void summarize_text(const char *text) {
    Text sentences = split_into_sentences(text);
    int unique_word_count;
    WordFrequency *word_frequencies = get_word_frequencies(text, &unique_word_count);
    
    printf("Summary:\n");
    for (int i = 0; i < sentences.sentence_count; i++) {
        printf("%s\n", sentences.sentences[i]);
    }

    printf("\nWord Frequencies:\n");
    for (int i = 0; i < unique_word_count; i++) {
        printf("%s: %d\n", word_frequencies[i].word, word_frequencies[i].frequency);
    }

    free_resources(&sentences, word_frequencies, unique_word_count);
}

int main() {
    char text[MAX_TEXT_LENGTH];

    printf("Enter text (max 10000 characters, end with EOF):\n");
    size_t length = fread(text, sizeof(char), MAX_TEXT_LENGTH - 1, stdin);
    text[length] = '\0';  // Null-terminate the input string

    summarize_text(text);

    return 0;
}