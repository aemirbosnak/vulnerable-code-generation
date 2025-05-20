//LLAMA2-13B DATASET v1.0 Category: Game ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAX_INPUT 1024
#define MAX_SENTENCE 512

// Structure to store information about a sentence
typedef struct {
    char *word;
    int frequency;
} Sentence;

// Function to calculate the frequency of each word in a sentence
void calculate_frequency(Sentence *sentences, int num_sentences) {
    for (int i = 0; i < num_sentences; i++) {
        for (char *word = sentences[i].word; *word != '\0'; word++) {
            if (word[0] == 'a' || word[0] == 'e' || word[0] == 'i' || word[0] == 'o' || word[0] == 'u') {
                sentences[i].frequency++;
            }
        }
    }
}

// Function to print the most common word in a sentence
void print_most_common_word(Sentence *sentences, int num_sentences) {
    Sentence most_common;
    int max_frequency = 0;
    char *most_common_word = NULL;

    for (int i = 0; i < num_sentences; i++) {
        if (sentences[i].frequency > max_frequency) {
            max_frequency = sentences[i].frequency;
            most_common_word = sentences[i].word;
        }
    }

    printf("The most common word in the sentences is: %s\n", most_common_word);
}

// Function to generate random sentences
void generate_sentences(Sentence *sentences, int num_sentences) {
    for (int i = 0; i < num_sentences; i++) {
        sentences[i].word = (char *)malloc(MAX_SENTENCE * sizeof(char));
        for (int j = 0; j < MAX_SENTENCE; j++) {
            sentences[i].word[j] = 'a' + (rand() % 26);
        }
        sentences[i].frequency = 0;
    }
}

int main() {
    Sentence sentences[10];
    int num_sentences = 10;

    // Generate random sentences
    generate_sentences(sentences, num_sentences);

    // Calculate the frequency of each word in each sentence
    calculate_frequency(sentences, num_sentences);

    // Print the most common word in each sentence
    for (int i = 0; i < num_sentences; i++) {
        print_most_common_word(sentences, i);
    }

    return 0;
}