//GEMINI-pro DATASET v1.0 Category: Text Summarizer ; Style: relaxed
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to remove stop words from a string
char *remove_stop_words(char *str) {
    char *stop_words[] = {"a", "an", "the", "and", "or", "but", "for", "nor", "as", "at", "by", "from", "in", "into", "near", "of", "on", "onto", "over", "past", "through", "to", "toward", "under", "up", "upon", "with", "without"};
    int num_stop_words = sizeof(stop_words) / sizeof(char *);

    char *new_str = malloc(strlen(str) + 1);
    int new_str_len = 0;

    char *word = strtok(str, " ");
    while (word != NULL) {
        int is_stop_word = 0;
        for (int i = 0; i < num_stop_words; i++) {
            if (strcmp(word, stop_words[i]) == 0) {
                is_stop_word = 1;
                break;
            }
        }

        if (!is_stop_word) {
            strcpy(new_str + new_str_len, word);
            new_str_len += strlen(word);
            new_str[new_str_len++] = ' ';
        }

        word = strtok(NULL, " ");
    }

    new_str[new_str_len - 1] = '\0';

    return new_str;
}

// Function to summarize a text
char *summarize_text(char *text) {
    // Remove stop words from the text
    char *cleaned_text = remove_stop_words(text);

    // Split the text into sentences
    char **sentences = malloc(100 * sizeof(char *));
    int num_sentences = 0;

    char *sentence = strtok(cleaned_text, ".");
    while (sentence != NULL) {
        sentences[num_sentences++] = sentence;
        sentence = strtok(NULL, ".");
    }

    // Calculate the frequency of each sentence
    int *sentence_frequencies = malloc(num_sentences * sizeof(int));
    for (int i = 0; i < num_sentences; i++) {
        sentence_frequencies[i] = 0;
        for (int j = 0; j < num_sentences; j++) {
            if (strcmp(sentences[i], sentences[j]) == 0) {
                sentence_frequencies[i]++;
            }
        }
    }

    // Sort the sentences by frequency
    for (int i = 0; i < num_sentences; i++) {
        for (int j = i + 1; j < num_sentences; j++) {
            if (sentence_frequencies[i] < sentence_frequencies[j]) {
                char *temp = sentences[i];
                sentences[i] = sentences[j];
                sentences[j] = temp;

                int temp_freq = sentence_frequencies[i];
                sentence_frequencies[i] = sentence_frequencies[j];
                sentence_frequencies[j] = temp_freq;
            }
        }
    }

    // Generate the summary
    char *summary = malloc(100 * sizeof(char *));
    int summary_len = 0;

    for (int i = 0; i < num_sentences; i++) {
        if (summary_len + strlen(sentences[i]) + 1 > 100) {
            break;
        }

        strcpy(summary + summary_len, sentences[i]);
        summary_len += strlen(sentences[i]);
        summary[summary_len++] = ' ';
    }

    summary[summary_len - 1] = '\0';

    // Free the allocated memory
    free(cleaned_text);
    for (int i = 0; i < num_sentences; i++) {
        free(sentences[i]);
    }
    free(sentences);
    free(sentence_frequencies);

    return summary;
}

int main() {
    // Get the text from the user
    char text[1000];
    printf("Enter the text you want to summarize: ");
    gets(text);

    // Summarize the text
    char *summary = summarize_text(text);

    // Print the summary
    printf("Summary: %s\n", summary);

    // Free the allocated memory
    free(summary);

    return 0;
}