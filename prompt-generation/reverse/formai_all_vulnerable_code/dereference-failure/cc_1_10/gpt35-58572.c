//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: expert-level
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// function to generate random sentence
char* generate_sentence(int num_words) {
    // array of sentences to randomly choose from
    char *sentences[] = {"The quick brown fox jumps over the lazy dog",
                         "She sells seashells by the seashore",
                         "Peter Piper picked a peck of pickled peppers",
                         "The rain in Spain stays mainly in the plain",
                         "How much wood would a woodchuck chuck if a woodchuck could chuck wood"};
    int num_sentences = 5;
    char* sentence = malloc(sizeof(char) * 100);
    // randomly choose sentence from array
    int sentence_idx = rand() % num_sentences;
    strcpy(sentence, sentences[sentence_idx]);
    // add random words to make sentence longer
    int words_left = num_words - num_sentences;
    for (int i = 0; i < words_left; i++) {
        char new_word[10];
        // randomly generate word
        for (int j = 0; j < 9; j++) {
            new_word[j] = rand() % 26 + 'a';
        }
        new_word[9] = '\0';
        // add random word to sentence
        strcat(sentence, " ");
        strcat(sentence, new_word);
    }
    return sentence;
}

int main() {
    // set up random seed
    srand(time(0));
    // generate random sentence
    char *sentence = generate_sentence(50);
    printf("Type the following sentence:\n%s\n\n", sentence);
    // get start time
    clock_t start = clock();
    // read user input
    char input[100];
    fgets(input, 100, stdin);
    // replace newline character with null character
    int len = strlen(input);
    if (len > 0 && input[len - 1] == '\n') {
        input[len - 1] = '\0';
    }
    // calculate time taken
    clock_t end = clock();
    double time_taken = (double) (end - start) / CLOCKS_PER_SEC;
    // calculate typing speed
    int num_chars = strlen(sentence);
    int num_mistakes = 0;
    int i = 0;
    while (input[i] != '\0') {
        if (input[i] != sentence[i]) {
            num_mistakes++;
        }
        i++;
    }
    int num_correct = num_chars - num_mistakes;
    int typing_speed = (int) (((double) num_correct / time_taken) * 60);
    // display results
    printf("\nYou typed: %s\n", input);
    printf("Total time taken: %.2f seconds\n", time_taken);
    printf("Typing speed: %d characters per minute\n", typing_speed);
    return 0;
}