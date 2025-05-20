//Gemma-7B DATASET v1.0 Category: Online Examination System ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 10
#define MAX_ANSWERS 4

typedef struct Question
{
    char *question;
    char **answers;
    int correctAnswer;
} Question;

Question questions[MAX_QUESTIONS] = {
    {"What is the meaning of the word 'entrepreneur'?", {"a. Business owner", "b. Employee", "c. Teacher", "d. Lawyer"}, 1},
    {"What is the capital of Australia?", {"a. Sydney", "b. Melbourne", "c. Canberra", "d. Perth"}, 2},
    {"Which scientist invented the theory of relativity?", {"a. Albert Einstein", "b. Isaac Newton", "c. Charles Darwin", "d. Galileo Galilei"}, 0},
    // Add more questions here...
};

int main()
{
    int i, score = 0;
    char answer;

    // Print questions
    for (i = 0; i < MAX_QUESTIONS; i++)
    {
        printf("%s\n", questions[i].question);

        // Print answers
        for (int j = 0; j < MAX_ANSWERS; j++)
        {
            printf("%s\n", questions[i].answers[j]);
        }

        // Get the user's answer
        printf("Enter your answer: ");
        scanf(" %c", &answer);

        // Check if the answer is correct
        if (answer == questions[i].correctAnswer)
        {
            score++;
            printf("Correct!\n");
        }
        else
        {
            printf("Incorrect. The answer is: %c\n", questions[i].correctAnswer);
        }
    }

    // Print the final score
    printf("Your final score is: %d\n", score);

    return 0;
}