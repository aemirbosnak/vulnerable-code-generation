//Falcon-180B DATASET v1.0 Category: Periodic Table Quiz ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num_questions = 10;
    int num_choices = 4;
    char *choices[4];
    char *answers[10];
    int i, j, k, correct = 0;
    int rand_num;
    srand(time(NULL));

    // Fill in the arrays
    for (i = 0; i < num_questions; i++) {
        rand_num = rand() % 118;
        answers[i] = malloc(20);
        sprintf(answers[i], "%s (%d)", "Element", rand_num + 1);
        for (j = 0; j < num_choices; j++) {
            rand_num = rand() % 118;
            choices[j] = malloc(20);
            sprintf(choices[j], "%s (%d)", "Element", rand_num + 1);
        }
    }

    // Print the quiz
    printf("Periodic Table Quiz\n");
    for (i = 0; i < num_questions; i++) {
        printf("%s\n", answers[i]);
        for (j = 0; j < num_choices; j++) {
            printf("%d. %s\n", j + 1, choices[j]);
        }
        printf("Enter your answer (1-%d): ", num_choices);
        scanf("%d", &k);
        if (k == rand_num + 1) {
            correct++;
        }
    }

    // Print the results
    printf("\nYou got %d out of %d correct.\n", correct, num_questions);
    for (i = 0; i < num_questions; i++) {
        printf("%s - Correct answer: %d\n", answers[i], rand_num + 1);
    }

    for (i = 0; i < num_choices; i++) {
        free(choices[i]);
    }
    for (i = 0; i < num_questions; i++) {
        free(answers[i]);
    }

    return 0;
}