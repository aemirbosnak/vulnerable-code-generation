//Gemma-7B DATASET v1.0 Category: Online Examination System ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 10

int main()
{
    int numQuestions = 0;
    char **questions = NULL;
    int **answers = NULL;

    printf("Welcome to the C Online Examination System!\n");

    // Allocate memory for questions and answers
    questions = malloc(MAX_QUESTIONS * sizeof(char *));
    answers = malloc(MAX_QUESTIONS * sizeof(int *));

    // Create questions
    questions[0] = "What is the meaning of the word 'entrepreneur'?\n";
    questions[1] = "What is the square root of 64?\n";
    questions[2] = "Write a C program to print 'Hello, world!'\n";
    questions[3] = "What is the capital of France?\n";
    questions[4] = "What is the difference between a simile and a metaphor?\n";
    questions[5] = "Explain the concept of polymorphism in OOP.\n";
    questions[6] = "Write a short story about a journey to the North Pole.\n";
    questions[7] = "What are the different types of data structures?\n";
    questions[8] = "What is the meaning of the word 'entrepreneur' in a technical sense?\n";
    questions[9] = "What is the sound of one hand clapping?\n";

    // Get the number of questions
    printf("How many questions do you want to answer? ");
    scanf("%d", &numQuestions);

    // Answer questions
    for (int i = 0; i < numQuestions; i++)
    {
        printf("%s", questions[i]);
        scanf("%d", answers[i]);
    }

    // Print results
    printf("Your answers:\n");
    for (int i = 0; i < numQuestions; i++)
    {
        printf("Question: %s, Answer: %d\n", questions[i], answers[i]);
    }

    // Free memory
    free(questions);
    free(answers);

    return 0;
}