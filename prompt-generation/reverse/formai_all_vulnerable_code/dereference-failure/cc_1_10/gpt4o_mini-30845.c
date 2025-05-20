//GPT-4o-mini DATASET v1.0 Category: Sentiment analysis tool ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000
#define POSITIVE_WORDS_FILE "positive-words.txt"
#define NEGATIVE_WORDS_FILE "negative-words.txt"

char *load_file(const char *filename, int *word_count) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }
    
    char *words = malloc(MAX_SIZE);
    if (!words) {
        perror("Error allocating memory");
        exit(EXIT_FAILURE);
    }

    int count = 0;
    while (fgets(words + count, MAX_SIZE - count, file) != NULL) {
        count += strlen(words + count);
    }
    fclose(file);
    words[count] = '\0';
    *word_count = count;

    return words;
}

int is_positive(const char *word, char **positive_words, int pos_count) {
    for (int i = 0; i < pos_count; i++) {
        if (strcmp(word, positive_words[i]) == 0) {
            return 1; // Found positive word
        }
    }
    return 0; // Not found in positive words
}

int is_negative(const char *word, char **negative_words, int neg_count) {
    for (int i = 0; i < neg_count; i++) {
        if (strcmp(word, negative_words[i]) == 0) {
            return 1; // Found negative word
        }
    }
    return 0; // Not found in negative words
}

void tokenize_and_analyze(const char *text, char **positive_words, int pos_count, char **negative_words, int neg_count) {
    char *token = strtok(text, " \n");
    int pos_score = 0, neg_score = 0;

    while (token != NULL) {
        if (is_positive(token, positive_words, pos_count)) {
            pos_score++;
        } else if (is_negative(token, negative_words, neg_count)) {
            neg_score++;
        }
        token = strtok(NULL, " \n");
    }

    if (pos_score > neg_score) {
        printf("Sentiment: Positive (Score: %d)\n", pos_score);
    } else if (neg_score > pos_score) {
        printf("Sentiment: Negative (Score: %d)\n", neg_score);
    } else {
        printf("Sentiment: Neutral (Score: %d)\n", pos_score);
    }
}

int main() {
    int pos_count = 0, neg_count = 0;
    
    char *positive_words[MAX_SIZE];
    char *negative_words[MAX_SIZE];

    char *pos_data = load_file(POSITIVE_WORDS_FILE, &pos_count);
    char *neg_data = load_file(NEGATIVE_WORDS_FILE, &neg_count);

    // Populate arrays for easier searching
    positive_words[0] = strtok(pos_data, "\n");
    for (int i = 1; i < pos_count; ++i) {
        positive_words[i] = strtok(NULL, "\n");
    }
    
    negative_words[0] = strtok(neg_data, "\n");
    for (int i = 1; i < neg_count; ++i) {
        negative_words[i] = strtok(NULL, "\n");
    }

    char text[MAX_SIZE];
    printf("Enter text for sentiment analysis (type 'exit' to quit):\n");
    
    while (1) {
        fgets(text, sizeof(text), stdin);
        if (strcmp(text, "exit\n") == 0) {
            break;
        }
        tokenize_and_analyze(text, positive_words, pos_count, negative_words, neg_count);
    }

    free(pos_data);
    free(neg_data);
    
    return 0;
}