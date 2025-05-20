//FormAI DATASET v1.0 Category: Online Examination System ; Style: creative
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_QUESTIONS 50

// struct to hold information of a question
struct Question{
    int question_num;
    char question[250];
    char option1[50], option2[50], option3[50], option4[50];
    int answer;
};

// function to load questions from file
int load_questions(struct Question *questions){
    FILE *fp = fopen("questions.txt", "r");
    if(fp == NULL){
        printf("Error Opening File!");
        return -1;
    }
    
    // read questions
    char line[250];
    int i = 0;
    while(fgets(line, sizeof(line), fp)){
        char *token = strtok(line, ",");
        questions[i].question_num = atoi(token);
        token = strtok(NULL, ",");
        strcpy(questions[i].question, token);
        token = strtok(NULL, ",");
        strcpy(questions[i].option1, token);
        token = strtok(NULL, ",");
        strcpy(questions[i].option2, token);
        token = strtok(NULL, ",");
        strcpy(questions[i].option3, token);
        token = strtok(NULL, ",");
        strcpy(questions[i].option4, token);
        token = strtok(NULL, ",");
        questions[i].answer = atoi(token);
        i++;
    }
    fclose(fp);
    return i;
}

// function to display questions
void display_questions(struct Question *questions, int num_questions){
    for(int i=0; i<num_questions; i++){
        printf("\n\nQuestion %d: %s", questions[i].question_num, questions[i].question);
        printf("\n1) %s", questions[i].option1);
        printf("\n2) %s", questions[i].option2);
        printf("\n3) %s", questions[i].option3);
        printf("\n4) %s", questions[i].option4);
    }
}

void take_exam(struct Question *questions, int num_questions){
    int marks = 0;
    for(int i=0; i<num_questions; i++){
        printf("\n\nQuestion %d: %s", questions[i].question_num, questions[i].question);
        printf("\n1) %s", questions[i].option1);
        printf("\n2) %s", questions[i].option2);
        printf("\n3) %s", questions[i].option3);
        printf("\n4) %s", questions[i].option4);
        int choice;
        printf("\nEnter your answer (1/2/3/4): ");
        scanf("%d", &choice);
        if(choice == questions[i].answer){
            printf("\nCorrect Answer!");
            marks++;
        }
        else{
            printf("\nIncorrect Answer!");
        }
    }
    printf("\n\nYou scored %d out of %d marks!", marks, num_questions);
}

int main(){
    printf("Welcome to Online Examination System!\n");
    printf("--------------------------------------\n");
    struct Question questions[MAX_QUESTIONS];
    int num_questions = load_questions(questions);
    if(num_questions == -1){
        return 0;
    }
    printf("Press 1 to View Questions\nPress 2 to Take Exam\n");
    int choice;
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch(choice){
        case 1:
            display_questions(questions, num_questions);
            break;
        case 2:
            take_exam(questions, num_questions);
            break;
        default:
            printf("Invalid Choice!");
    }
    return 0;
}