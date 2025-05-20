//MISTRAL-7B DATASET v1.0 Category: Typing Speed Test ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN_WORD_LENGTH 3
#define MAX_WORD_LENGTH 20
#define MIN_SENTENCE_LENGTH 10
#define MAX_SENTENCE_LENGTH 100

// Function to generate a random word of given length
char *generateRandomWord(int length) {
    char *word = malloc(length + 1);
    for (int i = 0; i < length; i++) {
        word[i] = 'a' + rand() % 26;
    }
    word[length] = '\0';
    return word;
}

// Function to generate a random sentence of given length
char *generateRandomSentence(int length) {
    char *sentence = malloc(length + 1);
    for (int i = 0; i < length / 2; i++) {
        int wordLength = rand() % (MAX_WORD_LENGTH - MIN_WORD_LENGTH + 1) + MIN_WORD_LENGTH;
        char *word = generateRandomWord(wordLength);
        strcat(sentence, word);
        strcat(sentence, " ");
        free(word);
    }
    sentence[length] = '\0';
    return sentence;
}

int main() {
    srand(time(NULL));

    clock_t start, end;
    double elapsed_time;

    printf("Welcome to the C Typing Speed Test!\n");
    printf("Get ready to type the following sentence as fast as you can:\n");

    int sentenceLength = rand() % (MAX_SENTENCE_LENGTH - MIN_SENTENCE_LENGTH + 1) + MIN_SENTENCE_LENGTH;
    char *testSentence = generateRandomSentence(sentenceLength);

    printf("%s\n", testSentence);

    start = clock();

    fgets(stdin, 1024, stdin);

    end = clock();

    free(testSentence);

    elapsed_time = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Your typing speed is %.2f words per minute.\n", 60 * sentenceLength / elapsed_time);

    return 0;
}