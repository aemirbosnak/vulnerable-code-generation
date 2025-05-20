//GEMINI-pro DATASET v1.0 Category: Text Summarizer ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function to compute the frequency of each word in a text */
int *compute_word_frequency(char *text, int *num_words) {
    char *token;
    int *frequency;
    int i, j;

    /* Split the text into words */
    token = strtok(text, " ,.-!?");
    while (token != NULL) {
        (*num_words)++;
        token = strtok(NULL, " ,.-!?");
    }

    /* Allocate memory for the frequency array */
    frequency = (int *)malloc(*num_words * sizeof(int));

    /* Initialize the frequency array to zero */
    for (i = 0; i < *num_words; i++) {
        frequency[i] = 0;
    }

    /* Compute the frequency of each word */
    token = strtok(text, " ,.-!?");
    while (token != NULL) {
        for (i = 0; i < *num_words; i++) {
            if (strcmp(token, text + i) == 0) {
                frequency[i]++;
                break;
            }
        }
        token = strtok(NULL, " ,.-!?");
    }

    return frequency;
}

/* Function to compute the entropy of a text */
double compute_entropy(char *text, int num_words) {
    int *frequency;
    double entropy;
    int i;

    /* Compute the frequency of each word */
    frequency = compute_word_frequency(text, &num_words);

    /* Compute the entropy */
    entropy = 0.0;
    for (i = 0; i < num_words; i++) {
        if (frequency[i] > 0) {
            entropy += (double)frequency[i] / (double)num_words * log2((double)frequency[i] / (double)num_words);
        }
    }

    return entropy;
}

/* Function to summarize a text */
char *summarize_text(char *text, double ratio) {
    int num_words;
    int *frequency;
    int i, j;
    char *summary;
    int summary_length;

    /* Compute the number of words in the text */
    num_words = 0;
    compute_word_frequency(text, &num_words);

    /* Compute the frequency of each word */
    frequency = compute_word_frequency(text, &num_words);

    /* Sort the words by frequency */
    for (i = 0; i < num_words - 1; i++) {
        for (j = i + 1; j < num_words; j++) {
            if (frequency[i] < frequency[j]) {
                int temp;
                temp = frequency[i];
                frequency[i] = frequency[j];
                frequency[j] = temp;
            }
        }
    }

    /* Compute the length of the summary */
    summary_length = (int)(ratio * num_words);

    /* Allocate memory for the summary */
    summary = (char *)malloc(summary_length * sizeof(char));

    /* Generate the summary */
    j = 0;
    for (i = 0; i < num_words; i++) {
        if (j >= summary_length) {
            break;
        }
        if (frequency[i] > 0) {
            strcpy(summary + j, text + i);
            j += strlen(text + i) + 1;
        }
    }

    return summary;
}

/* Main function */
int main() {
    char *text;
    double ratio;
    char *summary;

    /* Get the text from the user */
    printf("Enter the text: ");
    text = (char *)malloc(10000 * sizeof(char));
    gets(text);

    /* Get the ratio from the user */
    printf("Enter the ratio: ");
    scanf("%lf", &ratio);

    /* Summarize the text */
    summary = summarize_text(text, ratio);

    /* Print the summary */
    printf("Summary: %s\n", summary);

    return 0;
}