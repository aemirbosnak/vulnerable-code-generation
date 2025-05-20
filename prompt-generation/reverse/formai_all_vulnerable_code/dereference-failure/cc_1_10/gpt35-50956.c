//FormAI DATASET v1.0 Category: Online Examination System ; Style: high level of detail
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct question {
    char question_text[1000];
    char options[4][1000];
    int answer;
};

struct question* create_questions(int num_questions) {
    struct question* questions = (struct question*)malloc(num_questions * sizeof(struct question)); // allocating memory dynamically
    int i, j;
    for(i=0; i<num_questions; i++) {
        printf("Enter question %d:\n", i+1);
        getchar();
        fgets(questions[i].question_text, 1000, stdin); // accepting question text
        for(j=0; j<4; j++) {
            printf("Enter option %d for question %d:\n", j+1, i+1);
            fgets(questions[i].options[j], 1000, stdin); // accepting options
        }
        printf("Enter answer for question %d (1-4):\n", i+1);
        scanf("%d", &questions[i].answer); // accepting answer
    }
    return questions;
}

void display_question(struct question q) {
    printf("%s\n", q.question_text);
    for(int i=0; i<4; i++) {
        printf("%d. %s", i+1, q.options[i]);
    }
}

void start_exam(struct question* questions, int num_questions) {
    int score = 0;
    for(int i=0; i<num_questions; i++) {
        printf("Question %d:\n", i+1);
        display_question(questions[i]);
        int selected_option;
        printf("Enter answer (1-4):\n");
        scanf("%d", &selected_option);
        if(selected_option == questions[i].answer) {
            printf("Correct answer!\n");
            score++;
        } else {
            printf("Wrong answer!\n");
        }
    }
    printf("Exam finished! You scored %d out of %d.\n", score, num_questions);
}

int main() {
    int num_questions;
    printf("Welcome to the Online Examination System!\n");
    printf("Enter number of questions you want to add:\n");
    scanf("%d", &num_questions);
    struct question* questions = create_questions(num_questions);
    printf("All questions created successfully!\n");
    printf("Let's start the exam:\n");
    start_exam(questions, num_questions);
    return 0;
}