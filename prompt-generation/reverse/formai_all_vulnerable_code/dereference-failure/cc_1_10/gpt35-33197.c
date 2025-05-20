//FormAI DATASET v1.0 Category: Online Examination System ; Style: interoperable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Structure for storing question details
struct question{
    char question[200];
    char option1[100];
    char option2[100];
    char option3[100];
    char option4[100];
    int answer;
};

//Function to display and get choice from user
int choice(char *message,int lowerlimit,int upperlimit){
    int temp_choice;
    do{
        printf("%s(%d - %d): ",message,lowerlimit,upperlimit);
        scanf("%d",&temp_choice);
        if(temp_choice<lowerlimit||temp_choice>upperlimit){
            printf("Invalid Choice, Try Again!");
        }
    }while(temp_choice<lowerlimit||temp_choice>upperlimit);
    return temp_choice;
}

//Main function
int main(){
    int num_of_questions;
    struct question* exam_questions;
    char temp_str[200];
    int temp_choice;
    int score = 0;
    int i;
    
    printf("Welcome to the Online Examination System!\n\n");
    num_of_questions = choice("Enter Number of Questions",1,50);
    
    exam_questions = (struct question*) malloc(num_of_questions * sizeof(struct question));//Dynamic Memory Allocation
    
    //Get Questions & Answers from User
    for(i=0;i<num_of_questions;i++){
        printf("\n");
        printf("Question %d:\n",(i+1));
        printf("Enter Question: ");
        fgets(temp_str,200,stdin);//Clearing Buffer
        fgets(temp_str,200,stdin);
        strcpy(exam_questions[i].question,temp_str);
        
        printf("Enter Option 1: ");
        fgets(temp_str,100,stdin);//Clearing Buffer
        fgets(temp_str,100,stdin);
        strcpy(exam_questions[i].option1,temp_str);
        
        printf("Enter Option 2: ");
        fgets(temp_str,100,stdin);//Clearing Buffer
        fgets(temp_str,100,stdin);
        strcpy(exam_questions[i].option2,temp_str);
        
        printf("Enter Option 3: ");
        fgets(temp_str,100,stdin);//Clearing Buffer
        fgets(temp_str,100,stdin);
        strcpy(exam_questions[i].option3,temp_str);
        
        printf("Enter Option 4: ");
        fgets(temp_str,100,stdin);//Clearing Buffer
        fgets(temp_str,100,stdin);
        strcpy(exam_questions[i].option4,temp_str);
        
        exam_questions[i].answer = choice("Enter Correct Option",1,4);
    }
    
    //Give Exam and Display Result
    for(i=0;i<num_of_questions;i++){
        printf("\n");
        printf("Question %d:\n",(i+1));
        printf("%s\n",exam_questions[i].question);
        printf("%s\n",exam_questions[i].option1);
        printf("%s\n",exam_questions[i].option2);
        printf("%s\n",exam_questions[i].option3);
        printf("%s\n",exam_questions[i].option4);
        temp_choice = choice("Enter Your Choice",1,4);
        if(temp_choice==exam_questions[i].answer){
            score++;
            printf("Correct Answer!\n");
        }
        else{
            printf("Wrong Answer! Correct Answer is Option %d\n",exam_questions[i].answer);
        }
        
    }
    printf("\n");
    printf("Your Score is %d Out of %d\n",score,num_of_questions);
    
    free(exam_questions);//Deallocating Memory
    
    return 0;
}