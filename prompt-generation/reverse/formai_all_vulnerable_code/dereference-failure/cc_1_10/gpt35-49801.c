//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_WORD_LEN 20
#define MAX_TIME 30
#define BUFFER_SIZE 100

// Function to generate random words
char* generateRandomWord(int len){
    char *word = malloc(len * sizeof(char));
    static const char alphabet[] =
        "abcdefghijklmnopqrstuvwxyz"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        
    for (int i = 0; i < len; i++) {
        word[i] = alphabet[rand() % (sizeof(alphabet) - 1)];
    }
    word[len] = '\0';
    return word;
}

// Function to calculate typing speed
void calculateSpeed(double time_taken, int total_words, char typed_text[]){
    int typed_words = 0;
    char* token = strtok(typed_text, " ");
    while(token != NULL){
        typed_words++;
        token = strtok(NULL, " ");
    }
    double speed = ((double) typed_words / time_taken) * 60;
    printf("\nTyping speed: %.2lf words/min\n", speed);
}

int main(){
    printf("Welcome to Typing Speed Test\n");

    srand(time(NULL));
    char random_word[MAX_WORD_LEN];
    char typed_text[BUFFER_SIZE] = {'\0'};
    double time_taken;
    
    printf("You have %d seconds to type as many words as you can\n", MAX_TIME);
    time_t start_time = time(0);
    while(difftime(time(0), start_time) < MAX_TIME){
        strcpy(random_word, generateRandomWord(rand() % MAX_WORD_LEN + 1));
        printf("%s ", random_word);
        scanf("%s", typed_text + strlen(typed_text));
        strcat(typed_text, " ");
    }
    time_t end_time = time(0);

    time_taken = difftime(end_time, start_time);

    printf("\n\nYou typed: %s\n", typed_text);
    printf("Time taken: %.2lf seconds\n", time_taken);

    calculateSpeed(time_taken, MAX_TIME, typed_text);

    return 0;
}