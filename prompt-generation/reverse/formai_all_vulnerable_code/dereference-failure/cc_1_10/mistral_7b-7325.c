//MISTRAL-7B DATASET v1.0 Category: Typing Speed Test ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORDS 50
#define WORD_LENGTH 40

char *apocalypse_words[MAX_WORDS];

void generate_apocalypse_words() {
    FILE *fp;
    char filename[] = "apocalypse_words.txt";
    int i = 0;

    fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Error: Unable to open apocalypse_words.txt\n");
        exit(EXIT_FAILURE);
    }

    while (fgets(apocalypse_words[i], WORD_LENGTH, fp) != NULL) {
        apocalypse_words[i][strlen(apocalypse_words[i]) - 1] = '\0';
        i++;
    }

    fclose(fp);
}

void print_word(char *word) {
    printf("%s\n", word);
}

int main() {
    int i, score = 0;
    char guess[WORD_LENGTH];
    clock_t start, end;

    srand(time(NULL));
    generate_apocalypse_words();

    printf("\n\n*** POST-APOCALYPTIC TYPING SPEED TEST ***\n\n");

    for (i = 0; i < MAX_WORDS; i++) {
        start = clock();
        printf("Type the following word: ");
        print_word(apocalypse_words[i]);
        scanf("%s", guess);

        if (strcmp(guess, apocalypse_words[i]) == 0) {
            score++;
            printf("Correct!\n");
        } else {
            printf("Incorrect! The correct word was: %s\n", apocalypse_words[i]);
        }

        end = clock();
        double elapsed_time = (double)(end - start) / CLOCKS_PER_SEC;

        printf("Time taken to type the word: %.6f seconds\n", elapsed_time);
    }

    printf("\nYour final score is: %d\n", score);

    return 0;
}