//FormAI DATASET v1.0 Category: Online Examination System ; Style: interoperable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//structure for storing questions and their respective answers
struct question{
    char question[1000];
    char option1[100];
    char option2[100];
    char option3[100];
    char option4[100];
    int actual_ans;
} questions[10];

//function for reading the questions from file
void read_questions_file(){
    FILE *questions_file = fopen("questions.txt", "r");
    char line[1000]; //array for storing individual lines from the file
    int counter = 0; //counter for keeping track of number of questions

    while(fgets(line, 1000, questions_file)){
        strcpy(questions[counter].question, strtok(line, ",")); //storing the question
        strcpy(questions[counter].option1, strtok(NULL, ",")); //storing the first option
        strcpy(questions[counter].option2, strtok(NULL, ",")); //storing the second option
        strcpy(questions[counter].option3, strtok(NULL, ",")); //storing the third option
        strcpy(questions[counter].option4, strtok(NULL, ",")); //storing the fourth option
        questions[counter].actual_ans = atoi(strtok(NULL, ",")); //storing the actual answer
        
        counter++; //incrementing the counter for next question
    }

    fclose(questions_file); //closing the file after reading is done
}

//function for displaying the questions to the user
void display_questions(){
    for(int i=0; i<10; i++){
        printf("%d. %s\n", i+1, questions[i].question);
        printf("   1. %s\n", questions[i].option1);
        printf("   2. %s\n", questions[i].option2);
        printf("   3. %s\n", questions[i].option3);
        printf("   4. %s\n", questions[i].option4);
    }
}

//function for taking the user's answers and calculating the score
int calculate_score(){
    int score = 0; //variable for storing the score
    
    for(int i=0; i<10; i++){
        int user_ans; //variable for storing the user's answer
        do{
            printf("\nEnter your answer for question %d: ", i+1);
            scanf("%d", &user_ans);
        }while(user_ans!=1 && user_ans!=2 && user_ans!=3 && user_ans!=4); //while loop keeps running until user enters a valid option
        
        if(user_ans == questions[i].actual_ans){
            score++;
        }
    }

    return score;
}

int main(){
    read_questions_file(); //reading questions from file
    printf("Welcome to the Online Examination System!\n\n");
    printf("Please read the following instructions carefully:\n");
    printf("1. This exam consists of 10 questions.\n");
    printf("2. Each question is multiple choice with 4 options.\n");
    printf("3. Enter the option number as your answer (1, 2, 3 or 4).\n");
    printf("4. You will get 1 point for each correct answer.\n\n");

    char user_choice;
    do{
        display_questions(); //displaying questions to the user
        int score = calculate_score(); //calculating score
        printf("\nYour score is %d/10.\n", score); //displaying user's score

        do{
            printf("Enter R to try again or Q to quit: ");
            scanf(" %c", &user_choice);
        }while(user_choice!='r' && user_choice!='R' && user_choice!='q' && user_choice!='Q'); //while loop keeps running until user enters a valid option
    
    }while(user_choice=='r' || user_choice=='R'); //while loop runs again if user chooses to retry the exam

    return 0;
}