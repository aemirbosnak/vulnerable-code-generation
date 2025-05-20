//GEMINI-pro DATASET v1.0 Category: Text Summarizer ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to calculate the length of a string
int str_len(char *str) {
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}

// Function to compare two strings
int str_cmp(char *str1, char *str2) {
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i]) {
            return str1[i] - str2[i];
        }
        i++;
    }
    return str1[i] - str2[i];
}

// Function to copy a string
char *str_cpy(char *dest, char *src) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return dest;
}

// Function to concatenate two strings
char *str_cat(char *dest, char *src) {
    int dest_len = str_len(dest);
    int src_len = str_len(src);
    for (int i = 0; i < src_len; i++) {
        dest[dest_len + i] = src[i];
    }
    dest[dest_len + src_len] = '\0';
    return dest;
}

// Function to summarize a text
char *summarize_text(char *text) {
    // Tokenize the text into sentences
    char *sentences[100];
    int sentence_count = 0;
    char *sentence = strtok(text, ".");
    while (sentence != NULL) {
        sentences[sentence_count] = sentence;
        sentence_count++;
        sentence = strtok(NULL, ".");
    }

    // Calculate the score of each sentence
    int sentence_scores[100];
    for (int i = 0; i < sentence_count; i++) {
        sentence_scores[i] = 0;
        char *word = strtok(sentences[i], " ");
        while (word != NULL) {
            if (strcmp(word, "the") == 0 || strcmp(word, "is") == 0 || strcmp(word, "are") == 0 || strcmp(word, "was") == 0 || strcmp(word, "were") == 0 || strcmp(word, "a") == 0 || strcmp(word, "an") == 0) {
                sentence_scores[i] -= 1;
            } else {
                sentence_scores[i] += 1;
            }
            word = strtok(NULL, " ");
        }
    }

    // Sort the sentences by score
    for (int i = 0; i < sentence_count; i++) {
        for (int j = i + 1; j < sentence_count; j++) {
            if (sentence_scores[i] < sentence_scores[j]) {
                int temp = sentence_scores[i];
                sentence_scores[i] = sentence_scores[j];
                sentence_scores[j] = temp;
                char *temp_sentence = sentences[i];
                sentences[i] = sentences[j];
                sentences[j] = temp_sentence;
            }
        }
    }

    // Create the summary
    char *summary = malloc(1000);
    summary[0] = '\0';
    for (int i = 0; i < sentence_count; i++) {
        if (strlen(summary) + strlen(sentences[i]) < 1000) {
            summary = strcat(summary, sentences[i]);
            summary = strcat(summary, ". ");
        } else {
            break;
        }
    }

    return summary;
}

int main() {
    // Get the text from the user
    char text[1000];
    printf("Enter the text: ");
    gets(text);

    // Summarize the text
    char *summary = summarize_text(text);

    // Print the summary
    printf("Summary: %s", summary);

    return 0;
}