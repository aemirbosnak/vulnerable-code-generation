//Gemma-7B DATASET v1.0 Category: Online Examination System ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUESTIONS 10

int main()
{
    int num_questions = 0;
    int score = 0;
    char answer;

    // Allocate memory for questions
    char **questions = (char**)malloc(MAX_QUESTIONS * sizeof(char*));

    // Create and store questions
    questions[0] = "What is the meaning of life?";
    questions[1] = "Who invented the telephone?";
    questions[2] = "What is the capital of France?";
    questions[3] = "What is the sound of one hand clapping?";

    // Display questions
    printf("Welcome to the C Online Examination System!\n");
    printf("------------------------\n");
    while (num_questions < MAX_QUESTIONS)
    {
        printf("%d. %s\n", num_questions + 1, questions[num_questions]);
        num_questions++;
    }

    // Get the user's answer
    printf("Please enter your answer: ");
    scanf(" %c", &answer);

    // Check the answer and award points
    if (answer == 'a' || answer == 'A')
    {
        score++;
        printf("Correct!\n");
    }
    else
    {
        printf("Incorrect. The answer is a.\n");
    }

    // Display the final score
    printf("Your final score is: %d\n", score);

    // Free the allocated memory
    free(questions);

    return 0;
}