//FormAI DATASET v1.0 Category: Online Examination System ; Style: rigorous
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//defining struct to store candidate details
struct candidate {
    char name[50];
    int id;
    int marks;
};

int main() {
    int n, i, j, choice; //n: number of candidates, i,j: loop variables, choice: user input for menu
    printf("Welcome to the Online Examination System!\n");
    printf("Enter the number of candidates: ");
    scanf("%d", &n);
    
    struct candidate students[n]; //array of structs to store candidate details
    
    //taking input for candidate details
    for(i = 0; i < n; i++) {
        printf("\nCandidate %d Details:\n", i+1);
        printf("Enter Name: ");
        scanf("%s", students[i].name);
        printf("Enter id: ");
        scanf("%d", &students[i].id);
        students[i].marks = 0; //initializing marks to 0
    }
    
    do {
        printf("\nMenu:\n");
        printf("1. Start Exam\n");
        printf("2. View Results\n");
        printf("3. Exit\n");
        printf("Enter Choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("\n\tExam Rules:\n");
                printf("1. There are 10 MCQ Questions.\n");
                printf("2. Each question carries 10 marks.\n");
                printf("3. There is no negative marking.\n");
                printf("4. Enter the option number (1-4) for your answer.\n\n");
                
                //starting the exam for each candidate
                for(i = 0; i < n; i++) {
                    printf("\n%s, your exam will now start.\n", students[i].name);
                    for(j = 1; j <= 10; j++) {
                        int answer;
                        printf("Question %d:\n", j);
                        printf("1. Option 1\n");
                        printf("2. Option 2\n");
                        printf("3. Option 3\n");
                        printf("4. Option 4\n");
                        printf("Enter your answer: ");
                        scanf("%d", &answer);
                        if(answer > 0 && answer <= 4) //checking if user input is valid
                            students[i].marks += 10; //adding 10 marks for each correct answer
                    }
                }
                printf("\n\tExam Completed!\n");
                break;
                
            case 2:
                printf("\n\tResults:\n\n");
                //displaying result for each candidate
                for(i = 0; i < n; i++) {
                    printf("Candidate %d Name: %s\n", i+1, students[i].name);
                    printf("Candidate %d Id: %d\n", i+1, students[i].id);
                    printf("Candidate %d Marks: %d\n", i+1, students[i].marks);
                    printf("\n");
                }
                break;
                
            case 3:
                printf("\n\tExiting Online Examination System. Goodbye!\n");
                exit(0); //exiting the program
                break;
                
            default:
                printf("\nInvalid Choice. Please Try Again.\n");
                break;
        }
    } while(1); //infinite loop to continue displaying menu until user chooses to exit
    return 0;
}