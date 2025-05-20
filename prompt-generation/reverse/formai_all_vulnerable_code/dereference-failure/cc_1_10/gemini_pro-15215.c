//GEMINI-pro DATASET v1.0 Category: Spam Detection System ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define a struct to store the spam detection features
typedef struct {
    int has_caps_words;
    int has_exclamation_marks;
    int has_urls;
    int has_repeated_words;
} spam_features_t;

// Read a line of text from the user
char *read_line() {
    char *line = NULL;
    size_t len = 0;
    getline(&line, &len, stdin);
    return line;
}

// Extract the spam detection features from a line of text
spam_features_t extract_features(char *line) {
    spam_features_t features = {0};

    // Check if the line has any capital words
    for (int i = 0; i < strlen(line); i++) {
        if (isupper(line[i])) {
            features.has_caps_words = 1;
            break;
        }
    }

    // Check if the line has any exclamation marks
    for (int i = 0; i < strlen(line); i++) {
        if (line[i] == '!') {
            features.has_exclamation_marks = 1;
            break;
        }
    }

    // Check if the line has any URLs
    for (int i = 0; i < strlen(line); i++) {
        if (line[i] == 'h' && line[i+1] == 't' && line[i+2] == 't' && line[i+3] == 'p') {
            features.has_urls = 1;
            break;
        }
    }

    // Check if the line has any repeated words
    char *words[100];
    int num_words = 0;

    char *word = strtok(line, " ");
    while (word != NULL) {
        words[num_words++] = word;
        word = strtok(NULL, " ");
    }

    for (int i = 0; i < num_words; i++) {
        for (int j = i + 1; j < num_words; j++) {
            if (strcmp(words[i], words[j]) == 0) {
                features.has_repeated_words = 1;
                break;
            }
        }
    }

    return features;
}

// Classify a line of text as spam or not based on its features
int classify_spam(spam_features_t features) {
    int spam_score = 0;

    if (features.has_caps_words) {
        spam_score += 1;
    }

    if (features.has_exclamation_marks) {
        spam_score += 1;
    }

    if (features.has_urls) {
        spam_score += 2;
    }

    if (features.has_repeated_words) {
        spam_score += 1;
    }

    if (spam_score >= 2) {
        return 1;
    } else {
        return 0;
    }
}

// Print the results of spam detection
void print_results(int is_spam) {
    if (is_spam) {
        printf("This is spam.\n");
    } else {
        printf("This is not spam.\n");
    }
}

// Main function
int main() {
    // Read a line of text from the user
    char *line = read_line();

    // Extract the spam detection features from the line of text
    spam_features_t features = extract_features(line);

    // Classify the line of text as spam or not based on its features
    int is_spam = classify_spam(features);

    // Print the results of spam detection
    print_results(is_spam);

    // Free the memory allocated for the line of text
    free(line);

    return 0;
}