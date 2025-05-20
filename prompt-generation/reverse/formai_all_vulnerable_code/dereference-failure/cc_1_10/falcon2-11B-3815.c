//Falcon2-11B DATASET v1.0 Category: Online Examination System ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    char* question;
    char* optionA;
    char* optionB;
    char* optionC;
    char* optionD;
    char* correctOption;
} Question;

typedef struct {
    Question* questions;
    int numQuestions;
} Exam;

void addQuestion(Exam* exam, Question question) {
    if (exam->numQuestions == 0) {
        exam->questions = malloc(sizeof(Question));
        *exam->questions = question;
    } else {
        exam->questions = realloc(exam->questions, (exam->numQuestions + 1) * sizeof(Question));
        *(exam->questions + exam->numQuestions) = question;
    }
    exam->numQuestions++;
}

void printQuestions(Exam* exam) {
    for (int i = 0; i < exam->numQuestions; i++) {
        printf("%d. %s\n", i+1, exam->questions[i].question);
    }
}

int main() {
    srand(time(NULL));
    Exam exam;
    Question question;
    exam.numQuestions = 0;

    question.question = "What is the capital of France?";
    question.optionA = "London";
    question.optionB = "Berlin";
    question.optionC = "Madrid";
    question.optionD = "Paris";
    question.correctOption = "Paris";
    addQuestion(&exam, question);

    question.question = "What is the largest planet in our solar system?";
    question.optionA = "Mercury";
    question.optionB = "Venus";
    question.optionC = "Earth";
    question.optionD = "Jupiter";
    question.correctOption = "Jupiter";
    addQuestion(&exam, question);

    question.question = "What is the chemical formula for water?";
    question.optionA = "H2O";
    question.optionB = "H2S";
    question.optionC = "CO2";
    question.optionD = "O2";
    question.correctOption = "H2O";
    addQuestion(&exam, question);

    printQuestions(&exam);

    int numCorrect = 0;
    int numWrong = 0;
    int numSkipped = 0;
    int numQuestions = 0;
    while (numQuestions < exam.numQuestions) {
        Question question = exam.questions[numQuestions];
        printf("%s. %s\n", numQuestions+1, question.question);
        printf("A. %s\n", question.optionA);
        printf("B. %s\n", question.optionB);
        printf("C. %s\n", question.optionC);
        printf("D. %s\n", question.optionD);
        int choice;
        printf("Enter your choice (1-%d): ", question.correctOption);
        scanf("%d", &choice);
        if (choice == question.correctOption) {
            numCorrect++;
        } else {
            numWrong++;
        }
        numQuestions++;
        if (choice == 0 || choice == -1) {
            numSkipped++;
        }
    }
    printf("\n");
    printf("Examination Results:\n");
    printf("Correct Answers: %d\n", numCorrect);
    printf("Wrong Answers: %d\n", numWrong);
    printf("Skipped Questions: %d\n", numSkipped);
    printf("Total Questions: %d\n", exam.numQuestions);
    return 0;
}