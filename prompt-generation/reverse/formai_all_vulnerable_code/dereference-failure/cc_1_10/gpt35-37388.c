//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* Function to generate random words */
char *generateWord(int len){
    char *str = malloc(len + 1);
    int i;
    for(i = 0; i < len; i++){
        str[i] = 'a' + (rand() % 26);
    }
    str[len] = '\0';
    return str;
}

/* Function to calculate typing speed */
int calculateSpeed(char *input, char *target, double elapsed_time){
    int score = 0;
    int i;
    for(i = 0; i < strlen(input); i++){
        if(input[i] == target[i]){
            score++;
        }
    }
    double accuracy = (double) score / strlen(input);
    int speed = (int) (strlen(input) / elapsed_time * 60);
    printf("Your typing speed is %d WPM with %.0f%% accuracy!\n", speed, accuracy * 100);
    return speed;
}

int main(){
    srand(time(NULL));
    int word_len = 10;
    int num_words = 3;
    char *words[num_words];
    int i;
    for(i = 0; i < num_words; i++){
        words[i] = generateWord(word_len);
    }
    printf("Type the following words as fast as you can!\n\n");
    for(i = 0; i < num_words; i++){
        printf("%s ", words[i]);
    }
    printf("\n\n");

    char input[100];
    time_t start_time = time(NULL);

    /* Get input from user */
    fgets(input, 100, stdin);

    time_t end_time = time(NULL);
    double elapsed_time = difftime(end_time, start_time);

    /* Remove newline character from input */
    input[strlen(input) - 1] = '\0';

    /* Concatenate all words */
    char target[100];
    strcpy(target, words[0]);
    for(i = 1; i < num_words; i++){
        strcat(target, " ");
        strcat(target, words[i]);
    }

    if(strcmp(input, target) != 0){
        printf("You typed: %s\n", input);
        printf("The correct words were: %s\n", target);
        printf("You made a mistake!\n");
    } else {
        calculateSpeed(input, target, elapsed_time);
    }

    /* Free dynamically allocated memory */
    for(i = 0; i < num_words; i++){
        free(words[i]);
    }

    return 0;
}