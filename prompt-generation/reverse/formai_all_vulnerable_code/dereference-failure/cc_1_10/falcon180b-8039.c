//Falcon-180B DATASET v1.0 Category: Text Summarizer ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SENTENCE_LENGTH 100
#define MAX_SENTENCES 1000

// Function to clean the input sentence
void clean_sentence(char* sentence) {
    int i = 0, j = 0;
    while (sentence[i]) {
        if (isalpha(sentence[i])) {
            sentence[j++] = tolower(sentence[i]);
        }
        i++;
    }
    sentence[j] = '\0';
}

// Function to split the input text into sentences
int split_sentences(char* text, char* sentences[]) {
    char* sentence = strtok(text, ".");
    int count = 0;
    while (sentence!= NULL) {
        clean_sentence(sentence);
        strcpy(sentences[count], sentence);
        count++;
        sentence = strtok(NULL, ".");
    }
    return count;
}

// Function to generate the summary
void generate_summary(char* sentences[], int num_sentences, char* summary) {
    int i, j;
    for (i = 0, j = 0; i < num_sentences && j < MAX_SENTENCE_LENGTH; i++) {
        if (strlen(sentences[i]) > j) {
            strncat(summary, sentences[i] + j, 1);
            j++;
        } else {
            strcat(summary, sentences[i]);
            j = strlen(sentences[i]);
        }
        strcat(summary, " ");
    }
    summary[j] = '\0';
}

int main() {
    char input_text[10000];
    printf("Enter the input text: ");
    fgets(input_text, sizeof(input_text), stdin);

    char sentences[MAX_SENTENCES][MAX_SENTENCE_LENGTH];
    int num_sentences = split_sentences(input_text, sentences);

    char summary[MAX_SENTENCE_LENGTH];
    generate_summary(sentences, num_sentences, summary);

    printf("Summary: %s\n", summary);

    return 0;
}