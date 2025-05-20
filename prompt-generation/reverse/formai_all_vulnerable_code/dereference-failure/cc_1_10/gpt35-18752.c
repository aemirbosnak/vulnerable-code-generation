//FormAI DATASET v1.0 Category: Text Summarizer ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1000

int main() {
    char input[MAX_LEN];
    printf("Enter the text you want to summarize:\n");
    fgets(input, MAX_LEN, stdin);

    // Convert all text to lowercase
    for (int i = 0; i < strlen(input); i++) {
        if (input[i] >= 'A' && input[i] <= 'Z') {
            input[i] = input[i] - 'A' + 'a';
        }
    }

    // Split the text into an array of words
    char **words = malloc(MAX_LEN * sizeof(char*));
    int num_words = 0;
    char *token = strtok(input, " ");

    while (token != NULL) {
        words[num_words] = token;
        num_words++;
        token = strtok(NULL, " ");
    }

    // Count the frequency of each word
    int *freq = calloc(num_words, sizeof(int));
    for (int i = 0; i < num_words; i++) {
        for (int j = 0; j < num_words; j++) {
            if (strcmp(words[i], words[j]) == 0) {
                freq[i]++;
            }
        }
    }

    // Determine the most common word and its frequency
    int max_freq = 0;
    char *most_common_word = NULL;
    for (int i = 0; i < num_words; i++) {
        if (freq[i] > max_freq) {
            max_freq = freq[i];
            most_common_word = words[i];
        }
    }

    // Print the summary
    printf("\nSUMMARY: The most common word is \"%s\" with a frequency of %d\n", most_common_word, max_freq);

    // Free memory
    free(words);
    free(freq);

    return 0;
}