//Gemma-7B DATASET v1.0 Category: Online Examination System ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 10
#define MAX_ANSWERS 4

typedef struct Question {
    char question[256];
    char answers[MAX_ANSWERS][256];
    int correctAnswerIndex;
} Question;

int main() {
    Question questions[MAX_QUESTIONS] = {
        {"What is the meaning of the word 'entrepreneur'?", {"a. A person who starts and operates a business", "b. A person who is good at math", "c. A person who is creative", "d. A person who is successful"}, 0},
        {"Which scientist invented the theory of relativity?", {"a. Albert Einstein", "b. Isaac Newton", "c. Charles Darwin", "d. Galileo Galilei"}, 1},
        {"What is the capital of France?", {"a. Paris", "b. Rome", "c. Lyon", "d. Marseille"}, 2},
        {"What is the most populous continent in the world?", {"a. Asia", "b. North America", "c. South America", "d. Africa"}, 3},
        {"Which planet is the largest in the Solar System?", {"a. Mars", "b. Earth", "c. Jupiter", "d. Saturn"}, 4},
        {"What is the sound of one hand clapping?", {"a. Silence", "b. A hum", "c. A click", "d. A snap"}, 5},
        {"Which animal is known for its ability to swim?", {"a. Fish", "b. Dolphin", "c. Turtle", "d. Frog"}, 6},
        {"What is the meaning of the word 'entrepreneur'?", {"a. A person who starts and operates a business", "b. A person who is good at math", "c. A person who is creative", "d. A person who is successful"}, 7},
        {"Which scientist invented the theory of relativity?", {"a. Albert Einstein", "b. Isaac Newton", "c. Charles Darwin", "d. Galileo Galilei"}, 8},
        {"What is the capital of France?", {"a. Paris", "b. Rome", "c. Lyon", "d. Marseille"}, 9}
    };

    int numQuestions = 10;

    // Randomly select a question
    int randIndex = rand() % numQuestions;

    // Print the question
    printf("%s\n", questions[randIndex].question);

    // Print the answers
    for (int i = 0; i < MAX_ANSWERS; i++) {
        printf("%s\n", questions[randIndex].answers[i]);
    }

    // Get the user's answer
    char userAnswer[256];
    printf("Enter your answer: ");
    scanf("%s", userAnswer);

    // Check if the user's answer is correct
    int isCorrect = (strcmp(userAnswer, questions[randIndex].answers[questions[randIndex].correctAnswerIndex]) == 0);

    // Print the results
    if (isCorrect) {
        printf("Your answer is correct!\n");
    } else {
        printf("Your answer is incorrect. The correct answer is: %s\n", questions[randIndex].answers[questions[randIndex].correctAnswerIndex]);
    }

    return 0;
}