//Gemma-7B DATASET v1.0 Category: Online Examination System ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    // Define an array of questions and answers
    char **questions = (char **)malloc(10 * sizeof(char *));
    for (int i = 0; i < 10; i++)
    {
        questions[i] = (char *)malloc(256 * sizeof(char));
    }

    // Fill the questions and answers with sample data
    strcpy(questions[0], "What is the meaning of the word 'entrepreneur'?");
    questions[0][0] = 'a';
    questions[0][1] = 'b';
    questions[0][2] = 'c';

    strcpy(questions[1], "Which scientist invented the theory of relativity?");
    questions[1][0] = 'a';
    questions[1][1] = 'b';
    questions[1][2] = 'c';

    // Create a list of student answers
    char **answers = (char **)malloc(20 * sizeof(char *));
    for (int i = 0; i < 20; i++)
    {
        answers[i] = (char *)malloc(256 * sizeof(char));
    }

    // Get the student's answer for each question
    printf("Enter your answer for each question:\n");
    for (int i = 0; i < 10; i++)
    {
        scanf("%s", answers[i]);
    }

    // Check if the student's answer is correct
    int score = 0;
    for (int i = 0; i < 10; i++)
    {
        if (strcmp(answers[i], questions[i][0]) == 0)
        {
            score++;
        }
    }

    // Print the student's score
    printf("Your score is: %d out of 10\n", score);

    // Free the memory allocated for the questions and answers
    for (int i = 0; i < 10; i++)
    {
        free(questions[i]);
    }
    free(questions);

    for (int i = 0; i < 20; i++)
    {
        free(answers[i]);
    }
    free(answers);

    return 0;
}