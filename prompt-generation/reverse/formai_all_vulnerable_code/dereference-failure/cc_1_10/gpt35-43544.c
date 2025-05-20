//FormAI DATASET v1.0 Category: Text Summarizer ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SENTENCES 100
#define MAX_WORDS 1000
#define MAX_WORD_LEN 20
#define MAX_SENTENCE_LEN 1000

// Struct to hold information for each word
typedef struct {
    char word[MAX_WORD_LEN];
    int sentence_index;
    int word_index;
    int frequency;
} WordInfo;

// Utility function to check if word is already in the array
int contains_word(WordInfo* words, int num_words, char* word) {
    for (int i = 0; i < num_words; i++) {
        if (strcmp(words[i].word, word) == 0) {
            return i;
        }
    }
    return -1;
}

// Read input from file
void read_input(char* filename, char* input) {
    FILE* file;
    file = fopen(filename, "r");

    if (file == NULL) {
        printf("Failed to open file: %s\n", filename);
        exit(1);
    }

    char c = fgetc(file);
    int i = 0;
    while (c != EOF) {
        input[i] = c;
        i++;
        c = fgetc(file);
    }

    fclose(file);
}

// Split input string into sentences
int split_into_sentences(char* input, char sentences[][MAX_SENTENCE_LEN]) {
    int num_sentences = 0;
    int sentence_index = 0;
    int i = 0;

    while (input[i] != '\0') {
        if (input[i] == '.' || input[i] == '?' || input[i] == '!') {
            sentences[num_sentences][sentence_index] = input[i];
            sentences[num_sentences][++sentence_index] = '\0';
            num_sentences++;
            sentence_index = 0;
        } else {
            sentences[num_sentences][sentence_index] = input[i];
            sentence_index++;
        }
        i++;
    }

    return num_sentences;
}

// Split sentence into words
int split_into_words(char* sentence, char words[][MAX_WORD_LEN]) {
    int i = 0;
    int word_index = 0;
    int num_words = 0;

    while (sentence[i] != '\0') {
        if (sentence[i] == ' ' || sentence[i] == '\n' || sentence[i] == '\t') {
            if (word_index > 0) {
                words[num_words][word_index] = '\0';
                num_words++;
                word_index = 0;
            }
        } else {
            words[num_words][word_index] = sentence[i];
            word_index++;
        }

        i++;
    }

    if (word_index > 0) { // Handle last word
        words[num_words][word_index] = '\0';
        num_words++;
    }

    return num_words;
}

// Get information about each word in the input
void get_word_info(char sentences[][MAX_SENTENCE_LEN], int num_sentences, WordInfo* words, int* num_words) {
    int word_count = 0;
    for (int i = 0; i < num_sentences; i++) {
        char sentence[MAX_SENTENCE_LEN];
        strcpy(sentence, sentences[i]);

        char words_in_sentence[MAX_WORDS][MAX_WORD_LEN];
        int num_words_in_sentence = split_into_words(sentence, words_in_sentence);

        for (int j = 0; j < num_words_in_sentence; j++) {
            int index = contains_word(words, word_count, words_in_sentence[j]);

            if (index == -1) { // New word
                index = word_count;
                strcpy(words[index].word, words_in_sentence[j]);
                words[index].frequency = 1;
                words[index].sentence_index = i;
                words[index].word_index = j;
                word_count++;
            } else { // Word already exists
                words[index].frequency++;
            }
        }
    }

    *num_words = word_count;
}

// Sort words by frequency in descending order
void sort_words_descending(WordInfo* words, int num_words) {
    for (int i = 0; i < num_words - 1; i++) {
        for (int j = i + 1; j < num_words; j++) {
            if (words[i].frequency < words[j].frequency) {
                WordInfo temp = words[i];
                words[i] = words[j];
                words[j] = temp;
            }
        }
    }
}

// Print top n sentences that contain the most frequent words
void print_summary(char sentences[][MAX_SENTENCE_LEN], int num_sentences, WordInfo* words, int num_words, int num_summary_sentences) {
    int num_summary_words = num_words * num_summary_sentences;
    int summary_words[num_summary_words];
    int summary_word_count = 0;

    for (int i = 0; i < num_words; i++) {
        int sentence_index = words[i].sentence_index;
        int word_index = words[i].word_index;
        int added_to_summary = 0;

        for (int j = 0; j < summary_word_count; j++) {
            if (sentence_index == summary_words[j]) {
                added_to_summary = 1;
                break;
            }
        }

        if (!added_to_summary) {
            summary_words[summary_word_count] = sentence_index;
            summary_word_count++;
            if (summary_word_count >= num_summary_words) break;
        }
    }

    for (int i = 0; i < summary_word_count; i++) {
        printf("%s", sentences[summary_words[i]]);
    }
}

int main(int argc, char const *argv[]) {
    if (argc != 4) {
        printf("Usage: ./summarizer input_file num_summary_sentences output_file\n");
        return 1;
    }

    char input[MAX_SENTENCES*MAX_SENTENCE_LEN];
    read_input(argv[1], input);

    char sentences[MAX_SENTENCES][MAX_SENTENCE_LEN];
    int num_sentences = split_into_sentences(input, sentences);

    WordInfo words[MAX_WORDS];
    int num_words;
    get_word_info(sentences, num_sentences, words, &num_words);
    sort_words_descending(words, num_words);

    int num_summary_sentences = atoi(argv[2]);
    FILE* file;
    file = fopen(argv[3], "w");
    if (file == NULL) {
        printf("Unable to open file: %s", argv[3]);
        return 1;
    }

    for (int i = 0; i < num_summary_sentences; i++) {
        fprintf(file, "%s", sentences[words[i].sentence_index]);
    }

    fclose(file);

    return 0;
}