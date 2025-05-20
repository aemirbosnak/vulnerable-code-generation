//Gemma-7B DATASET v1.0 Category: Online Examination System ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void generate_exam_paper(int num_questions, char **questions, int **answers)
{
    // Allocate memory for the questions and answers
    questions = malloc(num_questions * sizeof(char *));
    answers = malloc(num_questions * sizeof(int *));

    // Create the questions
    for (int i = 0; i < num_questions; i++)
    {
        questions[i] = malloc(256 * sizeof(char));
        printf("Enter the question: ");
        fgets(questions[i], 256, stdin);
    }

    // Get the answers
    for (int i = 0; i < num_questions; i++)
    {
        answers[i] = malloc(10 * sizeof(int));
        printf("Enter the answer choices: ");
        scanf("%d %d %d %d", answers[i][0], answers[i][1], answers[i][2], answers[i][3]);
    }
}

int main()
{
    int num_questions = 10;
    char **questions = NULL;
    int **answers = NULL;

    generate_exam_paper(num_questions, questions, answers);

    // Print the exam paper
    for (int i = 0; i < num_questions; i++)
    {
        printf("%s\n", questions[i]);
        printf("Answers: ");
        for (int j = 0; j < 4; j++)
        {
            printf("%d ", answers[i][j]);
        }
        printf("\n");
    }

    // Free the memory
    for (int i = 0; i < num_questions; i++)
    {
        free(questions[i]);
        free(answers[i]);
    }
    free(questions);
    free(answers);

    return 0;
}