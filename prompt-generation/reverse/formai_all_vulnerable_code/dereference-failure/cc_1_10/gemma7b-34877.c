//Gemma-7B DATASET v1.0 Category: Online Examination System ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_QUESTIONS 10
#define MAX_ANSWERS 4

typedef struct Question {
    char *question;
    char **answers;
    int answerIndex;
} Question;

Question questions[MAX_QUESTIONS] = {
    {"What is the meaning of the word 'entrepreneur'?", {"a. A person who starts and manages a business", "b. A person who is good at math", "c. A person who is creative", "d. A person who is successful"}, 1},
    {"Which planet is the largest?", {"a. Earth", "b. Mars", "c. Jupiter", "d. Saturn"}, 2},
    {"What is the capital of France?", {"a. Paris", "b. Rome", "c. Lyon", "d. Marseille"}, 3},
    {"Which scientist invented the theory of relativity?", {"a. Albert Einstein", "b. Isaac Newton", "c. Charles Darwin", "d. Galileo Galilei"}, 4},
    {"What is the most common color of the human eye?", {"a. Blue", "b. Brown", "c. Gray", "d. Hazel"}, 5},
    {"Which animal is known for its sharp hearing?", {"a. Dog", "b. Cat", "c. Tiger", "d. Bat"}, 6},
    {"What is the sound of one hand clapping?", {"a. Silence", "b. Silence", "c. Silence", "d. A click"}, 7},
    {"Which fruit is the most popular in the world?", {"a. Apple", "b. Orange", "c. Banana", "d. Pineapple"}, 8},
    {"What is the meaning of the word 'entrepreneur'?", {"a. A person who starts and manages a business", "b. A person who is good at math", "c. A person who is creative", "d. A person who is successful"}, 9},
    {"Which scientist invented the theory of quantum mechanics?", {"a. Albert Einstein", "b. Isaac Newton", "c. Charles Darwin", "d. Galileo Galilei"}, 10}
};

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Generate a random question
    int questionIndex = rand() % MAX_QUESTIONS;

    // Display the question and answers
    printf("%s\n", questions[questionIndex].question);
    for (int i = 0; i < MAX_ANSWERS; i++) {
        printf("%s\n", questions[questionIndex].answers[i]);
    }

    // Get the user's answer
    char answer;

    // Validate the user's answer
    if (answer == questions[questionIndex].answerIndex) {
        // The user's answer is correct
        printf("Congratulations! You have answered the question correctly.\n");
    } else {
        // The user's answer is incorrect
        printf("Sorry, your answer is incorrect. The correct answer is %s.\n", questions[questionIndex].answers[questions[questionIndex].answerIndex]);
    }

    return 0;
}