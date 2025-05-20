//GPT-4o-mini DATASET v1.0 Category: Spam Detection System ; Style: active
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_MESSAGE_LEN 1024
#define STOP_WORDS_COUNT 5
#define STOP_WORDS_FILE "stopwords.txt"

// Function to load stop words from a file
int load_stop_words(const char *filename, char stop_words[STOP_WORDS_COUNT][30]) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Could not open stopwords file");
        return -1;
    }

    int count = 0;
    while (fgets(stop_words[count], sizeof(stop_words[count]), file) && count < STOP_WORDS_COUNT) {
        stop_words[count][strcspn(stop_words[count], "\n")] = 0;  // Remove newline character
        count++;
    }
    fclose(file);
    return count;
}

// Function to check if the message is spam
int is_spam(const char *message, char stop_words[STOP_WORDS_COUNT][30], int stop_word_count) {
    int spam_score = 0;
    char temp_message[MAX_MESSAGE_LEN];

    // Normalize the message to lower case
    for (int i = 0; message[i]; i++) {
        temp_message[i] = tolower(message[i]);
    }
    temp_message[strlen(message)] = '\0';

    for (int i = 0; i < stop_word_count; i++) {
        if (strstr(temp_message, stop_words[i])) {
            spam_score++;
        }
    }

    return (spam_score >= 2); // Flag as spam if 2 or more stop words are found
}

// Main Function
int main() {
    char stop_words[STOP_WORDS_COUNT][30];
    int stop_word_count = load_stop_words(STOP_WORDS_FILE, stop_words);
    if (stop_word_count < 0) {
        return 1; // Error in loading stop words
    }

    char message[MAX_MESSAGE_LEN];

    printf("Enter the message to check for spam:\n");
    fgets(message, sizeof(message), stdin);
    message[strcspn(message, "\n")] = 0; // Remove newline character

    if (is_spam(message, stop_words, stop_word_count)) {
        printf("The message is considered spam.\n");
    } else {
        printf("The message is not considered spam.\n");
    }

    return 0;
}