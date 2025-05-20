//LLAMA2-13B DATASET v1.0 Category: Game ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_WORD_LENGTH 20
#define MAX_SENTENCE_LENGTH 50

// Function to generate a random word
char *generate_word(void) {
    char word[MAX_WORD_LENGTH];
    srand(time(NULL));
    int i;

    for (i = 0; i < MAX_WORD_LENGTH; i++) {
        word[i] = 'a' + (rand() % 26);
    }

    return word;
}

// Function to generate a random sentence
char *generate_sentence(int num_words) {
    char sentence[MAX_SENTENCE_LENGTH];
    int i;

    for (i = 0; i < num_words; i++) {
        sentence[i] = generate_word();
    }

    sentence[i] = '\0';
    return sentence;
}

int main(void) {
    char *sentence = generate_sentence(5);
    printf("The sentence is: %s\n", sentence);

    // Let's play a game with the sentence!
    char guess[MAX_WORD_LENGTH];
    int correct = 0;

    printf("Guess a word in the sentence: ");
    scanf("%s", guess);

    int i;
    for (i = 0; i < strlen(sentence); i++) {
        if (guess[0] == sentence[i]) {
            correct++;
        }
    }

    printf("You guessed %d words correctly\n", correct);

    free(sentence);
    return 0;
}