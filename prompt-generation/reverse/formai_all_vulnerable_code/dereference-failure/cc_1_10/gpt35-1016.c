//FormAI DATASET v1.0 Category: Online Examination System ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct Question {
    char content[100];
    char optionA[50];
    char optionB[50];
    char optionC[50];
    char optionD[50];
    char answer;
};

struct Exam {
    char title[50];
    int num_questions;
    struct Question *questions;
};

void display_menu();
void add_question(struct Exam *exam);
void take_exam(struct Exam *exam);

int main() {
    struct Exam exam;
    exam.num_questions = 0;
    exam.questions = NULL;
    
    int choice;
    do {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_question(&exam);
                break;
            case 2:
                if (exam.num_questions == 0) {
                    printf("Error: no questions added yet.\n");
                    break;
                }
                take_exam(&exam);
                break;
            case 3:
                printf("Goodbye!\n");
                break;
            default:
                printf("Error: invalid choice.\n");
                break;
        }
    } while (choice != 3);

    return 0;
}

void display_menu() {
    printf("\n");
    printf("1. Add a question to the exam\n");
    printf("2. Take the exam\n");
    printf("3. Quit\n");
}

void add_question(struct Exam *exam) {
    struct Question new_question;
    printf("Enter the question content: ");
    scanf(" %[^\n]", new_question.content);
    printf("Enter option A: ");
    scanf(" %[^\n]", new_question.optionA);
    printf("Enter option B: ");
    scanf(" %[^\n]", new_question.optionB);
    printf("Enter option C: ");
    scanf(" %[^\n]", new_question.optionC);
    printf("Enter option D: ");
    scanf(" %[^\n]", new_question.optionD);
    printf("Enter the answer (A, B, C, or D): ");
    scanf(" %c", &new_question.answer);

    exam->num_questions++;
    exam->questions = realloc(exam->questions, exam->num_questions * sizeof(struct Question));
    exam->questions[exam->num_questions - 1] = new_question;

    printf("Question added!\n");
}

void take_exam(struct Exam *exam) {
    int num_correct = 0;
    for (int i = 0; i < exam->num_questions; i++) {
        printf("\nQuestion %d: %s\n", i + 1, exam->questions[i].content);
        printf("A. %s\n", exam->questions[i].optionA);
        printf("B. %s\n", exam->questions[i].optionB);
        printf("C. %s\n", exam->questions[i].optionC);
        printf("D. %s\n", exam->questions[i].optionD);

        char answer;
        printf("Your answer: ");
        scanf(" %c", &answer);

        if (answer == exam->questions[i].answer) {
            num_correct++;
            printf("Correct!");
        } else {
            printf("Incorrect! The answer was %c.", exam->questions[i].answer);
        }
    }

    printf("\n\nResults: \n");
    printf("%d out of %d correct.\n", num_correct, exam->num_questions);
}