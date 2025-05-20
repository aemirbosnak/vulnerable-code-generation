//Gemma-7B DATASET v1.0 Category: Online Examination System ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 10
#define MAX_ANSWERS 4

typedef struct Question
{
    char *question;
    char **answers;
    int answerIndex;
} Question;

Question questions[MAX_QUESTIONS] = {
    {"What is the meaning of the word 'entrepreneur'?", {"a. A business owner", "b. A scientist", "c. A teacher", "d. A lawyer"}, 2},
    {"Which scientist invented the theory of relativity?", {"a. Albert Einstein", "b. Isaac Newton", "c. Charles Darwin", "d. Galileo Galilei"}, 0},
    {"What is the capital of France?", {"a. Paris", "b. Rome", "c. Lyon", "d. Marseille"}, 0}
};

int main()
{
    int i, score = 0, currentQuestionIndex = 0;

    // Print the questions
    for (i = 0; i < MAX_QUESTIONS; i++)
    {
        printf("%s\n", questions[i].question);

        // Print the answers
        for (int j = 0; j < MAX_ANSWERS; j++)
        {
            printf("%s\n", questions[i].answers[j]);
        }

        // Get the user's answer
        char answer[MAX_ANSWERS];
        printf("Enter your answer: ");
        scanf("%s", answer);

        // Check if the user's answer is correct
        if (strcmp(answer, questions[i].answers[questions[i].answerIndex]) == 0)
        {
            score++;
        }

        // Move on to the next question
        currentQuestionIndex++;
    }

    // Print the final score
    printf("Your final score is: %d", score);

    return 0;
}