//Gemma-7B DATASET v1.0 Category: Online Examination System ; Style: active
#include <stdio.h>
#include <stdlib.h>

int main()
{
    system("clear");
    printf("Welcome to the C Online Examination System!\n");

    // Create a random question bank
    char **questions = (char**)malloc(10 * sizeof(char*));
    for (int i = 0; i < 10; i++)
    {
        questions[i] = (char*)malloc(100 * sizeof(char));
        sprintf(questions[i], "Question %d: ", i + 1);
        // Insert a unique question here
    }

    // Allocate memory for the answer choices
    char ***answers = (char***)malloc(10 * sizeof(char**));
    for (int i = 0; i < 10; i++)
    {
        answers[i] = (char**)malloc(4 * sizeof(char*));
        for (int j = 0; j < 4; j++)
        {
            answers[i][j] = (char*)malloc(100 * sizeof(char));
            sprintf(answers[i][j], "Answer Choice %d: ", j + 1);
            // Insert answer choices here
        }
    }

    // Get the student's name and roll number
    char student_name[50];
    printf("Enter your name: ");
    scanf("%s", student_name);

    int roll_number;
    printf("Enter your roll number: ");
    scanf("%d", &roll_number);

    // Start the examination
    printf("Start the examination:\n");
    for (int i = 0; i < 10; i++)
    {
        printf("%s", questions[i]);

        // Get the student's answer
        char answer;
        printf("Enter your answer: ");
        scanf(" %c", &answer);

        // Check if the answer is correct
        int is_correct = 0;
        for (int j = 0; j < 4; j++)
        {
            if (answer == answers[i][j][0])
            {
                is_correct = 1;
                break;
            }
        }

        // Give feedback to the student
        if (is_correct)
        {
            printf("Correct!\n");
        }
        else
        {
            printf("Incorrect. The correct answer is: %s\n", answers[i][0]);
        }
    }

    // End the examination

    printf("Thank you for taking the C Online Examination System, %s! Your score is: %d\n", student_name, roll_number);

    return 0;
}