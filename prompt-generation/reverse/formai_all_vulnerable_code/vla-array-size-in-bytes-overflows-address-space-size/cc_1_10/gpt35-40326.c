//FormAI DATASET v1.0 Category: Online Examination System ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
#define QUESTION_LIMIT 50
#define ANSWER_LIMIT 100
 
typedef struct {
    char question[ANSWER_LIMIT];
    char options[4][ANSWER_LIMIT];
    int correct_option;
} Question;
 
typedef struct {
    char name[100];
    int score;
} Participant;
 
int main() {
    int num_of_questions;
    printf("Enter the number of questions: ");
    scanf("%d", &num_of_questions);
 
    Question questions[QUESTION_LIMIT];
    for (int i = 0; i < num_of_questions; i++) {
        fflush(stdin);
        printf("\nEnter the question %d: ", i+1);
        fgets(questions[i].question, ANSWER_LIMIT, stdin);
 
        for (int j = 0; j < 4; j++) {
            printf("Enter option %d: ", j+1);
            fgets(questions[i].options[j], ANSWER_LIMIT, stdin);
        }
 
        printf("Enter the correct option (1-4): ");
        scanf("%d", &questions[i].correct_option);
    }
 
    int num_of_participants;
    printf("\nEnter the number of participants: ");
    scanf("%d", &num_of_participants);
 
    Participant participants[num_of_participants];
    for (int i = 0; i < num_of_participants; i++) {
        fflush(stdin);
        printf("\nEnter the name of participant %d: ", i+1);
        fgets(participants[i].name, 100, stdin);
        participants[i].score = 0;
    }
 
    printf("\nThe test has started!\n");
    for (int i = 0; i < num_of_questions; i++) {
        printf("\nQ%d. %s", i+1, questions[i].question);
        for (int j = 0; j < 4; j++) {
            printf("%d) %s", j+1, questions[i].options[j]);
        }
 
        int answer;
        printf("Enter your answer: ");
        scanf("%d", &answer);
 
        for (int j = 0; j < num_of_participants; j++) {
            if (answer == questions[i].correct_option) {
                participants[j].score++;
            }
        }
    }
 
    printf("\nResults:\n");
    for (int i = 0; i < num_of_participants; i++) {
        printf("%s scored %d marks!\n", participants[i].name, participants[i].score);
    }
 
    printf("\nThe test has ended!");
    return 0;
}