//FormAI DATASET v1.0 Category: Text Summarizer ; Style: innovative
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_STRING_LENGTH 1000
#define MAX_SENTENCE_LENGTH 100

char* get_input() {
    char* input = malloc(MAX_STRING_LENGTH);
    printf("Enter the text you want to summarize:\n");
    fgets(input, MAX_STRING_LENGTH, stdin);
    return input;
}

int is_end_of_sentence(char character) {
    return (character == '.' || character == '?' || character == '!');
}

int count_sentences(char* input) {
    int sentence_count = 0;
    int length = strlen(input);
    for (int i = 0; i < length; i++) {
        if (is_end_of_sentence(input[i])) {
            sentence_count++;
            if (i < length - 1) {
                // Ignore double periods at the end of a sentence
                if (input[i + 1] == '.') {
                    i++;
                }
            }
        }
    }
    return sentence_count;
}

void strip_punctuation(char* sentence) {
    int length = strlen(sentence);
    int new_length = 0;
    for (int i = 0; i < length; i++) {
        if (!ispunct(sentence[i]) || (i > 0 && sentence[i - 1] == ' ')) {
            sentence[new_length++] = tolower(sentence[i]);
        }
    }
    sentence[new_length++] = '\0';
}

void summarize(char* input, int sentence_count) {
    char* sentences[MAX_SENTENCE_LENGTH];
    int sentence_lengths[MAX_SENTENCE_LENGTH];
    int index = 0;

    // Tokenize sentences
    char* sentence = strtok(input, ".?!");

    while (sentence != NULL) {
        // Strip punctuation and convert to lowercase
        strip_punctuation(sentence);

        // Add sentence to array and keep track of length
        sentences[index] = sentence;
        sentence_lengths[index] = strlen(sentence);

        index++;

        sentence = strtok(NULL, ".?!");
    }

    // Sort sentences based on length
    for (int i = 0; i < sentence_count - 1; i++) {
        for (int j = 0; j < sentence_count - i - 1; j++) {
            if (sentence_lengths[j] < sentence_lengths[j + 1]) {
                int temp_length = sentence_lengths[j];
                sentence_lengths[j] = sentence_lengths[j + 1];
                sentence_lengths[j + 1] = temp_length;

                char* temp_sentence = sentences[j];
                sentences[j] = sentences[j + 1];
                sentences[j + 1] = temp_sentence;
            }
        }
    }

    // Print summary
    printf("Summary:\n");

    int total_chars = 0;
    for (int i = 0; i < sentence_count; i++) {
        total_chars += sentence_lengths[i];
        printf("%s. ", sentences[i]);

        if (total_chars > MAX_STRING_LENGTH / 2) {
            break;
        }
    }
}

int main() {
    char* input = get_input();
    int sentence_count = count_sentences(input);

    if (sentence_count == 0) {
        printf("Error: input does not contain any sentences.\n");
        return 1;
    }

    summarize(input, sentence_count);

    return 0;
}