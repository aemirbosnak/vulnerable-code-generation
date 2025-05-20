//MISTRAL-7B DATASET v1.0 Category: Typing Speed Test ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define WORD_LENGTH 50
#define BUFFER_SIZE 1024

char *words[MAX_WORDS];
int num_words = 0;

void generate_words() {
    FILE *dictionary = fopen("dictionary.txt", "r");
    char buffer[BUFFER_SIZE];
    char *token = NULL;
    char *word = malloc(WORD_LENGTH * sizeof(char));

    while (fgets(buffer, BUFFER_SIZE, dictionary)) {
        token = strtok(buffer, " \n");
        int len = strlen(token);

        if (len > WORD_LENGTH) {
            continue;
        }

        strcpy(word, token);
        words[num_words] = word;
        num_words++;
    }

    fclose(dictionary);
    free(word);
}

int check_word(char *word) {
    for (int i = 0; i < num_words; i++) {
        if (strcasecmp(words[i], word) == 0) {
            return 1;
        }
    }

    return 0;
}

void print_word(char *word) {
    printf(">> %s <<\n", word);
}

void type_word(char *word) {
    char user_input[WORD_LENGTH];
    int attempts = 0;

    while (1) {
        printf("Type the word: ");
        scanf("%s", user_input);

        if (strlen(user_input) == strlen(word)) {
            for (int i = 0; i < strlen(word); i++) {
                if (tolower(user_input[i]) != tolower(word[i])) {
                    printf("Error! Try again.\n");
                    attempts++;
                    break;
                }
            }

            if (attempts == 0) {
                printf("Correct!\n");
                print_word(word);
                break;
            } else {
                attempts--;
            }
        } else {
            printf("Error! Word length is not correct.\n");
        }
    }
}

int main() {
    srand(time(NULL));
    generate_words();

    int game_over = 0;
    int score = 0;

    while (!game_over) {
        int random_index = rand() % num_words;
        char *random_word = words[random_index];

        type_word(random_word);
        printf("Your score: %d\n", score);

        int random_event = rand() % 3;

        switch (random_event) {
            case 0:
                printf("\aA raid! Press Enter to continue.\n");
                getchar();
                break;
            case 1:
                printf("You found supplies! Your score += 5.\n");
                score += 5;
                break;
            case 2:
                printf("A mutant horde appeared! Game Over.\n");
                game_over = 1;
                break;
        }
    }

    printf("Game Over. Final score: %d\n", score);

    for (int i = 0; i < num_words; i++) {
        free(words[i]);
    }

    free(words);

    return 0;
}