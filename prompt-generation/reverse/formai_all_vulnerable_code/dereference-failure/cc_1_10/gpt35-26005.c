//FormAI DATASET v1.0 Category: Online Examination System ; Style: calm
#include <stdio.h>
#include <stdlib.h> 
#include <string.h>

// Structure to store question and answer choices
struct question {
    char question_text[500];
    char answer_a[100];
    char answer_b[100];
    char answer_c[100];
    char answer_d[100];
    char correct_answer[10];
};

// Function to read the questions and store them into an array of structures
void read_questions(struct question *q, int num_questions) {
    for(int i=0; i<num_questions; i++) {
        printf("Enter Question %d: ", i+1);
        fgets(q[i].question_text, 500, stdin);
        printf("Enter Answer Choice A: ");
        fgets(q[i].answer_a, 100, stdin);
        printf("Enter Answer Choice B: ");
        fgets(q[i].answer_b, 100, stdin);
        printf("Enter Answer Choice C: ");
        fgets(q[i].answer_c, 100, stdin);
        printf("Enter Answer Choice D: ");
        fgets(q[i].answer_d, 100, stdin);
        printf("Enter Correct Answer (A, B, C, or D): ");
        fgets(q[i].correct_answer, 10, stdin);
    }
}

// Function to take the exam and grade the answers
void take_exam(struct question *q, int num_questions) {
    int correct_answers = 0;

    printf("\n\nStart the exam!\n");

    for (int i=0; i<num_questions; i++) {
        printf("\nQuestion %d: %s", i+1, q[i].question_text);
        printf("A) %s", q[i].answer_a);
        printf("B) %s", q[i].answer_b);
        printf("C) %s", q[i].answer_c);
        printf("D) %s", q[i].answer_d);

        char answer[10];
        printf("Enter Your Answer: ");
        fgets(answer, 10, stdin);

        if (strcmp(answer, q[i].correct_answer) == 0) {
            printf("Correct!\n");
            correct_answers++;
        } else {
            printf("Incorrect!\n");
        }
    }

    printf("\n\nExam Finished!\n");
    printf("Total Correct Answers: %d\n", correct_answers);
    printf("Total Incorrect Answers: %d\n", num_questions - correct_answers);
}

int main() {
    int num_questions;
    printf("Enter the number of questions: ");
    scanf("%d", &num_questions);
    getchar(); // to consume input buffer

    // allocate memory for array of structs
    struct question *questions = (struct question*) malloc(sizeof(struct question) * num_questions);

    // read the questions
    read_questions(questions, num_questions);

    // take the exam
    take_exam(questions, num_questions);

    // Release the memory when done.
    free(questions);
    questions = NULL;

    return 0;
}