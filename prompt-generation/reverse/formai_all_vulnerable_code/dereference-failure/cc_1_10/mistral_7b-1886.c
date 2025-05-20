//MISTRAL-7B DATASET v1.0 Category: Typing Speed Test ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PHRASE_LENGTH 100
#define NUM_PHRASES 10
#define MIN_WORD_LENGTH 3
#define MAX_WORD_LENGTH 15

char *medieval_phrases[NUM_PHRASES];

void generate_phrases() {
    FILE *file = fopen("medieval_phrases.txt", "r");
    char line[MAX_PHRASE_LENGTH];
    int i = 0;

    if (file == NULL) {
        printf("Error: Unable to open phrases file.\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), file)) {
        size_t length = strlen(line);
        if (length > MIN_WORD_LENGTH && length < MAX_WORD_LENGTH) {
            medieval_phrases[i] = malloc(length + 1);
            strcpy(medieval_phrases[i], line);
            i++;
        }
    }

    fclose(file);
}

int main() {
    srand(time(NULL));
    int i, j;
    int num_correct = 0;
    int num_total = 0;
    double wpm;

    generate_phrases();

    clock_t start = clock();

    for (i = 0; i < NUM_PHRASES; i++) {
        int random_index = rand() % NUM_PHRASES;
        printf("%s: ", medieval_phrases[random_index]);
        fflush(stdout);

        char user_input[MAX_WORD_LENGTH];
        scanf("%s", user_input);

        if (strcmp(medieval_phrases[random_index], user_input) == 0) {
            num_correct++;
        }
        num_total++;
    }

    clock_t end = clock();
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    wpm = (double)num_correct * 60 / time_spent;

    printf("\nYou typed %d phrases correctly out of %d in %fs. Your WPM is %.2f.\n", num_correct, num_total, time_spent, wpm);

    for (i = 0; i < NUM_PHRASES; i++) {
        free(medieval_phrases[i]);
    }

    return 0;
}