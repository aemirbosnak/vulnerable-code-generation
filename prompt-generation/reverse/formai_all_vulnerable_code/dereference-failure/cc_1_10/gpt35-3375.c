//FormAI DATASET v1.0 Category: Online Examination System ; Style: relaxed
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct question{
    char query[200];
    char option1[100];
    char option2[100];
    char option3[100];
    char option4[100];
    int correct_option;
    int selected_option;
};

struct student{
    char name[50];
    int roll_no;
    int marks_obtained;
    int total_marks;
};

int main(){
    int num_questions, num_students;
    printf("Enter the number of questions in the exam: ");
    scanf("%d",&num_questions);
    printf("Enter the number of students appearing for the exam: ");
    scanf("%d",&num_students);

    struct question* questions = (struct question*)malloc(num_questions*sizeof(struct question));
    struct student* students = (struct student*)malloc(num_students*sizeof(struct student));

    for(int i=0; i<num_questions; i++){
        printf("\nEnter the query for question %d: ",i+1);
        scanf(" %[^\n]%*c", questions[i].query);
        printf("Enter the option 1: ");
        scanf(" %[^\n]%*c", questions[i].option1);
        printf("Enter the option 2: ");
        scanf(" %[^\n]%*c", questions[i].option2);
        printf("Enter the option 3: ");
        scanf(" %[^\n]%*c", questions[i].option3);
        printf("Enter the option 4: ");
        scanf(" %[^\n]%*c", questions[i].option4);
        printf("Enter the correct option (1-4): ");
        scanf("%d",&questions[i].correct_option);
    }

    for(int i=0; i<num_students; i++){
        printf("\nEnter the name of student %d: ",i+1);
        scanf(" %[^\n]%*c",students[i].name);
        printf("Enter the roll number of student %d: ",i+1);
        scanf("%d",&students[i].roll_no);
        students[i].marks_obtained = 0;
        students[i].total_marks = num_questions*4; //each question carries 4 marks
    }

    for(int i=0; i<num_students; i++){
        printf("\n\nHello, %s! Welcome to the exam.\nThe test contains %d questions with each carrying 4 marks.\nBest of luck!",students[i].name,num_questions);
        printf("\n\nPress any key to continue: ");
        getchar();
        for(int j=0; j<num_questions; j++){
            printf("\nQuestion %d: %s",j+1,questions[j].query);
            printf("\n1. %s",questions[j].option1);
            printf("\n2. %s",questions[j].option2);
            printf("\n3. %s",questions[j].option3);
            printf("\n4. %s",questions[j].option4);
            printf("\nEnter your choice (1-4): ");
            scanf("%d",&questions[j].selected_option);
            if(questions[j].selected_option == questions[j].correct_option){
                students[i].marks_obtained += 4;
            }
        }
        printf("\n\nThank you for taking the exam, %s!",students[i].name);
        printf("\nYour marks obtained: %d\n",students[i].marks_obtained);
    }

    printf("\n\nExam Results:");
    printf("\nRoll No\tName\tMarks Obtained");
    for(int i=0; i<num_students; i++){
        printf("\n%d\t%s\t%d",students[i].roll_no,students[i].name,students[i].marks_obtained);
    }
    printf("\n\n");

    return 0;
}