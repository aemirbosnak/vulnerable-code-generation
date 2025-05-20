//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: synchronous
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 10 // maximum number of words in the sentence
#define WORD_LENGTH 10 // maximum length of each word in the sentence

// function to randomly generate a sentence
char** generate_sentence(int sentence_length) {
    char** sentence = malloc(sizeof(char*) * sentence_length);
    char words[10][WORD_LENGTH] = {"the", "quick", "brown", "fox", "jumps", "over", "the", "lazy", "dog", "."};
    for(int i=0; i<sentence_length; i++) {
        sentence[i] = malloc(sizeof(char) * WORD_LENGTH);
        strcpy(sentence[i], words[rand() % 10]);
    }
    return sentence;
}

// function to print the sentence
void print_sentence(char** sentence, int sentence_length) {
    for(int i=0; i<sentence_length; i++)
        printf("%s ", sentence[i]);
    printf("\n");
}

// function to calculate the typing speed
void calculate_speed(int seconds, int count) {
    float speed = (float) count / ((float) seconds / 60);
    printf("\nYour typing speed is %.2f words per minute.\n", speed);
}

int main() {
    int sentence_length = rand() % MAX_WORDS + 1;
    char** sentence = generate_sentence(sentence_length);
    print_sentence(sentence, sentence_length);

    printf("\nType the above sentence and press enter when done.\n");
    fflush(stdout);
    char input[WORD_LENGTH * MAX_WORDS + 1];
    fgets(input, WORD_LENGTH * MAX_WORDS + 1, stdin);

    int len = strlen(input);
    if(input[len-1] == '\n')
        input[len-1] = '\0';
    char** input_sentence = malloc(sizeof(char*) * sentence_length);
    char* token = strtok(input, " ");
    int count=0;
    while(token != NULL) {
        input_sentence[count] = token;
        count++;
        token = strtok(NULL, " ");
    }

    int errors = 0;
    for(int i=0; i<sentence_length; i++) {
        if(strcmp(sentence[i], input_sentence[i]) != 0)
            errors++;
    }

    if(errors == 0)
        printf("Well done! You typed the sentence correctly.\n");
    else
        printf("You made %d errors. Keep practicing.\n", errors);

    clock_t start = clock();
    while((clock() - start) / CLOCKS_PER_SEC < 60) {
        fflush(stdout);
        fgets(input, WORD_LENGTH * MAX_WORDS + 1, stdin);
        len = strlen(input);
        if(input[len-1] == '\n')
            input[len-1] = '\0';
        token = strtok(input, " ");
        while(token != NULL) {
            input_sentence[count] = token;
            count++;
            token = strtok(NULL, " ");
        }
    }

    calculate_speed(60, count);
    return 0;
}