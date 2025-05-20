//FormAI DATASET v1.0 Category: Online Examination System ; Style: random
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Structure of Question 
struct Question {
    int questionNumber;
    char question[200];
    char options[4][50];
    int answer;
};

int main() {
    int numberOfQuestions;
    printf("Welcome to the C Online Examination System! \n");
    printf("Please enter the number of questions for the exam: ");
    scanf("%d",&numberOfQuestions);
    printf("\n");

    // Dynamic Allocation of Question Structure
    struct Question *questions;
    questions = (struct Question*) malloc(sizeof(struct Question) * numberOfQuestions);

    // Adding Questions to the Exam
    for(int i=0;i<numberOfQuestions;i++) {
        printf("Question %d:\n",i+1);
        questions[i].questionNumber = i+1;

        printf("Enter the question: ");
        scanf(" %[^\n]s",questions[i].question);

        printf("Enter Option A: ");
        scanf("%s",questions[i].options[0]);

        printf("Enter Option B: ");
        scanf("%s",questions[i].options[1]);

        printf("Enter Option C: ");
        scanf("%s",questions[i].options[2]);

        printf("Enter Option D: ");
        scanf("%s",questions[i].options[3]);

        printf("Enter the Correct Option: ");
        scanf("%d",&questions[i].answer);

        printf("\n");
    }

    // Taking the Exam
    int marks = 0;
    int userAnswer = -1;
    for(int i=0;i<numberOfQuestions;i++) {
        printf("Question %d: %s\n",i+1,questions[i].question);
        printf("A. %s\tB. %s\tC. %s\tD. %s\n",questions[i].options[0],questions[i].options[1],questions[i].options[2],questions[i].options[3]);

        while(userAnswer < 1 || userAnswer > 4) {
            printf("Enter your answer (1-4): ");
            scanf("%d",&userAnswer);
        }

        if(userAnswer == questions[i].answer) {
            printf("Correct Answer!\n");
            marks++;
        }
        else {
            printf("Wrong Answer!\n");
        }

        userAnswer = -1;
        printf("\n");
    }

    // Displaying Results
    printf("Your final score is %d / %d\n",marks,numberOfQuestions);

    if(marks >= 0.6 * numberOfQuestions) {
        printf("Congratulations! You passed the exam!\n");
    }
    else {
        printf("Sorry! You failed the exam!\n");
    }

    // Freeing Memory
    free(questions);

    return 0 ;
}