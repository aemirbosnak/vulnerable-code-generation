//FormAI DATASET v1.0 Category: Online Examination System ; Style: all-encompassing
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Question {
    int question_id;
    char question[1000];
    char option1[100];
    char option2[100];
    char option3[100];
    char option4[100];
    int correct_option;
};

int main() {
    int num_of_questions;
    printf("Enter number of questions: ");
    scanf("%d", &num_of_questions);
    
    struct Question exam_questions[num_of_questions];
    
    int i;
    for(i=0; i<num_of_questions; i++) {
        printf("Enter question %d: ", i+1);
        fflush(stdin);
        fgets(exam_questions[i].question, 1000, stdin);
        printf("Enter option 1: ");
        fflush(stdin);
        fgets(exam_questions[i].option1, 100, stdin);
        printf("Enter option 2: ");
        fflush(stdin);
        fgets(exam_questions[i].option2, 100, stdin);
        printf("Enter option 3: ");
        fflush(stdin);
        fgets(exam_questions[i].option3, 100, stdin);
        printf("Enter option 4: ");
        fflush(stdin);
        fgets(exam_questions[i].option4, 100, stdin);
        printf("Enter correct option: ");
        scanf("%d", &exam_questions[i].correct_option);
    }
    
    int score = 0;
    for(i=0; i<num_of_questions; i++) {
        char user_answer[100];
        printf("%d. %s", i+1, exam_questions[i].question);
        printf("1. %s", exam_questions[i].option1);
        printf("2. %s", exam_questions[i].option2);
        printf("3. %s", exam_questions[i].option3);
        printf("4. %s", exam_questions[i].option4);
        printf("Enter your answer: ");
        fflush(stdin);
        fgets(user_answer, 100, stdin);
        
        if(atoi(user_answer) == exam_questions[i].correct_option) {
            score++;
        }
    }
    
    printf("Your score: %d/%d\n", score, num_of_questions);
    
    return 0;
}