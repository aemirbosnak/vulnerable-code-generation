//FormAI DATASET v1.0 Category: Text Summarizer ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LEN 1000
#define MAX_SENTENCES 50
#define MAX_WORD_LEN 20

char* remove_punctuation(char* sentence) {
    char* new_sentence = NULL;
    int len = strlen(sentence);
    int j = 0;
    new_sentence = (char*) malloc(len * sizeof(char));
    for (int i = 0; i < len; i++) {
        if ((sentence[i] >= 'a' && sentence[i] <= 'z') || (sentence[i] >= 'A' && sentence[i] <= 'Z')) {
            new_sentence[j++] = sentence[i];
        }
    }
    new_sentence[j] = '\0';
    return new_sentence;
}

void convert_to_lowercase(char* sentence) {
    int len = strlen(sentence);
    for (int i = 0; i < len; i++) {
        sentence[i] = tolower(sentence[i]);
    }
}

char** get_words(char* sentence, int* num_words) {
    char** words = NULL;
    char* temp_sentence = NULL;
    char* token = NULL;
    int i = 0;
    temp_sentence = remove_punctuation(sentence);
    convert_to_lowercase(temp_sentence);
    words = (char**) malloc(MAX_SENTENCES * sizeof(char*));
    token = strtok(temp_sentence, " ");
    while (token) {
        words[i] = (char*) malloc((strlen(token) + 1) * sizeof(char));
        strcpy(words[i], token);
        i++;
        token = strtok(NULL, " ");
    }
    *num_words = i;
    return words;
}

void print_summary(char** sentences, int* scores, int num_sentences, int num_total_words, int summary_size) {
    int count = 0;
    printf("SUMMARY:\n");
    for (int i = 0; i < num_sentences; i++) {
        if (scores[i] > 0) {
            printf("%s\n", sentences[i]);
            count++;
            if (count == summary_size) {
                break;
            }
        }
    }
    if (count == 0) {
        printf("No summary found.\n");
    }
}

void calculate_sentence_scores(char** sentences, int* scores, int num_sentences, int* word_counts, int num_total_words) {
    char** words = NULL;
    int num_words = 0;
    int count = 0;
    for (int i = 0; i < num_sentences; i++) {
        words = get_words(sentences[i], &num_words);
        count = 0;
        for (int j = 0; j < num_words; j++) {
            for (int k = 0; k < num_total_words; k++) {
                if (strcmp(words[j], words[k]) == 0) {
                    count++;
                }
            }
        }
        scores[i] = count;
        free(words);
    }
}

int main() {
    char input_text[MAX_STR_LEN];
    char* sentences[MAX_SENTENCES];
    int scores[MAX_SENTENCES] = {0};
    int word_counts[MAX_WORD_LEN] = {0};
    int num_sentences = 0;
    int num_total_words = 0;
    int summary_size = 5;
    char* token = NULL;
    printf("Enter the text you want to summarize:\n");
    fgets(input_text, MAX_STR_LEN, stdin);
    token = strtok(input_text, ".");
    while (token) {
        sentences[num_sentences] = (char*) malloc((strlen(token) + 1) * sizeof(char));
        strcpy(sentences[num_sentences], token);
        num_sentences++;
        token = strtok(NULL, ".");
    }
    for (int i = 0; i < num_sentences; i++) {
        word_counts[i] = strlen(sentences[i]);
        num_total_words += word_counts[i];
    }
    calculate_sentence_scores(sentences, scores, num_sentences, word_counts, num_total_words);
    print_summary(sentences, scores, num_sentences, num_total_words, summary_size);
    for (int i = 0; i < num_sentences; i++) {
        free(sentences[i]);
    }
    return 0;
}