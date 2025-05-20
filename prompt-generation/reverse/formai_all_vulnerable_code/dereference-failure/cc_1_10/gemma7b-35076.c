//Gemma-7B DATASET v1.0 Category: Online Examination System ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

int main()
{

    system("clear");

    // Generating random questions
    int numQuestions = rand() % 10 + 1;
    printf("Number of questions: %d\n", numQuestions);

    // Array of questions
    char **questions = (char**)malloc(numQuestions * sizeof(char*));
    for (int i = 0; i < numQuestions; i++)
    {
        questions[i] = (char*)malloc(256 * sizeof(char));
        sprintf(questions[i], "Question %d: ", i + 1);
        printf("%s", questions[i]);
    }

    // Array of answer choices
    char ***answers = (char***)malloc(numQuestions * sizeof(char**));
    for (int i = 0; i < numQuestions; i++)
    {
        answers[i] = (char**)malloc(4 * sizeof(char*));
        for (int j = 0; j < 4; j++)
        {
            answers[i][j] = (char*)malloc(256 * sizeof(char));
            sprintf(answers[i][j], "Answer Choice %d: ", j + 1);
            printf("%s", answers[i][j]);
        }
    }

    // Collecting user answers
    int userAnswer;
    printf("Please select your answer: ");
    scanf("%d", &userAnswer);

    // Checking user answer
    int isCorrect = (userAnswer - 1) == rand() % 4;

    // Displaying results
    system("clear");
    printf("Results:");
    if (isCorrect)
    {
        printf("\nCongratulations! You are correct.");
    }
    else
    {
        printf("\nSorry, your answer is incorrect. The correct answer is:");
        printf("\n%s", questions[rand() % numQuestions]);
        printf("\nThe correct answer is: %s", answers[rand() % numQuestions][rand() % 4]);
    }

    return 0;
}