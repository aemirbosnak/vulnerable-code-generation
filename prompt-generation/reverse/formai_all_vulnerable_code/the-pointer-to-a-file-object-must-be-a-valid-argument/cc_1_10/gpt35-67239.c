//FormAI DATASET v1.0 Category: Online Examination System ; Style: realistic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/* Structure to store student information */
struct student{
    char name[20];
    int roll;
    int age;
};

/* Structure to store question information */
struct question{
    char question[100];
    char option1[50];
    char option2[50];
    char option3[50];
    char option4[50];
    int answer;
};

/* Function to display menu */
void display_menu(){
    printf("\n\n\n");
    printf("Welcome to Online Exam System\n\n");
    printf("1. Start Exam\n");
    printf("2. View Student Results\n");
    printf("3. Exit\n");
    printf("\n\n\n");
}

/* Function to get student details */
void get_student_details(struct student *s){
    printf("Enter Student Name: ");
    scanf("%s",s->name);
    printf("Enter Student Roll Number: ");
    scanf("%d",&s->roll);
    printf("Enter Student Age: ");
    scanf("%d",&s->age);
}

/* Function to get questions */
void get_questions(struct question *q){
    printf("Enter Question: ");
    scanf("%s",q->question);
    printf("Enter Option 1: ");
    scanf("%s",q->option1);
    printf("Enter Option 2: ");
    scanf("%s",q->option2);
    printf("Enter Option 3: ");
    scanf("%s",q->option3);
    printf("Enter Option 4: ");
    scanf("%s",q->option4);
    printf("Enter Answer (1-4): ");
    scanf("%d",&q->answer);
}

/* Function to start exam */
void start_exam(){
    int num_questions;
    int score = 0;
    printf("Enter the number of questions: ");
    scanf("%d",&num_questions);
    struct question *questions = (struct question*)malloc(sizeof(struct question)*num_questions);
    for(int i=0;i<num_questions;i++){
        printf("Enter Question %d Details:\n",i+1);
        get_questions(&questions[i]);
    }
    struct student s;
    get_student_details(&s);
    printf("Welcome %s, your exam has started.\n",s.name);
    for(int i=0;i<num_questions;i++){
        printf("\n\nQuestion %d: %s\n",i+1,questions[i].question);
        printf("1. %s\n",questions[i].option1);
        printf("2. %s\n",questions[i].option2);
        printf("3. %s\n",questions[i].option3);
        printf("4. %s\n",questions[i].option4);
        int ans;
        printf("Enter your answer: ");
        scanf("%d",&ans);
        if(ans == questions[i].answer){
            printf("Correct Answer!\n");
            score++;
        }
        else{
            printf("Wrong Answer!\n");
        }
    }
    printf("\n\n%s, your exam has ended.\n",s.name);
    printf("Your Score: %d/%d\n",score,num_questions);
    free(questions);
}

/* Function to view student results */
void view_results(){
    FILE *fp;
    fp = fopen("results.txt","r");
    char str[255];
    while(fgets(str, 255, fp) != NULL){
        printf("%s",str);
    }
    fclose(fp);
}

/* Function to save student result */
void save_result(struct student s, int score){
    FILE *fp;
    fp = fopen("results.txt","a");
    fputs(s.name, fp);
    fputs(" - ", fp);
    fprintf(fp,"%d/%d\n",score,5);
    fclose(fp);
}

/* Main Function */
int main(){
    while(1){
        display_menu();
        int choice;
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                start_exam();
                break;
            case 2:
                view_results();
                break;
            case 3:
                printf("\n\nGoodbye!\n\n");
                exit(0);
            default:
                printf("\n\nInvalid Choice!\n\n");
                break;
        }
    }
    return 0;
}