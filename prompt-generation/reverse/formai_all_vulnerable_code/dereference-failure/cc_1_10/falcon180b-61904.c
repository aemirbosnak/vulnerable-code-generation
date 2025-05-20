//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STRING_LENGTH 1000

// Function to remove punctuation from a string
void remove_punctuation(char* str) {
    int i = 0, j = 0;
    while (str[i]) {
        if (!ispunct(str[i])) {
            str[j++] = tolower(str[i]);
        }
        i++;
    }
    str[j] = '\0';
}

// Function to tokenize a string
void tokenize(char* str, char* tokens[]) {
    int i = 0, j = 0, k = 0;
    while (str[i]) {
        if (isspace(str[i])) {
            tokens[k++] = strndup(str+j, i-j);
            j = i+1;
        }
        i++;
    }
    tokens[k++] = strndup(str+j, i-j);
    tokens[k] = NULL;
}

// Function to calculate the frequency of each word in the input text
void calculate_word_frequency(char* text, int* frequencies) {
    char* tokens[MAX_STRING_LENGTH];
    int num_tokens = 0;
    tokenize(text, tokens);
    for (int i = 0; i < MAX_STRING_LENGTH && tokens[i]!= NULL; i++) {
        frequencies[strcspn(tokens[i], ".,?!")] += 1;
        num_tokens++;
    }
}

// Function to classify the input text as spam or not spam
char classify_text(int* frequencies) {
    int num_spam_words = 0;
    for (int i = 0; i < MAX_STRING_LENGTH; i++) {
        if (frequencies[i] > 0) {
            num_spam_words += frequencies[i];
        }
    }
    return num_spam_words > (MAX_STRING_LENGTH / 2)?'s' : 'n';
}

// Main function to read input text, classify it, and print the result
int main() {
    char input_text[MAX_STRING_LENGTH];
    printf("Enter input text: ");
    fgets(input_text, MAX_STRING_LENGTH, stdin);
    input_text[strcspn(input_text, "\n")] = '\0';

    int frequencies[MAX_STRING_LENGTH] = {0};
    calculate_word_frequency(input_text, frequencies);

    char result = classify_text(frequencies);
    printf("Result: %c\n", result);

    return 0;
}