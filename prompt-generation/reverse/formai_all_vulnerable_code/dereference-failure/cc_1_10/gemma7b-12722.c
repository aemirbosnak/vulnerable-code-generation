//Gemma-7B DATASET v1.0 Category: Online Examination System ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 10
#define MAX_ANSWERS 5

typedef struct Question
{
    char *question;
    char **answers;
    int correct_answer;
} Question;

Question questions[MAX_QUESTIONS] =
{
    {"What is the meaning of the word 'entrepreneur'?", {"a. Business owner", "b. Employee", "c. Salesperson", "d. Manager", "e. Lawyer"}, 1},
    {"Which scientist invented the theory of relativity?", {"a. Isaac Newton", "b. Albert Einstein", "c. Charles Darwin", "d. Galileo Galilei", "e. Albert Turing"}, 2},
    {"What is the capital of France?", {"a. Paris", "b. Rome", "c. Lyon", "d. Marseille", "e. Brussels"}, 3},
    {"Which planet is the largest?", {"a. Mars", "b. Earth", "c. Jupiter", "d. Saturn", "e. Venus"}, 4},
    {"What is the sound of one hand clapping?", {"a. Silence", "b. A hum", "c. A click", "d. A buzz", "e. A beep"}, 5},
    {"What is the meaning of the word 'entrepreneur'?", {"a. Business owner", "b. Employee", "c. Salesperson", "d. Manager", "e. Lawyer"}, 1},
    {"Which scientist invented the theory of relativity?", {"a. Isaac Newton", "b. Albert Einstein", "c. Charles Darwin", "d. Galileo Galilei", "e. Albert Turing"}, 2},
    {"What is the capital of France?", {"a. Paris", "b. Rome", "c. Lyon", "d. Marseille", "e. Brussels"}, 3},
    {"Which planet is the largest?", {"a. Mars", "b. Earth", "c. Jupiter", "d. Saturn", "e. Venus"}, 4},
    {"What is the sound of one hand clapping?", {"a. Silence", "b. A hum", "c. A click", "d. A buzz", "e. A beep"}, 5}
};

int main()
{
    int i, score = 0;

    // Display questions
    for (i = 0; i < MAX_QUESTIONS; i++)
    {
        printf("%s\n", questions[i].question);

        // Display answers
        for (int j = 0; j < MAX_ANSWERS; j++)
        {
            printf("%s\n", questions[i].answers[j]);
        }

        // Get the user's answer
        char answer;
        printf("Enter your answer: ");
        scanf("%c", &answer);

        // Check if the user's answer is correct
        if (answer == questions[i].correct_answer)
        {
            score++;
        }
    }

    // Display the user's score
    printf("Your score: %d out of %d\n", score, MAX_QUESTIONS);

    return 0;
}