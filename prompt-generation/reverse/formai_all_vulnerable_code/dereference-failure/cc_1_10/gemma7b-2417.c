//Gemma-7B DATASET v1.0 Category: Online Examination System ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_QUESTIONS 10

typedef struct Question
{
    char *question;
    char **answers;
    int correctAnswer;
} Question;

Question questions[MAX_QUESTIONS] =
{
    {"What is the meaning of the word 'entrepreneur'?", {"a. A person who sells things", "b. A person who owns a business", "c. A person who is good at math", "d. A person who is good at writing"}, 1},
    {"What is the capital of France?", {"a. Paris", "b. Lyon", "c. Marseille", "d. Brussels"}, 2},
    {"Which scientist invented the theory of relativity?", {"a. Albert Einstein", "b. Isaac Newton", "c. Charles Darwin", "d. Galileo Galilei"}, 3},
    {"What is the most populous continent in the world?", {"a. Asia", "b. North America", "c. Africa", "d. South America"}, 4},
    {"Which planet is the largest in the solar system?", {"a. Mars", "b. Earth", "c. Jupiter", "d. Saturn"}, 5},
    {"What is the sound of one hand clapping?", {"a. Silence", "b. Hum", "c. Click", "d. Buzz"}, 6},
    {"Which animal is known for its intelligence?", {"a. Dog", "b. Cat", "c. Elephant", "d. Horse"}, 7},
    {"Which fruit is the most popular in the world?", {"a. Apple", "b. Orange", "c. Banana", "d. Strawberry"}, 8},
    {"What is the most common color of hair in the world?", {"a. Black", "b. Brown", "c. Blonde", "d. Red"}, 9},
    {"What is the meaning of the word 'entrepreneur'?", {"a. A person who sells things", "b. A person who owns a business", "c. A person who is good at math", "d. A person who is good at writing"}, 1}
};

int main()
{
    int i, score = 0, timeLeft = 60;
    char answer;

    system("clear");

    // Print the questions
    for (i = 0; i < MAX_QUESTIONS; i++)
    {
        printf("%d. %s\n", i + 1, questions[i].question);

        // Print the answers
        for (int j = 0; j < 4; j++)
        {
            printf("  %c. %s\n", questions[i].answers[j] + 97, questions[i].answers[j]);
        }

        printf("\n");
    }

    // Get the user's answer
    printf("Enter your answer: ");
    scanf("%c", &answer);

    // Check if the answer is correct
    for (i = 0; i < MAX_QUESTIONS; i++)
    {
        if (questions[i].correctAnswer == answer - 97)
        {
            score++;
        }
    }

    // Print the results
    printf("Your score: %d/%d\n", score, MAX_QUESTIONS);

    // End the exam
    printf("Thank you for taking the exam.\n");

    return 0;
}