//Falcon2-11B DATASET v1.0 Category: Periodic Table Quiz ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num_elements = 101;
    int num_questions = 10;
    int *questions = (int*) malloc(num_questions * sizeof(int));
    int *answers = (int*) malloc(num_questions * sizeof(int));

    srand(time(0));

    for (int i = 0; i < num_questions; i++) {
        int element = rand() % num_elements;
        int question = rand() % 4 + 1;

        questions[i] = element;
        answers[i] = question;
    }

    int score = 0;
    int num_correct = 0;

    printf("Periodic Table Quiz\n\n");
    for (int i = 0; i < num_questions; i++) {
        int element = questions[i];
        int question = answers[i];

        printf("Element %d has %d %s\n", element, question, question == 1? "proton" :
                                                               question == 2? "neutron" :
                                                               question == 3? "electron" : "atomic mass unit");

        int correct = 0;
        printf("Answer: ");
        scanf("%d", &correct);

        if (correct == question) {
            score++;
            num_correct++;
        }
    }

    printf("\nYou scored %d/%d (%.2f%%)\n", score, num_questions, ((double)score / (double)num_questions) * 100.0);
    printf("\n\n");

    free(questions);
    free(answers);

    return 0;
}