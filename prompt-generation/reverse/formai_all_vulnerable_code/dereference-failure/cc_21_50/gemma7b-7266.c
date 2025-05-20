//Gemma-7B DATASET v1.0 Category: Online Examination System ; Style: creative
#include <stdio.h>
#include <stdlib.h>

void main()
{
    system("cls");

    // Generate a random question
    int question_num = rand() % 10;
    char question[100];
    switch (question_num)
    {
        case 0:
            strcpy(question, "What is the capital of France?");
            break;
        case 1:
            strcpy(question, "Who invented the telephone?");
            break;
        case 2:
            strcpy(question, "What is the meaning of the word 'entrepreneur'?");
            break;
        case 3:
            strcpy(question, "What is the sound of one hand clapping?");
            break;
        case 4:
            strcpy(question, "What is the most common color of hair in the world?");
            break;
        case 5:
            strcpy(question, "What is the chemical symbol for gold?");
            break;
        case 6:
            strcpy(question, "What is the meaning of the word 'entrepreneur'?");
            break;
        case 7:
            strcpy(question, "Who was the first president of the United States?");
            break;
        case 8:
            strcpy(question, "What is the meaning of the word 'entrepreneur'?");
            break;
        case 9:
            strcpy(question, "What is the meaning of the word 'entrepreneur'?");
            break;
    }

    // Display the question
    printf("**Question:**\n\n%s", question);

    // Get the answer from the user
    char answer[20];
    printf("Enter your answer: ");
    scanf("%s", answer);

    // Check if the answer is correct
    char correct_answer[20];
    switch (question_num)
    {
        case 0:
            strcpy(correct_answer, "Paris");
            break;
        case 1:
            strcpy(correct_answer, "Alexander Graham Bell");
            break;
        case 2:
            strcpy(correct_answer, "A person who owns and operates a business") ;
            break;
        case 3:
            strcpy(correct_answer, "A sound like two hands clapping together") ;
            break;
        case 4:
            strcpy(correct_answer, "Black") ;
            break;
        case 5:
            strcpy(correct_answer, "Au") ;
            break;
        case 6:
            strcpy(correct_answer, "A person who owns and operates a business") ;
            break;
        case 7:
            strcpy(correct_answer, "George Washington") ;
            break;
        case 8:
            strcpy(correct_answer, "A person who owns and operates a business") ;
            break;
        case 9:
            strcpy(correct_answer, "A person who owns and operates a business") ;
            break;
    }

    // Display the results
    if (strcmp(answer, correct_answer) == 0)
    {
        printf("**Congratulations!**\n\nYou have answered the question correctly!");
    }
    else
    {
        printf("**Sorry, but your answer is incorrect.**\n\nThe correct answer is: %s", correct_answer);
    }

    // Pause the program
    system("pause");
}