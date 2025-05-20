//Gemma-7B DATASET v1.0 Category: Online Examination System ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_QUESTIONS 10
#define MAX_ANSWERS 4

typedef struct Question {
    char *question;
    char **answers;
    int correctAnswer;
} Question;

Question questions[MAX_QUESTIONS] = {
    {"What is the meaning of the word 'entrepreneur'?", {"a. A person who is good at business", "b. A person who is good at math", "c. A person who is good at science", "d. A person who is good at technology"}, 1},
    {"Which scientist invented the theory of relativity?", {"a. Albert Einstein", "b. Isaac Newton", "c. Charles Darwin", "d. Galileo Galilei"}, 2},
    {"Which planet is the largest?", {"a. Earth", "b. Mars", "c. Jupiter", "d. Saturn"}, 3},
    {"What is the capital of France?", {"a. Paris", "b. Lyon", "c. Marseille", "d. Lille"}, 4},
    {"Which animal is known for its ability to swim?", {"a. Dog", "b. Cat", "c. Fish", "d. Horse"}, 5},
    {"Which fruit is the most popular in the world?", {"a. Apple", "b. Orange", "c. Banana", "d. Pineapple"}, 6},
    {"What is the meaning of the word 'entrepreneur'?", {"a. A person who is good at business", "b. A person who is good at math", "c. A person who is good at science", "d. A person who is good at technology"}, 1},
    {"Which scientist invented the theory of relativity?", {"a. Albert Einstein", "b. Isaac Newton", "c. Charles Darwin", "d. Galileo Galilei"}, 2},
    {"Which planet is the largest?", {"a. Earth", "b. Mars", "c. Jupiter", "d. Saturn"}, 3},
    {"What is the capital of France?", {"a. Paris", "b. Lyon", "c. Marseille", "d. Lille"}, 4}
};

int main() {
    time_t start_time = time(NULL);
    int score = 0;
    int currentQuestion = 0;

    printf("Welcome to the C Online Examination System!\n");

    while (currentQuestion < MAX_QUESTIONS) {
        printf("Question %d: %s\n", currentQuestion + 1, questions[currentQuestion].question);

        for (int i = 0; i < MAX_ANSWERS; i++) {
            printf("Answer %d: %s\n", i + 1, questions[currentQuestion].answers[i]);
        }

        int answerChoice = 0;
        printf("Enter your answer choice: ");
        scanf("%d", &answerChoice);

        if (answerChoice == questions[currentQuestion].correctAnswer) {
            score++;
        }

        currentQuestion++;
    }

    time_t end_time = time(NULL);
    int timeTaken = end_time - start_time;

    printf("Your score: %d/%d\n", score, MAX_QUESTIONS);
    printf("Time taken: %d minutes\n", timeTaken);

    return 0;
}