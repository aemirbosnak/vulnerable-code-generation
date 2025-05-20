//FormAI DATASET v1.0 Category: Text Summarizer ; Style: Ada Lovelace
/* 
Ada's Text Summarizer Program 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SENTENCES 20  // Maximum number of sentences in the summary
#define MAX_SUMMARY_LEN 500  // Maximum length of the summary

/* Function to calculate the frequency of each word in the given text */
void calc_word_freq(char *text, int *word_freq) {
    char *word, *save_ptr;
    word = strtok_r(text, " ,.?!;:", &save_ptr);

    while (word != NULL) {
        word_freq[atoi(word)]++;
        word = strtok_r(NULL, " ,.?!;:", &save_ptr);
    }
}

/* Function to convert the given text into an array of sentences */
void get_sentences(char *text, char *sentences[]) {
    char *sentence, *save_ptr;
    int i = 0;
    sentence = strtok_r(text, ".!?\n", &save_ptr);

    while (sentence != NULL && i < MAX_SENTENCES) {
        sentences[i++] = sentence;
        sentence = strtok_r(NULL, ".!?\n", &save_ptr);
    }
}

/* Function to sort the sentences in descending order of importance */
void sort_sentences(char *sentences[], int *word_freq) {
    int i, j, temp;
    char *temp_sentence;

    for (i = 0; i < MAX_SENTENCES - 1; i++) {
        for (j = i + 1; j < MAX_SENTENCES; j++) {
            if (word_freq[i] < word_freq[j]) {
                temp = word_freq[i];
                word_freq[i] = word_freq[j];
                word_freq[j] = temp;

                temp_sentence = sentences[i];
                sentences[i] = sentences[j];
                sentences[j] = temp_sentence;
            }
        }
    }
}

int main() {
    char text[2000], summary[MAX_SUMMARY_LEN], *sentences[MAX_SENTENCES];
    int i, word_freq[MAX_SENTENCES] = {0};

    printf("Welcome to Ada's Text Summarizer Program!\n\n");
    printf("Please enter the text you want to summarize:\n");
    fgets(text, 2000, stdin);

    calc_word_freq(text, word_freq);
    get_sentences(text, sentences);
    sort_sentences(sentences, word_freq);

    /* Constructing the summary by selecting the most important sentences */
    strcpy(summary, sentences[0]);
    for (i = 1; i < MAX_SENTENCES && summary[i] != '\0'; i++) {
        if (strlen(summary) + strlen(sentences[i]) < MAX_SUMMARY_LEN) {
            strcat(summary, " ");
            strcat(summary, sentences[i]);
        }
    }

    printf("\nThe summary is: \n%s\n", summary);
    printf("\nThank you for using Ada's Text Summarizer Program!\n");

    return 0;
}