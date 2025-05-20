//Falcon-180B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CONSPIRACIES 1000
#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

// Function prototypes
void generate_conspiracy(char* conspiracy);
void generate_random_word(char* word);
int main(void) {
    srand(time(NULL));
    int num_conspiracies;
    printf("Enter the number of conspiracies to generate: ");
    scanf("%d", &num_conspiracies);
    char conspiracies[num_conspiracies][MAX_CONSPIRACIES];
    for (int i = 0; i < num_conspiracies; i++) {
        generate_conspiracy(conspiracies[i]);
        printf("\n");
    }
    return 0;
}

// Generates a random conspiracy theory
void generate_conspiracy(char* conspiracy) {
    char noun1[MAX_WORD_LENGTH];
    char noun2[MAX_WORD_LENGTH];
    char verb[MAX_WORD_LENGTH];
    char adjective1[MAX_WORD_LENGTH];
    char adjective2[MAX_WORD_LENGTH];
    char preposition[MAX_WORD_LENGTH];
    char article1[MAX_WORD_LENGTH];
    char article2[MAX_WORD_LENGTH];

    generate_random_word(noun1);
    generate_random_word(noun2);
    generate_random_word(verb);
    generate_random_word(adjective1);
    generate_random_word(adjective2);
    generate_random_word(preposition);
    generate_random_word(article1);
    generate_random_word(article2);

    sprintf(conspiracy, "The %s %s is %s %s %s %s %s %s.", noun1, adjective1, verb, preposition, article2, noun2, adjective2, article1);
}

// Generates a random word
void generate_random_word(char* word) {
    const char* vowels = "aeiouAEIOU";
    const char* consonants = "bcdfghjklmnpqrstvwxyzBCDFGHJKLMNPQRSTVWXYZ";
    int word_length = rand() % MAX_WORD_LENGTH + 1;
    word[0] = rand() % 2? vowels[rand() % strlen(vowels)] : consonants[rand() % strlen(consonants)];
    for (int i = 1; i < word_length; i++) {
        word[i] = rand() % 2? vowels[rand() % strlen(vowels)] : consonants[rand() % strlen(consonants)];
    }
    word[word_length] = '\0';
}