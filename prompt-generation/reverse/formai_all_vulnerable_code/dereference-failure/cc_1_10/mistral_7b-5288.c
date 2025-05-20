//MISTRAL-7B DATASET v1.0 Category: Typing Speed Test ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_WORDS 100
#define WORD_LENGTH 30
#define LINE_LENGTH 80
#define WORDS_PER_LINE 5

typedef struct Word {
    char *word;
    int length;
} Word;

Word *words;
int num_words = 0;

void generate_words() {
    FILE *file = fopen("dictionary.txt", "r");

    if (file == NULL) {
        printf("Error: Could not open dictionary file.\n");
        exit(1);
    }

    char line[LINE_LENGTH];
    char *token;

    while (fgets(line, sizeof(line), file)) {
        token = strtok(line, " \t\n");

        if (num_words >= MAX_WORDS) {
            printf("Warning: Maximum number of words reached.\n");
            break;
        }

        words[num_words].length = strlen(token);
        words[num_words].word = malloc(words[num_words].length + 1);
        strcpy(words[num_words].word, token);

        num_words++;
    }

    fclose(file);
}

void print_line() {
    int index = rand() % num_words;
    printf("%s", words[index].word);

    for (int i = 0; i < WORDS_PER_LINE - 1; i++) {
        index = rand() % num_words;
        printf(" %s", words[index].word);
    }

    printf("\n");
}

int main() {
    srand(time(NULL));

    words = malloc(MAX_WORDS * sizeof(Word));
    generate_words();

    clock_t start = clock();
    int correct_words = 0;

    while (1) {
        print_line();

        char user_input[WORD_LENGTH];
        fgets(user_input, sizeof(user_input), stdin);
        user_input[strlen(user_input) - 1] = '\0';

        int index = -1;
        for (int i = 0; i < num_words; i++) {
            if (strcmp(words[i].word, user_input) == 0) {
                index = i;
                break;
            }
        }

        if (index != -1) {
            correct_words++;
        }

        clock_t end = clock();
        double elapsed_time = (double)(end - start) / CLOCKS_PER_SEC;

        printf("Time elapsed: %.2f seconds\n", elapsed_time);
        printf("Correct words: %d\n", correct_words);

        if (correct_words >= num_words / 2) {
            printf("Congratulations! You passed the test.\n");
            break;
        }
    }

    for (int i = 0; i < num_words; i++) {
        free(words[i].word);
    }
    free(words);

    return 0;
}