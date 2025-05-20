//MISTRAL-7B DATASET v1.0 Category: Typing Speed Test ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WORD_LENGTH 40
#define NUM_WORDS 20

char *words[NUM_WORDS];

void setup() {
    int i;
    FILE *fp;

    fp = fopen("words.txt", "r");

    for(i = 0; i < NUM_WORDS; i++) {
        words[i] = (char *)calloc(WORD_LENGTH, sizeof(char));
        fgets(words[i], WORD_LENGTH, fp);
        words[i][strlen(words[i]) - 1] = '\0';
    }

    fclose(fp);
}

void print_words(char **words, int num_words) {
    int i;

    for(i = 0; i < num_words; i++) {
        printf("%s ", words[i]);
    }

    printf("\n");
}

int main() {
    int i, j, k;
    int num_correct = 0;
    int num_total = 0;
    char user_input[WORD_LENGTH];
    char *target_word = NULL;

    setup();

    clock_t start = clock();

    for(i = 0; i < NUM_WORDS; i++) {
        target_word = words[i];

        printf("\nType the following word as fast as you can: %s", target_word);
        scanf("%s", user_input);

        if(strcmp(target_word, user_input) == 0) {
            num_correct++;
        }

        num_total++;
    }

    clock_t end = clock();
    double elapsed_secs = (double)(end - start) / CLOCKS_PER_SEC;

    printf("\nYou typed %d words correctly out of %d in %.2f seconds.\n", num_correct, num_total, elapsed_secs);

    for(i = 0; i < NUM_WORDS; i++) {
        free(words[i]);
    }

    return 0;
}