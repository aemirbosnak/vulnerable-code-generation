//LLAMA2-13B DATASET v1.0 Category: Spell checking ; Style: scientific
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LENGTH 50
#define MIN_SCORE 0
#define MAX_SCORE 100

struct word {
    char *text;
    int score;
};

struct dictionary {
    struct word *words;
    int count;
};

// Function to check if a word is in the dictionary
int check_dictionary(struct dictionary *dict, char *word) {
    int i;
    for (i = 0; i < dict->count; i++) {
        if (strcmp(word, dict->words[i].text) == 0) {
            return 1;
        }
    }
    return 0;
}

// Function to calculate the score of a word
int calculate_score(struct word *word) {
    int score = 0;
    int i;
    for (i = 0; i < strlen(word->text); i++) {
        score += (word->text[i] - 'a') * (word->text[i] - 'a') + 1;
    }
    return score;
}

// Function to print the spell check report
void print_report(struct dictionary *dict, struct word *word) {
    int score = calculate_score(word);
    printf("Word: %s\n", word->text);
    printf("Score: %d (%.2f%%)\n", score, (float)score / 100);
}

int main() {
    struct dictionary dict;
    struct word word;

    // Initialize the dictionary with 10 words
    dict.words = (struct word *)malloc(10 * sizeof(struct word));
    dict.count = 10;
    for (int i = 0; i < 10; i++) {
        word.text = (char *)malloc(20 * sizeof(char));
        sprintf(word.text, "word%d", i);
        dict.words[i] = word;
    }

    // Read the input text from the user
    char text[MAX_LENGTH];
    printf("Enter a sentence: ");
    fgets(text, MAX_LENGTH, stdin);

    // Tokenize the input text into individual words
    char *token = strtok(text, " ");
    int i = 0;
    while (token != NULL) {
        word.text = token;
        word.score = calculate_score(&word);
        print_report(&dict, &word);
        token = strtok(NULL, " ");
        i++;
    }

    // Free the memory allocated for the dictionary
    free(dict.words);

    return 0;
}