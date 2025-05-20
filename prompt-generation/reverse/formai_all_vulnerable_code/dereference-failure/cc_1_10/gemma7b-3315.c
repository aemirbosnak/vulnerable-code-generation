//Gemma-7B DATASET v1.0 Category: Online Examination System ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_QUESTIONS 10
#define MAX_ANSWERS 5

typedef struct Question
{
    char *question;
    char **answers;
    int correctAnswer;
} Question;

Question questions[NUM_QUESTIONS] =
{
    {"What is the meaning of the word 'entrepreneur'?", {"a. Business owner", "b. Engineer", "c. Teacher", "d. Lawyer", "e. Doctor"}, 1},
    {"Which planet is the largest?", {"a. Mars", "b. Earth", "c. Jupiter", "d. Saturn", "e. Venus"}, 2},
    {"What is the capital of France?", {"a. Paris", "b. Lyon", "c. Marseille", "d. Lille", "e. Brussels"}, 3},
    {"Which animal is known for its sharp claws?", {"a. Lion", "b. Tiger", "c. Bear", "d. Crocodile", "e. Tiger Shark"}, 4},
    {"What is the most common color of hair in the world?", {"a. Black", "b. Brown", "c. Red", "d. Blonde", "e. Gray"}, 5},
    {"Which scientist invented the theory of relativity?", {"a. Isaac Newton", "b. Albert Einstein", "c. Charles Darwin", "d. Galileo Galilei", "e. Albert Einstein"}, 6},
    {"What is the meaning of the word 'entrepreneur'?", {"a. Business owner", "b. Engineer", "c. Teacher", "d. Lawyer", "e. Doctor"}, 7},
    {"Which planet is the largest?", {"a. Mars", "b. Earth", "c. Jupiter", "d. Saturn", "e. Venus"}, 8},
    {"What is the capital of France?", {"a. Paris", "b. Lyon", "c. Marseille", "d. Lille", "e. Brussels"}, 9},
    {"Which animal is known for its sharp claws?", {"a. Lion", "b. Tiger", "c. Bear", "d. Crocodile", "e. Tiger Shark"}, 10}
};

int main()
{
    system("clear");
    printf("**Welcome to the C Online Examination System!**\n");
    printf("---------------------------------------------------\n");

    for (int i = 0; i < NUM_QUESTIONS; i++)
    {
        printf("Question %d: %s\n", i + 1, questions[i].question);

        for (int j = 0; j < MAX_ANSWERS; j++)
        {
            printf("Answer %c: %s\n", j + 1, questions[i].answers[j]);
        }

        printf("Enter your answer: ");
        char answer = getchar();

        if (answer == questions[i].correctAnswer)
        {
            printf("Correct!\n");
        }
        else
        {
            printf("Incorrect. The answer is: %c\n", questions[i].correctAnswer);
        }

        printf("---------------------------------------------------\n");
    }

    printf("Thank you for taking the C Online Examination System!**\n");
    system("pause");

    return 0;
}