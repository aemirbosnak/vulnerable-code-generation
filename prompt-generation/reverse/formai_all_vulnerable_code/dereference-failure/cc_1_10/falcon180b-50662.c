//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000000
#define MAX_WORD_LENGTH 50

// Function to remove punctuation from a string
void remove_punctuation(char* str) {
    int i, j;
    for (i = 0, j = 0; str[i]!= '\0'; i++) {
        if (!ispunct(str[i])) {
            str[j++] = tolower(str[i]);
        }
    }
    str[j] = '\0';
}

// Function to split a string into words
void split_string(char* str, char** words) {
    char* token;
    int num_words = 0;
    token = strtok(str, " ");
    while (token!= NULL) {
        words[num_words++] = token;
        token = strtok(NULL, " ");
    }
}

// Function to calculate the frequency of each word in the message
void calculate_word_frequencies(char** words, int num_words, int* frequencies) {
    int i, j;
    for (i = 0; i < num_words; i++) {
        frequencies[i] = 1;
    }
    for (i = 0; i < num_words; i++) {
        for (j = i + 1; j < num_words; j++) {
            if (strcmp(words[i], words[j]) == 0) {
                frequencies[i]++;
            }
        }
    }
}

// Function to check if a message is spam
int is_spam(int* frequencies, int num_words) {
    int i, sum = 0;
    for (i = 0; i < num_words; i++) {
        sum += frequencies[i];
    }
    return sum > num_words / 2;
}

// Main function
int main() {
    char message[1000];
    char* words[MAX_WORDS];
    int frequencies[MAX_WORDS];
    int num_words;
    printf("Enter a message: ");
    fgets(message, sizeof(message), stdin);
    remove_punctuation(message);
    split_string(message, words);
    num_words = 0;
    while (words[num_words]!= NULL) {
        num_words++;
    }
    calculate_word_frequencies(words, num_words, frequencies);
    if (is_spam(frequencies, num_words)) {
        printf("Spam!\n");
    } else {
        printf("Not spam.\n");
    }
    return 0;
}