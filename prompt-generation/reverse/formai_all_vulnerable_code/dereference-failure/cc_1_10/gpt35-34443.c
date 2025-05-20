//FormAI DATASET v1.0 Category: Text Summarizer ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SUMMARY_LENGTH 100 // maximum length of summary

// function to clean text from punctuations and new lines
void clean_text(char *text) {
    int i, j;
    for (i = 0, j = 0; text[i]; i++) {
        if (isalpha(text[i])) {
            text[j++] = tolower(text[i]);
        } else if (text[i] == '.' || text[i] == '?' || text[i] == '!') {
            text[j++] = '.';
            text[j++] = '\0';
        }
    }
    text[j] = '\0';
}

// function to split text into sentences
int split_text(char *text, char sentences[][100]) {
    char *sentence = strtok(text, ".");
    int sentence_count = 0;
    while (sentence) {
        strcpy(sentences[sentence_count++], sentence);
        sentence = strtok(NULL, ".");
    }
    return sentence_count;
}

// function to calculate frequency of words in text
void word_frequency(char *text, int words[], char *word_list[], int *word_count) {
    char *word = strtok(text, " ");
    while (word) {
        int found = 0;
        for (int i = 0; i < *word_count; i++) {
            if (strcmp(word_list[i], word) == 0) {
                found = 1;
                words[i]++;
                break;
            }
        }
        if (!found) {
            word_list[*word_count] = word;
            words[(*word_count)++] = 1;
        }
        word = strtok(NULL, " ");
    }
}

// function to find most frequent words in text
void most_frequent_words(int *words, char **word_list, int word_count, char *most_frequent[]) {
    for (int i = 0; i < 5; i++) {
        int max = -1;
        int max_index;
        for (int j = 0; j < word_count; j++) {
            if (words[j] > max) {
                max = words[j];
                max_index = j;
            }
        }
        most_frequent[i] = word_list[max_index];
        words[max_index] = -1;
    }
}

int main() {
    char text[1000];
    char sentences[20][100];
    char *word_list[100];
    int words[100] = {0};
    char *most_frequent[5];
    int word_count = 0;
    int sentence_count;
    char summary[MAX_SUMMARY_LENGTH] = "";

    printf("Enter text:\n");
    fgets(text, 1000, stdin);
    clean_text(text);
    sentence_count = split_text(text, sentences);
    word_frequency(text, words, word_list, &word_count);
    most_frequent_words(words, word_list, word_count, most_frequent);

    // construct summary
    strcat(summary, "The most frequent words in the text are: ");
    for (int i = 0; i < 5; i++) {
        strcat(summary, most_frequent[i]);
        if (i != 4) strcat(summary, ", ");
    }
    if (sentence_count > 1) {
        strcat(summary, "\nThe text can be summarized as follows:\n");
        strcat(summary, sentences[0]);
        strcat(summary, ".");
    } else {
        strcat(summary, "\nThe text is too short to be summarized.");
    }

    printf("Summary: %s\n", summary);
    return 0;
}