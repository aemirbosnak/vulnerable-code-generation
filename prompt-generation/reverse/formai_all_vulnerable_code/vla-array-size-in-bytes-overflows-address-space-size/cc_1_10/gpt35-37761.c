//FormAI DATASET v1.0 Category: Online Examination System ; Style: accurate
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// structure to store questions and answer options
struct Question 
{
    char question[100];
    char option1[50];
    char option2[50];
    char option3[50];
    char option4[50];
    int correct_option; // 1 for option1, 2 for option2, 3 for option3 and 4 for option4
};

// function to display the questions and options
void displayQuestion(struct Question q)
{
    printf("\n%s\n", q.question);
    printf("1. %s\n", q.option1);
    printf("2. %s\n", q.option2);
    printf("3. %s\n", q.option3);
    printf("4. %s\n", q.option4);
}

int main()
{
    int num_questions; // number of questions in the exam
    printf("Enter the number of questions in the exam: ");
    scanf("%d", &num_questions);

    struct Question quiz[num_questions]; // create an array of Question structures

    // get question and answer details from the user
    for(int i = 0; i < num_questions; i++)
    {
        fflush(stdin); // clear any previous input from the buffer

        printf("\nEnter details for question %d: \n", i+1);
        printf("Question: ");
        fgets(quiz[i].question, sizeof(quiz[i].question), stdin);

        printf("Option 1: ");
        fgets(quiz[i].option1, sizeof(quiz[i].option1), stdin);

        printf("Option 2: ");
        fgets(quiz[i].option2, sizeof(quiz[i].option2), stdin);

        printf("Option 3: ");
        fgets(quiz[i].option3, sizeof(quiz[i].option3), stdin);

        printf("Option 4: ");
        fgets(quiz[i].option4, sizeof(quiz[i].option4), stdin);

        printf("Enter the correct option number (1-4): ");
        scanf("%d", &quiz[i].correct_option);
    }

    // display the questions and ask for user inputs
    int score = 0; // initialize user's score to zero
    printf("\n---- Exam Starts Now ----\n");

    for(int i = 0; i < num_questions; i++)
    {
        printf("\nQuestion %d:\n", i+1);
        displayQuestion(quiz[i]);

        int user_ans; // variable to store user's answer
        printf("Enter your answer (1-4): ");
        scanf("%d", &user_ans);

        if(user_ans == quiz[i].correct_option)
        {
            printf("Correct! You earned 1 point.\n");
            score++;
        }
        else
        {
            printf("Incorrect. No points earned.\n");
        }
    }

    // display user's final score
    printf("\n---- Exam Ends ----\n");
    printf("Your final score is %d/%d\n", score, num_questions);

    return 0;
}