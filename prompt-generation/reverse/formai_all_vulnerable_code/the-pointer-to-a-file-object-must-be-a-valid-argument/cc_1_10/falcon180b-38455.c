//Falcon-180B DATASET v1.0 Category: Terminal Based Game ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100
#define MAX_WORD_LEN 20

char words[MAX_WORDS][MAX_WORD_LEN];
int num_words;

void load_words() {
    FILE *fp = fopen("words.txt", "r");
    char line[MAX_WORD_LEN];
    char *word;
    int i = 0;

    while (fgets(line, sizeof(line), fp)) {
        word = strtok(line, " ");
        while (word!= NULL) {
            strcpy(words[i], word);
            i++;
            word = strtok(NULL, " ");
        }
    }

    num_words = i;
    fclose(fp);
}

void print_word(int index) {
    int len = strlen(words[index]);
    for (int i = 0; i < len; i++) {
        printf("_");
    }
}

int main() {
    srand(time(NULL));

    load_words();

    int lives = 5;
    int score = 0;
    int word_index = rand() % num_words;
    char guess[MAX_WORD_LEN];

    while (lives > 0 && strcmp(guess, words[word_index])!= 0) {
        printf("\nLives: %d\n", lives);
        printf("Score: %d\n", score);
        printf("Guessed letters: ");
        for (int i = 0; i < strlen(guess); i++) {
            if (isalpha(guess[i])) {
                printf("%c ", toupper(guess[i]));
            }
        }
        printf("\n");

        print_word(word_index);

        char c;
        while ((c = getchar())!= '\n') {
            if (isalpha(c)) {
                guess[strlen(guess)] = toupper(c);
                guess[strlen(guess)] = '\0';
            }
        }

        if (strcmp(guess, words[word_index]) == 0) {
            printf("\nCongratulations, you guessed the word: %s\n", words[word_index]);
            lives++;
            score += 10;
            word_index = rand() % num_words;
        } else {
            lives--;
        }
    }

    printf("\nGame over. The word was: %s\n", words[word_index]);

    return 0;
}