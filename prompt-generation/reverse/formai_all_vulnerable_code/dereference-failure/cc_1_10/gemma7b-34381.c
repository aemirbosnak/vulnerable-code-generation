//Gemma-7B DATASET v1.0 Category: Online Examination System ; Style: curious
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
    {"What is the meaning of the word 'entrepreneur'?", {"a. A person who starts and manages a business", "b. A person who is good at mathematics", "c. A person who is creative", "d. A person who is ambitious"}, 1},
    {"What is the capital of France?", {"a. Paris", "b. Rome", "c. Lyon", "d. Brussels"}, 2},
    {"Which scientist invented the theory of relativity?", {"a. Isaac Newton", "b. Albert Einstein", "c. Charles Darwin", "d. Galileo Galilei"}, 3},
    {"What is the most common color of the human eye?", {"a. Blue", "b. Brown", "c. Hazel", "d. Gray"}, 4},
    {"What is the sound of one hand clapping?", {"a. Silence", "b. Hum", "c. Click", "d. Bang"}, 5},
    {"What is the meaning of the word 'entrepreneur'?", {"a. A person who starts and manages a business", "b. A person who is good at mathematics", "c. A person who is creative", "d. A person who is ambitious"}, 1},
    {"What is the capital of France?", {"a. Paris", "b. Rome", "c. Lyon", "d. Brussels"}, 2},
    {"Which scientist invented the theory of relativity?", {"a. Isaac Newton", "b. Albert Einstein", "c. Charles Darwin", "d. Galileo Galilei"}, 3},
    {"What is the most common color of the human eye?", {"a. Blue", "b. Brown", "c. Hazel", "d. Gray"}, 4},
    {"What is the sound of one hand clapping?", {"a. Silence", "b. Hum", "c. Click", "d. Bang"}, 5}
};

int main() {
    time_t t = time(NULL);
    srand(t);

    int score = 0;
    int currentQuestion = rand() % MAX_QUESTIONS;

    printf("Welcome to the C Online Examination System!\n");
    printf("Current Question: %s\n", questions[currentQuestion].question);

    for (int i = 0; i < MAX_ANSWERS; i++) {
        printf("Answer %d: %s\n", i + 1, questions[currentQuestion].answers[i]);
    }

    int answer = -1;
    printf("Enter your answer: ");
    scanf("%d", &answer);

    if (answer == questions[currentQuestion].correctAnswer) {
        score++;
        printf("Correct! You have earned 1 point.\n");
    } else {
        printf("Incorrect. The correct answer is: %s\n", questions[currentQuestion].answers[questions[currentQuestion].correctAnswer]);
    }

    printf("Your total score is: %d\n", score);

    return 0;
}