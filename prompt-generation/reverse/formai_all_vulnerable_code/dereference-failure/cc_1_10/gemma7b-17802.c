//Gemma-7B DATASET v1.0 Category: Online Examination System ; Style: complex
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

Question questions[MAX_QUESTIONS] =
{
    {"What is the meaning of the word 'entrepreneur'?", {"a. A person who owns and operates a business", "b. A person who is creative and innovative", "c. A person who is good at managing money", "d. A person who is ambitious and determined"}, 2},
    {"Which scientist invented the theory of relativity?", {"a. Albert Einstein", "b. Isaac Newton", "c. Charles Darwin", "d. Galileo Galilei"}, 1},
    {"What is the capital of France?", {"a. Paris", "b. Rome", "c. Berlin", "d. Lyon"}, 0},
    {"Which planet is the largest?", {"a. Earth", "b. Mars", "c. Jupiter", "d. Saturn"}, 3},
    {"What is the meaning of the word 'entrepreneur'?", {"a. A person who owns and operates a business", "b. A person who is creative and innovative", "c. A person who is good at managing money", "d. A person who is ambitious and determined"}, 2}
};

int main()
{
    int i, score = 0, totalQuestions = MAX_QUESTIONS;

    printf("Welcome to the C Online Examination System!\n");

    for (i = 0; i < totalQuestions; i++)
    {
        printf("Question %d: %s\n", i + 1, questions[i].question);

        printf("Answers:\n");

        int j;
        for (j = 0; j < MAX_ANSWERS; j++)
        {
            printf("%d. %s\n", j + 1, questions[i].answers[j]);
        }

        int answerChoice = getChoice();

        if (answerChoice == questions[i].correctAnswer)
        {
            score++;
        }

        printf("Next question...\n");
    }

    printf("Your total score: %d out of %d\n", score, totalQuestions);

    return 0;
}

int getChoice()
{
    int choice;

    printf("Enter your choice: ");
    scanf("%d", &choice);

    return choice;
}