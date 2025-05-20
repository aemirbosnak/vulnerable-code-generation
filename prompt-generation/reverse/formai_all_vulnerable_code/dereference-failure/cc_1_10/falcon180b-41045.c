//Falcon-180B DATASET v1.0 Category: Online Examination System ; Style: optimized
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define TRUE 1
#define FALSE 0
#define MAX_QUESTIONS 100
#define MAX_OPTIONS 5

struct question{
    char question[100];
    char option1[50];
    char option2[50];
    char option3[50];
    char option4[50];
    char correct_option[3];
    int correct_answer;
};

void add_question(struct question *q){
    printf("Enter question: ");
    scanf("%[^\n]",q->question);
    printf("Enter option 1: ");
    scanf("%[^\n]",q->option1);
    printf("Enter option 2: ");
    scanf("%[^\n]",q->option2);
    printf("Enter option 3: ");
    scanf("%[^\n]",q->option3);
    printf("Enter option 4: ");
    scanf("%[^\n]",q->option4);
    printf("Enter correct option (1,2,3,4): ");
    scanf("%s",q->correct_option);
    q->correct_answer = atoi(q->correct_option[0]);
}

void display_question(struct question q){
    printf("%s\n",q.question);
    printf("1. %s\n",q.option1);
    printf("2. %s\n",q.option2);
    printf("3. %s\n",q.option3);
    printf("4. %s\n",q.option4);
}

int main(){
    struct question questions[MAX_QUESTIONS];
    int num_questions,i,j,score=0;
    char choice;

    printf("Enter number of questions: ");
    scanf("%d",&num_questions);

    for(i=0;i<num_questions;i++){
        add_question(&questions[i]);
    }

    printf("\nOnline Examination System\n");
    printf("---------------------------------\n");

    for(i=0;i<num_questions;i++){
        printf("\nQuestion %d:\n",i+1);
        display_question(questions[i]);
        printf("Enter your choice: ");
        scanf(" %c",&choice);

        if(choice=='1' && questions[i].correct_answer==1){
            score++;
        }
        else if(choice=='2' && questions[i].correct_answer==2){
            score++;
        }
        else if(choice=='3' && questions[i].correct_answer==3){
            score++;
        }
        else if(choice=='4' && questions[i].correct_answer==4){
            score++;
        }
        else{
            printf("\nWrong answer.\n");
        }
    }

    printf("\nYour score is %d out of %d.\n",score,num_questions);

    return 0;
}