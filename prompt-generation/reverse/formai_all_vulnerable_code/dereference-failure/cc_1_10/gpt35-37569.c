//FormAI DATASET v1.0 Category: Online Examination System ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define N 5

// Function to generate random question numbers
int *generate_question_numbers(int n)
{
    int *numbers = malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
    {
        numbers[i] = rand() % 10 + 1;
        for (int j = 0; j < i; j++)
        {
            if (numbers[j] == numbers[i])
            {
                i--;
                break;
            }
        }
    }
    return numbers;
}

// Function to check answers
int check_answers(int *answers, int *keys, int n)
{
    int score = 0;
    for (int i = 0; i < n; i++)
    {
        if (answers[i] == keys[i])
        {
            score++;
        }
    }
    return score;
}

int main()
{
    int *question_numbers;
    int answers[N], keys[N] = {1, 2, 3, 4, 5};
    int score = 0;
    char name[50];

    // Set random seed
    srand(time(NULL));

    // Prompt user for name
    printf("Enter your name: ");
    scanf("%s", name);

    // Generate random question numbers
    question_numbers = generate_question_numbers(N);

    // Print welcome message
    printf("Welcome to the C online examination system, %s!\n", name);
    printf("You will be presented with %d multiple-choice questions.\n", N);

    // Ask questions and record answers
    for (int i = 0; i < N; i++)
    {
        int answer;
        printf("Question %d: What is the value of x in the following code?\n", i + 1);
        printf("int x = %d;\n", question_numbers[i]);
        printf("a) %d\n", question_numbers[i] - 1);
        printf("b) %d\n", question_numbers[i]);
        printf("c) %d\n", question_numbers[i] + 1);
        printf("d) %d\n", question_numbers[i] * 2);
        printf("Enter your answer: ");
        scanf("%d", &answer);
        answers[i] = answer;
    }

    // Check answers and print score
    score = check_answers(answers, keys, N);
    printf("\nThank you for taking the exam, %s!\n", name);
    printf("Your score is: %d out of %d\n", score, N);

    return 0;
}