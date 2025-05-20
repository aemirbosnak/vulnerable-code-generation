//Gemma-7B DATASET v1.0 Category: Online Examination System ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXAM_QUESTIONS 10

int main()
{
    char **questions = NULL;
    int numQuestions = 0;

    // Allocate memory for the questions
    questions = malloc(MAX_EXAM_QUESTIONS * sizeof(char *));
    for (int i = 0; i < MAX_EXAM_QUESTIONS; i++)
    {
        questions[i] = malloc(256 * sizeof(char));
    }

    // Create a list of exam questions
    questions[0] = "What is the meaning of life?";
    questions[1] = "Who invented the computer?";
    questions[2] = "What is the capital of France?";
    questions[3] = "What is the sound of one hand clapping?";
    questions[4] = "What is the square of 5?";
    questions[5] = "What is the meaning of the word 'entrepreneur'?";
    questions[6] = "What is the difference between a tomato and a strawberry?";
    questions[7] = "What is the meaning of the word 'giraffe'?";
    questions[8] = "What is the most common color of hair in the world?";
    questions[9] = "What is the sound of a clock ticking?";

    // Get the number of questions from the user
    numQuestions = 0;
    printf("How many questions do you want to answer? ");
    scanf("%d", &numQuestions);

    // Answer the questions
    for (int i = 0; i < numQuestions; i++)
    {
        printf("Question %d: ", i + 1);
        scanf("%s", questions[i]);
    }

    // Check the answers
    for (int i = 0; i < numQuestions; i++)
    {
        printf("Your answer to question %d: ", i + 1);
        printf("%s\n", questions[i]);
    }

    // Free the memory
    for (int i = 0; i < MAX_EXAM_QUESTIONS; i++)
    {
        free(questions[i]);
    }
    free(questions);

    return 0;
}