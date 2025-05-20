//FormAI DATASET v1.0 Category: Text Summarizer ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUMMARY_LEN 50

// function to extract the first MAX_SUMMARY_LEN characters from a given string
char* extract_summary(char *text) {
    char *summary = (char*) malloc(MAX_SUMMARY_LEN + 1);
    strncpy(summary, text, MAX_SUMMARY_LEN);
    summary[MAX_SUMMARY_LEN] = '\0';
    return summary;
}

// function to count the number of occurrences of a given character in a string
int count_chars(char *text, char c) {
    int count = 0;
    for (int i = 0; i < strlen(text); i++) {
        if (text[i] == c) {
            count++;
        }
    }
    return count;
}

// function to compute the relevance score of a sentence
float score_sentence(char *sentence, char *keywords) {
    float score = 0;
    char *word = strtok(keywords, " ");
    while (word != NULL) {
        if (strstr(sentence, word) != NULL) {
            score += 1;
        }
        word = strtok(NULL, " ");
    }
    return score / count_chars(sentence, ' ');
}

// main function
int main() {
    // read the input text
    char *text = (char*) malloc(1000 * sizeof(char));
    printf("Enter the input text:\n");
    fgets(text, 1000, stdin);

    // read the keywords
    char *keywords = (char*) malloc(500 * sizeof(char));
    printf("Enter the keywords (separated by spaces):\n");
    fgets(keywords, 500, stdin);

    // split the text into sentences
    char *sentence = strtok(text, ".\n");

    // compute the relevance score of each sentence
    float scores[1000];
    int n_sentences = 0;
    while (sentence != NULL) {
        scores[n_sentences] = score_sentence(sentence, keywords);
        n_sentences++;
        sentence = strtok(NULL, ".\n");
    }

    // extract the top 5 most relevant sentences
    for (int i = 0; i < 5; i++) {
        float max_score = -1;
        int max_index = -1;
        for (int j = 0; j < n_sentences; j++) {
            if (scores[j] > max_score) {
                max_score = scores[j];
                max_index = j;
            }
        }
        if (max_index == -1) {
            break;
        }
        char *summary = extract_summary(strtok(text + max_index, ".\n"));
        printf("%s.\n", summary);
        scores[max_index] = -1;
    }

    return 0;
}