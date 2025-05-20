//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>

#define MAX_WORDS 5000
#define MIN_WORD_LEN 3
#define MAX_WORD_LEN 15
#define THRESHOLD 0.5

// Function to tokenize a string into words
void tokenize(char* str, char** tokens) {
    int i = 0;
    char* token;
    char* word = strtok(str, ",.?!;:");
    while (word!= NULL) {
        if (strlen(word) >= MIN_WORD_LEN && strlen(word) <= MAX_WORD_LEN) {
            tokens[i] = word;
            i++;
        }
        word = strtok(NULL, ",.?!;:");
    }
}

// Function to calculate the frequency of each word in a message
void calculate_frequency(char** tokens, int num_tokens, int* freq) {
    for (int i = 0; i < num_tokens; i++) {
        freq[i] = 0;
    }
    for (int i = 0; i < num_tokens; i++) {
        for (int j = i + 1; j < num_tokens; j++) {
            if (strcmp(tokens[i], tokens[j]) == 0) {
                freq[i]++;
            }
        }
    }
}

// Function to calculate the probability of a message being spam
double calculate_probability(int* freq, int num_tokens) {
    double prob = 1.0;
    for (int i = 0; i < num_tokens; i++) {
        if (freq[i] > 0) {
            prob *= freq[i] * (freq[i] - 1);
        }
    }
    return prob;
}

// Function to classify a message as spam or not spam
char classify_message(double prob) {
    if (prob > THRESHOLD) {
        return's';
    } else {
        return 'n';
    }
}

// Function to read messages from a file
void read_messages(char* filename, char** messages, int* num_messages) {
    FILE* file = fopen(filename, "r");
    char line[1000];
    int i = 0;
    while (fgets(line, sizeof(line), file)!= NULL) {
        messages[i] = strdup(line);
        i++;
    }
    fclose(file);
    *num_messages = i;
}

// Function to write results to a file
void write_results(char* filename, char* results, int num_results) {
    FILE* file = fopen(filename, "w");
    for (int i = 0; i < num_results; i++) {
        fprintf(file, "%c\n", results[i]);
    }
    fclose(file);
}

// Main function
int main() {
    char* messages[MAX_WORDS];
    int num_messages;
    read_messages("messages.txt", messages, &num_messages);
    int num_tokens;
    char** tokens;
    for (int i = 0; i < num_messages; i++) {
        tokenize(messages[i], &tokens);
        num_tokens = strlen(messages[i]) / 3;
        int freq[MAX_WORDS];
        calculate_frequency(tokens, num_tokens, freq);
        double prob = calculate_probability(freq, num_tokens);
        char result = classify_message(prob);
        printf("%c\n", result);
    }
    return 0;
}