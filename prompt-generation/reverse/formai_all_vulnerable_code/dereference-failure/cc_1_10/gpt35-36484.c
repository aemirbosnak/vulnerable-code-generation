//FormAI DATASET v1.0 Category: Online Examination System ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct question {
    int id;
    char title[100];
    char choices[4][50];
    int correct_answer;
} Question;

int main() {
    int num_questions = 3;
    Question *questions = malloc(num_questions * sizeof(Question)); // Allocate memory for questions

    // Populate questions
    questions[0].id = 1;
    strcpy(questions[0].title, "What is the capital of France?");
    strcpy(questions[0].choices[0], "A. Paris");
    strcpy(questions[0].choices[1], "B. Rome");
    strcpy(questions[0].choices[2], "C. Madrid");
    strcpy(questions[0].choices[3], "D. Berlin");
    questions[0].correct_answer = 0;

    questions[1].id = 2;
    strcpy(questions[1].title, "What is the name of the currency used in Japan?");
    strcpy(questions[1].choices[0], "A. Yen");
    strcpy(questions[1].choices[1], "B. Euro");
    strcpy(questions[1].choices[2], "C. Pound");
    strcpy(questions[1].choices[3], "D. Dollar");
    questions[1].correct_answer = 0;

    questions[2].id = 3;
    strcpy(questions[2].title, "What is the name of the largest desert in the world?");
    strcpy(questions[2].choices[0], "A. Sahara");
    strcpy(questions[2].choices[1], "B. Gobi");
    strcpy(questions[2].choices[2], "C. Kalahari");
    strcpy(questions[2].choices[3], "D. Arabian");
    questions[2].correct_answer = 0;

    int score = 0;
    for (int i = 0; i < num_questions; i++) {
        printf("Question %d: %s\n", questions[i].id, questions[i].title);
        for (int j = 0; j < 4; j++) {
            printf("%s\n", questions[i].choices[j]);
        }
        int answer;
        printf("Enter your answer: ");
        scanf("%d", &answer);
        if (answer == questions[i].correct_answer) {
            printf("You are correct!\n");
            score++;
        } else {
            printf("Sorry, the correct answer is %s\n", questions[i].choices[questions[i].correct_answer]);
        }
    }

    printf("Your final score is %d out of %d\n", score, num_questions);

    free(questions); // Free memory

    return 0; 
}