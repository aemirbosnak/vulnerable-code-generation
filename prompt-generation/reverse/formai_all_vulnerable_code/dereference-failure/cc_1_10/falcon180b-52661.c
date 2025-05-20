//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_WORDS 10000
#define MIN_WORD_LEN 3
#define MAX_WORD_LEN 30

// Function to tokenize the input string
void tokenize(char *input, char **tokens) {
    int i = 0, j = 0, k = 0;
    while (input[i]) {
        if (isalnum(input[i])) {
            tokens[k++] = &input[i];
            while (isalnum(input[i]))
                i++;
        }
        else
            i++;
    }
    tokens[k] = NULL;
}

// Function to calculate the frequency of each word
void calculate_frequency(char **tokens, int num_tokens, int *frequency) {
    for (int i = 0; i < num_tokens; i++) {
        for (int j = 0; j < i; j++) {
            if (strcmp(tokens[i], tokens[j]) == 0) {
                frequency[i] += frequency[j];
                break;
            }
        }
    }
}

// Function to calculate the probability of a word being spam
double calculate_probability(int *frequency, int num_tokens) {
    double sum = 0.0;
    for (int i = 0; i < num_tokens; i++)
        sum += frequency[i];
    return (double)frequency[num_tokens - 1] / sum;
}

// Function to classify the input string as spam or not spam
char classify(double probability) {
    if (probability >= 0.5)
        return 'S';
    else
        return 'N';
}

int main() {
    char input[10000];
    char *tokens[MAX_WORDS];
    int frequency[MAX_WORDS];
    int num_tokens = 0;
    double probability;

    // Read input string from user
    printf("Enter the input string: ");
    scanf("%s", input);

    // Tokenize the input string
    tokenize(input, tokens);
    num_tokens = strlen(tokens[0]);

    // Calculate the frequency of each word
    calculate_frequency(tokens, num_tokens, frequency);

    // Calculate the probability of the input string being spam
    probability = calculate_probability(frequency, num_tokens);

    // Classify the input string as spam or not spam
    char result = classify(probability);

    // Print the result
    printf("The input string is %c\n", result);

    return 0;
}