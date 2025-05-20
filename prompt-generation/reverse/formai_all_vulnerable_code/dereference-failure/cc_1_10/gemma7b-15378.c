//Gemma-7B DATASET v1.0 Category: Online Examination System ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_QUESTIONS 10
#define MAX_ANSWERS 4

typedef struct Question
{
    char *question;
    char **answers;
    int correctAnswer;
} Question;

Question questions[MAX_QUESTIONS] =
{
    {"What is the meaning of the word 'entrepreneur'?",
        {"a. A person who owns a business", "b. A person who is good at math", "c. A person who is creative", "d. A person who is successful"},
        1},

    {"Which scientist invented the theory of relativity?",
        {"a. Albert Einstein", "b. Isaac Newton", "c. Charles Darwin", "d. Galileo Galilei"},
        2},

    {"What is the capital of France?",
        {"a. Paris", "b. Rome", "c. Lyon", "d. Marseille"},
        3},

    // Add more questions here
};

int main()
{
    int i, score = 0, timeLeft = 60;

    // Seed the random number generator
    srand(time(NULL));

    // Display the questions
    for (i = 0; i < MAX_QUESTIONS; i++)
    {
        printf("%s\n", questions[i].question);

        // Display the answers
        for (int j = 0; j < MAX_ANSWERS; j++)
        {
            printf("%s) %s\n", j + 1, questions[i].answers[j]);
        }

        // Get the user's answer
        int answer = rand() % MAX_ANSWERS + 1;

        // Check if the user's answer is correct
        if (answer == questions[i].correctAnswer)
        {
            score++;
        }

        timeLeft--;
    }

    // Display the user's score
    printf("Your score: %d\n", score);

    // Display the time left
    printf("Time left: %d seconds\n", timeLeft);

    return 0;
}