//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define MAX_STRING_LENGTH 50
#define NUM_WORDS 10

char** generate_words();

int main() {
    char** words = generate_words();
    time_t start_time, end_time;
    char input_str[MAX_STRING_LENGTH];
    int num_correct = 0;
  
    printf("\nWELCOME TO THE TYPING SPEED TEST\n\n");
    printf("You will be given a series of words to type.\n");
    printf("Type each word and hit enter to proceed to next.\n");
    printf("Your score will be based on the number of correctly typed words.\n\n");
    printf("Press enter to start the test:");
  
    getchar();
    system("clear");
    start_time = time(NULL);
    for (int i = 0; i < NUM_WORDS; i++) {
        printf("%s ", words[i]);
        fgets(input_str, MAX_STRING_LENGTH, stdin);
        input_str[strcspn(input_str, "\n")] = 0;  // remove newline char from input
        if (strcmp(words[i], input_str) == 0) {
            num_correct++;
        }
        system("clear");
    }
    end_time = time(NULL);

    printf("Congratulations on completing the test!\n");
    printf("You typed %d words correctly out of %d\n", num_correct, NUM_WORDS);
    printf("It took you %ld seconds to complete the test\n", (end_time - start_time));
    printf("Your typing speed is %.2f words per minute\n\n", ((float)num_correct / (end_time - start_time)) * 60);
  
    for (int i = 0; i < NUM_WORDS; i++) {
        free(words[i]);
    }
    free(words);

    return 0;
}

char** generate_words() {
    char** words = (char**)malloc(sizeof(char*) * NUM_WORDS);
    char alphabet[] = "abcdefghijklmnopqrstuvwxyz";
    srand(time(NULL));

    for (int i = 0; i < NUM_WORDS; i++) {
        int word_len = rand() % 6 + 5;  // generate random length for the word between 5 and 10
        words[i] = (char*)malloc(sizeof(char) * (word_len + 1));
        for (int j = 0; j < word_len; j++) {
            words[i][j] = alphabet[rand() % 26];
        }
        words[i][word_len] = '\0';
    }

    return words;
}