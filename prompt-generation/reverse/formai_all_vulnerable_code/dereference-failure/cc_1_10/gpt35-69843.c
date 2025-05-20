//FormAI DATASET v1.0 Category: Text Summarizer ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT 1000
#define MAX_SUMMARY 100

/* Function to check if a character is a sentence ending punctuation */
int is_sentence_end(char c) {
    if(c == '.' || c == '?' || c == '!') {
        return 1;
    }
    return 0;
}

/* Function to calculate the score of each sentence based on how many important words it has */
int calculate_sentence_score(char sentence[], char important_words[][20], int num_words) {
    int score = 0;
    char *ptr;
    char *word = strtok_r(sentence, " ", &ptr);
    while(word != NULL) {
        for(int i = 0; i < num_words; i++) {
            if(strcmp(word, important_words[i]) == 0) {
                score++;
                break;
            }
        }
        word = strtok_r(NULL, " ", &ptr);
    }
    return score;
}

/* Function to summarize the input text */
void summarize_text() {
    char input[MAX_INPUT];
    char important_words[MAX_SUMMARY][20];
    char output[MAX_SUMMARY][100];
    int num_words = 0;
    int num_sentences = 0;

    /* Get input text from user */
    printf("Enter input text (max %d characters):\n", MAX_INPUT);
    fgets(input, MAX_INPUT, stdin);

    /* Get important words from user */
    printf("Enter important words (one per line, max %d words):\n", MAX_SUMMARY);
    char *word = malloc(20);
    while(num_words < MAX_SUMMARY && fgets(word, 20, stdin) != NULL && *word != '\n') {
        strtok(word, "\n"); // remove newline character
        strcpy(important_words[num_words], word);
        num_words++;
    }
    free(word);

    /* Start summarization */
    char *ptr;
    char *sentence = strtok_r(input, ".", &ptr);
    int scores[MAX_INPUT];
    while(sentence != NULL) {
        /* Remove leading and trailing whitespace */
        char *end_ptr = sentence + strlen(sentence) - 1;
        while(isspace(*sentence)) sentence++;
        while(end_ptr > sentence && isspace(*end_ptr)) end_ptr--;
        *(end_ptr + 1) = '\0';

        /* Calculate sentence score */
        int score = calculate_sentence_score(sentence, important_words, num_words);
        scores[num_sentences] = score;

        /* Add sentence to output */
        if(score > 0) {
            strcpy(output[num_sentences], sentence);
            num_sentences++;
        }

        sentence = strtok_r(NULL, ".", &ptr);
    }

    /* Print output */
    printf("Summary:\n");
    for(int i = 0; i < num_sentences; i++) {
        printf("%s.", output[i]);
        if(i < num_sentences - 1) printf(" ");
    }
    printf("\n");
}

int main() {
    summarize_text();
    return 0;
}