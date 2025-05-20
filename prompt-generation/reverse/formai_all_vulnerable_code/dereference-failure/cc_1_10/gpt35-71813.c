//FormAI DATASET v1.0 Category: Online Examination System ; Style: unmistakable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

#define MAX_QUESTIONS 10

typedef struct{
    char question[100];
    char optionA[50];
    char optionB[50];
    char optionC[50];
    char optionD[50];
    char correctAnswer[50];
} Question;

void showInstructions(){
    printf("Welcome to the Online Examination System!\n");
    printf("You will be presented with 10 multiple choice questions.\n");
    printf("Each question will have 4 options.\n");
    printf("Select the appropriate option and press Enter to move to the next question.\n");
}

Question* readQuestionsFromFile(char* fileName){
    
    FILE* fp;
    fp = fopen(fileName, "r");
    if(fp == NULL){
        printf("Unable to open file!\n");
        exit(1);
    }

    Question* questions = malloc(MAX_QUESTIONS * sizeof(Question));
    char line[200];
    int i=0;

    while(fgets(line, sizeof(line), fp)){
        strcpy(questions[i].question, strtok(line, ","));
        strcpy(questions[i].optionA, strtok(NULL, ","));
        strcpy(questions[i].optionB, strtok(NULL, ","));
        strcpy(questions[i].optionC, strtok(NULL, ","));
        strcpy(questions[i].optionD, strtok(NULL, ","));
        strcpy(questions[i].correctAnswer, strtok(NULL, "\n"));
        i++;
    }
    fclose(fp);

    return questions;
}

bool isAnswerCorrect(char* answer, Question* question){
    return strcmp(answer, question->correctAnswer) == 0;
}

void displayQuestion(int index, Question* question){
    printf("Question %d: %s\n", index+1, question->question);
    printf("A. %s\n", question->optionA);
    printf("B. %s\n", question->optionB);
    printf("C. %s\n", question->optionC);
    printf("D. %s\n", question->optionD);
    printf("Please enter your answer (A/B/C/D): ");
}

void conductExam(Question* questions){
    int score=0;
    char choice[10];
    for(int i=0; i<MAX_QUESTIONS; i++){
        displayQuestion(i, &questions[i]);
        scanf("%s", choice);
        if(isAnswerCorrect(choice, &questions[i]))
            score++;
    }
    printf("\nYour final score is: %d/%d", score, MAX_QUESTIONS);
}

int main(){
    showInstructions();

    printf("\nPress Enter to begin the exam...");
    getchar();

    Question* questions = readQuestionsFromFile("questions.txt");
    conductExam(questions);
    free(questions);

    return 0;
}