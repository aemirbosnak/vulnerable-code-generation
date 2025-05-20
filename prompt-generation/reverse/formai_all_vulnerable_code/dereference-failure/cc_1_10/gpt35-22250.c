//FormAI DATASET v1.0 Category: Online Examination System ; Style: inquisitive
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Question {
    int qno;
    char question[255];
    char op1[255];
    char op2[255];
    char op3[255];
    char op4[255];
    int correct;
};

struct User {
    char name[255];
    int score;
};

int read_int() {
    char line[255];
    fgets(line, sizeof(line), stdin);
    return atoi(line);
}

struct Question* read_questions(int num_questions) {
    struct Question* questions = malloc(num_questions * sizeof(struct Question));
    for (int i = 0; i < num_questions; i++) {
        printf("Enter question %d: ", i+1);
        fgets(questions[i].question, sizeof(questions[i].question), stdin);
        printf("Enter option 1: ");
        fgets(questions[i].op1, sizeof(questions[i].op1), stdin);
        printf("Enter option 2: ");
        fgets(questions[i].op2, sizeof(questions[i].op2), stdin);
        printf("Enter option 3: ");
        fgets(questions[i].op3, sizeof(questions[i].op3), stdin);
        printf("Enter option 4: ");
        fgets(questions[i].op4, sizeof(questions[i].op4), stdin);
        printf("Enter correct answer (1-4): ");
        questions[i].correct = read_int();
        questions[i].qno = i+1;
    }
    return questions;
}

void display_question(struct Question question) {
    printf("%d. %s\n", question.qno, question.question);
    printf("  1. %s\n", question.op1);
    printf("  2. %s\n", question.op2);
    printf("  3. %s\n", question.op3);
    printf("  4. %s\n", question.op4);
}

void display_result(struct User user, int num_questions) {
    printf("\n\nQuiz Results\n");
    printf("Name: %s\n", user.name);
    printf("Score: %d/%d\n", user.score, num_questions);
}

int main() {

    printf("Welcome to the C Online Examination System\n");

    printf("Enter your name: ");
    char name[255];
    fgets(name, sizeof(name), stdin);

    printf("Enter the number of questions in the exam: ");
    int num_questions = read_int();

    struct Question* questions = read_questions(num_questions);

    struct User user;
    strcpy(user.name, name);
    user.score = 0;

    for (int i = 0; i < num_questions; i++) {
        printf("\nQuestion %d:\n", i+1);
        display_question(questions[i]);
        printf("Enter your answer: ");
        int user_answer = read_int();
        if (user_answer == questions[i].correct) {
            printf("Correct!\n");
            user.score++;
        }
        else {
            printf("Incorrect. The correct answer is %d\n", questions[i].correct);
        }
    }

    display_result(user, num_questions);

    free(questions);
    return 0;
}