//Gemma-7B DATASET v1.0 Category: Online Examination System ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_QUESTIONS 10
#define MAX_ANSWERS 4

int main()
{
    // Seed the random number generator
    srand(time(NULL));

    // Create an array of questions
    char **questions = (char **)malloc(MAX_QUESTIONS * sizeof(char *));
    for (int i = 0; i < MAX_QUESTIONS; i++)
    {
        questions[i] = (char *)malloc(MAX_ANSWERS * sizeof(char));
    }

    // Fill the questions with random text
    for (int i = 0; i < MAX_QUESTIONS; i++)
    {
        for (int j = 0; j < MAX_ANSWERS; j++)
        {
            questions[i][j] = (char)rand() % 26 + 'a';
        }
    }

    // Create an array of answers
    char **answers = (char **)malloc(MAX_QUESTIONS * sizeof(char *));
    for (int i = 0; i < MAX_QUESTIONS; i++)
    {
        answers[i] = (char *)malloc(MAX_ANSWERS * sizeof(char));
    }

    // Randomly select the correct answer for each question
    for (int i = 0; i < MAX_QUESTIONS; i++)
    {
        for (int j = 0; j < MAX_ANSWERS; j++)
        {
            answers[i][j] = (char)rand() % MAX_ANSWERS + 'a';
        }
    }

    // Print the questions and answers
    for (int i = 0; i < MAX_QUESTIONS; i++)
    {
        printf("Question: %s\n", questions[i]);
        printf("Answers: ");
        for (int j = 0; j < MAX_ANSWERS; j++)
        {
            printf("%c ", answers[i][j]);
        }
        printf("\n");
    }

    // Free the memory allocated for the questions and answers
    for (int i = 0; i < MAX_QUESTIONS; i++)
    {
        free(questions[i]);
        free(answers[i]);
    }
    free(questions);
    free(answers);

    return 0;
}